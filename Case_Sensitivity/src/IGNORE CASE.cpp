#include <iostream>
#include <string>
#include "IGNORE CASE.h"


namespace es{
  std::string IGNORE_CASE(const char* arrREPLY)
  {
    char CAPS_ALPHABETS[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\"+!@#$/^&*()-':;,?) ";

    char  SMALL_ALPHABETS[]="abcdefghijklmnopqrstuvwxyz1234567890\"+!@#$/^&*()-':;,?) ";
   


     char SAVE_REPLY[100];

     int i=0;

   while(i<=strlen(arrREPLY))
   {  
	   for(int j=0;j<57;j++)
	   {

            if(arrREPLY[i]==CAPS_ALPHABETS[j]||arrREPLY[i]==SMALL_ALPHABETS[j])
	        {
                  SAVE_REPLY[i]=CAPS_ALPHABETS[j];
                    break;
            }
       }

      i++;
   }

    const char* SUCCESS=SAVE_REPLY;


     return SUCCESS;
  }
}
