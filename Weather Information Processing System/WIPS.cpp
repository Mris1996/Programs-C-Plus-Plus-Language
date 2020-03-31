#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "WIPS.h"
#include <algorithm>
#include <ctype.h>
using namespace std;

string ** Ary = nullptr;
int CMAry[100][100];
int CCAry[100][100];
int PRESAry[100][100];
string CNAry[4];
double CCAve3;
double CCAve2;
double CCAve1;
double PRESAve3;
double PRESAve2;
double PRESAve1;
char LMHCCAve3;
char LMHCCAve2;
char LMHCCAve1;
char PRESAve3_LMH;
char PRESAve2_LMH;
char PRESAve1_LMH;
double PROB3;
double PROB2;
double PROB1;
string gridX1;
string gridX2;
string gridY1;
string gridY2;
int GridX1;
int GridX2;
int GridY1;
int GridY2;
string citylocation;
string cloudcover;
ifstream filez;
string input;
string pressure;
int BigCity[21][21];
int MidCity[21][21];
int SmallCity[21][21];
double totalCCbigcity;
double totalCCmidcity;
double totalCCsmallcity;
double totalPRESbigcity;
double totalPRESmidcity;
double totalPRESsmallcity;
double BCcount;
double MCcount;
double SCcount;




void choices(){

		cout << "------------------------------------" << endl;
		cout << "Welcome to Weather Information Processing System!" << endl << endl;
		cout << "1)		Read in and process a configuration file" << endl;
		cout << "2)		Display city map" << endl;
		cout << "3)		Display cloud coverage map (cloudiness index)" << endl;
		cout << "4)		Display cloud coverage map (LMH symbols)" << endl;
		cout << "5)		Display atmospheric pressure map (pressure index)" << endl;
		cout << "6)		Display atmospheric pressure map (LMH symbols)" << endl;
		cout << "7)		Show weather forecast summary report" << endl;
		cout << "8)		Quit" << endl << endl;

}

void MainMenu()//options menu
{
	int choice;
	do
	{
		choices();
		cout << "Please enter your choice : ";


	if(!(cin>>choice))
	{

		cerr << "Please pick a number between 1 and 8" << endl;
		cin.clear();
	   cin.ignore(8, '\n');

	}
	cout << endl;
	if (choice == 1)
	{
		Read_and_Process();
		endoffunc();
	}
	if (choice == 2)
	{

		if (citylocation == "")
		{
			cout << "PLease read in and process a configuration file" << endl << "Returning to main menu" <<endl<< endl;
			MainMenu ();
		}
		else
		{
			ProcessCM(citylocation);
			BuildArrayFunc();
			deletearraysfunc();
			endoffunc();
			MainMenu();
		}
	}
	if (choice == 3)
	{
		if (cloudcover == "")
		{
			cout << "PLease read in and process a configuration file" << endl << "Returning to main menu" <<endl<< endl;
			MainMenu ();
		}
		else
		{
			ProcessCC(cloudcover);
			BuildArrayFunc();
			deletearraysfunc();
			endoffunc();
			MainMenu();
		}
	}
	if (choice == 4)
	{
		if (cloudcover == "")
		{
			cout << "PLease read in and process a configuration file" << endl << "Returning to main menu" <<endl<< endl;
			MainMenu ();
		}
		else
		{
			ProcessCCLMH(cloudcover);
			BuildArrayFunc();
			deletearraysfunc();
			endoffunc();
			MainMenu();
		}
	}
	if (choice == 5)
	{
		if (pressure == "")
		{
			cout << "PLease read in and process a configuration file" << endl << "Returning to main menu" <<endl<< endl;
			MainMenu ();
		}
		else
		{
			ProcessPRES(pressure);
			BuildArrayFunc();
			deletearraysfunc();
			endoffunc();
			MainMenu();
		}
	}
	if (choice == 6)
	{
		if (pressure == "")
		{
			cout << "Please read in and process a configuration file" << endl << "Returning to main menu" <<endl<< endl;
			MainMenu ();
		}
		else
		{
			ProcessPRESLMH(pressure);
			BuildArrayFunc();
			deletearraysfunc();
			endoffunc();
			MainMenu();
		}
	}
	if (choice == 7)
	{
		if (citylocation == "")
		{
			cout << "Please read in and process a configuration file" << endl << "Returning to main menu" <<endl<< endl;
			MainMenu ();
		}
		else
		{
			Summary();
			endoffunc();
			MainMenu();
		}
	}
	if (choice == 8)
	{

		cout << "Good Bye" << endl;
		exit(1);
	}


	if(choice<=0||choice>=9)
	 {
cerr << "Please pick a number between 1 and 8" << endl;
MainMenu();

}

} while (choice != 8);

}



void Read_and_Process()//inputs text file and stores data into variables
{


cout<< "[Read in and process a configuration file]"<<endl;
    cout << "Please enter config filename: ";

   string filename;
   cin >> filename;

   filez.open(filename.c_str());

   if(filez.fail()){
	cerr<<" Error"<<endl;
	Read_and_Process();
}

string line;
for (int x = 0; getline (filez,line) && x < 18; x++)
{
      if (x == 2)
      {
		int GridX1int;
		int GridX2int;
        gridX1 = line.substr(15,1);
        gridX2 = line.substr(17);
		istringstream(gridX1)>>GridX1int;
		istringstream(gridX2)>>GridX2int;
		GridX1 = GridX1int +1;
		GridX2 = GridX2int+1;
        cout << "Reading in GridX_IdxRange: " << gridX1 <<"-"<<gridX2 <<"... done!" << endl;
      }
      if( x == 6)
      {
        int GridY1int;
		int GridY2int;
        gridY1 = line.substr(15,1);
        gridY2 = line.substr(17);
		istringstream(gridY1)>>GridY1int;
		istringstream(gridY2)>>GridY2int;
		GridY1 = GridY1int +1;
		GridY2 = GridY2int+1;
        cout << "Reading in GridY_IdxRange: " << gridY1 <<"-"<<gridY2<< "... done!" <<endl;
      }
      if(x==7)
      {
        cout<<endl;
        cout<<"Storing data from input file :"<<endl;
        }
      if(x == 9)
      {

        citylocation =line;
		ProcessCM(citylocation);
        cout << citylocation << "... done!"<<endl;
      }
       if(x == 13)
      {
        cloudcover =line;
		ProcessCC(cloudcover);
		ProcessCCLMH(cloudcover);
        cout << cloudcover<< "... done!"<<endl;
      }
       if(x == 17)
      {
        pressure =line;
		ProcessPRES(pressure);
		ProcessPRESLMH(pressure);
        cout << pressure<< "... done!"<<endl;
        cout<<endl;
      }
}
	CalcWeather();
	cout << "All records successfully stored. Going back to main menu ...\n" << endl;
    filez.close();
	MainMenu();
}
void Create2DAry()//initialize array
{
	Ary = new string * [GridX2];

	for (int i = 0; i < GridX2; i++)
		Ary [i] = new string [GridY2];

	for (int i = 0; i < GridX2; i++)
	{
		for (int j = 0; j < GridY2; j++)
		{
			Ary[i][j] = " ";
		}
	}
}
void BuildArrayFunc()//display array
{
	cout<<"   ";
	for(int r = 0; r < GridX2+2; r++)
	{
		cout << setw(3) << "#";
	}
	cout << endl;

	for (int i = GridY2-1; i >= 0; i--)
	{
		if (i < 10)
		{
			cout <<"  "<<i << setw(3) << "#";
		}
		else
		{
			cout << i << setw(2) << "#";
		}

		for (int j = 0; j < GridX2; j++)
		{
			cout << setw(3) << Ary [j][i];
		}
		cout << setw(3) << "#";
		cout << endl;
	}
	cout<<"   ";
	for(int r = 0; r < GridX2+2; r++)
	{
		cout << setw(3) << "#";
	}
	cout << endl;
	cout << "      ";

	for(int r = 0; r < GridX2; r++)
	{
		cout << setw(3) << r;
	}
	cout << endl;
}

void deletearraysfunc()//dellocates array
{
	if (GridY2 <= 0)
		return;
	else{
	for (int i = 0; i < GridX2; i++)
	{
		delete [] Ary [i];
	}

	delete [] Ary;

	cout << endl;
	}
}

void ProcessCM(string inputFilename)//processes the citylocation.txt and displays the results
{
	Create2DAry();

	ifstream inputfile;
    
	inputfile.open(inputFilename);
	if (!inputfile)
	{
		cout << endl;
		cerr << "Error in reading the file / File not found!" << endl << "Going back to main menu... \n" << endl;
		MainMenu ();
	}

	a1StructClass cm;




	while (inputfile >> cm.filler >> cm.cityX >> cm.filler >>cm.cityY >> cm.filler >>cm.filler >> cm.cityID >> cm.filler >> cm.cityname)
	{
		stringstream cityIDstr;
		cityIDstr << cm.cityID;
		Ary [cm.cityX][cm.cityY] = cityIDstr.str();


		CMAry [cm.cityX][cm.cityY] = cm.cityID;


			CNAry[cm.cityID] = cm.cityname;



	}


	inputfile.close();
}

void ProcessCC(string inputFilename)//processes the cloudcover.txt and displays the results
{
	Create2DAry();
	ifstream inputfile;

	inputfile.open(inputFilename);
	if (!inputfile)
	{
		cout << endl;
		cerr << "Error in reading the file / File not found!" << endl << "Going back to main menu... \n" << endl;
		MainMenu ();
	}

	a1StructClass x;

	while (inputfile >> x.filler >> x.cloudX >> x.filler >> x.cloudY >> x.filler >> x.filler >> x.cloudID)
	{


		CCAry [x.cloudX][x.cloudY] = x.cloudID;

		x.cloudID=x.cloudID/10;
		stringstream cloudstrstr;
		cloudstrstr << x.cloudID;

		Ary [x.cloudX][x.cloudY] = cloudstrstr.str();
	}

	inputfile.close();
}

void ProcessCCLMH(string inputFilename)//processes the cloudcover.txt and displays the results as either L/M/H with a simple if else method
{
	Create2DAry();

	ifstream inputfile;

	inputfile.open(inputFilename);
	if (!inputfile)
	{
		cout << endl;
		cerr << "Error in reading the file / File not found!" << endl << "Going back to main menu... \n" << endl;
		MainMenu ();
	}

	a1StructClass x;


	while (inputfile >> x.filler >> x.cloudX >> x.filler >> x.cloudY >> x.filler >> x.filler >> x.cloudIDlmh)
	{
		if (x.cloudIDlmh >= 0 && x.cloudIDlmh < 35)
		{
			x.cloudLMH = 'L';

		}
		if (x.cloudIDlmh >= 35 && x.cloudIDlmh < 65)
		{
			x.cloudLMH = 'M';
		}
		else if(x.cloudIDlmh >= 65 && x.cloudIDlmh < 100)
		{
			x.cloudLMH = 'H';
		}

		stringstream cloudlmhstrstr;
		cloudlmhstrstr << x.cloudLMH;

		Ary [x.cloudX][x.cloudY] = cloudlmhstrstr.str();

	}

	inputfile.close();
}


void ProcessPRES(string inputFilename)//processes the pressure.txt and displays the results
{
	Create2DAry();
	ifstream inputfile;
	inputfile.open(inputFilename);
	if (!inputfile)
	{
		cout << endl;
		cerr << "Error in opening file : " << inputFilename << endl << "Going back to main menu... \n" << endl;
		MainMenu ();
	}

	a1StructClass x;

	while (inputfile >> x.filler >> x.presX >> x.filler >> x.presY >> x.filler >> x.filler >> x.presID)
	{


		PRESAry [x.presX][x.presY] = x.presID;

		x.presID = x.presID/10;

		stringstream presstrstr;
		presstrstr << x.presID;

		Ary [x.presX][x.presY] = presstrstr.str();
	}

	inputfile.close();
}
void ProcessPRESLMH(string inputFilename)//processes the pressure.txt and displays the results as either L/M/H with a simple if else method
{
	Create2DAry();
	ifstream inputfile;
	inputfile.open(inputFilename);
	if (!inputfile)
	{
		cout << endl;
		cerr << "Error in reading the file / File not found!" << endl << "Going back to main menu... \n" << endl;
		MainMenu ();
	}

	a1StructClass x;

	while (inputfile >> x.filler >> x.presX >> x.filler >> x.presY >> x.filler >> x.filler >> x.presID)
	{
		if (x.presID >= 0 && x.presID < 35)
		{
			x.presLMH = 'L';
		}
		if (x.presID >= 35 && x.presID < 65)
		{
			x.presLMH = 'M';
		}
		else if (x.presID >= 65 && x.presID < 100)
		{
			x.presLMH = 'H';
		}

		stringstream presstrstr;
		presstrstr << x.presLMH;

		Ary [x.presX][x.presY] = presstrstr.str();
	}

	inputfile.close();
}

void CalcWeather()//calculates the average cloud coverage for each city as well as average pressure for each city
{

	for (int i = 0; i < GridX2; i++)
	{
		for (int j = 0; j < GridY2; j++)
		{
			if (CMAry[i][j] == 3)
			{
				BigCity[i][j] = 3;
				BigCity[i-1][j] = 3;
				BigCity[i-1][j+1] = 3;
				BigCity[i][j+1] = 3;
				BigCity[i+1][j+1] = 3;
				BigCity[i+1][j] = 3;
				BigCity[i+1][j-1] = 3;
				BigCity[i][j-1] = 3;
				BigCity[i-1][j-1] = 3;
			}
			if (CMAry[i][j] == 2)
			{
				MidCity[i][j] = 2;
				MidCity[i-1][j] = 2;
				MidCity[i-1][j+1] = 2;
				MidCity[i][j+1] = 2;
				MidCity[i+1][j+1] = 2;
				MidCity[i+1][j] = 2;
				MidCity[i+1][j-1] = 2;
				MidCity[i][j-1] = 2;
				MidCity[i-1][j-1] = 2;
			}
			else if (CMAry[i][j] == 1)
			{
				SmallCity[i][j] = 1;
				SmallCity[i-1][j] = 1;
				SmallCity[i-1][j+1] = 1;
				SmallCity[i][j+1] = 1;
				SmallCity[i+1][j+1] = 1;
				SmallCity[i+1][j] = 1;
				SmallCity[i+1][j-1] = 1;
				SmallCity[i][j-1] = 1;
				SmallCity[i-1][j-1] = 1;

			}
		}
	}


	for (int i = 0; i < GridX2; i++)
	{
		for (int j = 0; j < GridY2; j++)
		{

			if (BigCity [i][j] == 3)
			{
				totalCCbigcity = totalCCbigcity + CCAry[i][j];	// using cloud cover values
				BCcount++;
			}
			if (MidCity [i][j] == 2)
			{
				totalCCmidcity = totalCCmidcity + CCAry[i][j];
				MCcount++;
			}
			else if (SmallCity [i][j] == 1)
			{


				totalCCsmallcity = totalCCsmallcity + CCAry[i][j];
				SCcount++;

			}


		}
	}

	CCAve3 = totalCCbigcity / BCcount;
	CCAve2 = totalCCmidcity / MCcount;
	CCAve1 = totalCCsmallcity / SCcount;


	if (CCAve3 >= 0 && CCAve3 < 35)
	{
		LMHCCAve3 = 'L';
	}
	if (CCAve3 >= 35 && CCAve3 < 65)
	{
		LMHCCAve3 = 'M';
	}
	else if (CCAve3 >= 65 && CCAve3 < 10)
	{
		LMHCCAve3 = 'H';
	}


	if (CCAve2 >= 0 && CCAve2 < 35)
	{
		LMHCCAve2 = 'L';
	}
	if (CCAve2 >= 35 && CCAve2 < 65)
	{
		LMHCCAve2 = 'M';
	}
	else if (CCAve2 >= 65 && CCAve2 < 10)
	{
		LMHCCAve2 = 'H';
	}


	if (CCAve1 >= 0 && CCAve1 < 35)
	{
		LMHCCAve1 = 'L';
	}
	if (CCAve1 >= 35 && CCAve1 < 65)
	{
		LMHCCAve1 = 'M';
	}
	else if (CCAve1 >= 65 && CCAve1 < 10)
	{
		LMHCCAve1 = 'H';
	}



	for (int i = 0; i < GridX2; i++)
	{
		for (int j = 0; j < GridY2; j++)
		{
			if (BigCity [i][j] == 3)
			{
				totalPRESbigcity = totalPRESbigcity + PRESAry[i][j];
			}
			if (MidCity [i][j] == 2)
			{
				totalPRESmidcity = totalPRESmidcity + PRESAry[i][j];
			}
			else if (SmallCity [i][j] == 1)
			{
				totalPRESsmallcity = totalPRESsmallcity + PRESAry[i][j];
			}

		}
	}

	PRESAve3 = totalPRESbigcity / BCcount;
	PRESAve2 = totalPRESmidcity / MCcount;
	PRESAve1 = totalPRESsmallcity /SCcount;



	if (PRESAve3 >= 0 && PRESAve3 < 35)
	{
		PRESAve3_LMH = 'L';
	}
	if (PRESAve3 >= 35 && PRESAve3 < 65)
	{
		PRESAve3_LMH = 'M';
	}
	else if (PRESAve3 >= 65 && PRESAve3 < 100)
	{
		PRESAve3_LMH = 'H';
	}


	if (PRESAve2 >= 0 && PRESAve2 < 35)
	{
		PRESAve2_LMH = 'L';
	}
	if (PRESAve2 >= 35 && PRESAve2 < 65)
	{
		PRESAve2_LMH = 'M';
	}
	else if (PRESAve2 >= 65 && PRESAve2 < 100)
	{
		PRESAve2_LMH = 'H';
	}


	if (PRESAve1 >= 0 && PRESAve1 < 35)
	{
		PRESAve1_LMH = 'L';
	}
	if (PRESAve1 >= 35 && PRESAve1 < 65)
	{
		PRESAve1_LMH = 'M';
	}
	else if (PRESAve1 >= 65 && PRESAve1 < 100)
	{
		PRESAve1_LMH = 'H';
	}


	if (PRESAve3_LMH == 'L' && LMHCCAve3 == 'H')
	{
		PROB3 = 90.00;
	}
	if (PRESAve3_LMH == 'L' && LMHCCAve3 == 'M')
	{
		PROB3 = 80.00;
	}
	if (PRESAve3_LMH == 'L' && LMHCCAve3 == 'L')
	{
		PROB3 = 70.00;
	}
	if (PRESAve3_LMH == 'M' && LMHCCAve3 == 'H')
	{
		PROB3 = 60.00;
	}
	if (PRESAve3_LMH == 'M' && LMHCCAve3 == 'M')
	{
		PROB3 = 50.00;
	}
	if (PRESAve3_LMH == 'M' && LMHCCAve3 == 'L')
	{
		PROB3 = 40.00;
	}
	if (PRESAve3_LMH == 'H' && LMHCCAve3 == 'H')
	{
		PROB3 = 30.00;
	}
	if (PRESAve3_LMH == 'H' && LMHCCAve3 == 'M')
	{
		PROB3 = 20.00;
	}
	else if(PRESAve3_LMH == 'H' && LMHCCAve3 == 'L')
	{
		PROB3 = 10.00;
	}


	if (PRESAve2_LMH == 'L' && LMHCCAve2 == 'H')
	{
		PROB2 = 90.00;
	}
	if (PRESAve2_LMH == 'L' && LMHCCAve2 == 'M')
	{
		PROB2 = 80.00;
	}
	if (PRESAve2_LMH == 'L' && LMHCCAve2 == 'L')
	{
		PROB2 = 70.00;
	}
	if (PRESAve2_LMH == 'M' && LMHCCAve2 == 'H')
	{
		PROB2 = 60.00;
	}
	if (PRESAve2_LMH == 'M' && LMHCCAve2 == 'M')
	{
		PROB2 = 50.00;
	}
	if (PRESAve2_LMH == 'M' && LMHCCAve2 == 'L')
	{
		PROB2 = 40.00;
	}
	if (PRESAve2_LMH == 'H' && LMHCCAve2 == 'H')
	{
		PROB2 = 30.00;
	}
	if (PRESAve2_LMH == 'H' && LMHCCAve2 == 'M')
	{
		PROB2 = 20.00;
	}
	else if(PRESAve2_LMH == 'H' && LMHCCAve2 == 'L')
	{
		PROB2 = 10.00;
	}


	if (PRESAve1_LMH == 'L' && LMHCCAve1 == 'H')
	{
		PROB1 = 90.00;
	}
	if (PRESAve1_LMH == 'L' && LMHCCAve1 == 'M')
	{
		PROB1 = 80.00;
	}
	if (PRESAve1_LMH == 'L' && LMHCCAve1 == 'L')
	{
		PROB1 = 70.00;
	}
	if (PRESAve1_LMH == 'M' && LMHCCAve1 == 'H')
	{
		PROB1 = 60.00;
	}
	if (PRESAve1_LMH == 'M' && LMHCCAve1 == 'M')
	{
		PROB1 = 50.00;
	}
	if (PRESAve1_LMH == 'M' && LMHCCAve1 == 'L')
	{
		PROB1 = 40.00;
	}
	if (PRESAve1_LMH == 'H' && LMHCCAve1 == 'H')
	{
		PROB1 = 30.00;
	}
	if (PRESAve1_LMH == 'H' && LMHCCAve1 == 'M')
	{
		PROB1 = 20.00;
	}
	else if(PRESAve1_LMH == 'H' && LMHCCAve1 == 'L')
	{
		PROB1 = 10.00;
	}
}

void Summary()//Displays summary of weather forecast report ,this includes the city name ,its average cloud coverage ,its average pressure and its probability of rain
{
	cout<<setprecision(2)<<fixed;

	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;


	cout << "City Name : " << CNAry[3] << endl;
	cout << "City ID   : 3" << endl;
	cout << "Ave. Cloud Cover (ACC)		: " << CCAve3 << " (" << LMHCCAve3 << ")" << endl;
	cout << "Ave. Pressure (AP)		: " << PRESAve3 << " (" << PRESAve3_LMH << ")" << endl;
	cout << "Probability of Rain (%)		: " << PROB3 << endl;

	if (PROB3 == 90.00)
	{
		cout << "~~~~"<<endl<< "~~~~~"<<endl << "\\\\\\\\\\" << endl;
		cout << endl;
	}
	if (PROB3 == 80.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << " \\\\\\\\" << endl;
		cout << endl;
	}
	if (PROB3 == 70.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "  \\\\\\" << endl;
		cout << endl;
	}
	if (PROB3 == 60.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "   \\\\" << endl;
		cout << endl;
	}
	if (PROB3 == 50.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "    \\" << endl;
		cout << endl;
	}
	if (PROB3 == 40.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << endl;
		cout << endl;
	}
	if (PROB3 == 30.00)
	{
		cout << "~~~\n" << "~~~~\n" << endl;
		cout << endl;
	}
	if (PROB3 == 20.00)
	{
		cout << "~~\n" << "~~~\n" << endl;
		cout << endl;
	}
	else if( PROB3 == 10)
	{
		cout << "~\n" << "~~\n" << endl;
		cout << endl;
	}

	cout << "City Name : " << CNAry[2] << endl;
	cout << "City ID   : 2" << endl;
	cout << "Ave. Cloud Cover (ACC)		: " << CCAve2 << " (" << LMHCCAve2 << ")" << endl;
	cout << "Ave. Pressure (AP)		: " << PRESAve2 << " (" << PRESAve2_LMH << ")" << endl;
	cout << "Probability of Rain (%)		: " << PROB2 << endl;

	if (PROB2 == 90.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "\\\\\\\\\\" << endl;
		cout << endl;
	}
	if(PROB2 == 80.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << " \\\\\\\\" << endl;
		cout << endl;
	}
	if (PROB2 == 70.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "  \\\\\\" << endl;
		cout << endl;
	}
	if (PROB2 == 60.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "   \\\\" << endl;
		cout << endl;
	}
	if (PROB2 == 50.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "    \\" << endl;
		cout << endl;
	}
	if (PROB2 == 40.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << endl;
		cout << endl;
	}
	if (PROB2 == 30.00)
	{
		cout << "~~~\n" << "~~~~\n" << endl;
		cout << endl;
	}
	if (PROB2 == 20.00)
	{
		cout << "~~\n" << "~~~\n" << endl;
		cout << endl;
	}
	else if( PROB2 == 10)
	{
		cout << "~\n" << "~~\n" << endl;
		cout << endl;
	}

	cout << "City Name : " << CNAry[1] << endl;
	cout << "City ID   : 1" << endl;
	cout << "Ave. Cloud Cover (ACC)		: " << CCAve1 << " (" << LMHCCAve1 << ")" << endl;
	cout << "Ave. Pressure (AP)		: "<< PRESAve1 << " (" << PRESAve1_LMH << ")" << endl;
	cout << "Probability of Rain (%)		: " << PROB1 << endl;

	if (PROB1 == 90.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "\\\\\\\\\\" << endl;
		cout << endl;
	}
	if (PROB1 == 80.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << " \\\\\\\\" << endl;
		cout << endl;
	}
	if (PROB1 == 70.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "  \\\\\\" << endl;
		cout << endl;
	}
	if (PROB1 == 60.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "   \\\\" << endl;
		cout << endl;
	}
	if (PROB1 == 50.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << "    \\" << endl;
		cout << endl;
	}
	if (PROB1 == 40.00)
	{
		cout << "~~~~\n" << "~~~~~\n" << endl;
		cout << endl;
	}
	if (PROB1 == 30.00)
	{
		cout << "~~~\n" << "~~~~\n" << endl;
		cout << endl;
	}
	if (PROB1 == 20.00)
	{
		cout << "~~\n" << "~~~\n" << endl;
		cout << endl;
	}
	else if( PROB1 == 10)
	{
		cout << "~\n" << "~~\n" << endl;
		cout << endl;
	}
}

void endoffunc()
{
    cout << "Press <enter> to go back to main menu ...";

    cin.get();
    cin.get();

    cout << endl;
}

int main()
{

	MainMenu();

	return 0;

}

