#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

string operator+(std::string const &a, int b);
void seperate(string text);

class Tools 
{
private:
	ifstream inFile;
public:
	void initialize();
	void resetAll();
	void resetQuestions();
	void getNumberOfAnswers(string a);
	void getAnswers(string x);
	void recieveANStext(string file, string *x);//new
	void sendto(string file);
	void sendto(string file,int x);
	void sendto(string file,double x);
	void sendto(string file,string x);
	void sendto(string file,char x);
	void sendto(string file,bool x);
	void sendto(string file,int x,char command);
	void sendto(string file,double x,char command);
	void sendto(string file,string x,char command);
	void sendto(string file,char x,char command);
	void sendto(string file,bool x,char command);
	void sendto(int x, string file);
	static double getAvg(Student[], int);  // quoted by hassan $_$
	static void TheStudentsInformation(Student[], int);
	int recieveFromInt(string file);
	double recieveFromDouble(string file);
	string recieveFromString(string file);//recieveWholefile(string file);
	char recieveFromChar(string file);
	bool recieveFromBool(string file);
	void recieveQtext(string file,string *x,int max);
	string recieveWholefile(string file);

	bool collision(float x, float y, float ex, float ey, float width, float height);
};