#include "Multiple.h"



Multiple::Multiple()
{
	answer1_ = "";
	answer2_ = "";
	answer3_ = "";
}

Multiple::Multiple(string answer1, string answer2, string answer3, int rightAns)
{
	answer1_ = "";
	answer2_ = "";
	answer3_ = "";
	setAnswer(answer1,answer2,answer3,rightAns);
}

void Multiple::setAnswer(string answer1,string answer2,string answer3 ,int rightAns)
{
	rightAnswer_=rightAns;
	answer1_= answer1;
	answer2_ = answer2;
	answer3_ = answer3;
	if (rightAns == 1) Sanswer_ = answer1;
	if (rightAns == 2) Sanswer_ = answer2;
	if (rightAns == 3) Sanswer_ = answer3;
}


string Multiple::getAnswer(int rightAns)
{
	if (rightAns == 1) return answer1_;
	if (rightAns == 2) return answer2_;
	if (rightAns == 3) return answer3_;
	return "";
}

string Multiple::getSAnswer(){ return Sanswer_;}

string Multiple::getAnswer1()
{
	return answer1_;
}

string Multiple::getAnswer2()
{
	return answer2_;
}

string Multiple::getAnswer3()
{
	return answer3_;
}

string Multiple::getAllAnswers()
{
	string temp = answer1_ + "\n" + answer2_ + "\n"+answer3_;
	return temp;
}

int Multiple::getRightAns()
{
	return rightAnswer_;
}

void Multiple::newQuestionMul(string Qtext,string answer1,string answer2,string answer3,int rightAns, short Qgrade,short Qpentality)
{
	Qtext_ = Qtext;
	setAnswer(answer1, answer2, answer3,rightAns);
	Qgrade_=Qgrade;
	Qpentality_=Qpentality;
}

Multiple::~Multiple()
{
}