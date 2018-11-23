#ifndef IGNORE_CASE_H
#define    IGNORE_CASE_H
#include <string>

//DYNAMICALLY LINKED WITH ELARSA

#ifdef API_SUPPORT_DLL
#define ES_API_DLL __declspec(dllexport)
#else
#define ES_API_DLL __declspec(dllexport)
#endif

namespace es
{

    ES_API_DLL std::string IGNORE_CASE(const char* arrREPLY);    
}



#endif