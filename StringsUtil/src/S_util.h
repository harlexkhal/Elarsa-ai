#pragma once

#ifdef API_SUPPORT_DLL
#define ES_API_DLL __declspec(dllexport)

#else
#define ES_API_DLL __declspec(dllimport)

#endif

#ifdef API_SUPPORT_DLL

#include <iostream>
#include <string>

#endif
namespace Es {
	class ES_API_DLL S_util
	{
	public:
		S_util();
		~S_util();
		S_util(const char* string);
		S_util(std::string& normstring);

		std::string Ignorecase_Lower();
		std::string Ignorcase_Upper();
		void Set_string(const char* string);
		void Set_string(std::string& string);

	private:
		const char* c_string;
		std::string s_stringLower;
		std::string s_stringUpper;
		//std::string Encrypted;
	};
}
