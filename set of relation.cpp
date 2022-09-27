#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <algorithm>
#include <map>
using namespace std;




int main()
{
	
	
char homeGreeting []= //This is the greeting interface
	
	"	  _____                                 _    _                      __ "
	"	 |  __ \\                               | |  (_)                    / _|	"
	"	 | |__) |_ __  ___   _ __    ___  _ __ | |_  _   ___  ___    ___  | |_ 	"
	"	 |  ___/| '__|/ _ \\ | '_ \\  / _ \\| '__|| __|| | / _ \\/ __|  / _ \\ |  _|	"
	"	 | |    | |  | (_) || |_) ||  __/| |   | |_ | ||  __/\\__ \\ | (_) || |  	"
	"	 |_|    |_| __\\___/ | .__/  \\___||_|    \\__||_| \\___||___/  \\___/ |_|  	"
	"          |  __ \\      | |  | |  | |  (_)                             		"
	"          | |__) |  _  | |  |_|_ | |_  _   ___   _ __                		" 
	"          |  _  / / _ \\| | / _` || __|| | / _ \\ | '_ \\                		"
	"          | | \\ \\|  __/| || (_| || |_ | || (_) || | | |               		"
	"          |_|  \\_\\\\___||_| \\__,_| \\__||_| \\___/ |_| |_|               		";
     
/*	int songChoice = 0; 

	cout << "1. Rivers in the desert";
	cout << "\n2. Pokemon Fire Red Route 1";
	cout << "\n3. Elevator music"; 
	cout << "\n4. Last surprise";
	cout << "\n5. No music";
	cout << "\n\n*WARNING VOLUME MAY VARY"   ;                                                             
    cout << "\nPlease choose a song to play during the usage of the project : ";
    cin >> songChoice;
    
    if (songChoice == 1) //Used to choose the song that the user wants
    {
    	string songPlay = "open rivers.mp3 type mpegvideo alias song";
    	mciSendString(songPlay.c_str(), NULL, 0, 0);
    	mciSendString("play rivers repeat", NULL, 0, 0);
	}
	else if (songChoice == 2)
	{
		string songFile = "open route.mp3 type mpegvideo alias song"; 
    	mciSendString(songFile.c_str(), NULL, 0, 0);
    	mciSendString("play route repeat", NULL, 0, 0);
	}
	else if (songChoice == 3)
	{
		string songFile = "open elevator.mp3 type mpegvideo alias song"; 
    	mciSendString(songFile.c_str(), NULL, 0, 0);
    	mciSendString("play elevator repeat", NULL, 0, 0);
	}
	else if (songChoice == 4)
	{
		string songFile = "open surprise.mp3 type mpegvideo alias song"; 
    	mciSendString(songFile.c_str(), NULL, 0, 0);
    	mciSendString("play surprise repeat", NULL, 0, 0);
	}
	else
	{
	
	}*/
	
    /*for(int animation = 0; animation < strlen(homeGreeting); animation++) //This is used to animate the text of the greeting interface
    {
        Sleep(4);
        cout<<homeGreeting[animation];
    }   */    
	cout<<homeGreeting;                                                                                            
	int pairNum = 0;
	int setNum = 0;
	int transitive = -1;
	int symmetric = -1;
	int reflexive = -1;
	
	
	
	cout << "\n\nPlease enter the number of element in the Set : ";
	cin >> setNum;
	int Set[setNum];
	for (int i = 0; i < setNum; i++ )
	{
		cout << "\nPlease enter the element "<< i+1 <<" for the set : ";
		cin >> Set[i];
	}
	
	cout << "\nPlease enter the amount of pair for a relation that you have : ";
	cin >> pairNum;
	
	
	int Relation[pairNum][2];
	int transClosure[pairNum][2] = {};
	int symmClosure[pairNum][2] = {};
	int reflexClosure[pairNum][2] = {};
	
	for (int i = 0; i < pairNum; i++ ) //This loop will process the pair that the user has input in
	{
		cout << "Please enter the 1st element for pair " << i+1 << " : ";
		cin >> Relation[i][0];
		cout << "Please enter the 2nd element for pair " << i+1 << " : ";
		cin >> Relation[i][1];
		"\n";
	}
	
	
	for (int i = 0; i < pairNum; i++) //This loop is to find the transitive and tranisitive closure
	{
		for (int j = 0; j < pairNum; j++)
		{
			if (Relation [j][0] == Relation [i][1] )
			{
				bool find = false;
				for (int k = 0; k < pairNum; k++)
				{
					if( Relation [k][0] == Relation [i][0] && Relation [k][1] == Relation [j][1])
					{
						find = true;
						break;
					}
				}
				if(!find)
				{
					transitive++;
					transClosure[transitive][0] = Relation [i][0];
					transClosure[transitive][1] = Relation [j][1];	
								
				}
			}
		}
	}
	
	for (int i = 0; i < setNum; i++) //This loop is to find the reflexive and reflexive closure
	{
		bool find = false;
		for (int j = 0; j < pairNum; j++)
		{
			if( Relation [j][0] ==  Set[i] && Relation [j][1] == Set[i])
			{
				find = true;
				break;
			}
		}
		if (!find)
		{	
			reflexive++;
			reflexClosure[reflexive][0] = Set[i];
			reflexClosure[reflexive][1] = Set[i];	
		}
	}
	
	for (int i = 0; i < pairNum; i++) //This loop is to find the symmetric and symmetric closure
	{
		bool find = false;
		for (int j = 0; j < pairNum; j++)
		{
			if( Relation [j][0] ==  Relation[i][1] && Relation [j][1] == Relation[i][0])
			{
				find = true;
				break;
			}
		}
		if (!find)
		{	
			symmetric++;
			symmClosure[symmetric][0] = Relation[i][1];
			symmClosure[symmetric][1] = Relation[i][0];	
		}
	}
	
	
	if(transitive == -1) //This processes the output for transitive
	{
		cout<< "\nThe relation is transitive\n\n";
	} 
	else 
	{
		cout<< "\nThe relation is not transitive\n";
		cout<< "The  transitive closure is :" ;
		for(int i = 0; i <= transitive ; i++)
		{
			cout<<"(" <<transClosure[i][0]<<',' << transClosure[i][1] << ")";
		}
		cout<< "\n\n";
	}

	
	if(symmetric == -1)//This processes the output for symmetric
	{
		cout<< "The relation is symmetric\n\n";
	} 
	else 
	{
		cout<< "The relation is not symmetric\n";
		cout<< "The  symmetric closure is :" ;
		for(int i = 0; i <= symmetric ; i++)
		{
			cout<<"(" <<symmClosure[i][0]<<',' << symmClosure[i][1] << ")";
		}
		cout<< "\n\n";
	}
	
	if(reflexive == -1)//This processes the output for reflexive
	{
		cout<< "The relation is reflexive\n";
	} 
	else 
	{
		cout<< "The relation is not reflexive\n";
		cout<< "The reflexive closure is :" ;
		for(int i = 0; i <= reflexive ; i++)
		{
			cout<<"(" <<reflexClosure[i][0]<<',' << reflexClosure[i][1] << ")";
		}
	}
	
}	







