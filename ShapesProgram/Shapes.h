#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct a2StructClass
{
bool warp;
int entry = 0;
int shapenumber = 1;
int shapepts;
int side1;
int side2;
int sidex1;
int sidex2;
int sidex3;
int sidex4;
int sidey1;
int sidey2;
int sidey3 =0;
int sidey4 =0;
int sq1;
int sq2;
int sq3;
int sq4;
int bigareaside1;
int bigareaside2;
int bigarea;
int Xaxis =shapenumber+100;
int Yaxis =shapenumber+100;
double radius;
string verticesstr;
string ascend;
string descend;
string standarea;
string shapenamesc;
string specialtype;
string containwarpspacesc;
string pointsonshape;
string pointsinshape;
stringstream stream;
};

void MainMenu();
void inputshape();
void inputws();
void A2D(int y);
void computearea();
void sortinga();
void sortingd();
void sortingc();
bool ascend(const string& s1, const string& s2);
bool descend(const string& s1, const string& s2);
bool is_not_digit(char c);
void sorterfunc();
void printreports();
#endif
