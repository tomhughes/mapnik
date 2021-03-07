
#include "catch.hpp"

#include <mapnik/projection.hpp>
#include <mapnik/proj_transform.hpp>
#include <mapnik/box2d.hpp>
#include <cmath>
#include <tuple>

TEST_CASE("projection transform")
{

SECTION("Test bounding box transforms - 4326 to 3857")
{
    mapnik::projection proj_4326("epsg:4326");
    mapnik::projection proj_3857("epsg:3857");

    CHECK(proj_4326.is_geographic());
    CHECK(!proj_3857.is_geographic());

    mapnik::proj_transform prj_trans(proj_4326, proj_3857);

    double minx = -45.0;
    double miny = 55.0;
    double maxx = -40.0;
    double maxy = 75.0;

    mapnik::box2d<double> bbox(minx, miny, maxx, maxy);

    prj_trans.forward(bbox);
    INFO(bbox.to_string());
    CHECK(bbox.minx() == Approx(-5009377.085697311));
    CHECK(bbox.miny() == Approx(7361866.1130511891));
    CHECK(bbox.maxx() == Approx(-4452779.631730943));
    CHECK(bbox.maxy() == Approx(12932243.1119920239));

    prj_trans.backward(bbox);
    CHECK(bbox.minx() == Approx(minx));
    CHECK(bbox.miny() == Approx(miny));
    CHECK(bbox.maxx() == Approx(maxx));
    CHECK(bbox.maxy() == Approx(maxy));

}


#if defined(MAPNIK_USE_PROJ)
SECTION("test proj_transform failure behavior")
{
    mapnik::projection proj_4269("epsg:4269");
    mapnik::projection proj_3857("epsg:3857");
    mapnik::proj_transform prj_trans(proj_4269, proj_3857);
    mapnik::proj_transform prj_trans2(proj_3857, proj_4269);

    // test valid coordinate
    double x0 = -180.0;
    double y0 = -60.0;
    CHECK( prj_trans.forward(&x0,&y0,nullptr,1,1) );
    CHECK( x0 == Approx(-20037508.3427892439) );
    CHECK( y0 == Approx(-8399737.8896366451) );
    double x1 = -180.0;
    double y1 = -60.0;
    CHECK( prj_trans2.backward(&x1,&y1,nullptr,1,1) );
    CHECK( x1 == Approx(-20037508.3427892439) );
    CHECK( y1 == Approx(-8399737.8896366451) );

    // now test invalid coordinate
    double x2 = -181.0;
    double y2 = -91.0;
    prj_trans.forward(&x2,&y2,nullptr,1,1);
    CHECK( std::isinf(x2) );
    CHECK( std::isinf(y2) );
    double x3 = -181.0;
    double y3 = -91.0;
    prj_trans2.backward(&x3,&y3,nullptr,1,1);
    CHECK( std::isinf(x3) );
    CHECK( std::isinf(y3) );
}

SECTION("test forward/backward transformations")
{
    //WGS 84 - World Geodetic System 1984, used in GPS
    mapnik::projection proj_4236("epsg:4236");
    //OSGB 1936 / British National Grid -- United Kingdom Ordnance Survey
    mapnik::projection proj_27700("epsg:27700");
    //WGS 84 / Equal Earth Greenwich
    mapnik::projection proj_8857("epsg:8857");
    //European Terrestrial Reference System 1989 (ETRS89)
    mapnik::projection proj_4937("epsg:4937");
    //"Webmercator" WGS 84 / Pseudo-Mercator -- Spherical Mercator, Google Maps, OpenStreetMap, Bing, ArcGIS, ESRI
    mapnik::projection proj_3857("epsg:3857");

    mapnik::proj_transform tr1(proj_4236, proj_27700);
    mapnik::proj_transform tr2(proj_4236, proj_8857);
    mapnik::proj_transform tr3(proj_4236, proj_4236);
    mapnik::proj_transform tr4(proj_4236, proj_4937);
    mapnik::proj_transform tr5(proj_4236, proj_3857);
    std::initializer_list<std::reference_wrapper<mapnik::proj_transform>> transforms = {
        tr1, tr2, tr3, tr4, tr5
    };

    std::initializer_list<std::tuple<double, double>> coords = {
        {-4.0278869, 57.8796955}, // Dórnach, Highland
        {-4.2488787, 55.8609825}, // Glaschú, Alba
        {-1.4823897, 51.8726941}, // Charlbury, England
        {-3.9732612, 51.7077400}  // Felindre, Cymru
    };

    for (auto const& c : coords)
    {
        double x0, y0;
        std::tie(x0, y0) = c;
        for (mapnik::proj_transform const& tr : transforms)
        {
            double x1 = x0;
            double y1 = y0;
            tr.forward (&x1, &y1, nullptr, 1, 1);
            tr.backward(&x1, &y1, nullptr, 1, 1);
            CHECK (x0 == Approx(x1));
            CHECK (y0 == Approx(y1));
        }
    }
}

// Github Issue https://github.com/mapnik/mapnik/issues/2648
SECTION("Test proj antimeridian bbox")
{
    mapnik::projection prj_geog("epsg:4326");
    mapnik::projection prj_proj("epsg:2193");

    mapnik::proj_transform prj_trans_fwd(prj_proj, prj_geog);
    mapnik::proj_transform prj_trans_rev(prj_geog, prj_proj);

    // reference values taken from proj4 command line tool:
    // (non-corner points assume PROJ_ENVELOPE_POINTS == 20)
    //
    //  cs2cs -Ef %.10f epsg:2193 +to epsg:4326 <<END
    //        2105800 3087000 # left-most
    //        1495200 3087000 # bottom-most
    //        2105800 7173000 # right-most
    //        3327000 7173000 # top-most
    //  END
    //
    // wrong = mapnik.Box2d(-177.3145325044, -62.3337481525,
    //                       178.0277836332, -24.5845974912)
    const mapnik::box2d<double> better(-180.0, -62.3337481525,
                                        180.0, -24.5845974912);

    {
        mapnik::box2d<double> ext(274000, 3087000, 3327000, 7173000);
        prj_trans_fwd.forward(ext, PROJ_ENVELOPE_POINTS);
        CHECK(ext.minx() == Approx(better.minx()));
        CHECK(ext.miny() == Approx(better.miny()));
        CHECK(ext.maxx() == Approx(better.maxx()));
        CHECK(ext.maxy() == Approx(better.maxy()));
    }

    {
        // check the same logic works for .backward()
        mapnik::box2d<double> ext(274000, 3087000, 3327000, 7173000);
        prj_trans_rev.backward(ext, PROJ_ENVELOPE_POINTS);
        CHECK(ext.minx() == Approx(better.minx()));
        CHECK(ext.miny() == Approx(better.miny()));
        CHECK(ext.maxx() == Approx(better.maxx()));
        CHECK(ext.maxy() == Approx(better.maxy()));
    }

    // reference values taken from proj4 command line tool:
    //
    //  cs2cs -Ef %.10f epsg:2193 +to epsg:4326 <<END
    //        274000 3087000 # left-most
    //        276000 3087000 # bottom-most
    //        276000 7173000 # right-most
    //        274000 7173000 # top-most
    //  END
    //
    const mapnik::box2d<double> normal(148.7639922894, -60.1221489796,
                                       159.9548476477, -24.9771194497);

    {
        // checks for not being snapped (ie. not antimeridian)
        mapnik::box2d<double> ext(274000, 3087000, 276000, 7173000);
        prj_trans_fwd.forward(ext, PROJ_ENVELOPE_POINTS);
        CHECK(ext.minx() == Approx(normal.minx()));
        CHECK(ext.miny() == Approx(normal.miny()));
        CHECK(ext.maxx() == Approx(normal.maxx()));
        CHECK(ext.maxy() == Approx(normal.maxy()));
    }

    {
        // check the same logic works for .backward()
        mapnik::box2d<double> ext(274000, 3087000, 276000, 7173000);
        CHECKED_IF(prj_trans_rev.backward(ext, PROJ_ENVELOPE_POINTS))
        {
            CHECK(ext.minx() == Approx(normal.minx()));
            CHECK(ext.miny() == Approx(normal.miny()));
            CHECK(ext.maxx() == Approx(normal.maxx()));
            CHECK(ext.maxy() == Approx(normal.maxy()));
        }
    }
}
#endif

}
