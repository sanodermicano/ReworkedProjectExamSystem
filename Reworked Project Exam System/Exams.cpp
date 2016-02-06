#include "Exams.h"
#include <time.h>


Exams::Exams() :check(0) 
{
	checkrand= -1;
	checkrand1 = -1;
	mulTemp_ = new Multiple[7];
	tfTemp_ = new TF[7];
	n = 0;
	n1 = 0;
}

Exams::Exams(short t,short m) : check(0) 
{
	if (t < 0)t = 1;
	if (m < 0)m = 1;
	checkrand = -1;
	checkrand1 = -1;
	mulTemp_ = new Multiple[m];
	tfTemp_ = new TF[t];
	n = 0;
	n1 = 0;
}

void Exams::addQ(const TF & t)
{
	tfTemp_[n] = t;
	++n;
}

void Exams::addQ(const Multiple & m)
{
	mulTemp_[n1] = m;
	++n1;
}


TF Exams::getRandomTFQuestion(int max, int help)//watch out
{
	srand(time(NULL));
	if (max == 0) 
	{ 
		max = help;
	}
	short p = rand() % max;
	
	//this what happens when I get millions of errors because of one question
		while (checkrand == p) 
		{
			p = rand() % max;
		}
	checkrand = p;
	return tfTemp_[p];
}

Multiple Exams::getRandomMULQuestion(int max, int help)
{
	srand(time(NULL));
	if (max == 0) 
	{
		max = help;
	}
	short p = rand() % max;

	//this what happens when I get millions of errors because of one question
	while (checkrand1 == p) 
	{
		p = rand() % max;
	}
	checkrand1 = p;
	return mulTemp_[p];
}



Exams::~Exams() { if (tfTemp_) delete[] tfTemp_;
if(mulTemp_)delete[] mulTemp_; }