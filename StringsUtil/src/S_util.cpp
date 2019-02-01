#include "S_util.h"

namespace Es {

	S_util::S_util()
	{
	}


	S_util::~S_util()
	{
	}

	S_util::S_util(const char* string)
		: c_string(string) {}

	S_util::S_util(std::string& normstring)
	{
		c_string = normstring.c_str();
	}

	std::string S_util::Ignorecase_Lower()
	{

		char CAPS_ALPHABETS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\"+!@#$/^&*()-':;,?) ";

		char  SMALL_ALPHABETS[] = "abcdefghijklmnopqrstuvwxyz1234567890\"+!@#$/^&*()-':;,?) ";



		char SAVE_REPLY[100];

		int i = 0;

		while (i <= strlen(this->c_string))
		{
			for (int j = 0; j < 57; j++)
			{

				if (this->c_string[i] == CAPS_ALPHABETS[j] || this->c_string[i] == SMALL_ALPHABETS[j])
				{
					SAVE_REPLY[i] = SMALL_ALPHABETS[j];
					break;
				}
			}

			i++;
		}

		this->s_stringLower = SAVE_REPLY;


		return (this->s_stringLower);
	}


	std::string S_util::Ignorcase_Upper()
	{


		char CAPS_ALPHABETS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\"+!@#$/^&*()-':;,?) ";

		char  SMALL_ALPHABETS[] = "abcdefghijklmnopqrstuvwxyz1234567890\"+!@#$/^&*()-':;,?) ";



		char SAVE_REPLY[100];

		int i = 0;
		while (i <= strlen(this->c_string))
		{
			for (int j = 0; j < 57; j++)
			{

				if (this->c_string[i] == CAPS_ALPHABETS[j] || this->c_string[i] == SMALL_ALPHABETS[j])
				{
					SAVE_REPLY[i] = CAPS_ALPHABETS[j];
					break;
				}
			}

			i++;
		}

		this->s_stringUpper = SAVE_REPLY;

		return (this->s_stringUpper);
	}

	void S_util::Set_string(const char * string)
	{
		c_string = string;
	}

	void S_util::Set_string(std::string& string)
	{
		c_string = string.c_str();
	}
}