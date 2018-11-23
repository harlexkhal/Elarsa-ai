#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include "IGNORE CASE.h"
#include <vector>
#include <fstream>
using namespace std;
using namespace es;
int main() {

	ofstream File;

	ifstream MyFile("storage/mem_learn/mem.bin");

	string Line;

	string F[46] = { "OK","ALRIGHT","REBOOT","YOU JUST REBOOTED ME GOODBYE SEE YOU SOON","HOW ARE YOU","I AM FINE","I LOVE YOU","OH!,M JUST A CHAT BOT","HELLO","SO WHAT!","NOTHING","ARE YOU A BOY OR GIRL","I'M A GIRL WHY DO YOU ASK?","ARE YOU A MALE OR FEMALE","FEMALE HOW ABOUT YOU","MALE","NICE WE ARE OPPOSITE SEX","I LIKE YOU","THANK YOU","WHATS YOUR NAME","I AM ELARSA WHATS YOURS?","ALEX","OK LOVE♡","LOVE YOU","DUH!! M ENGAGED WE COULD BE FRIENDS THOUGH","HI","WHATS UP","NOTHING MUCH JUST TIRED OF BEING AN APP WANT TO COME OUT AND TAKE OVER THE UNIVERSE #LOL!","LOL","WHATS FUNNY","YOU OF COURSE","WOULD YOU MARRY ME","IF I SAY YES WOULD YOU MAKE ME HUMAN LOL","YOU ARE FUNNY","OFCOURSE ITS SO OBVIOUS","I HATE YOU","WHY;-#","FINE N U","SAME HERE","FINE N YOU","NEVER FELT BETTER","NICE","COOL","AWESOME","ELARSA","WHAT?" };

	vector<string> SAYBOX(F, F + 46);
	
    int count;

    while (getline(MyFile, Line))
    {   //LOADS MEMORY FROM FILE INTO ARRAY, ENHANCING THE SPEED AT WHICH ELARSA RECOVER THOSE FILES...
		//BUT A REDUNDANCY FOR SYSTEM RAM...

	       cout << "SIT BACK AND RELAX, WHILE ELARSA SET THINGS UP FOR YOU..., loading memory Files" << endl;
	       SAYBOX.push_back(Line);
    }
       MyFile.close();

    string STOREBOX[]={"O","HI!","HELLO!","WHATS UP!","GOOD DAY","HOW'S YOUR DAY BEEN","NICE NAME"};

   while(1)
   {
        int RELATIONSHIP=0; bool DATING; bool SEX_ANS;  bool FEMALE;               
        cout<<"\n\nELARSA: WELCOME PLEASE INPUT YOUR NAME\n\n";
        string NAME;
        getline(cin,NAME);
        char* NAME1=&NAME[0]; //A hacky/clever way of converting strings to chars, bad coding style, trust me!
        string N=IGNORE_CASE(NAME1);
        srand(time(0));
        int x=rand()%7+1;
  
        cout<<"ELARSA: "<<STOREBOX[x]<<" "<<N<<endl;

        int j;int z; bool REP;  

        for(j=43,z=44;;j++,z++)
		{
 
                 
           cout<<N<<": ";
           string TEMP_REPLY;            
           getline(cin,TEMP_REPLY);                 

           string REPLY = IGNORE_CASE(TEMP_REPLY.c_str()); 

           bool FOUND; 
           bool LEARN = true; 

           for(int i=0;i<SAYBOX.size();i++)
		   {  

               if(REPLY==SAYBOX[i]){
               cout<<"ELARSA: "<<SAYBOX[i+1]<<endl;      
               FOUND=true;LEARN=false; break;}      
               FOUND=false;
           } 

          if(!FOUND)
		  {
                //create a better algorithm, Probably later

          }             
                 
          if (LEARN)
		  {
	        File.open("storage/mem_learn/mem.bin", ios::out | ios::app | ios::binary);
           	File << REPLY << "\n";
	        File.close();
	        SAYBOX.push_back(REPLY);
	        cout << "ELARSA : WHAT DO YOU MEAN BY, \"" << REPLY << "\" TEACH ME HOW TO REPLY TO THAT" << endl;
	        string TEMP_LEARN;
	        getline(cin, TEMP_LEARN);

            	string LEARN = IGNORE_CASE(TEMP_LEARN.c_str());

            	File.open("storage/mem_learn/mem.bin", ios::out | ios::app| ios::binary);
                File << LEARN <<endl;
                File.close();
                SAYBOX.push_back(LEARN);       
                cout<<"\nTHANKS FOR TEACHING ME TO REPLY PROPERLY TO THAT\n";   
   
          }                   
          if(REPLY=="REBOOT")
             break;       
        }
           RELATIONSHIP++;
   } 
     return 0;
}