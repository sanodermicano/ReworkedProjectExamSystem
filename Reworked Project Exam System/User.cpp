#include "User.h"


User::User()
{
	setAll("","","");
}

User::User(string name,string password,string userID)
{
	setAll(name,password,userID);
}

void User::setAll(string name,string password,string userID)
{
	name_=name;
	password_=password;
	userID_=userID;
}

string User::getName(){return name_; }
string User::getUserID()
{
	return userID_;
}
string User::getPassword()
{
	return password_;
}