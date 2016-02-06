#pragma once
#include "main.h"
#include "Questions.h"

class TF : public Questions
{
public:
	TF();
	void setQchoice(bool);
	void setQanswer(bool);
	bool getQchoice();
	bool getQanswer();
	bool checkAnswer();
	void newQuestionTF(string Qtext, short Qgrade,short Qpentality,bool Qanswer);
	~TF();
private:
	bool Qchoice_;//student answer
	bool Qanswer_;
};