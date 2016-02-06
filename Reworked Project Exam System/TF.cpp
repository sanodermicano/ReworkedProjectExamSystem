#include "TF.h"


TF::TF()
{
	Qanswer_=false;
	Qchoice_=false;
}

void TF::setQchoice(bool Qchoice)
{
	Qchoice_=Qchoice;
}
void TF::setQanswer(bool Qanswer)
{
	Qanswer_=Qanswer;
}
bool TF::getQchoice()
{
	return Qchoice_;
}
bool TF::getQanswer()
{
	return Qanswer_;
}
bool TF::checkAnswer()
{
	return Qchoice_ == Qanswer_;
}
void TF::newQuestionTF(string Qtext, short Qgrade,short Qpentality,bool Qanswer)
{
	Qtext_=Qtext;
	Qanswer_=Qanswer;
	Qgrade_=Qgrade;
	Qpentality_=Qpentality;
}

TF::~TF()
{
}