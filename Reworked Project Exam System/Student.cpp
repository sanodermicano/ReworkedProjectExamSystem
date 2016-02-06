#include "Student.h"


int Student::getScore()
{ 
	return score_;
} 

Student::Student()
{ 
	setAll("","","");
	setScore(0);
	//a=new Answers[20];
} //default constructor

Student::Student(string n,string ID,string p,int s,int ans)
{ 
	setAll(n,ID,p);
	setScore(s);
		//a=new Answers[ans];	
} //initializer

void Student::setScore(int s)
{
	score_=s;
}
void Student::addScore(int s) 
{
	score_+=s;
}