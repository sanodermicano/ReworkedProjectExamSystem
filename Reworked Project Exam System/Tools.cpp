#include "AllHeaders.h"

double Tools::getAvg(Student a[], int s) 
{
	double sum = 0;
	for (int i = 0;i < s;i++) 
	{

		sum = sum + a[i].getScore();
	}
	return sum / s;
}

void Tools::TheStudentsInformation(Student a[], int s) 
{
	for (int i = 0;i < s;i++)
		cout << a[i].getName() << " " << a[i].getUserID() << " " << a[i].getScore() << endl;
}

void Tools::getNumberOfAnswers(string a) 
{
	ifstream inFile(a);
	int count = 0;
	while (!inFile.eof()) 
	{
		getline(inFile, a);
		inFile >> a;
		count++;
	}
	count--;
	if (count ==1)cout <<'\n' << count << " ANSWER" << endl;
	else cout <<'\n'<< count << " ANSWERS" << endl;
	inFile.close();
}

void Tools::getAnswers(string x) 
{
	ifstream inFile(x);
	while (!inFile.eof()) 
	{
		getline(inFile, x);
		cout << x << endl;
	}
	inFile.close();
}

void Tools::sendto(string file)
{
	ofstream send(file,ios::app);
	send.close();
}

void Tools::sendto(string file,int x)
{
	ofstream send(file,ios::app);
	send << x <<'\n';
	send.close();
}

void Tools::sendto(int x,string file ) 
{
	ofstream send(file);
	send << x << '\n';
	send.close();
}

void Tools::sendto(string file,double x)
{
	ofstream send(file,ios::app);
	send << x <<'\n';
	send.close();
}

void Tools::sendto(string file,string x)
{
	ofstream send(file,ios::app);
	send << x <<'\n';
	send.close();
}

void Tools::sendto(string file,char x)
{
	ofstream send(file,ios::app);
	send << x <<'\n';
	send.close();
}

void Tools::sendto(string file,bool x)
{
	ofstream send(file,ios::app);
	send << x <<'\n';
	send.close();
}

void Tools::sendto(string file,int x,char command)
{
	ofstream send(file,ios::app);
	send << x <<command;
	send.close();
}
void Tools::sendto(string file,double x,char command)
{
	ofstream send(file,ios::app);
	send << x <<command;
	send.close();
}
void Tools::sendto(string file,string x,char command)
{
	ofstream send(file,ios::app);
	send << x <<command;
	send.close();
}
void Tools::sendto(string file,char x,char command)
{
ofstream send(file,ios::app);
	send << x <<command;
	send.close();
}
void Tools::sendto(string file,bool x,char command)
{
	ofstream send(file,ios::app);
	send << x <<command;
	send.close();
}




int Tools::recieveFromInt(string file)
{
	int x;
	ifstream takeFrom(file);
	while(takeFrom>>x);
	takeFrom.close();
	return x;
}

double Tools::recieveFromDouble(string file)
{
	double x;
	ifstream takeFrom(file);
	while(takeFrom>>x);
	takeFrom.close();
	return x;
}

	string Tools::recieveFromString(string file)
{
	ifstream takeFrom(file);
	while(takeFrom>>file);
	takeFrom.close();
	return file;
}

	char Tools::recieveFromChar(string file)
{
	char x;
	ifstream takeFrom(file);
	while(takeFrom>>x);
	takeFrom.close();
	return x;
}

	bool Tools::recieveFromBool(string file)
{
	bool x;
	ifstream takeFrom(file);
	while(takeFrom>>x);
	takeFrom.close();
	return x;
}


	void Tools::recieveQtext(string file,string *x,int max)
	{
		//the string is either empty or 
	ifstream takeFrom(file);
	int i=0;//here we must put random question???????
	//string prevLine="";
	while(i<max)
		{
		getline(takeFrom,x[i]);//problem right here! from the second time crash?
		++i; 
		}
	takeFrom.close();
	}

	void Tools::recieveANStext(string file, string *x){
		ifstream takeFrom(file);
		int i = 0;
		//string prevLine="";
		while (1) {
			getline(takeFrom, x[i]);

			if (i == 0);//negation
			else
				if (x[i] == x[i - 1]) break;
			i++;
		}
		takeFrom.close();
	}


string Tools::recieveWholefile(string file) 
{
  ifstream takeFrom(file);
  while (!takeFrom.eof()) 
  {
	  getline(takeFrom,file,';');//it removes everything before the ;
  }
takeFrom.close();
  return file;
 }

void Tools::resetAll() 
{
	ofstream reset("database/numQuestions.txt");
	reset << 500;
	reset.close();
	ofstream reset1("database/MULanswers.txt");
	reset1.close();
	ofstream reset2("database/stu.txt");
	reset2.close();
	ofstream reset3("database/MUL.txt");
	reset3.close();
	ofstream reset4("database/MULnumbers.txt");//put numbers and character in one line
	reset4 << 0;
	reset4.close();
	ofstream reset5("database/numExamTakers.txt");//put numbers and character in one line
	reset5 << 0;
	reset5.close();
	ofstream reset6("database/TF.txt");
	reset6.close();
	ofstream reset7("database/TFnumbers.txt");
	reset7 << 0;
	reset7.close();
	ofstream reset8("database/ins.txt");
	reset8.close();
	ofstream reset9("database/ans.txt");
	reset9 << 0;
	reset9.close();
	ofstream reset11("database/stuGrade.txt");
	reset11 << 0;
	reset11.close();
	ofstream reset12("database/numStudents.txt");
	reset12 << 0;
	reset12.close();
	ofstream reset13("database/numInstructor.txt");
	reset13 << 0;
	reset13.close();
	ofstream reset14("database/numTF.txt");
	reset14 << 0;
	reset14.close();
	ofstream reset15("database/numMUL.txt");
	reset15 << 0;
	reset15.close();
	ofstream grade("database/numGrades.txt");
	grade << 0;
	grade.close();
}

void Tools::initialize() 
{
	sendto("database/numExamTakers.txt");
	sendto("database/numGrades.txt");
	sendto("database/stuGrade.txt");
	sendto("database/numQuestions.txt");
	sendto("database/stu.txt");
	sendto("database/MULchar.txt");
	sendto("database/MUL.txt");
	sendto("database/MULnumbers.txt");
	sendto("database/TF.txt");
	sendto("database/TFnumbers.txt");
	sendto("database/ins.txt");
	sendto("database/ans.txt");
	sendto("database/admin.txt");
	sendto("database/numStudents.txt");
	sendto("database/numInstructor.txt");
	sendto("database/numTF.txt");
	sendto("database/numMUL.txt");
	sendto("database/MULanswers.txt");

	system("title Exam System");
}

void Tools::resetQuestions() 
{
	ofstream reset("database/MULanswers.txt");
	reset.close();
	ofstream reset1("database/numExamTakers.txt");//put numbers and character in one line
	reset1 << 0;
	reset1.close();
	ofstream reset2("database/stuGrade.txt");
	reset2 << 0;
	reset2.close(); 
	ofstream reset3("database/MUL.txt");
	reset3.close();
	ofstream reset4("database/MULnumbers.txt");
	reset4 << 0;
	reset4.close();
	ofstream reset5("database/MULchar.txt");
	reset5.close();
	ofstream reset6("database/TF.txt");
	reset6.close();
	ofstream reset7("database/TFnumbers.txt");
	reset7 << 0;
	reset7.close();
	ofstream reset9("database/ans.txt");
	reset9 << 0;
	reset9.close();
	ofstream reset14("database/numTF.txt");
	reset14 << 0;
	reset14.close();
	ofstream reset15("database/numMUL.txt");
	reset15 << 0;
	reset15.close();
}

bool Tools::collision(float x, float y, float ex, float ey, float width, float height) 
{
	//pretty much like a 4 polygonic rectangle
	if (x + width < ex || x > ex + width || y + height < ey || y > ey + height) return false; //if it was outside the box
	else return true; //if it was inside the box
}


//outside of tools class_____________________________________________________________________________________________________

void seperate(string text)
{
	ALLEGRO_FONT* font20 = al_load_ttf_font("Marlboro.ttf", 20, NULL);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	int x;
	//making the characters fit in the window--> the characters are already too small
	string line1, line2, line3;
	char *a = new char[text.size() + 1];
	a[text.size()] = 0;
	memcpy(a, text.c_str(), text.size());
	for (x = 0; x < text.length() + 1; x++)
	{
		if (x <= 65)
			line1.push_back(a[x]);
		if (x > 65 && x <= 130)
			line2.push_back(a[x]);
		if (x > 130)
			line3.push_back(a[x]);
	}
	if (x <= 65 || (x > 65 && x <= 130) || x > 130)
	{
		line1.push_back('-');
		al_draw_textf(font20, black, 50, 115, NULL, "%s", line1.c_str());
		al_draw_line(40, 135, 625, 135, black, 3);
	}
	if (x > 65 && x <= 130 || x > 130)
	{
		line2.push_back('-');
		al_draw_textf(font20, black, 50, 155, NULL, "%s", line2.c_str());
		al_draw_line(40, 175, 625, 175, black, 3);
	}
	if (x > 130)
	{
		al_draw_textf(font20, black, 50, 195, NULL, "%s", line3.c_str());
		al_draw_line(40, 215, 625, 215, black, 3);
	}
	al_destroy_font(font20);
}


string operator+(std::string const &a, int b) {
	ostringstream oss;
	oss << a << b;
	return oss.str();
}