#pragma once
#include "main.h"
#include "Questions.h"

class Multiple : public Questions
{
public:
	Multiple();
	Multiple(string answer1, string answer2, string answer3, int rightAns);
	void setAnswer(string answer1, string answer2, string answer3, int rightAns);
	string getAnswer(int rightAns);
	string getSAnswer();
	string getAnswer1();
	string getAnswer2();
	string getAnswer3();
	string getAllAnswers();
	int getRightAns();
	void newQuestionMul(string Qtext, string answer1, string answer2, string answer3, int rightAns, short Qgrade, short Qpentality);
	~Multiple();
private:
	int rightAnswer_;
	string answer1_;
	string answer2_;
	string answer3_;
	string Sanswer_;
};