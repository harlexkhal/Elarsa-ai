#pragma once

#ifdef AI_ASSIT

#define ES_API_DLL __declspec(dllexport)

#else
#define ES_API_DLL __declspec(dllimport)

#endif


#ifdef AI_ASSIT

#include <iostream>
#include <sstream>
#include <string>
#include  <vector>

#endif

namespace assist
{
   ES_API_DLL void s_SearchAssit(const char* string, std::vector<std::string>& Data, bool& strFound, bool& Learn);

}

typedef   std::vector<std::vector<std::string>::iterator>::iterator vec_vec_it_it;
typedef    std::vector<std::vector<std::string>::iterator> vec_vec_it;