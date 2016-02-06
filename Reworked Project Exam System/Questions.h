#pragma once
#include "main.h"

class Questions//every question should be an object to save answer with Qtext
{
public:
	Questions(string="",short=0,short=0);
	~Questions();
	string getQtext();
	short getQgrade();
	short getQpentality();
	void setAll(string,short,short);
	
protected:
	short Qgrade_;
	short Qpentality_;
	string Qtext_;
};