#include "Questions.h"


Questions::Questions(string t, short g, short p)
{
	setAll(t,g,p);
}

void Questions::setAll(string Qtext,short Qgrade,short Qpentality)
{
	Qtext_=Qtext;
	Qgrade_=Qgrade;
	Qpentality_=Qpentality;
}

string Questions::getQtext()
{ 
	return Qtext_;
}

short Questions::getQgrade(){ return Qgrade_; }

short Questions::getQpentality(){ return Qpentality_; }

Questions::~Questions()
{
}



