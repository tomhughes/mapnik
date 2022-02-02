#ifndef MAPNIK_WARNING_HPP
#define MAPNIK_WARNING_HPP
// clang-format off
#if defined(_MSC_VER)
    #define MAPNIK_DISABLE_WARNING_PUSH           __pragma(warning( push ))
    #define MAPNIK_DISABLE_WARNING_POP            __pragma(warning( pop )) 
    #define MAPNIK_DISABLE_WARNING(warningNumber) __pragma(warning( disable : warningNumber ))

    // add warnings to deactivate here
    // example: #define DISABLE_WARNING_UNREFERENCED_FORMAL_PARAMETER    DISABLE_WARNING(4100)
    #define MAPNIK_DISABLE_WARNING_UNKNOWN_PRAGMAS         MAPNIK_DISABLE_WARNING(4068)
    #define MAPNIK_DISABLE_WARNING_PRAGMAS                 //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_PRAGMA_MESSAGES         //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_UNSEQUENCED             //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_UNUSED_FUNCTION         //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_UNUSED_PARAMETER        //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_REDECLARED_CLASS_MEMBER //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_UNUSED_LOCAL_TYPEDEF    //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_UNUSED_LOCAL_TYPEDEFS   //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_SHADOW                  //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_CPP11_NARROWING         //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_SIGN_CONVERSION         //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_SIGN_COMPARE            //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_CONVERSION              MAPNIK_DISABLE_WARNING(4244)
    #define MAPNIK_DISABLE_WARNING_CPP_98_COMPAT_PEDANTIC  //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_DISABLE_MACRO_EXPANSION //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_OLD_STYLE_CAST          //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_DOCUMENTATION           //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_DOCUMENTATION_UNKNOWN_COMMAND //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_UNDEF                   //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_DEPRECATED              MAPNIK_DISABLE_WARNING(4996)
    #define MAPNIK_DISABLE_WARNING_PADDED                  //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_CPP_98_COMPAT           //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_RESERVED_ID_MACRO       //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_WEAK_VTABLE             //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_EXTRA_SEMI              //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_GLOBAL_CONSTRUCTORS     //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_HEADER_HYGIENE          //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_EXIT_TIME_DESTRUCTORS   //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_SWITCH_ENUM             //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_MISSING_NORETURN        //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_COVERED_SWITCH_DEFAULT  //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_WARNING_FLOAT_EQUAL             //MAPNIK_DISABLE_WARNING(??)
    #define MAPNIK_DISABLE_LONG_LONG                       //MAPNIK_DISABLE_WARNING(??)    
    #define MAPNIK_DISABLE_UNDEFINED_VAR_TEMPLATE          //MAPNIK_DISABLE_WARNING(??)    
    #define MAPNIK_DISABLE_UNUSED_VARIABLE                 MAPNIK_DISABLE_WARNING(4101)   
    #define MAPNIK_DISABLE_MISMATCHED_TAGS                 //MAPNIK_DISABLE_WARNING(??)    
    
#elif defined(__GNUC__) || defined(__clang__)
    #define MAPNIK_DO_PRAGMA(X) _Pragma(#X)
    #define MAPNIK_DISABLE_WARNING_PUSH           MAPNIK_DO_PRAGMA(GCC diagnostic push)
    #define MAPNIK_DISABLE_WARNING_POP            MAPNIK_DO_PRAGMA(GCC diagnostic pop) 
    #define MAPNIK_DISABLE_WARNING(warningName)   MAPNIK_DO_PRAGMA(GCC diagnostic ignored #warningName)
   // add warnings to deactivate here
   // example: #define DISABLE_WARNING_UNREFERENCED_FORMAL_PARAMETER    DISABLE_WARNING(-Wunused-parameter)
    #define MAPNIK_DISABLE_WARNING_UNKNOWN_PRAGMAS         MAPNIK_DISABLE_WARNING(-Wunknown-pragmas)
    #define MAPNIK_DISABLE_WARNING_PRAGMAS                 MAPNIK_DISABLE_WARNING(-Wpragmas)
    #define MAPNIK_DISABLE_WARNING_PRAGMA_MESSAGES         MAPNIK_DISABLE_WARNING(-W#pragma-messages)
    #define MAPNIK_DISABLE_WARNING_UNSEQUENCED             MAPNIK_DISABLE_WARNING(-Wunsequenced)
    #define MAPNIK_DISABLE_WARNING_UNUSED_FUNCTION         MAPNIK_DISABLE_WARNING(-Wunused-function)
    #define MAPNIK_DISABLE_WARNING_UNUSED_PARAMETER        MAPNIK_DISABLE_WARNING(-Wunused-parameter)
    #define MAPNIK_DISABLE_WARNING_REDECLARED_CLASS_MEMBER MAPNIK_DISABLE_WARNING(-Wredeclared-class-member)
    #define MAPNIK_DISABLE_WARNING_UNUSED_LOCAL_TYPEDEF    MAPNIK_DISABLE_WARNING(-Wunused-local-typedef)
    #define MAPNIK_DISABLE_WARNING_UNUSED_LOCAL_TYPEDEFS   MAPNIK_DISABLE_WARNING(-Wunused-local-typedefs)
    #define MAPNIK_DISABLE_WARNING_SHADOW                  MAPNIK_DISABLE_WARNING(-Wshadow)
    #define MAPNIK_DISABLE_WARNING_CPP11_NARROWING         MAPNIK_DISABLE_WARNING(-Wc++11-narrowing)
    #define MAPNIK_DISABLE_WARNING_SIGN_CONVERSION         MAPNIK_DISABLE_WARNING(-Wsign-conversion)
    #define MAPNIK_DISABLE_WARNING_SIGN_COMPARE            MAPNIK_DISABLE_WARNING(-Wsign-compare)
    #define MAPNIK_DISABLE_WARNING_CONVERSION              MAPNIK_DISABLE_WARNING(-Wconversion)
    #define MAPNIK_DISABLE_WARNING_CPP_98_COMPAT_PEDANTIC  MAPNIK_DISABLE_WARNING(-Wc++98-compat-pedantic)
    #define MAPNIK_DISABLE_WARNING_DISABLE_MACRO_EXPANSION MAPNIK_DISABLE_WARNING(-Wdisabled-macro-expansion)
    #define MAPNIK_DISABLE_WARNING_OLD_STYLE_CAST          MAPNIK_DISABLE_WARNING(-Wold-style-cast)
    #define MAPNIK_DISABLE_WARNING_DOCUMENTATION           MAPNIK_DISABLE_WARNING(-Wdocumentation)
    #define MAPNIK_DISABLE_WARNING_DOCUMENTATION_UNKNOWN_COMMAND MAPNIK_DISABLE_WARNING(-Wdocumentation-unknown-command)
    #define MAPNIK_DISABLE_WARNING_UNDEF                   MAPNIK_DISABLE_WARNING(-Wundef)
    #define MAPNIK_DISABLE_WARNING_DEPRECATED              MAPNIK_DISABLE_WARNING(-Wdeprecated)
    #define MAPNIK_DISABLE_WARNING_PADDED                  MAPNIK_DISABLE_WARNING(-Wpadded)
    #define MAPNIK_DISABLE_WARNING_CPP_98_COMPAT           MAPNIK_DISABLE_WARNING(-Wc++98-compat)
    #define MAPNIK_DISABLE_WARNING_RESERVED_ID_MACRO       MAPNIK_DISABLE_WARNING(-Wreserved-id-macro)
    #define MAPNIK_DISABLE_WARNING_WEAK_VTABLE             MAPNIK_DISABLE_WARNING(-Wweak-vtables)
    #define MAPNIK_DISABLE_WARNING_EXTRA_SEMI              MAPNIK_DISABLE_WARNING(-Wextra-semi)
    #define MAPNIK_DISABLE_WARNING_GLOBAL_CONSTRUCTORS     MAPNIK_DISABLE_WARNING(-Wglobal-constructors)
    #define MAPNIK_DISABLE_WARNING_HEADER_HYGIENE          MAPNIK_DISABLE_WARNING(-Wheader-hygiene)
    #define MAPNIK_DISABLE_WARNING_EXIT_TIME_DESTRUCTORS   MAPNIK_DISABLE_WARNING(-Wexit-time-destructors)
    #define MAPNIK_DISABLE_WARNING_SWITCH_ENUM             MAPNIK_DISABLE_WARNING(-Wswitch-enum)
    #define MAPNIK_DISABLE_WARNING_MISSING_NORETURN        MAPNIK_DISABLE_WARNING(-Wmissing-noreturn)
    #define MAPNIK_DISABLE_WARNING_COVERED_SWITCH_DEFAULT  MAPNIK_DISABLE_WARNING(-Wcovered-switch-default)
    #define MAPNIK_DISABLE_WARNING_FLOAT_EQUAL             MAPNIK_DISABLE_WARNING(-Wfloat-equal)
    #define MAPNIK_DISABLE_LONG_LONG                       MAPNIK_DISABLE_WARNING(-Wlong-long)
    #define MAPNIK_DISABLE_UNDEFINED_VAR_TEMPLATE          MAPNIK_DISABLE_WARNING(-Wundefined-var-template)
    #define MAPNIK_DISABLE_UNUSED_VARIABLE                 MAPNIK_DISABLE_WARNING(-Wunused-variable)
    #define MAPNIK_DISABLE_MISMATCHED_TAGS                 MAPNIK_DISABLE_WARNING(-Wmismatched-tags)
#else
    #define MAPNIK_DISABLE_WARNING_PUSH
    #define MAPNIK_DISABLE_WARNING_POP
    // add all of the above warnings here (will be used if unknown compiler)
    #define MAPNIK_DISABLE_WARNING_UNKNOWN_PRAGMAS         
    #define MAPNIK_DISABLE_WARNING_PRAGMAS                 
    #define MAPNIK_DISABLE_WARNING_PRAGMA_MESSAGES         
    #define MAPNIK_DISABLE_WARNING_UNSEQUENCED             
    #define MAPNIK_DISABLE_WARNING_UNUSED_FUNCTION         
    #define MAPNIK_DISABLE_WARNING_UNUSED_PARAMETER        
    #define MAPNIK_DISABLE_WARNING_REDECLARED_CLASS_MEMBER 
    #define MAPNIK_DISABLE_WARNING_UNUSED_LOCAL_TYPEDEF    
    #define MAPNIK_DISABLE_WARNING_UNUSED_LOCAL_TYPEDEFS   
    #define MAPNIK_DISABLE_WARNING_SHADOW                  
    #define MAPNIK_DISABLE_WARNING_CPP11_NARROWING         
    #define MAPNIK_DISABLE_WARNING_SIGN_CONVERSION         
    #define MAPNIK_DISABLE_WARNING_SIGN_COMPARE            
    #define MAPNIK_DISABLE_WARNING_CONVERSION              
    #define MAPNIK_DISABLE_WARNING_CPP_98_COMPAT_PEDANTIC  
    #define MAPNIK_DISABLE_WARNING_DISABLE_MACRO_EXPANSION 
    #define MAPNIK_DISABLE_WARNING_OLD_STYLE_CAST          
    #define MAPNIK_DISABLE_WARNING_DOCUMENTATION           
    #define MAPNIK_DISABLE_WARNING_DOCUMENTATION_UNKNOWN_COMMAND
    #define MAPNIK_DISABLE_WARNING_UNDEF                  
    #define MAPNIK_DISABLE_WARNING_DEPRECATED             
    #define MAPNIK_DISABLE_WARNING_PADDED                 
    #define MAPNIK_DISABLE_WARNING_CPP_98_COMPAT          
    #define MAPNIK_DISABLE_WARNING_RESERVED_ID_MACRO      
    #define MAPNIK_DISABLE_WARNING_WEAK_VTABLE            
    #define MAPNIK_DISABLE_WARNING_EXTRA_SEMI             
    #define MAPNIK_DISABLE_WARNING_GLOBAL_CONSTRUCTORS    
    #define MAPNIK_DISABLE_WARNING_HEADER_HYGIENE         
    #define MAPNIK_DISABLE_WARNING_EXIT_TIME_DESTRUCTORS  
    #define MAPNIK_DISABLE_WARNING_SWITCH_ENUM            
    #define MAPNIK_DISABLE_WARNING_MISSING_NORETURN       
    #define MAPNIK_DISABLE_WARNING_COVERED_SWITCH_DEFAULT 
    #define MAPNIK_DISABLE_WARNING_FLOAT_EQUAL   
    #define MAPNIK_DISABLE_LONG_LONG    
    #define MAPNIK_DISABLE_UNDEFINED_VAR_TEMPLATE     
    #define MAPNIK_DISABLE_UNUSED_VARIABLE
    #define MAPNIK_DISABLE_MISMATCHED_TAGS
#endif
// clang-format on
#endif
