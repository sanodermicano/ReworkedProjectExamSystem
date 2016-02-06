#pragma once
#include "Questions.h"
#include "TF.h"
#include "Multiple.h"

class Exams 
{
public:
	Exams();
	Exams(short t, short m);
	void addQ(const TF &t);
	void addQ(const Multiple &m);
	TF getRandomTFQuestion(int, int);
	Multiple getRandomMULQuestion(int, int);
	~Exams();
private:
	int check, checkrand, checkrand1;
	int n, n1;// : 10; initializer list can work in header files? yet I believe it makes the memory runs slower.
	TF *tfTemp_;
	Multiple *mulTemp_;
};