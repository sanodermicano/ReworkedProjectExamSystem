#pragma once
#include "main.h"
#include "Exams.h"
#include "User.h"
#include "Answers.h"



class Student : public User
{

public:
	Student();
	Student(string,string,string ,int,int);
	void setScore(int);
	void addScore(int s);
	int getScore();
private:
	//Answers *a; //keep or remove or change later
	int score_;
};