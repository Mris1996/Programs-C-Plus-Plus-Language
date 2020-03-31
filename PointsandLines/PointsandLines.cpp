#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cassert>
#include <cstring>
#include <fstream>
#include <time.h>
#include <set>
#include <unordered_set>
#include <random>
#include <sstream>
#include <iomanip>
#include "PointsandLines.h"
#include "myTemplate.h"
#include <map>
#include <algorithm>
using namespace std;
//global variables
a3StructClass sc;
vector<string>Point2Dary;
vector<int>p2dx;
vector<int>p2dy;
vector<string>p2dview;
vector<string>Point3Dary;
vector<int>p3dx;
vector<int>p3dy;
vector<int>p3dz;
vector<string>p3dview;
vector<string>Line2Dary;
vector<int>l2dx1;
vector<int>l2dx2;
vector<int>l2dy1;
vector<int>l2dy2;
vector<string>l2dview;
vector<string>Line3Dary;
vector<int>l3dx1;
vector<int>l3dx2;
vector<int>l3dy1;
vector<int>l3dy2;
vector<int>l3dz1;
vector<int>l3dz2;
vector<string>l3dview;
class Point2D{ 
protected:
    int x;
    int y;
    int x2;
    int y2;
    double distFrOrigin;
    void setDistFrOrigin(){
        this->distFrOrigin=sqrt(pow(getX(),2)+pow(getY(),2));
    }
public:
    Point2D(int x,int y ){
        setX(x);
        setY(y);
    }
    Point2D(int x,int y , int x2 , int y2){
        setX(x);
        setY(y);
        setX2(x2);
        setY2(y2);
        setDistFrOrigin();
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int x){
        this->x=x;
    }
    void setY(int y){
        this->y=y;
    }
     int getX2(){
        return x2;
    }
    void setX2(int x2){
        this->x2=x2;
    }
     int getY2(){
        return y2;
    }
    void setY2(int y2){
        this->y2=y2;
    }
    double getScalarValue(){
        return distFrOrigin;
    }
    string toString(){
           if(sc.filtcrit=="Point2D"){
           if(equals(getX(),getX2())&&equals(getY(),getY2())){//checks if the element above the current one is the same or not , to remove duplicatre
           }
            else{
            sc.streamsc.width(4);
            sc.streamsc<<setw(2)<<"["<<setw(4)<<getX()<<","<<setw(4)<<getY()<<"]   "<<fixed<<setprecision(3)<<getScalarValue();
            string returnstring = sc.streamsc.str();
            sc.streamsc.str("");
            p2dview.push_back(returnstring);
            if(sc.filtcrit=="Point2D"&&sc.sortcrit=="x-ordinate"&&sc.sortord=="ASC"){
                 sort(begin(p2dview), end(p2dview), sortx1asc);
            }
            else if(sc.filtcrit=="Point2D"&&sc.sortcrit=="x-ordinate"&&sc.sortord=="DSC"){
                 sort(begin(p2dview), end(p2dview), sortx1dsc);
            }
            if(sc.filtcrit=="Point2D"&&sc.sortcrit=="y-ordinate"&&sc.sortord=="ASC"){
                sort(begin(p2dview), end(p2dview), sorty1asc);
            }
            else if(sc.filtcrit=="Point2D"&&sc.sortcrit=="y-ordinate"&&sc.sortord=="DSC"){
                 sort(begin(p2dview), end(p2dview), sorty1dsc);
            }
           else if(sc.filtcrit=="Point2D"&&sc.sortcrit=="Dist.Fr Origin"&&sc.sortord=="ASC"){
                 sort(begin(p2dview), end(p2dview), p2ddistasc);
            }
            else if(sc.filtcrit=="Point2D"&&sc.sortcrit=="Dist.Fr Origin"&&sc.sortord=="DSC"){
                 sort(begin(p2dview), end(p2dview), p2ddistdsc);
            }
                    return returnstring;
            }
            }
        else if(sc.filtcrit=="Line2D"){
            sc.streamsc<<setw(2)<<"["<<setw(4)<<getX()<<","<<setw(4)<<getY()<<"]";
            string returnstring = sc.streamsc.str();
            sc.streamsc.str("");
            return returnstring;
            }
            }
};
class Point3D:public Point2D{//inherit line2d
protected:
    int z;
    int z2;
    void setDistFrOrigin(){
    this->distFrOrigin = sqrt( pow(getX(),2) + pow(getY(),2) + pow(getZ(),2));
    }
public:
    Point3D(int x,int y,int z):Point2D( x, y){
        setX(x);
        setY(y);
        setZ(z);
    }
    Point3D(int x,int y,int z,int x2,int y2, int z2):Point2D( x, y, x2, y2){
        setX(x);
        setY(y);
        setZ(z);
        setX2(x2);
        setY2(y2);
        setZ2(z2);
        setDistFrOrigin();
    }
    int getZ(){
        return z;
    }
    int getZ2(){
        return z2;
    }
    void setZ(int z){
        this->z=z;
    }
    void setZ2(int z2){
        this->z2=z2;
    }
    string toString(){
           if(sc.filtcrit=="Point3D"){
           if(equals(getX(),getX2())&&equals(getY(),getY2())&&equals(getZ(),getZ2())){//checks if the element above the current one is the same or not , to remove duplicatre
           }
            else{
            sc.streamsc.width(4);
            sc.streamsc<<setw(2)<<"["<<setw(4)<<getX()<<","<<setw(4)<<getY()<<","<<setw(4)<<getZ()<<"]    "<<fixed<<setprecision(3)<<getScalarValue();
            string returnstring = sc.streamsc.str();
            sc.streamsc.str("");
            p3dview.push_back(returnstring);
            if(sc.filtcrit=="Point3D"&&sc.sortcrit=="x-ordinate"&&sc.sortord=="ASC"){
                 sort(begin(p3dview), end(p3dview), sortx1asc);
            }
            else if(sc.filtcrit=="Point3D"&&sc.sortcrit=="x-ordinate"&&sc.sortord=="DSC"){
                 sort(begin(p3dview), end(p3dview), sortx1dsc);
            }
            if(sc.filtcrit=="Point3D"&&sc.sortcrit=="y-ordinate"&&sc.sortord=="ASC"){
                sort(begin(p3dview), end(p3dview), sorty1asc);
            }
            else if(sc.filtcrit=="Point3D"&&sc.sortcrit=="y-ordinate"&&sc.sortord=="DSC"){
                 sort(begin(p3dview), end(p3dview), sorty1dsc);
            }
            if(sc.filtcrit=="Point3D"&&sc.sortcrit=="z-ordinate"&&sc.sortord=="ASC"){
                sort(begin(p3dview), end(p3dview), sortz1asc);
            }
            else if(sc.filtcrit=="Point3D"&&sc.sortcrit=="z-ordinate"&&sc.sortord=="DSC"){
                sort(begin(p3dview), end(p3dview), sortz1dsc);
            }
            else if(sc.filtcrit=="Point3D"&&sc.sortcrit=="Dist.Fr Origin"&&sc.sortord=="ASC"){
                sort(begin(p3dview), end(p3dview), p3ddistasc);
            }
            else if(sc.filtcrit=="Point3D"&&sc.sortcrit=="Dist.Fr Origin"&&sc.sortord=="DSC"){
                sort(begin(p3dview), end(p3dview), p3ddistdsc);
            }
                return returnstring;
            }
            }
            else if(sc.filtcrit=="Line3D"){
            sc.streamsc<<setw(2)<<"["<<setw(4)<<getX()<<","<<setw(4)<<getY()<<","<<setw(4)<<getZ()<<"]";
            string returnstring = sc.streamsc.str();
            sc.streamsc.str("");
            return returnstring;
            }
    }
};
class Line2D{
private:
    Point2D *pt1;//aggregate point2d
    Point2D *pt2;
    Point2D *pt1x;
    Point2D *pt2x;
protected:
    double length;
    void setLength(){
      this->length=sqrt( pow( getPt1().getX()-getPt2().getX(),2 ) + pow( getPt1().getY()- getPt2().getY(),2) );
    }
public:
    Line2D(Point2D *pt1,Point2D *pt2){
        setPt1(pt1);
        setPt2(pt2);
    }
    Line2D(Point2D *pt1,Point2D *pt2,Point2D *pt1x,Point2D *pt2x){
        setPt1(pt1);
        setPt2(pt2);
        setPt1x(pt1x);
        setPt2x(pt2x);
        setLength();
    }
    Point2D getPt1(){
        return *pt1;
    }
    Point2D getPt2(){
        return *pt2;
    }
    Point2D getPt1x(){
        return *pt1x;
    }
    Point2D getPt2x(){
        return *pt2x;
    }
    double getScalarValue(){
        return length;
    }
    void setPt1(Point2D *pt1){
        this->pt1=pt1;
    }
    void setPt2(Point2D *pt2){
        this->pt2=pt2;
    }
     void setPt1x(Point2D *pt1x){
        this->pt1x=pt1x;
    }
    void setPt2x(Point2D *pt2x){
        this->pt2x=pt2x;
    }
    string toString(){
       if(equals(getPt1().toString(),getPt1x().toString())&&equals(getPt2().toString(),getPt2x().toString())){//checks if the element above the current one is the same or not , to remove duplicatre
       }
       else{
        sc.streamsc.width(4);
        sc.streamsc<<getPt1().toString()<<"   "<<getPt2().toString()<<"   "<<fixed<<setprecision(3)<<getScalarValue();
        string returnstring = sc.streamsc.str();
        sc.streamsc.str("");
        l2dview.push_back(returnstring);

            if(sc.filtcrit=="Line2D"&&sc.sortcrit=="Pt. 1"&&sc.sortord=="ASC"){
                 sort(begin(l2dview), end(l2dview), sortxypt1asc);
            }
            else if(sc.filtcrit=="Line2D"&&sc.sortcrit=="Pt. 1"&&sc.sortord=="DSC"){
                 sort(begin(l2dview), end(l2dview), sortxypt1dsc);
            }
            if(sc.filtcrit=="Line2D"&&sc.sortcrit=="Pt. 2"&&sc.sortord=="ASC"){
                sort(begin(l2dview), end(l2dview), sortxypt2asc);
            }
            else if(sc.filtcrit=="Line2D"&&sc.sortcrit=="Pt. 2"&&sc.sortord=="DSC"){
                 sort(begin(l2dview), end(l2dview), sortxypt2dsc);
            }
            else if(sc.filtcrit=="Line2D"&&sc.sortcrit=="Length"&&sc.sortord=="ASC"){
                sort(begin(l2dview), end(l2dview), l2dlengthasc);
            }
            else if(sc.filtcrit=="Line2D"&&sc.sortcrit=="Length"&&sc.sortord=="DSC"){
                sort(begin(l2dview), end(l2dview), l2dlengthdsc);
            }
		return returnstring;
       }
    }
};
class Line3D:public Line2D{//inherit line2d
private:
    Point3D *pt1;//aggregate point3d
    Point3D *pt2;
    Point3D *pt1x;
    Point3D *pt2x;
protected:
    void setLength(){
      this->length=sqrt( pow( getPt1().getX()-getPt2().getX(),2 ) + pow( getPt1().getY()- getPt2().getY(),2) + pow( getPt1().getZ()- getPt2().getZ(),2));
    }
public:
    Line3D(Point3D *pt1,Point3D *pt2):Line2D(pt1,pt2){
        setPt1(pt1);
        setPt2(pt2);
    }
    Line3D(Point3D *pt1,Point3D *pt2,Point3D *pt1x,Point3D *pt2x):Line2D(pt1,pt2,pt1x,pt2x){
        setPt1(pt1);
        setPt2(pt2);
        setPt1x(pt1x);
        setPt2x(pt2x);
        setLength();
    }
    Point3D getPt1(){
        return *pt1;
    }
    Point3D getPt2(){
        return *pt2;
    }
    Point3D getPt1x(){
        return *pt1x;
    }
    Point3D getPt2x(){
        return *pt2x;
    }
    void setPt1(Point3D *pt1){
        this->pt1=pt1;
    }
    void setPt2(Point3D *pt2){
        this->pt2=pt2;
    }
     void setPt1x(Point3D *pt1x){
        this->pt1x=pt1x;
    }
    void setPt2x(Point3D *pt2x){
        this->pt2x=pt2x;
    }
    string toString(){
        if(equals(getPt1().toString(),getPt1x().toString())&&equals(getPt2().toString(),getPt2x().toString())){
        }
        else{
        sc.streamsc.width(4);
        sc.streamsc<<getPt1().toString()<<"   "<<getPt2().toString()<<"   "<<fixed<<setprecision(3)<<getScalarValue();//checks if the element above the current one is the same or not , to remove duplicatre
        string returnstring = sc.streamsc.str();
        sc.streamsc.str("");
        l3dview.push_back(returnstring);

            if(sc.filtcrit=="Line3D"&&sc.sortcrit=="Pt. 1"&&sc.sortord=="ASC"){
                 sort(begin(l3dview), end(l3dview), sortxypt1asc);
            }
            else if(sc.filtcrit=="Line3D"&&sc.sortcrit=="Pt. 1"&&sc.sortord=="DSC"){
                 sort(begin(l3dview), end(l3dview), sortxypt1dsc);
            }
            if(sc.filtcrit=="Line3D"&&sc.sortcrit=="Pt. 2"&&sc.sortord=="ASC"){
            	   sort(begin(l3dview), end(l3dview), l3dsortxypt2asc);
            }
            else if(sc.filtcrit=="Line3D"&&sc.sortcrit=="Pt. 2"&&sc.sortord=="DSC"){
                 sort(begin(l3dview), end(l3dview), l3dsortxypt2dsc);
            }
            else if(sc.filtcrit=="Line3D"&&sc.sortcrit=="Length"&&sc.sortord=="ASC"){
                sort(begin(l3dview), end(l3dview), l3dlengthasc);
            }
            else if(sc.filtcrit=="Line3D"&&sc.sortcrit=="Length"&&sc.sortord=="DSC"){
                sort(begin(l3dview), end(l3dview), l3dlengthdsc);
            }
	    return returnstring;

        }
    }
};
void Read_and_Process()
{
    clearvec();
    ifstream infilestream;
    stringstream stream;
    string input;
    cout << "Please enter filename: ";
    cin >> input;
    cout<<endl;
      string filename = "/home/vmw_ubuntu/"+input;
   infilestream.open(filename.c_str());
    if(infilestream.fail()){
        cerr<<"Sorry! The file that you have specified do not exist! Returning back to main menu"<<endl<<endl;
        MainMenu();
    }
string line;
int counter =0;
if (infilestream.is_open())
  {
    while ( infilestream.good() )
    {
        getline (infilestream,line);//gets the line and send to the respective functions according to the substring
                  if(line.substr(0,7)=="Point2D"){
                    Point2Dary.push_back(line);
                    }
                    else if(line.substr(0,7)=="Point3D"){
                    Point3Dary.push_back(line);
                    }
                    else if(line.substr(0,6)=="Line2D"){
                    Line2Dary.push_back(line);
                    }
                    else if(line.substr(0,6)=="Line3D"){
                    Line3Dary.push_back(line);
                    }
    }
  }
infilestream.close();
if(Point2Dary.size()>0){
    sort( Point2Dary.begin(), Point2Dary.end());//sorts first according to the first digit it finds
    P2D();
}
if(Point3Dary.size()>0){
    sort( Point3Dary.begin(), Point3Dary.end());//sorts first according to the first digit it finds
    P3D();
}
if(Line2Dary.size()>1){
    sort( Line2Dary.begin(), Line2Dary.end());//sorts first according to the first digit it finds
    L2D();
}
if(Line3Dary.size()>1){
    sort( Line3Dary.begin(), Line3Dary.end());//sorts first according to the first digit it finds
    L3D();
}
cout<<endl;
counter = Point2Dary.size()+ Point3Dary.size()+ Line3Dary.size()+Line2Dary.size();//counts the amount of data stored
cout<<counter<<" records read in successfully"<<endl<<endl;
cout<<"Going back to main menu..."<<endl;
MainMenu();
}
void P2D(){
vector<int>emptyary;
    if(Point2Dary.size()<1){
        cerr<<"Input some data"<<endl<<endl;
        Read_and_Process();
    }
    else{
        for(int i=0;i<Point2Dary.size();i++){
            Point2Dary[i].replace(Point2Dary[i].find("Point2D,"),9,"");
            Point2Dary[i].replace(Point2Dary[i].find("["),1,"");
            Point2Dary[i].replace(Point2Dary[i].find("]"),1,"");
        }
        for(int i=0;i<Point2Dary.size();i++){
            sc.streamsc<<Point2Dary[i]<<endl;
        }
        string p2d = sc.streamsc.str();
        sc.streamsc.str("");
        stringstream ss(p2d);
   if( p2d.length() != 0 )
   {
      while( !ss.eof() )
      {
         if( ss.peek()!= ',')//gets integer that is beside this char
         {
            ss>>sc.TEMP_INT;
           emptyary.push_back(sc.TEMP_INT);
         }
         ss.get();
      }
   }
        for(int i=0;i<emptyary.size()-1;i++){
            if(i%2==0){
                p2dx.push_back(emptyary[i]);
            }
            else{
                p2dy.push_back(emptyary[i]);
            }
        }
        emptyary.clear();
    }
}
void P3D(){
vector<int>emptyary;
vector<int>emptyary2;
    if(Point3Dary.size()<1){
        cerr<<"Input some data"<<endl<<endl;
        Read_and_Process();
    }
    else{
        for(int i=0;i<Point3Dary.size();i++){
            Point3Dary[i].replace(Point3Dary[i].find("Point3D,"),9,"");
            Point3Dary[i].replace(Point3Dary[i].find("["),1,"");
            Point3Dary[i].replace(Point3Dary[i].find("]"),1,"");
        }
        for(int i=0;i<Point3Dary.size();i++){
            sc.streamsc<<Point3Dary[i]<<endl;
        }
        string p3d = sc.streamsc.str();
        sc.streamsc.str("");
        stringstream ss(p3d);
   if( p3d.length() != 0 )
   {
      while( !ss.eof() )
      {
         if( ss.peek()!= ',')//gets integer that is beside this char
         {
            ss>>sc.TEMP_INT;
           emptyary.push_back(sc.TEMP_INT);
         }
         ss.get();
      }
   }
        for(int i=0;i<emptyary.size()-1;i++){
            if(i%3==0||i==0){
                p3dx.push_back(emptyary[i]);
            }
            else{
                emptyary2.push_back(emptyary[i]);
            }
        }
         for(int i=0;i<emptyary2.size();i++){
            if(i%2==0){
                p3dy.push_back(emptyary2[i]);
            }
            else{
                p3dz.push_back(emptyary2[i]);
            }
        }
        emptyary.clear();
        emptyary2.clear();
    }
}
void L2D(){
vector<int>emptyary;
vector<int>emptyary2;
vector<int>emptyary3;
    if(Line2Dary.size()<1){
        cerr<<"Input some data"<<endl<<endl;
        Read_and_Process();
    }
    else{
        for(int i=0;i<Line2Dary.size();i++){
            Line2Dary[i].replace(Line2Dary[i].find("Line2D,"),7,"");
            Line2Dary[i].replace(Line2Dary[i].find("["),1,"");
            Line2Dary[i].replace(Line2Dary[i].find("["),1,"");
            Line2Dary[i].replace(Line2Dary[i].find("]"),1,"");
            Line2Dary[i].replace(Line2Dary[i].find("]"),1,"");
        }
        for(int i=0;i<Line2Dary.size();i++){
            sc.streamsc<<Line2Dary[i]<<endl;
        }
        string l2d = sc.streamsc.str();
        sc.streamsc.str("");
        stringstream ss(l2d);
   if( l2d.length() != 0 )
   {
      while( !ss.eof() )
      {
         if( ss.peek()!= ',')//gets integer that is beside this char
         {
            ss>>sc.TEMP_INT;
           emptyary.push_back(sc.TEMP_INT);
         }
         ss.get();
      }
   }
        for(int i=0;i<emptyary.size()-1;i++){
            if(i%2==0){
                emptyary2.push_back(emptyary[i]);
            }
            else{
                emptyary3.push_back(emptyary[i]);
            }
        }
         for(int i=0;i<emptyary2.size();i++){
            if(i%2==0){
                l2dx1.push_back(emptyary2[i]);
            }
            else{
                l2dx2.push_back(emptyary2[i]);
            }
        }
        for(int i=0;i<emptyary3.size();i++){
            if(i%2==0){
                l2dy1.push_back(emptyary3[i]);
            }
            else{
                l2dy2.push_back(emptyary3[i]);
            }
        }
        emptyary.clear();
        emptyary2.clear();
        emptyary3.clear();
    }
}
void L3D(){
vector<int>emptyary;
vector<int>emptyary2;
vector<int>emptyary3;
vector<int>emptyary4;
vector<int>emptyary5;
    if(Line3Dary.size()<1){
        cerr<<"Input some data"<<endl<<endl;
        Read_and_Process();
    }
    else{
        for(int i=0;i<Line3Dary.size();i++){
            Line3Dary[i].replace(Line3Dary[i].find("Line3D,"),7,"");
            Line3Dary[i].replace(Line3Dary[i].find("["),1,"");
            Line3Dary[i].replace(Line3Dary[i].find("["),1,"");
            Line3Dary[i].replace(Line3Dary[i].find("]"),1,"");
            Line3Dary[i].replace(Line3Dary[i].find("]"),1,"");
        }
        for(int i=0;i<Line3Dary.size();i++){
            sc.streamsc<<Line3Dary[i]<<endl;
        }
        string l3d = sc.streamsc.str();
        sc.streamsc.str("");
        stringstream ss(l3d);
   if( l3d.length() != 0 )
   {
      while( !ss.eof() )
      {
         if( ss.peek()!= ',')//gets integer that is beside this char
         {
            ss>>sc.TEMP_INT;
           emptyary.push_back(sc.TEMP_INT);
         }
         ss.get();
      }
   }
        for(int i=0;i<emptyary.size()-1;i++){
            if(i%3==0||i==0){
                emptyary2.push_back(emptyary[i]);
            }
            else{
                emptyary3.push_back(emptyary[i]);
            }
        }
         for(int i=0;i<emptyary2.size();i++){
            if(i%2==0){
                l3dx1.push_back(emptyary2[i]);
            }
            else{
                l3dx2.push_back(emptyary2[i]);
            }
        }
        for(int i=0;i<emptyary3.size();i++){
            if(i%2==0){
                emptyary4.push_back(emptyary3[i]);
            }
            else{
                emptyary5.push_back(emptyary3[i]);
            }
        }
        for(int i=0;i<emptyary4.size();i++){
            if(i%2==0){
                l3dy1.push_back(emptyary4[i]);
            }
            else{
                l3dy2.push_back(emptyary4[i]);
            }
        }
        for(int i=0;i<emptyary5.size();i++){
            if(i%2==0){
                l3dz1.push_back(emptyary5[i]);
            }
            else{
                l3dz2.push_back(emptyary5[i]);
            }
        }
        emptyary.clear();
        emptyary2.clear();
        emptyary3.clear();
        emptyary4.clear();
        emptyary5.clear();
    }
}
void filteringCriteria(){
    char choice;
    do
    {
        cout << "[Specifying filtering criteria: (current:"<<sc.filtcrit<<"]" <<endl;
        cout << "a)" << "   Point2D records " << endl;
        cout << "b)" << "   Point3D records " << endl;
        cout << "c)" << "   Line2D records " << endl;
        cout << "d)" << "   Line3D records " << endl;
        cout << "Please enter your criteria (a-d):";
        if (cin >> choice)
        {
            if (choice == 'q')
            {
                cout << endl;
                MainMenu();
            }
            else if (choice == 'a')
            {
                sc.filtcrit="Point2D";
                sc.sortcrit="x-ordinate";
		cout<<"Filtering criteria successfully set to '"<<sc.filtcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'b')
            {
                sc.filtcrit="Point3D";
                sc.sortcrit="x-ordinate";
		cout<<"Filtering criteria successfully set to '"<<sc.filtcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'c')
            {
                sc.filtcrit="Line2D";
                sc.sortcrit="Pt. 1";
		cout<<"Filtering criteria successfully set to '"<<sc.filtcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'd')
            {
                sc.filtcrit="Line3D";
                sc.sortcrit="Pt. 1";
		cout<<"Filtering criteria successfully set to '"<<sc.filtcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else
            {
                cerr << "Pick either 'a','b','c','d' or 'q'" << endl;
            }
        }
        else
        {
             cerr << "Pick either 'a','b','c','d' or 'q'" << endl;
        }
    }
    while (choice != 'a' || choice != 'b' || choice != 'c' || choice!='d');
}
void sortingCriteria(){
     char choice;
     if(sc.filtcrit=="Line3D"){
    do
    {
        cout << "[Specifying sorting criteria: (current:"<<sc.sortcrit<<"]" <<endl;
        cout << "a)" << "   Pt. 1's(x,y)values" << endl;
        cout << "b)" << "   Pt. 2's(x,y)values" << endl;
        cout << "c)" << "   Length value" << endl;
        cout << "Please enter your criteria (a-c):";
        if (cin >> choice)
        {
            if (choice == 'q')
            {
                cout << endl;
                MainMenu();
            }
            else if (choice == 'a')
            {
               sc.sortcrit="Pt. 1";
		cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'b')
            {
                sc.sortcrit="Pt. 2";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'c')
            {
                sc.sortcrit="Length";
 	        cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else
            {
                cerr << "Pick either 'a','b','c' or 'q'" << endl;
            }
        }
        else
        {
             cerr << "Pick either 'a','b','c' or 'q'" << endl;
        }
        cout << endl;
    }
    while (choice != 'a' || choice != 'b' || choice != 'c');
        }
    if(sc.filtcrit=="Line2D"){
    do
    {
        cout << "[Specifying sorting criteria: (current:"<<sc.sortcrit<<"]" <<endl;
        cout << "a)" << "   Pt. 1's(x,y)values" << endl;
        cout << "b)" << "   Pt. 2's(x,y)values" << endl;
        cout << "c)" << "   Length value" << endl;
        cout << "Please enter your criteria (a-c):";
        if (cin >> choice)
        {
            if (choice == 'q')
            {
                cout << endl;
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'a')
            {
               sc.sortcrit="Pt. 1";
               cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'b')
            {
                sc.sortcrit="Pt. 2";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'c')
            {
                sc.sortcrit="Length";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else
            {
                cerr << "Pick either 'a','b','c' or 'q'" << endl;
            }
        }
        else
        {
             cerr << "Pick either 'a','b','c' or 'q'" << endl;
        }
        cout << endl;
    }
    while (choice != 'a' || choice != 'b' || choice != 'c');
        }
   else  if(sc.filtcrit=="Point3D"){
    do
    {
        cout << "[Specifying sorting criteria: (current:"<<sc.sortcrit<<"]" <<endl;
        cout << "a)" << "  X ordinate value" << endl;
        cout << "b)" << "  Y ordinate value" << endl;
        cout << "c)" << "  Z ordinate value" << endl;
        cout << "d)" << "  Distance from origin value" << endl;
        cout << "Please enter your criteria (a-c):";
        if (cin >> choice)
        {
            if (choice == 'q')
            {
                cout << endl;
               cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'a')
            {
               sc.sortcrit="x-ordinate";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'b')
            {
                sc.sortcrit="y-ordinate";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'c')
            {
                sc.sortcrit="z-ordinate";
                MainMenu();
            }
             else if (choice == 'd')
            {
                sc.sortcrit="Dist.Fr Origin";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else
            {
                cerr << "Pick either 'a','b','c','d' or 'q'" << endl;
            }
        }
        else
        {
             cerr << "Pick either 'a','b','c','d' or 'q'" << endl;
        }
        cout << endl;
    }
    while (choice != 'a' || choice != 'b' || choice != 'c'|| choice != 'd');
        }
    else if(sc.filtcrit=="Point2D"){
    do
    {
        cout << "[Specifying sorting criteria: (current:"<<sc.sortcrit<<"]" <<endl;
        cout << "a)" << "  X ordinate value" << endl;
        cout << "b)" << "  Y ordinate value" << endl;
        cout << "c)" << "  Distance from origin value" << endl;
        cout << "Please enter your criteria (a-c):";
        if (cin >> choice)
        {
            if (choice == 'q')
            {
                cout << endl;
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'a')
            {
               sc.sortcrit="x-ordinate";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'b')
            {
                sc.sortcrit="y-ordinate";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'c')
            {
                sc.sortcrit="Dist.Fr Origin";
                cout<<"Sorting criteria successfully set to '"<<sc.sortcrit<<"'!"<<endl<<endl;
                MainMenu();
            }
            else
            {
                cerr << "Pick either 'a','b','c' or 'q'" << endl;
            }
        }
        else
        {
             cerr << "Pick either 'a','b','c' or 'q'" << endl;
        }
        cout << endl<<endl;
    }
    while (choice != 'a' || choice != 'b' || choice != 'c');
        }
}
void sortingOrder(){
     char choice;
    do
    {
        cout << "[Specifying sorting order: (current:"<<sc.sortord<<"]" <<endl;
        cout << "a)" << "   ASC(Ascending order) " << endl;
        cout << "b)" << "   DSC(Descending order) " << endl;
        cout << "Please enter your criteria (a-d): ";
        if (cin >> choice)	
        {
            if (choice == 'q')
            {
                cout << endl;
                MainMenu();
            }
            else if (choice == 'a')
            {
                sc.sortord="ASC";
                cout<<"Sorting order successfully set to '"<<sc.sortord<<"'!"<<endl<<endl;
                MainMenu();
            }
            else if (choice == 'b')
            {
                sc.sortord="DSC";
                cout<<"Sorting order successfully set to '"<<sc.sortord<<"'!"<<endl<<endl;
                MainMenu();
            }
            else
            {
                cerr << "Pick either 'a','b' or 'q'" << endl;
            }
        }
        else
        {
           cerr << "Pick either 'a','b' or 'q'" << endl;
        }
        cout << endl<<endl;
    }
    while (choice != 'a' || choice != 'b');
}
void viewData(){
    if(Point2Dary.size()<1&&Point3Dary.size()<1&&Line2Dary.size()<1&&Line3Dary.size()<1){//if no data stored , itll prompt user to store data
         cerr<<"Input a data"<<endl<<endl;
            Read_and_Process();
    }
    else{
        cout<<" [View data...]"<<endl;
        cout<<"filtering criteria :"<<sc.filtcrit<<endl;
        cout<<"sorting criteria :"<<sc.sortcrit<<endl;
        cout<<"sorting order :"<<sc.sortord<<endl<<endl;
        if(sc.filtcrit=="Point2D")
        {   p2dview.clear();
            for(int i =0;i<p2dx.size();i++){
            Point2D obj(p2dx[i],p2dy[i],p2dx[i+1],p2dy[i+1]);
            obj.toString();
            }
            if(p2dview.size()>0){

                sc.streamsc<<setw(6)<<"X"<<setw(5)<<"Y"<<setw(4)<<"    Dist.Fr Origin"<<endl;
            for(int i=0;i<17;i++){
                sc.streamsc<<" -";
            }
            sc.streamsc<<endl;
            for(int i=0;i<p2dview.size();i++){
                sc.streamsc<<p2dview[i]<<endl;
            }
            sc.streamsc<<endl;
            sc.content = sc.streamsc.str();
            sc.streamsc.str("");
            }
            else{
            cerr<<"No Point2D data,choose another filter criteria or add a new data"<<endl<<endl;//
            MainMenu();
            }
        }
        if(sc.filtcrit=="Point3D")
        {
            p3dview.clear();
            for(int i =0;i<p3dx.size();i++){
            Point3D obj(p3dx[i],p3dy[i],p3dz[i],p3dx[i+1],p3dy[i+1],p3dz[i+1]);
            obj.toString();
            }
            if(p3dview.size()>0){
            sc.streamsc<<setw(6)<<"X"<<setw(5)<<"Y"<<setw(5)<<"Z"<<setw(4)<<"     Dist.Fr Origin"<<endl;
            for(int i=0;i<17;i++){
                sc.streamsc<<" -";
            }
            sc.streamsc<<endl;
            for(int i=0;i<p3dview.size();i++){
                sc.streamsc<<p3dview[i]<<endl;
            }
            sc.streamsc<<endl;
            sc.content = sc.streamsc.str();
            sc.streamsc.str("");
            }
            else{
            cerr<<"No Point3D data,choose another filter criteria or add a new data"<<endl<<endl;
            MainMenu();
            }
        }
        if(sc.filtcrit=="Line2D")
        {
            l2dview.clear();
            for(int i =0;i<l2dx1.size();i++){
            Point2D  pt1(l2dx1[i],l2dy1[i]);
            Point2D  pt2(l2dx2[i],l2dy2[i]);
            Point2D  pt1x(l2dx1[i+1],l2dy1[i+1]);
            Point2D  pt2x(l2dx2[i+1],l2dy2[i+1]);
            Line2D obj( &pt1, &pt2 , &pt1x ,  &pt2x);
            obj.toString();
            }
            if(l2dview.size()>0){
            sc.streamsc<<setw(6)<<"P1-X"<<setw(5)<<"P1-Y"<<setw(10)<<"P2-X"<<setw(5)<<"P2-Y"<<"    Length"<<endl;
            for(int i=0;i<21;i++){
            sc.streamsc<<" -";
            }
            sc.streamsc<<endl;
            for(int i=0;i<l2dview.size();i++){
                 sc.streamsc<<l2dview[i]<<endl;
            }
            sc.streamsc<<endl;
            sc.content = sc.streamsc.str();
            sc.streamsc.str("");
            }
            else{
            cerr<<"No Line2D data,choose another filter criteria or add a new data"<<endl<<endl;
            MainMenu();
            }
        }
        if(sc.filtcrit=="Line3D")
        {
            l3dview.clear();
            for(int i =0;i<l3dx1.size();i++){
            Point3D  pt1(l3dx1[i],l3dy1[i],l3dz1[i]);
            Point3D  pt2(l3dx2[i],l3dy2[i],l3dz2[i]);
            Point3D  pt1x(l3dx1[i+1],l3dy1[i+1],l3dz1[i+1]);
            Point3D  pt2x(l3dx2[i+1],l3dy2[i+1],l3dz2[i+1]);
            Line3D obj( &pt1, &pt2 , &pt1x ,  &pt2x);
            obj.toString();
            }
            if(l3dview.size()>0){
            sc.streamsc<<setw(6)<<"P1-X"<<setw(5)<<"P1-Y"<<setw(5)<<"P1-Z"<<setw(10)<<"P2-X"<<setw(5)<<"P2-Y"<<setw(5)<<"P2-Z"<<"    Length"<<endl;
            for(int i=0;i<29;i++){
                 sc.streamsc<<" -";
            }
             sc.streamsc<<endl;
            for(int i=0;i<l3dview.size();i++){
                 sc.streamsc<<l3dview[i]<<endl;
            }
            sc.streamsc<<endl;
            sc.content = sc.streamsc.str();
            sc.streamsc.str("");
            }
            else{
            cerr<<"No Line3D data,choose another filter criteria or add a new data"<<endl<<endl;
            MainMenu();
            }
        }
        cout<<sc.content;
    }
}
void clearvec(){//to ensure that the program can be used more than once

    Point2Dary.clear();
    p2dview.clear();
    Line2Dary.clear();
    Point3Dary.clear();
    Line3Dary.clear();
    p3dx.clear();
    p3dy.clear();
    p3dz.clear();
    p2dx.clear();
    p2dy.clear();
    l2dx1.clear();
    l2dx2.clear();
    l2dy1.clear();
    l2dy2.clear();
    l3dx1.clear();
    l3dx2.clear();
    l3dy1.clear();
    l3dy2.clear();
    l3dz1.clear();
    l3dz2.clear();
}
void storeData(){
if(p2dview.size()<1&&p3dview.size()<1&&l2dview.size()<1&&l3dview.size()<1){//makes sure user views the data before storing data
    viewData();
}
else{
if(p2dview.size()<1&&sc.filtcrit=="Point2D"){
	cout<<"View data and try again"<<endl<<endl;
    viewData();
}
if(p3dview.size()<1&&sc.filtcrit=="Point3D"){
	cout<<"View data and try again"<<endl<<endl;
    viewData();
}
if(l2dview.size()<1&&sc.filtcrit=="Line2D"){
	cout<<"View data and try again"<<endl<<endl;
    viewData();
}
if(l3dview.size()<1&&sc.filtcrit=="Line3D"){
	cout<<"View data and try again"<<endl<<endl;
    viewData();
}
else{
ofstream  outfilestream ;
string input;
cout<<"Please Enter filename :";
cin>>input;
  string filename = "/home/vmw_ubuntu/"+input;
outfilestream.open(filename);
outfilestream<<" [View data...]"<<endl;
outfilestream<<"filtering criteria :"<<sc.filtcrit<<endl;
outfilestream<<"sorting criteria :"<<sc.sortcrit<<endl;
outfilestream<<"sorting order :"<<sc.sortord<<endl<<endl;
outfilestream <<sc.content;
if(sc.filtcrit=="Point2D"){
    cout<<p2dview.size()<<" records output successfully!"<<endl;
}
else if(sc.filtcrit=="Point3D"){
    cout<<p3dview.size()<<" records output successfully!"<<endl;
}
else if(sc.filtcrit=="Line2D"){
    cout<<l2dview.size()<<" records output successfully!"<<endl;
}
else if(sc.filtcrit=="Line3D"){
    cout<<l3dview.size()<<" records output successfully!"<<endl;
}

outfilestream.close();
cout<<"Going back to main menu..."<<endl<<endl;
MainMenu();
}
}
}
bool sortx1dsc(string a, string b)
{
    int i = stoi(a.substr(2,4));
    int g = stoi(b.substr(2,4));
    if(i==g){
        i = stoi(a.substr(7,4));
        g = stoi(b.substr(7,4));
    }
    return i > g;
}
bool sortx1asc(string a, string b)
{
    int i = stoi(a.substr(2,4));
    int g = stoi(b.substr(2,4));
    if(i==g){
        i = stoi(a.substr(7,4));
        g = stoi(b.substr(7,4));
    }
    return i < g;
}
bool sorty1dsc(string a, string b)
{
    int i = stoi(a.substr(7,4));
    int g = stoi(b.substr(7,4));
     if(i==g){
        i = stoi(a.substr(2,4));
        g = stoi(b.substr(2,4));
    }
    return i > g;
}
bool sorty1asc(string a, string b)
{
    int i = stoi(a.substr(7,4));
    int g = stoi(b.substr(7,4));
        if(i==g){
        i = stoi(a.substr(2,4));
        g = stoi(b.substr(2,4));
        }
    return i < g;
}
bool sortz1dsc(string a, string b)
{
    int i = stoi(a.substr(12,4));
    int g = stoi(b.substr(12,4));
        if(i==g){
        i = stoi(a.substr(2,4));
        g = stoi(b.substr(2,4));
    }
    return i > g;
}
bool sortz1asc(string a, string b)
{
     int i = stoi(a.substr(12,4));
    int g = stoi(b.substr(12,4));
    if(i==g){
        i = stoi(a.substr(2,4));
        g = stoi(b.substr(2,4));
    }
    return i < g;

}
bool sortxypt1dsc(string a, string b)
{
	int i = stoi(a.substr(2,5));
    	int g = stoi(b.substr(2,5));
        if(i==g){
        i = stoi(a.substr(7,5));
        g = stoi(b.substr(7,5));
        }
    return i > g;
}
bool sortxypt1asc(string a, string b)
{
    int i = stoi(a.substr(2,5));
    int g = stoi(b.substr(2,5));
        if(i==g){
        i = stoi(a.substr(7,5));
        g = stoi(b.substr(7,5));
        }
    return i < g;
}
bool sortxypt2dsc(string a, string b)
{
    int i = stoi(a.substr(17,5));
    int g = stoi(b.substr(17,5));
        if(i==g){
        i = stoi(a.substr(22,5));
        g = stoi(b.substr(22,5));
        }
    return i > g;
}
bool sortxypt2asc(string a, string b)
{
    int i = stoi(a.substr(17,5));
    int g = stoi(b.substr(17,5));
        if(i==g){
        i = stoi(a.substr(22,5));
        g = stoi(b.substr(22,5));
        }
    return i < g;
}
bool l3dsortxypt2asc(string a, string b)
{
    int i = stoi(a.substr(22,5));
    int g = stoi(b.substr(22,5));
        if(i==g){
        i = stoi(a.substr(27,5));
        g = stoi(b.substr(27,5));
        }
    return i < g;
}
bool l3dsortxypt2dsc(string a, string b)
{
    int i = stoi(a.substr(22,5));
    int g = stoi(b.substr(22,5));
        if(i==g){
        i = stoi(a.substr(27,5));
        g = stoi(b.substr(27,5));
        }
    return i > g;
}
bool p2ddistasc(string a, string b)
{
    int i = stoi(a.substr(14,8));
    int g = stoi(b.substr(14,8));
    if(i==g){
    i = stoi(a.substr(17,4));
    g = stoi(b.substr(17,4));
    }
    return i < g;
    }
bool p2ddistdsc(string a, string b)
{
    int i = stoi(a.substr(14,8));
    int g = stoi(b.substr(14,8));
    if(i==g){
    i = stoi(a.substr(17,4));
    g = stoi(b.substr(17,4));
    }
    return i > g;
    }
bool p3ddistasc(string a, string b)
{
    int i = stod(a.substr(21,8));
    int g = stod(b.substr(21,8));
    if(i==g){
    i = stoi(a.substr(24,4));
    g = stoi(b.substr(24,4));
    }
    return i < g;
    }
bool p3ddistdsc(string a, string b)
{
    int i = stod(a.substr(21,8));
    int g = stod(b.substr(21,8));
    if(i==g){
    i = stoi(a.substr(24,4));
    g = stoi(b.substr(24,4));
    }
    return i > g;
    }
bool l2dlengthasc(string a, string b)
{
    int i = stoi(a.substr(30,8));
    int g = stoi(b.substr(30,8));
    if(i==g){
    i = stoi(a.substr(33,4));
    g = stoi(b.substr(33,4));
    }
    return i < g;
}
bool l2dlengthdsc(string a, string b)
{
    int i = stoi(a.substr(30,8));
    int g = stoi(b.substr(30,8));
    if(i==g){
    i = stoi(a.substr(33,4));
    g = stoi(b.substr(33,4));
    }
    return i > g;
}
bool l3dlengthasc(string a, string b)
{
    int i = stoi(a.substr(39,8));
    int g = stoi(b.substr(39,8));
    if(i==g){
    i = stoi(a.substr(42,4));
    g = stoi(b.substr(42,4));
    }
    return i < g;
}
bool l3dlengthdsc(string a, string b)
{
    int i = stoi(a.substr(39,8));
    int g = stoi(b.substr(39,8));
    if(i==g){
    i = stoi(a.substr(42,4));
    g = stoi(b.substr(42,4));
    }
    return i > g;
}
void MainMenu()//options menu
{
	int choice;
     
        cout << "----------------------------------" << endl;
        cout << "Reading in Points and Lines program" << endl << endl;
        cout << "1)	    Read in  data" << endl;
        cout << "2)	    Specify filtering criteria (current:"<<sc.filtcrit<<")" << endl;
        cout << "3)	    Specify sorting criteria (current:"<<sc.sortcrit<<")" << endl;
        cout << "4)	    Specify sorting order (current:"<<sc.sortord<<")" << endl;
        cout << "5)	    View data" << endl;
        cout << "6)	    Store data" << endl;
        cout << "7)	    Length calculator " << endl;
		cout << "Please enter your choice : ";
	if(!(cin>>choice))
	{
        cout<<endl;
		cerr << "Please pick a number between 1 and 7" <<endl<<endl;
		cin.clear();
	   cin.ignore(8, '\n');
	   MainMenu();
	}
	cout << endl;
	if (choice == 1)
	{
		Read_and_Process();
	}
	if (choice == 2)
	{
            filteringCriteria();
			MainMenu();
	}
	if (choice == 3)
	{
            sortingCriteria();
			MainMenu();
	}
	if (choice == 4)
	{
            sortingOrder();
			MainMenu();
	}
	if (choice == 5)
	{
            viewData();
            endoffunc();
			MainMenu();
	}
	if (choice == 6)
	{
            storeData();
			MainMenu ();
	}
	if (choice == 7)
	{
            calclength();
			MainMenu ();
	}
}
void endoffunc()
{
    cout << "Press <enter> to go back to main menu ...";

    cin.get();
    cin.get();

    cout << endl;
}
void calclength(){
string dimensions;
double x;
double y;
double z;
vector<double>pts;
double length;
cout<<"[Length calculator]"<<endl;
cout<<"Enter if line is 2D or 3D :";
cin>>dimensions;
transform(dimensions.begin(), dimensions.end(),dimensions.begin(),::toupper);
if(dimensions!="2D"&&dimensions!="3D"){
    cout<<endl;
    cerr<<"Invalid entry...please try again"<<endl<<endl;
    calclength();
}
if(dimensions=="2D"){

    for(int i=0;i<2;i++){
cout<<"[PointX"<<i<<"] : ";
cin>>x;
cout<<"[PointY"<<i<<"] : ";
cin>>y;
pts.push_back(x);
pts.push_back(y);
    }
length = sqrt(pow(pts[0]-pts[2],2)+pow(pts[1]-pts[3],2));
cout<<endl<<"Length is :"<<setprecision(5)<<length<<endl<<endl;
pts.clear();
}
if(dimensions=="3D"){

    for(int i=0;i<2;i++){
cout<<"[PointX"<<i<<"] : ";
cin>>x;
cout<<"[PointY"<<i<<"] : ";
cin>>y;
cout<<"[PointZ"<<i<<"] : ";
cin>>z;
pts.push_back(x);
pts.push_back(y);
pts.push_back(z);
    }
length = sqrt(pow(pts[0]-pts[3],2)+pow(pts[1]-pts[4],2)+pow(pts[2]-pts[5],2));
cout<<endl<<"Length is :"<<setprecision(5)<<length<<endl<<endl;
pts.clear();
}
}
int main()
{
    MainMenu();
}


