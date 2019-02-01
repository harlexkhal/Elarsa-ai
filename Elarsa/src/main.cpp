#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include "../../AI_Assist/src/StringAssit.h"
#include "../../StringsUtil/src/S_util.h"


int main()
{  
	std::ofstream File;
	std::ifstream MyFile("msgstore.bin");
	std::string Line;
	Es::S_util msg_util;
	std::vector<std::string> MsgStore;
	std::cout << "loading memory Files..." << std::endl;

	while (std::getline(MyFile, Line))
	{
		MsgStore.push_back(Line);
	}
	MyFile.close();

	std::string Start_Ups[] = { "O","HI!","HELLO!","WHATS UP!","GOOD DAY","HOW'S YOUR DAY BEEN","NICE NAME" };

	bool Running = true;
	while (Running)
	{
		std::cout << "\nELARSA: Hello, Input Your Name:\n\n";
		std::string NAME;
		std::getline(std::cin, NAME);
		char* NAME1 = &NAME[0];
		msg_util.Set_string(NAME1);
		std::string N = msg_util.Ignorcase_Upper();
		std::srand(time(0));
		int x = rand() % 7 + 1;

		std::cout << "ELARSA: " << Start_Ups[x] << " " << N << std::endl;

		while (true)
		{     //TEMP_REPLY CHANGED TO Human_Reply;
			std::cout << N << ": ";
			std::string Human_Reply;
			std::getline(std::cin, Human_Reply);
			msg_util.Set_string(Human_Reply);
			Human_Reply = msg_util.Ignorcase_Upper();

			if (Human_Reply == "REBOOT")
				break;

			bool FOUND = false;
			bool LEARN = true;

			for (int i = 0; i < MsgStore.size(); i++)
			{
				if (Human_Reply == MsgStore[i])
				{
					std::cout << "ELARSA: " << MsgStore[i + 1] << std::endl;
					FOUND = true; LEARN = false; break;
				}
				FOUND = false;
			}

			if (!FOUND)
			{
				//Using Ai_Assit.dll to try Understand the Text and Reply back appriopriately
				assist::s_SearchAssit(Human_Reply.c_str(), MsgStore, FOUND, LEARN);
			}

			if (LEARN)
			{
				File.open("msgstore.bin", std::ios::out | std::ios::app | std::ios::binary);
				File << Human_Reply << "\n";
				File.close();
				MsgStore.push_back(Human_Reply);
				std::cout << "ELARSA : WHAT DO YOU MEAN BY, \"" << Human_Reply << "\" HOW WOULD YOU LIKE ME TO REPLY TO THAT" << std::endl;
				std::string Learn_Reply;
				std::getline(std::cin, Learn_Reply);
				msg_util.Set_string(Learn_Reply);
				Learn_Reply = msg_util.Ignorcase_Upper();

				File.open("msgstore.bin", std::ios::out | std::ios::app | std::ios::binary);
				File << Learn_Reply << std::endl;
				File.close();
				MsgStore.push_back(Learn_Reply);
				std::cout << "\nTHANKS FOR TEACHING ME TO REPLY PROPERLY TO THAT\n";
			}
			
		}
	}

}