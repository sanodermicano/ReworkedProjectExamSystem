#pragma once
#include "main.h"

class User
{
public:
	User();
	User(string name,string password,string userID);
	void setAll(string,string,string);
	string getName();
	string getUserID();
	string getPassword();
protected:
	string name_;
	string password_;
	string userID_;
};
