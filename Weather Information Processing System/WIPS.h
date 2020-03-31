
#ifndef CSCI251_A1_H
#define CSCI251_A1_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
struct a1StructClass
{
    int X2;	
    int Y2;	
    int cityX;
    int cityY;
    int cityID;
    string cityname;
    char filler;
    int cloudX;
    int cloudY;
    int cloudID;
    int cloudIDlmh;
    char cloudLMH;
    int presX;
    int presY;
    int presID;
    char presLMH;
};

void MainMenu();
void Read_and_Process();
void Create2DAry();
void BuildArrayFunc();
void deletearraysfunc();
void ProcessCM(string fileName);
void ProcessCC(string fileName);
void ProcessCCLMH(string fileName);
void ProcessPRES(string fileName);
void ProcessPRESLMH(string fileName);
void CalcWeather();
void Summary();
void endoffunc();
void deletearraysfuncno2();
#endif

