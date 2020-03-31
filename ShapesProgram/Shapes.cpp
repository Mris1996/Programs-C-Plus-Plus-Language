#include <iostream>

#include <stdio.h>

#include <string>

#include <math.h>

#include <fstream>

#include <string.h>

#include <sstream>

#include "Shapes.h"

#include <iomanip>

#include <bits/stdc++.h>

#include <stdlib.h>

#include <ctype.h>

#include <algorithm>



using namespace std;



a2StructClass sc;
vector<bool>containws;

vector<string>shapenames;

vector<string> reports;

vector<string> sortedreports;

vector<string> sortedreportsc;

vector<string>points;

vector<int>xaxis;

vector<int>yaxis;

vector<int> xaxisarea;

vector<int> yaxisarea;

int*circlex =  new int[shapenames.size()];

int*circley =  new int[shapenames.size()];

int* rad =  new int[sc.shapenumber];

int*squarex =  new int[shapenames.size()*4];

int*squarey =  new int[shapenames.size()*4];

int*crossx =  new int[shapenames.size()*12];

int*crossy =  new int[shapenames.size()*12];

int*rectanglex =  new int[shapenames.size()*4];

int*rectangley =  new int[shapenames.size()*4];

int* sqside = new int[sc.shapenumber];

int* side1 = new int[sc.shapenumber];

int* side2 = new int[sc.shapenumber];

int* sqr1ary = new int[sc.shapenumber];

int* sqr2ary = new int[sc.shapenumber];

int* sqr3ary = new int[sc.shapenumber];

int* sqr4ary = new int[sc.shapenumber];

int* bigareaary = new int[sc.shapenumber];

vector<vector<int> > Array2D( sc.Xaxis , vector<int> (sc.Xaxis));



class ShapeTwoD{//parent class with virtual functions

protected:

string name;

bool containsWarpSpace;

double area;

string point;

int shapenum =1;

int x;

int y;

public:

ShapeTwoD(){}

ShapeTwoD(string name,bool containsWarpSpace){

	setName(name);

	setContainWarpSpace(containsWarpSpace);

}



virtual string getName(){

      name[0] = toupper(name[0]);

	return name;

}

virtual void setName(string name){



this->name=name;



}

virtual bool getcontainsWarpSpace(){

	return containsWarpSpace;

}

virtual void setContainWarpSpace(bool containsWarpSpace){



this->containsWarpSpace = containsWarpSpace;

}



virtual string toString(){

	string returnstring;

	return returnstring;



}



virtual double computeArea(){

    return area;

}

virtual bool isPointInShape(int x,int y){

return false;

}

virtual bool isPointOnShape(int x,int y){

return false;

}



virtual void setPoints(){

this->point=point;

}

virtual string getPoints(){

return point;

}

virtual void setShapenum(int shapenum){

this->shapenum = shapenum;

}

virtual int getShapenum(){

return shapenum;

}

void sort(int n, int* ptr)

{

    int i, j, t;



    // Sort the numbers using pointers

    for (i = 0; i < n; i++) {



        for (j = i + 1; j < n; j++) {



            if (*(ptr + j) < *(ptr + i)) {



                t = *(ptr + i);

                *(ptr + i) = *(ptr + j);

                *(ptr + j) = t;

            }

        }

    }



}



};

class circle : public ShapeTwoD //subclass of s2d class , overrides virtual functions

{

protected:



    double radius;



public:

    circle(){};

    circle(double radius,string name,bool containsWarpSpace,string point,int shapenum){

    setRadius(radius);

    setName(name);

    setContainWarpSpace(containsWarpSpace);

    setPoints(point);

    setShapenum(shapenum);

    }

string getName(){

      name[0] = toupper(name[0]);

	return name;

}

void setName(string name){



this->name=name;



}

bool getcontainsWarpSpace(){

	return containsWarpSpace;

}

void setContainWarpSpace(bool containsWarpSpace){



this->containsWarpSpace = containsWarpSpace;

}



void setRadius(double radius){

this->radius = radius;



}

 double computeArea(){



     area =  3.14 * radius *  radius;

    return area;

}

void setShapenum(int shapenum){

this->shapenum = shapenum;

}

int getShapenum(){

return shapenum;

}

bool isPointInShape (int x , int y)

{

	int diameter = pow(radius, 2);

	int circle = pow(x - circlex[shapenum], 2) + pow(y - circley[shapenum], 2);



	if(circle < diameter)

	{

		return true;

	}



	return false;

}



bool isPointOnShape (int x , int y)

{

	int diameter = pow(radius, 2);

	int circle = pow(x - circlex[shapenum], 2) + pow(y - circley[shapenum], 2);



	if(circle == diameter)

	{

		return true;

	}



	return false;

}



void setPoints(string point){

this->point=point;

}

string getPoints(){

return point;

}



string toString(){



    int circlex1 = circlex[shapenum] - radius;

	int circlex2 = circlex[shapenum] + radius;

	int circley1 = circley[shapenum] - radius;

	int circley2 = circley[shapenum] + radius;



	for(int i = circlex1; i <= circlex2; i++)

	{

		for(int j = circley1; j <= circley2; j++)

		{

			if(circle::isPointOnShape(i,j)){

				sc.stream << ",(" << i << "," << j <<") ";

			}

		}

	}

    sc.pointsonshape = sc.stream.str();

     if(sc.pointsonshape.substr(0)==" "){

            sc.pointsonshape= "None!";

			}

	 sc.pointsonshape.erase(0,1);

    sc.stream.str("");

   for(int i = circlex1; i <= circlex2; i++)

	{

		for(int j = circley1; j <= circley2; j++)

		{

			if(circle::isPointInShape(i,j)){

				sc.stream << ", (" << i << "," << j <<")";

			}

		}

	}

	sc.pointsinshape = sc.stream.str();

     if(sc.pointsinshape.substr(0)==" "){

            sc.pointsinshape= " None!";

			}

	sc.pointsinshape.erase(0,1);

    sc.stream.str("");

     if(getcontainsWarpSpace() == true){

		sc.specialtype = "WS";

	}

	else if( getcontainsWarpSpace() == false){

		sc.specialtype = "NS";

    }

    sc.stream << fixed << setprecision(2) << area;

    string dblarea = sc.stream.str();

    sc.stream.str("");

    sc.stream << fixed << setprecision(0) << shapenum-1;

    string shapenumber = sc.stream.str();

    sc.stream.str("");

	string returnstring ="Shape["+ shapenumber +"] "+"\n"+"Name : "+getName()+"\n"+"Special Type : "+sc.specialtype+"\n"+"Area : "+ dblarea+" units square"+"\n"+"Center Points"+"\n"+getPoints()+"\n"+"\n"+"Points on perimeter :"+ sc.pointsonshape+"\n"+"\n"+"Points within shape :"+ sc.pointsinshape;

    reports.push_back(returnstring);

    sortedreports.push_back(dblarea+"             "+"\n"+returnstring);

    sortedreportsc.push_back(sc.specialtype+dblarea+"             "+"\n"+returnstring);

	return returnstring;

}



};

class square : public ShapeTwoD //subclass of s2d class , overrides virtual functions

{

protected:

double side1;

int* squarexshapenum =  new int[4];

int* squareyshapenum =  new int [4];

public:

    square(){};

    square(int side1,string name,bool containsWarpSpace,string point,int shapenum){

		setSides(side1);

		setName(name);

		setContainWarpSpace(containsWarpSpace);

        setPoints(point);

        setShapenum(shapenum);





}

void setShapenum(int shapenum){

this->shapenum = shapenum;

}

int getShapenum(){

return shapenum;

}

double getSide1(){



        return side1;

    }

double computeArea(){



     area = side1 * side1;

    return area;

}



string getName(){

      name[0] = toupper(name[0]);

	return name;

}

void setName(string name){



this->name=name;



}

bool getcontainsWarpSpace(){

	return containsWarpSpace;

}

void setContainWarpSpace(bool containsWarpSpace){



this->containsWarpSpace = containsWarpSpace;

}

void setSides(int side1){

this->side1 = side1;



}

void setPoints(string point){

this->point=point;

}

string getPoints(){

return point;

}



bool isPointOnShape(int x, int y){



		if(x > squarexshapenum[0] &&  x < squarexshapenum[3] ){

            if(y == squareyshapenum[3]|| y == squareyshapenum[0]){

                return true;

           }

		}

		if(y > squareyshapenum[0] &&  y < squareyshapenum[3] ){

            if(x == squarexshapenum[3]|| x == squarexshapenum[0]){

                return true;

           }

		}

		return false;

}

bool isPointInShape(int x, int y)

{

	if( x < squarexshapenum[3]&& x > squarexshapenum[0] && y < squareyshapenum[3]&& y >squareyshapenum[0])

	{

		return true;

	}

	return false;

}



string toString(){



     if(getcontainsWarpSpace() == true){

		sc.specialtype = "WS";

	}

	else if( getcontainsWarpSpace() == false){

		sc.specialtype = "NS";

    }

    sc.stream << fixed << setprecision(2) << area;

    string dblarea = sc.stream.str();

    sc.stream.str("");



      sc.stream << fixed << setprecision(0) << shapenum-1;

    string shapenumber = sc.stream.str();

    sc.stream.str("");

	for(int i =0;i<4;i++){



    squarexshapenum[i] = squarex[(shapenum*8)+i];

    squareyshapenum[i] = squarey[(shapenum*8)+i];



    }



    sort(4, squarexshapenum);

    sort(4, squareyshapenum);


    int squarex1 = squarexshapenum[0];

    int squarex2 = squarexshapenum[3];

    int squarey1 = squareyshapenum[0];

    int squarey2 = squareyshapenum[3];



for(int i = squarex1; i <= squarex2; i++)

	{

		for(int j = squarey1; j <= squarey2; j++)

		{

			if(square::isPointOnShape(i,j)){

				sc.stream << ", (" << i << "," << j <<")";

			}

		}

	}

    sc.pointsonshape = sc.stream.str();

     if(sc.pointsonshape.substr(0)==""){

            sc.pointsonshape= " None!";

			}

	 sc.pointsonshape.erase(0,1);

    sc.stream.str("");

   for(int i = squarex1; i <= squarex2; i++)

	{

		for(int j = squarey1; j <= squarey2; j++)

		{

			if(square::isPointInShape(i,j)){

				sc.stream << ", (" << i << "," << j <<")";

			}

		}

	}
	sc.pointsinshape = sc.stream.str();

	   if(sc.pointsinshape.substr(0)==""){

            sc.pointsinshape= " None!";

			}

	 sc.pointsinshape.erase(0,1);

    sc.stream.str("");





	string returnstring = "Shape["+ shapenumber +"] "+"\n"+"Name : "+getName()+"\n"+"Special Type : "+sc.specialtype+"\n"+"Area : "+ dblarea+" units square"+"\n"+"Vertices"+"\n"+getPoints()+"\n"+"\n"+"Points on perimeter :"+ sc.pointsonshape+"\n"+"\n"+"Points within shape :"+ sc.pointsinshape;



    reports.push_back(returnstring);

    sortedreports.push_back(dblarea+"             "+"\n"+returnstring);

    sortedreportsc.push_back(sc.specialtype+dblarea+"             "+"\n"+returnstring);



	return returnstring;

}

     

};

class rectangle : public ShapeTwoD //subclass of s2d class , overrides virtual functions

{

protected:

double side1;

double side2;

int* rectanglexshapenum =  new int[4];

int* rectangleyshapenum =  new int [4];



public:

    rectangle(){};

    rectangle(int side1,int side2,string name,bool containsWarpSpace,string point,int shapenum){

		setSides(side1,side2);

		setName(name);

		setContainWarpSpace(containsWarpSpace);

        setPoints(point);

        setShapenum(shapenum);

             for(int i =0;i<4;i++){

    rectanglexshapenum[i] = rectangley[i+shapenum*4];

    rectangleyshapenum[i] = rectanglex[i+shapenum*4];

    }
 	sort(4, rectanglexshapenum);

    	sort(4, rectangleyshapenum);





}



double getSide1(){



    return side1;

    }

double computeArea(){



    area = side1 * side2;

    return area;

}

string getName(){

      name[0] = toupper(name[0]);

	return name;

}

void setName(string name){

    this->name=name;

}

bool getcontainsWarpSpace(){

	return containsWarpSpace;

}

void setContainWarpSpace(bool containsWarpSpace){

    this->containsWarpSpace = containsWarpSpace;

}



void setSides(int side1,int side2){

    this->side1 = side1;

    this->side2 = side2;

}

void setPoints(string point){

    this->point=point;

}

string getPoints(){

    return point;

}

void setShapenum(int shapenum){

    this->shapenum = shapenum;

}

int getShapenum(){

    return shapenum;

}

bool isPointOnShape(int x, int y){

		if(x > rectanglexshapenum[0] &&  x < rectanglexshapenum[3] ){

            if(y == rectangleyshapenum[3]|| y == rectangleyshapenum[0]){

                return true;

           }

		}

		if(y > rectangleyshapenum[0] &&  y < rectangleyshapenum[3] ){

            if(x == rectanglexshapenum[3]|| x == rectanglexshapenum[0]){

                return true;

           }

		}

    return false;

}

bool isPointInShape(int x, int y)

{

	if( x < rectanglexshapenum[3]&& x > rectanglexshapenum[0] && y < rectangleyshapenum[3]&& y >rectangleyshapenum[0])

	{

		return true;

	}



    return false;

}

string toString(){

     if(getcontainsWarpSpace() == true){

		sc.specialtype = "WS";

	}

	else if( getcontainsWarpSpace() == false){

		sc.specialtype = "NS";

    }

    sc.stream << fixed << setprecision(2) << area;

    string dblarea = sc.stream.str();

    sc.stream.str("");



      sc.stream << fixed << setprecision(0) << shapenum-1;

    string shapenumber = sc.stream.str();

    sc.stream.str("");

    int rectanglex1 = rectanglexshapenum[0];

    int rectanglex2 = rectanglexshapenum[3];

    int rectangley1 = rectangleyshapenum[0];

    int rectangley2 = rectangleyshapenum[3];



    for(int i = rectanglex1; i <= rectanglex2; i++)

	{

		for(int j = rectangley1; j <= rectangley2; j++)

		{

			if(rectangle::isPointOnShape(i,j)){

				sc.stream << ", (" << i << "," << j <<")";

			}

		}

	}

    sc.pointsonshape = sc.stream.str();

     if(sc.pointsonshape.substr(0)==""){

            sc.pointsonshape= " None!";

			}

	 sc.pointsonshape.erase(0,1);

    sc.stream.str("");

   for(int i = rectanglex1; i <= rectanglex2; i++)

	{

		for(int j = rectangley1; j <= rectangley2; j++)

		{

			if(rectangle::isPointInShape(i,j)){

				sc.stream << ", (" << i << "," << j <<")";

			}

		}

	}

	sc.pointsinshape = sc.stream.str();

	   if(sc.pointsinshape.substr(0)==""){

            sc.pointsinshape= " None!";

			}

    sc.pointsinshape.erase(0,1);

    sc.stream.str("");





	string returnstring = "Shape["+ shapenumber +"] "+"\n"+"Name : "+getName()+"\n"+"Special Type : "+sc.specialtype+"\n"+"Area : "+ dblarea+" units rectangle"+"\n"+"Vertices"+"\n"+getPoints()+"\n"+"\n"+"Points on perimeter :"+ sc.pointsonshape+"\n"+"\n"+"Points within shape :"+ sc.pointsinshape;



    reports.push_back(returnstring);

    sortedreports.push_back(dblarea+"             "+"\n"+returnstring);

    sortedreportsc.push_back(sc.specialtype+dblarea+"             "+"\n"+returnstring);

   

	return returnstring;

}



};

class cross : public ShapeTwoD //subclass of s2d class , overrides virtual functions

{

protected:

int square1;

int square2;

int square3;

int square4;

int bigsquarearea;

int* crossxshapenum =  new int[12];

int* crossyshapenum =  new int [12];

public:

    cross(){};

    cross(int square1,int square2,int square3 , int square4,int bigsquarearea,string name,bool containsWarpSpace,string point,int shapenum){

		setSides(square1,square2,square3,square4,bigsquarearea);

		setName(name);

		setContainWarpSpace(containsWarpSpace);

		setPoints(point);

		setShapenum(shapenum);

    for(int i =0;i<12;i++){

    crossxshapenum[i] =crossx[i+shapenum*12];

    crossyshapenum[i] =crossy[i+shapenum*12];

}
	sort(12,crossxshapenum);
	sort(12,crossyshapenum);


}

double computeArea(){



     int allsqarea = square1+square2+square3+square4;

     area = bigsquarearea - allsqarea;

    return area;

}

string getName(){

      name[0] = toupper(name[0]);

	return name;

}

void setName(string name){



this->name=name;

}

bool getcontainsWarpSpace(){

	return containsWarpSpace;

}

void setContainWarpSpace(bool containsWarpSpace){



this->containsWarpSpace = containsWarpSpace;

}

void setSides(int square1,int square2,int square3 , int square4,int bigsquarearea){

this->square1=square1;

this->square2=square2;

this->square3=square3;

this->square4=square4;

this->bigsquarearea=bigsquarearea;

}



void setPoints(string point){

this->point=point;

}

string getPoints(){

return point;

}

void setShapenum(int shapenum){

this->shapenum = shapenum;

}

int getShapenum(){

return shapenum;

}

bool isPointOnShape(int x, int y){

    if(x > crossxshapenum[0] &&  x < crossxshapenum[2] ){

             if(y==crossyshapenum[2]||y==crossyshapenum[6]){

                return true;

           }

		}

 if(x == crossxshapenum[0] ){

             if(y>crossyshapenum[2]&&y<crossyshapenum[6]){

                return true;

           }

		}



    if(x > crossxshapenum[6] &&  x < crossxshapenum[10] ){

             if(y==crossyshapenum[2]||y==crossyshapenum[6]){

                return true;

           }

		}

    if(x == crossxshapenum[11] ){

             if(y>crossyshapenum[2]&&y<crossyshapenum[6]){

                return true;

           }

		}

    if(x > crossxshapenum[2] &&  x < crossxshapenum[6] ){

              if(y==crossyshapenum[0]||y==crossyshapenum[11]){

                return true;

           }

		}

    if(x == crossxshapenum[2] ||  x == crossxshapenum[6] ){

             if(y>crossyshapenum[0]&&y<crossyshapenum[2]){

                return true;

           }

		}

		 if(x == crossxshapenum[2] ||  x == crossxshapenum[6] ){

             if(y>crossyshapenum[6]&&y<crossyshapenum[11]){

                return true;

           }

		}

    return false;

}

bool isPointInShape(int x, int y)

{

    if(x > crossxshapenum[0] &&  x <crossxshapenum[2] ){

             if(y>crossyshapenum[2]&&y<crossyshapenum[6]){

                return true;

           }

		}

	if(x > crossxshapenum[2] &&  x <crossxshapenum[6] ){

             if(y>crossyshapenum[0]&&y<crossyshapenum[11]){

                return true;

           }

		}

    if(x == crossxshapenum[2] ||  x ==crossxshapenum[6] ){

             if(y>crossyshapenum[2]&&y<crossyshapenum[6]){

                return true;

           }

		}



	if(x > crossxshapenum[6] &&  x <crossxshapenum[11] ){

             if(y>crossyshapenum[2]&&y<crossyshapenum[6]){

                return true;

           }

		}

    return false;

}

string toString(){

    if(getcontainsWarpSpace() == true){

		sc.specialtype = "WS";

	}

	else if( getcontainsWarpSpace() == false){

		sc.specialtype = "NS";

    }



    int crossx1 = crossxshapenum[0];

    int crossx2 = crossxshapenum[3];

    int crossy1 = crossyshapenum[0];

    int crossy2 = crossyshapenum[3];



    for(int i = crossx1; i <= crossx2; i++)

	{

		for(int j = crossy1; j <= crossy2; j++)

		{

			if(cross::isPointOnShape(i,j)){

				sc.stream << ", (" << i << "," << j <<") ";

			}

		}

	}

    sc.pointsonshape = sc.stream.str();

     if(sc.pointsonshape.substr(0)==""){

            sc.pointsonshape= " None!";

			}

	 sc.pointsonshape.erase(0,1);

    sc.stream.str("");

   for(int i = crossx1; i <= crossx2; i++)

	{

		for(int j = crossy1; j <= crossy2; j++)

		{

			if(cross::isPointInShape(i,j)){

				sc.stream << ", (" << i << "," << j <<")";

			}

		}

	}

	sc.pointsinshape = sc.stream.str();

	   if(sc.pointsinshape.substr(0)==""){

            sc.pointsinshape= " None!";

			}

    sc.pointsinshape.erase(0,1);



    sc.stream << fixed << setprecision(2) << area;

    string dblarea = sc.stream.str();

    sc.stream.str("");



      sc.stream << fixed << setprecision(0) << shapenum-1;

    string shapenumber = sc.stream.str();

    sc.stream.str("");



	string returnstring = "Shape["+ shapenumber +"] "+"\n"+"Name : "+getName()+"\n"+"Special Type : "+sc.specialtype+"\n"+"Area : "+ dblarea+" units cross"+"\n"+"Vertices"+"\n"+getPoints()+"\n"+"\n"+"Points on perimeter :"+ sc.pointsonshape+"\n"+"\n"+"Points within shape :"+ sc.pointsinshape;



    reports.push_back(returnstring);

    sortedreports.push_back(dblarea+"             "+"\n"+returnstring);

    sortedreportsc.push_back(sc.specialtype+dblarea+"             "+"\n"+returnstring);

   

	return returnstring;

}

};

void A2D(int y){//computes string to display points



 int x=0;

    for (int i = 0; i < sc.Xaxis; i++)

	{

		for (int j = 0; j < sc.Yaxis; j++)

		{

			if(Array2D[i][j]==y)

            {

                sc.stream<<"Point["<<x<<"] : ("<<i<<", "<<j<<")"<<endl;

                x++;

            }

		}

	}

sc.verticesstr = sc.stream.str();

sc.stream.str("");

points.push_back(sc.verticesstr);

}

void inputdata(){//collects data from user and computes area

int x,y;

cout<<"Please enter name of shape(Square/Rectangle/Cross/Circle):";

inputshape();

cout<<"Please enter special type:";

inputws();

if(sc.shapenamesc != "circle"){

   for(int i =1; i <sc.shapepts+1;i++){

        cout<<"Pleas enter x-ordinate of pt."<<i<<": ";

        cin>>x;

        cout<<"Pleas enter y-ordinate of pt."<<i<<": ";

        cin>>y;

        Array2D[x][y] = sc.shapenumber;

        xaxis.push_back(x);

        yaxis.push_back(y);

    }

      A2D(sc.shapenumber);

}

else if(sc.shapenamesc == "circle"){

		cout<<"Pleas enter x-ordinate of center : ";

		cin>>x;

		cout<<"Pleas enter y-ordinate of center : ";

		cin>>y;

		cout<<"Please enter radius(units) : ";

		cin>>sc.radius;

        Array2D[x][y] = sc.shapenumber;

        A2D(sc.shapenumber);

        rad[sc.shapenumber]=sc.radius;

        circlex[sc.shapenumber]=x;

        circley[sc.shapenumber]=y;

}

cout<<endl;

     if(sc.shapenamesc == "square"){

        for(int i =0 ; i < sc.shapepts-1; i++){



                for(int i = 0;i<4;i++){

                xaxisarea.push_back(xaxis[i]);

                yaxisarea.push_back(yaxis[i]);

        }

        if(xaxisarea[i+1]>xaxisarea[i]){

            sc.side1=xaxisarea[i+1]-xaxisarea[i];

        }



    }

    for(int i = 0;i<4;i++){

        squarex[i+sc.shapenumber*8]=xaxis[i];

        squarey[i+sc.shapenumber*8]=yaxis[i];

    }

     sqside[sc.shapenumber]=sc.side1;

	}

	else if(sc.shapenamesc == "rectangle"){

      for(int i =0 ; i < sc.shapepts-1; i++){



          for(int i = 0;i<4;i++){

          xaxisarea.push_back(xaxis[i]);

          yaxisarea.push_back(yaxis[i]);



    }

        if(xaxisarea[i+1]>xaxisarea[i]){

            sc.side1=xaxisarea[i+1]-xaxisarea[i];



        }

        if(yaxisarea[i+1]>yaxisarea[i]){

            sc.side2=yaxisarea[i+1]-yaxisarea[i];

        }

    }

     for(int i = 0;i<4;i++){

        rectanglex[i+sc.shapenumber*8]=xaxis[i];

        rectangley[i+sc.shapenumber*8]=yaxis[i];



    }

     side1[sc.shapenumber]=sc.side1;

     side2[sc.shapenumber]=sc.side2;

	}

    else if(sc.shapenamesc== "cross"){

            for(int i = 0;i<12;i++){

                xaxisarea.push_back(xaxis[i]);

                yaxisarea.push_back(yaxis[i]);

                }

             for(int i =0 ; i < 12; i++){

             for(int j =0 ; j < 12; j++){

                    if(xaxisarea[j]>xaxisarea[i]){

                    swap(xaxisarea[i],xaxisarea[j]);

                    }

                }

            }



             for(int i =0 ; i < 12; i++){

             for(int j =0 ; j < 12; j++){

                if(yaxisarea[j]>yaxisarea[i]){

                    swap(yaxisarea[i],yaxisarea[j]);

                    }

                }

            }

vector<int>emptyarray;

sc.sidex1=xaxisarea[11]-xaxisarea[9];

sc.sidex2=xaxisarea[10]-xaxisarea[7];

sc.sidex3=xaxisarea[5]-xaxisarea[1];

sc.sidex4=xaxisarea[3]-xaxisarea[0];

sc.sidey1=yaxisarea[11]-yaxisarea[9];

sc.sidey2=yaxisarea[10]-yaxisarea[7];

sc.sidey3=yaxisarea[5]-yaxisarea[1];

sc.sidey4=yaxisarea[3]-yaxisarea[0];



for(int i =0 ; i < 12; i++){

    if(xaxisarea[9]==xaxis[i]){

            emptyarray.push_back(i);

    }

}

for(int i =0 ; i < emptyarray.size(); i++){

for(int j =0 ; j < emptyarray.size(); j++){

        if(emptyarray[j]>emptyarray[i]){

        swap(emptyarray[i],emptyarray[j]);

        }

 }

    }

    if(yaxis[emptyarray[emptyarray.size()-2]]==yaxisarea[9]){

        sc.sq1 = sc.sidex1*sc.sidey1;

        emptyarray.clear();

        for(int i =0 ; i < 12; i++){

        if(yaxisarea[7]==yaxis[i]){

             emptyarray.push_back(i);

        }

        }

              for(int i =0 ; i < emptyarray.size(); i++){

                for(int j =0 ; j < emptyarray.size(); j++){

                    if(emptyarray[j]>emptyarray[i]){

                    swap(emptyarray[i],emptyarray[j]);

                        }

                    }

                }

             if(xaxis[emptyarray[emptyarray.size()-2]]==xaxisarea[6]){

                    sc.sq2=sc.sidex3*sc.sidey2;

                   emptyarray.clear();

                  for(int i =0 ; i < 12; i++){

                    if(yaxisarea[5]==yaxis[i]){

                    emptyarray.push_back(i);

                    }

                    }

                    for(int i =0 ; i < emptyarray.size(); i++){

                for(int j =0 ; j < emptyarray.size(); j++){

                    if(emptyarray[j]>emptyarray[i]){

                    swap(emptyarray[i],emptyarray[j]);

                        }

                    }

                }

                 if(xaxis[emptyarray[emptyarray.size()-2]]==xaxisarea[3]){

                        emptyarray.clear();

                        sc.sq3=sc.sidex4*sc.sidey3;

                        sc.sq4=sc.sidex2*sc.sidey4;



                 }

                 else{

                      emptyarray.clear();

                      sc.sq3=sc.sidex4*sc.sidey4;

                      sc.sq4=sc.sidex2*sc.sidey3;

                 }

             }

             else{

                sc.sq2=sc.sidex4*sc.sidey2;

                     emptyarray.clear();

                  for(int i =0 ; i < 12; i++){

                    if(yaxisarea[5]==yaxis[i]){

                    emptyarray.push_back(i);

                    }

                    }

                    for(int i =0 ; i < emptyarray.size(); i++){

                for(int j =0 ; j < emptyarray.size(); j++){

                    if(emptyarray[j]>emptyarray[i]){

                    swap(emptyarray[i],emptyarray[j]);

                        }

                    }

                }

                 if(xaxis[emptyarray[emptyarray.size()-2]]==xaxisarea[3]){

                        sc.sq3=sc.sidex4*sc.sidey3;

                        sc.sq4=sc.sidex2*sc.sidey4;

                 }

                 else{

                      sc.sq3=sc.sidex4*sc.sidey4;

                      sc.sq4=sc.sidex2*sc.sidey3;

                 }

             }

            }

    else{

        emptyarray.clear();

        sc.sq1 = sc.sidex1*sc.sidey2;

        for(int i =0 ; i < 12; i++){

        if(yaxisarea[7]==yaxis[i]){

             emptyarray.push_back(i);

        }

        }

              for(int i =0 ; i < emptyarray.size(); i++){

                for(int j =0 ; j < emptyarray.size(); j++){

                    if(emptyarray[j]>emptyarray[i]){

                    swap(emptyarray[i],emptyarray[j]);

                        }

                    }

                }

             if(xaxis[emptyarray[emptyarray.size()-2]]==xaxisarea[6]){

                    sc.sq2=sc.sidex3*sc.sidey2;

                   emptyarray.clear();

                  for(int i =0 ; i < 12; i++){

                    if(yaxisarea[5]==yaxis[i]){

                    emptyarray.push_back(i);

                    }

                    }

                    for(int i =0 ; i < emptyarray.size(); i++){

                for(int j =0 ; j < emptyarray.size(); j++){

                    if(emptyarray[j]>emptyarray[i]){

                    swap(emptyarray[i],emptyarray[j]);

                        }

                    }

                }

                 if(xaxis[emptyarray[emptyarray.size()-2]]==xaxisarea[3]){

                        emptyarray.clear();

                        sc.sq3=sc.sidex4*sc.sidey3;

                        sc.sq4=sc.sidex2*sc.sidey4;

                 }

                 else{

                      emptyarray.clear();

                      sc.sq3=sc.sidex4*sc.sidey4;

                      sc.sq4=sc.sidex2*sc.sidey3;

                 }

             }

             else{

                sc.sq2=sc.sidex4*sc.sidey2;

                 emptyarray.clear();

                  for(int i =0 ; i < 12; i++){

                    if(yaxisarea[5]==yaxis[i]){

                    emptyarray.push_back(i);

                    }

                    }

                    for(int i =0 ; i < emptyarray.size(); i++){

                for(int j =0 ; j < emptyarray.size(); j++){

                    if(emptyarray[j]>emptyarray[i]){

                    swap(emptyarray[i],emptyarray[j]);

                        }

                    }

                }

                 if(xaxis[emptyarray[emptyarray.size()-2]]==xaxisarea[3]){

                        emptyarray.clear();

                        sc.sq3=sc.sidex4*sc.sidey3;

                        sc.sq4=sc.sidex2*sc.sidey4;



                 }

                 else{

                      emptyarray.clear();

                      sc.sq3=sc.sidex4*sc.sidey4;

                      sc.sq4=sc.sidex2*sc.sidey3;

                 }

             }



        }

    for(int i = 0;i<12;i++){

       crossx[i+sc.shapenumber*24]=xaxis[i];

        crossy[i+sc.shapenumber*24]=yaxis[i];



    }

    sc.bigareaside1 = xaxisarea[11]-xaxisarea[0];

    sc.bigareaside2 = yaxisarea[11]-yaxisarea[0];

    sc.bigarea = sc.bigareaside1*sc.bigareaside2;

    sqr1ary[sc.shapenumber]=sc.sq1;

    sqr2ary[sc.shapenumber]=sc.sq2;

    sqr3ary[sc.shapenumber]=sc.sq3;

    sqr4ary[sc.shapenumber]=sc.sq4;

    bigareaary[sc.shapenumber]=sc.bigarea;

	}



	xaxisarea.clear();

	yaxisarea.clear();

    yaxis.clear();

    xaxis.clear();

    sc.shapenumber++;

    cout<<"Record successfully stored.Going back to main menu..."<<endl<<endl;

    MainMenu();

}

void inputshape(){//assists in collecting shape name data from user

cin>>sc.shapenamesc;



     if(sc.shapenamesc == "square"){

		sc.shapepts = 4;

	}

	else if(sc.shapenamesc == "rectangle"){

		sc.shapepts = 4;



	}

	else if(sc.shapenamesc== "cross"){

		sc.shapepts = 12;



	}

	else if(sc.shapenamesc == "circle"){

	}

    else{

	cout<<"Incorrect data ,please enter name of shape again:";

    	   inputshape();

	}

shapenames.push_back(sc.shapenamesc);



}

void inputws(){//assists in collecting special type data from user

	cin>>sc.containwarpspacesc;

	if(sc.containwarpspacesc == "ws"){

       sc.warp = true;

	}

	else if(sc.containwarpspacesc == "ns"){

         sc.warp = false;

	}

	else{

	  cout<<"Incorrect data , please enter special type again:";

       inputws();

	}

    containws.push_back(sc.warp);

}

void computearea(){//does dynamic binding and polymorphism to compute area and other computations



if(shapenames.size()<2){

        cout<<"Input data first!"<<endl;

        cout<<endl;

        MainMenu();

}

else{

for(int i=1;i<shapenames.size();i++){



    if(shapenames[i]=="circle"){

         circle circ(rad[i],shapenames[i],containws[i],points[i],i);

            ShapeTwoD * s2dci = &circ;

            s2dci->computeArea();

            s2dci->toString();

    }

    else if(shapenames[i]=="square"){

            square sqr(sqside[i],shapenames[i],containws[i],points[i],i);

            ShapeTwoD * s2dsq = &sqr;

            s2dsq->computeArea();

            s2dsq->toString();

    }

    else if(shapenames[i]=="rectangle"){

            rectangle rect(side1[i],side2[i],shapenames[i],containws[i],points[i],i);

            ShapeTwoD * s2dre = &rect;

            s2dre->computeArea();

            s2dre->toString();

    }

    else if(shapenames[i]=="cross"){

            cross cross(sqr1ary[i],sqr2ary[i],sqr3ary[i],sqr4ary[i],bigareaary[i],shapenames[i],containws[i],points[i],i);

            ShapeTwoD * s2dcr = &cross;

            s2dcr->computeArea();

            s2dcr->toString();

    }

    sc.entry =0;

}

cout<<"Computation completed! ("<<shapenames.size()-1<<" records were updated)"<<endl;

cout<<endl;

MainMenu();

}

}

void printreports(){//displays strings of reports

cout<<"Total no. of records available = "<<shapenames.size()-1<<endl;

cout<<endl;



    if(reports.size()<2){

        cout<<"Compute area first!"<<endl;

        cout<<endl;

        MainMenu();

    }

    else{   if(sc.entry == 0){



            sortinga();

            sortingd();

            sortingc();

            }



            for (int j = 1; j < shapenames.size(); j++)

            {

                cout<<reports[j]<<endl<<endl;

            }



            cout<<endl;

            sc.entry ++;

    }

}

void sortinga(){//sorts reports by ascending area

    sort(sortedreports.begin(), sortedreports.end(), ascend);

 for (int j = 0; j < sortedreports.size(); j++)

            {

                sortedreports[j].erase(0,10);

            }

            for (int j = 0; j < sortedreports.size(); j++)

            {

                 sc.stream<<sortedreports[j]<<endl;

            }



          sc.ascend = sc.stream.str();

            sc.stream.str("");



}

void sortingd(){//sorts reports by descending area

 reverse(sortedreports.begin(),sortedreports.end());

     for (int j = 0; j < sortedreports.size(); j++)

            {

                 sc.stream<<sortedreports[j]<<endl;

            }



         sc.descend = sc.stream.str();

            sc.stream.str("");



}

void sortingc(){//sorts reports by descending specialtype then descending area 



sort(sortedreportsc.begin(), sortedreportsc.end(), greater<string>());

vector<string>ws;

vector<string>ns;

for (int j = 0; j < sortedreportsc.size(); j++)

            {



                if(sortedreportsc[j].substr(0,2)=="WS"){

                    ws.push_back(sortedreportsc[j]);

                }

                else if(sortedreportsc[j].substr(0,2)=="NS"){

                    ns.push_back(sortedreportsc[j]);

                }

            }

            for (int j = 0; j < ws.size(); j++)

            {

              ws[j].erase(0,2);

            }

             for (int j = 0; j < ns.size(); j++)

            {

              ns[j].erase(0,2);

            }



            sort(ws.begin(), ws.end(), descend);

            sort(ns.begin(), ns.end(), descend);

            for (int j = 0; j < ws.size(); j++)

            {

                ws[j].erase(0,10);

            }

            for (int j = 0; j < ns.size(); j++)

            {

                ns[j].erase(0,10);

            }

            for (int j = 0; j < ws.size(); j++)

            {

                 sc.stream<<ws[j]<<endl;

            }

            string wstemp = sc.stream.str();

            sc.stream.str("");

            for (int j = 0; j < ns.size(); j++)

            {

                 sc.stream<<ns[j]<<endl;

            }

            string nstemp = sc.stream.str();

            sc.stream.str("");

            sc.standarea = wstemp+nstemp;

}

void sorterfunc(){//sort menu function that is being displayed to users

if(shapenames.size()<2){

    cerr<<"Input at least 2 data of shapes!"<<endl;

}

else{

char x;

cout<<" a)    Sort by area(ascending)"<<endl;

cout<<" b)    Sort by area(descending)"<<endl;

cout<<" c)    Sort by special type and area"<<endl;

cout<<endl<<"Please select sort option('q' to go main menu) : ";

cin>>x;

cout << endl;

	if (x == 'a')

	{



            cout<<"Sort by area (smallest to largest)..."<<endl<<sc.ascend;

	}



    else if (x == 'b')

    {



            cout<<"Sort by area (largest to smallest)..."<<endl<<sc.descend;





	}

	else if (x == 'c')

	{

            cout<<"Sort by special type and area (Warp Space first! then largest to smallest)..."<<endl<<sc.standarea;

	}

	else if (x == 'q')

    {

        MainMenu();

    }

	else{

        cerr << "Please pick either a,b,c or q" << endl<<endl;

        sorterfunc();

	}



}

}

void MainMenu(){//first thing displayed to user upon execution of code



	int choice;

	for(int inf = 1; inf < inf+1;inf++){

	

		cout << "------------------------------------" << endl;

		cout << "Welcome to Shapes program" << endl << endl;

		cout << "1)	Input sensor data" << endl;

		cout << "2)	Compute area (for all records)" << endl;

		cout << "3)	Print shapes report" << endl;

		cout << "4)	Sort shapes data" << endl;

		cout << "Please enter your choice : ";

	if(!(cin>>choice))

	{

		cerr << "Please pick a number between 1 and 4" << endl;

		cin.clear();

	  	 cin.ignore(8, '\n');

	}

	cout << endl;

	if (choice == 1)

	{

	inputdata();

	}

	if (choice == 2)

	{

	    computearea();



	}

	if (choice == 3)

	{

        printreports();

	}

	if (choice == 4)

	{

        sorterfunc();

	}

	if(choice<=0||choice>=5)

	 {

		MainMenu();

     }

	}

}

bool is_not_digit(char c){

    return !isdigit(c);

}

bool ascend(const string& s1, const string& s2){

   
    string::const_iterator it1 = s1.begin(), it2 = s2.begin();



    if (isdigit(s1[0]) && isdigit(s2[0])) {

        int n1, n2;

        stringstream ss(s1);

        ss >> n1;

        ss.clear();

        ss.str(s2);

        ss >> n2;



        if (n1 != n2) return n1 < n2;



        it1 = find_if(s1.begin(), s1.end(), is_not_digit);

        it2 = find_if(s2.begin(), s2.end(), is_not_digit);

    }



    return lexicographical_compare(it1, s1.end(), it2, s2.end());

}

bool descend(const string& s1, const string& s2){

 

    string::const_iterator it1 = s1.begin(), it2 = s2.begin();



    if (isdigit(s1[0]) && isdigit(s2[0])) {

        int n1, n2;

        stringstream ss(s1);

        ss >> n1;

        ss.clear();

        ss.str(s2);

        ss >> n2;



        if (n1 != n2) return n1 > n2;



        it1 = find_if(s1.begin(), s1.end(), is_not_digit);

        it2 = find_if(s2.begin(), s2.end(), is_not_digit);

    }



    return lexicographical_compare(it1, s1.end(), it2, s2.end());

}



int main(){

    reports.push_back("empty");

    sortedreports.push_back("empty");

    shapenames.push_back("empty");

    containws.push_back(true);

    points.push_back("empty");

    circlex[0]=0;

    circley[0]=0;

    for(int i =0; i < 8;i++){

        squarex[i]=0;

        squarey[i]=0;

        rectanglex[i]=0;

        rectangley[i]=0;

    }

     for(int i =0; i <24;i++){

        crossx[i]=0;

        crossy[i]=0;

    }



    MainMenu();

	return 0;

}

