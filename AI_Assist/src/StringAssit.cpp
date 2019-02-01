#include "StringAssit.h"

enum Search
{
	Found = 0,
	Not_Found=-1
};

enum StringNumType
{
	Odd_Num_String = 1,
    Even_Num_String = 0
};

static int minimum = 3;

namespace assist {
	void IntelliSearch(const char* string, int stringChunks, bool EvenOddNumString, std::vector<std::string>& Data, std::vector<std::string>::iterator& it, bool& strFound, vec_vec_it& it_array, int minimum, bool& Learn)
	{
		
		if (stringChunks < minimum)
			return;

		int i = 0;
		int z = 0;
		char s_TempStorage[11] = "";
		char b_TempStorage[11] = "";

		while (true)
		{
			int c = i;
			for (int j = 0; j < stringChunks; j++, c++)
			{
				s_TempStorage[j] = string[c];
			}

			int j = 0;
			for (int x = (strlen(string) - z) - (stringChunks); j < stringChunks; j++, x++)
			{
				b_TempStorage[j] = string[x];
			}

			if (stringChunks == 3)
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2])
					break;
			}
			
			if (stringChunks == 4 )
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3])
					break;
			}

			if (stringChunks == 5 )
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3] && b_TempStorage[4] == s_TempStorage[4])
					break;
			}

			if (stringChunks == 6 )
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3] && b_TempStorage[4] == s_TempStorage[4] && b_TempStorage[5] == s_TempStorage[5])
					break;
			}

			if (stringChunks == 7 )
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3] && b_TempStorage[4] == s_TempStorage[4] && b_TempStorage[5] == s_TempStorage[5] && b_TempStorage[6] == s_TempStorage[6])
					break;
			}

			if (stringChunks == 8 )
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3] && b_TempStorage[4] == s_TempStorage[4] && b_TempStorage[5] == s_TempStorage[5] && b_TempStorage[6] == s_TempStorage[6] && b_TempStorage[7] == s_TempStorage[7])
					break;
			}

			if (stringChunks == 9 )
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3] && b_TempStorage[4] == s_TempStorage[4] && b_TempStorage[5] == s_TempStorage[5] && b_TempStorage[6] == s_TempStorage[6] && b_TempStorage[7] == s_TempStorage[7] && b_TempStorage[8] == s_TempStorage[8])
					break;
			}

			if (stringChunks == 10)
			{
				if (b_TempStorage[0] == s_TempStorage[0] && b_TempStorage[1] == s_TempStorage[1] && b_TempStorage[2] == s_TempStorage[2] && b_TempStorage[3] == s_TempStorage[3] && b_TempStorage[4] == s_TempStorage[4] && b_TempStorage[5] == s_TempStorage[5] && b_TempStorage[6] == s_TempStorage[6] && b_TempStorage[7] == s_TempStorage[7] && b_TempStorage[8] == s_TempStorage[8] && b_TempStorage[9] == s_TempStorage[9])
					break;
			}
			
			int m_Search_Info = (*it).find(s_TempStorage);
			int z_Search_Info = (*it).find(b_TempStorage);
			if (m_Search_Info >= Found && z_Search_Info >= Found)
			{	
				if (strlen(string) < 0x0000000a) 
				{
					std::cout<<"ELARSA: "<< (*++it) << std::endl;
					strFound = true; Learn = false;
					return;
				}

				it_array.push_back(it);
					strFound = true;
					return;	
			}

			i++;
			z++;
		}
		stringChunks -= 2;
		IntelliSearch(string, stringChunks, EvenOddNumString, Data, it, strFound, it_array, minimum, Learn);
	}


	void s_SearchAssit(const char* string, std::vector<std::string>& Data, bool& strFound, bool& Learn)
	{
		std::vector<std::string>::iterator it;
		it = Data.begin();

		vec_vec_it iterator_array;
		int Recursive_Depth = 10;
		int StringLength = strlen(string);
		bool string_EvenOddCheck = (StringLength % 2);
		
		
		if (string_EvenOddCheck == Odd_Num_String)
			Recursive_Depth = 9;

		if (strlen(string) < 0x0000000a && string_EvenOddCheck == Odd_Num_String)
			Recursive_Depth = 5;
		
		if (strlen(string) < 0x0000000a && string_EvenOddCheck == Even_Num_String)
			Recursive_Depth = 6;

		for (; it != Data.end(); ++it)
		{
			IntelliSearch(string, Recursive_Depth, string_EvenOddCheck, Data, it, strFound, iterator_array, minimum, Learn);
			
		 if (strlen(string) < 0x0000000a && strFound)
				break;  
		}

		minimum ++; 

		//Not comfortable with how this msg Filter works, Adjustment would be made later************************
		// need to figure out what to do with the possible Reply Filter in order to be exact on what a person said to Elarsa (**To be FIXED**)
		int size_of_iterator_array = iterator_array.size();
		if (strFound)
		{
		    vec_vec_it_it iterator_array_it = iterator_array.begin();
			
			if (size_of_iterator_array > 1)
			{
				std::vector<std::string> arrdata;

				for (; iterator_array_it != iterator_array.end(); ++iterator_array_it)
				{
					arrdata.push_back((*(*iterator_array_it)));
				}

				s_SearchAssit(string, arrdata, strFound, Learn);
			}

			if(size_of_iterator_array == 1)
			{
				it = (*iterator_array_it);
				std::cout<<"ELARSA: " << (*++it) << std::endl;
				Learn = false;
				return;
			}
		}

		else
		{
			return;
		}
	}
}