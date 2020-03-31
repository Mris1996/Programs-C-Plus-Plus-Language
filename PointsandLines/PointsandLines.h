#ifndef POINTSANDLINES_H
#define POINTSANDLINES_H

#include <iostream>
#include <string>

using namespace std;
struct a3StructClass
{
string filtcrit = "Point2D";
string sortcrit = "x-ordinate";
string sortord = "ASC";
string content;
stringstream streamsc;
    int p2d=0;
    int p3d=0;
    int l2d=0;
    int l3d=0;
 int TEMP_INT = 0;
};

void MainMenu();
void Read_and_Process();
void filteringCriteria();
void sortingCriteria();
void sortingOrder();
void viewData();
void clearvec();
void P2D();
void P3D();
void L2D();
void L3D();
bool sortx1dsc(string a, string b);
bool sortx1asc(string a, string b);
bool sorty1dsc(string a, string b);
bool sorty1asc(string a, string b);
bool sortz1asc(string a, string b);
bool sortz1dsc(string a, string b);
bool sortxypt1dsc(string a, string b);
bool sortxypt1asc(string a, string b);
bool sortxypt2dsc(string a, string b);
bool sortxypt2asc(string a, string b);
bool p2ddistasc(string a, string b);
bool p2ddistdsc(string a, string b);
bool p3ddistasc(string a, string b);
bool p3ddistdsc(string a, string b);
bool l2dlengthasc(string a, string b);
bool l2dlengthdsc(string a, string b);
bool l3dlengthasc(string a, string b);
bool l3dlengthdsc(string a, string b);
bool l3dsortxypt2asc(string a, string b);
bool l3dsortxypt2dsc(string a, string b);
void storeData();
void viewdata();
void viewall();
void calclength();
void endoffunc();

#endif

