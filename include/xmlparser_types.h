#ifndef XMLPARSER_TYPES_H
#define XMLPARSER_TYPES_H

#ifdef _WIN32
        #ifdef XMLPARSER_DLL_EXPORT
            #define XML_API __declspec(dllexport) 
        #else    
            #define XML_API __declspec(dllimport) 
        #endif
#else
    #define XML_API
#endif

/* Define calling convention*/
#define ADDCALL __stdcall

#endif // XMLPARSER_TYPES.H