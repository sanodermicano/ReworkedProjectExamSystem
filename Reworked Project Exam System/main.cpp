#include "allHeaders.h"

/*Project Exam system, by Hassan Al-Nouri and Majd Sami, the code is lines,
yet we still have two problems, the performence, the RNG and it would be 
beautiful if this exam system's database can be sent and recieved online
as some real exam system between instructors and students around the world
or make it possible for those who can't use the keyboard but can talk to 
use it.*/

//Vision: Our gift to the world is the time we give to serve it.

bool main() //bool main is so true
{
	bool isGenerateRand = false, isFullscreen = true, isNotMuted = true, isStuSound = true, isSpecialCase = false, isDummy = true;
	string songname = "sounds/1.ogg";
	string  temp, truefalse, ID, password, inputID, inputPassword, name, multi;
	string emptyy;
	string intro = "Can you type? If not please use the Windows Speech Recogniser\nthen say \"type N\" and then say \"Enter\" before using the program.\n";
	Tools tool;
	TF tf;
	Multiple mul;
	

	system("color 3f");

	cout << intro;
	speak(intro,8500);
	cin >> emptyy;
	if (emptyy == "no" || emptyy == "No" || emptyy == "NO" || emptyy == "n" || emptyy == "N") 
	{
			isSpecialCase = true;
			isStuSound = false;
			cout << "Microsoft's commands like: \"Type (Letter)\".\nMy Voice Commands in the Student's GUI: \n\"True\" \n\"False\" \n\"A\" \n\"B\" \n\"C\" \n\"Switch/Change\" \n\"Leave\": Leave the exam before finishing it. \n\"Quit\"\n";
			speak("Press any button to continue", 1700);
			system("PAUSE");
	}
	else isSpecialCase = false;

	initializeAgain:
	tool.initialize();
	//tool.resetQuestions();	//use those for emergency
	//	tool.resetAll();
	bool isDone = false, isStudent = false, isInstructor = false, isAdmin = false, isHelp = false, isExam = false, isScore = false, isShot = false, isOptions = false, qanswer;

	short numStudents = tool.recieveFromInt("database/numStudents.txt");
	short numInstructors = tool.recieveFromInt("database/numInstructor.txt");
	short numTF = tool.recieveFromInt("database/numTF.txt");
	short numMUL = tool.recieveFromInt("database/numMUL.txt");
	short numGrades = tool.recieveFromInt("database/numGrades.txt");
	short numExamTakers = tool.recieveFromInt("database/numExamTakers.txt");
	short qgrade, qpenalty, numANS = 20, size = 0, rightAns = 0, maxTF = numTF, maxMUL = numMUL, picChanger = 0, MrBreaker = 0, specialNum = 0, color1 = 0, color2 = 0, color3 = 0; //leave size alone
	short tempo = 0;

	float x = 0.0, y = 0.0, newX = 0.0, newY = 0.0 ;

	emptyy = "";

	if (numTF < 0) numTF = 0;
	if (numMUL < 0) numMUL = 0;
	if (numStudents < 0) numStudents = 0;
	//containers for questions and students_________________

	string mulAnsTemp[3];
	string tempname;
	string *TFarr = new string[numTF];
	string *MULarr = new string[numMUL];
	string *mulAns = new string[numMUL * 3];

	TF *TrueFalseArr = new TF[numTF],the_TFQuestion;
	Multiple *MultipleArr = new Multiple[numMUL],the_MULQuestion;
	Student tempStu;
	
	//containers for questions and students_________________


	//TF____________________________________________________

	if (numTF > 1) 
	{
		ifstream fromTF("database/TFnumbers.txt");
		tool.recieveQtext("database/TF.txt", TFarr,numTF);
		
		for (short i = 0; i < numTF; i++) 
		{
			fromTF >> qgrade >> qpenalty >> qanswer;
			if (TFarr[i] != "") 
			{
				TrueFalseArr[tempo].newQuestionTF(TFarr[i], qgrade, qpenalty, qanswer);
				++tempo;
			}
		}
		fromTF.close();
	}
	numTF = tempo;
	//TF__________________________________________________
	tempo = 0;
	int tempo2 = 0;
	//MUL_________________________________________________
	if (numMUL > 1) 
	{
		tool.recieveQtext("database/MUL.txt", MULarr,numMUL);
		tool.recieveQtext("database/MULanswers.txt",mulAns,numMUL*3);//problem right here
		ifstream fromMUL("database/MULnumbers.txt");
		ifstream fromMULchar("database/MULchar.txt");
		ifstream fromMULanswers("database/MULanswers.txt");
		
		for (short i = 0; i < numMUL*3; i+=3) 
		{
			fromMUL >> qgrade >> qpenalty>>rightAns;
			if (MULarr[tempo2] != "") 
			{
				MultipleArr[tempo].newQuestionMul(MULarr[tempo2], mulAns[i], mulAns[i + 1], mulAns[i + 2], rightAns, qgrade, qpenalty);//problem right here//look in multiple.h
				++tempo;
			}
			++tempo2;
		}
		fromMUL.close();
		fromMULchar.close();
		fromMULanswers.close();
	
		numMUL = tempo2;
	}
	//MUL_________________________________________________
	
	


	//exam system_________________________________________
	Exams exam(numTF+1,numMUL+1);
	for (short i = 0; i < numTF; i++)
		if(TrueFalseArr[i].getQtext()!="")
		exam.addQ(TrueFalseArr[i]);

	for (short i = 0; i < numMUL; i++)
		if (MultipleArr[i].getQtext() != "")
		exam.addQ(MultipleArr[i]);
	//exam system_________________________________________
	

	//Answers system______________________________________
	//allegro initilization_______________________________
	if (!al_init()) 
	{ 
		system("PAUSE"); return -1; 
	}
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	al_init_acodec_addon();
	al_init_native_dialog_addon();
	al_install_audio();
	al_install_keyboard();
	al_install_mouse();

	al_reserve_samples(2);
	ALLEGRO_SAMPLE *song = al_load_sample(songname.c_str());
	ALLEGRO_SAMPLE *shot = al_load_sample("sounds/Pistol Shot Sound Effect.ogg");

	ALLEGRO_SAMPLE_INSTANCE *stuff = al_create_sample_instance(song);
	al_set_sample_instance_playmode(stuff, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(stuff, al_get_default_mixer());
	if (isSpecialCase == false)
	al_play_sample_instance(stuff);
	

	

	//allegro initilization_______________________________
	ALLEGRO_FONT* font20 = al_load_ttf_font("Marlboro.ttf", 20, NULL);
	ALLEGRO_FONT *font24 = al_load_ttf_font("Marlboro.ttf", 24, NULL);
	ALLEGRO_FONT *font75 = al_load_ttf_font("Marlboro.ttf", 75, NULL);
	//main loop___________________________________________
	while (isDone == false) 
	{
		system("color f1");
		system("cls");
		cout << "Welcome to RPES, if you need a description about the software type \"help\".\nIf you needed to change the options or the special case mode type \"options\" or say \"Type O P T I O N S\".\nOr type \"Games\" to have fun!\n\nEnter your userID\t[Write quit to exit]\n";
		if(isSpecialCase==true)
		speak("Welcome to R P E S, please enter your username or say \"type H E L P\". Or if you wanted to have fun say \"Type G A M E\".",9000);
		cin >> ID;
		if (ID == "quit" || ID == "QUIT" || ID == "Quit") 
		{
			if (isSpecialCase == true) speak("Hope you get well soon!", 2000);
			else speak("Goodbye", 1000);
			delete[] TFarr;
			delete[] MULarr;
			delete[] MultipleArr;
			delete[] mulAns;
			exit(0);
		}
		if (ID == "help" || ID == "HELP" || ID == "Help" || ID=="hep") 
		{
			isStudent = isHelp= true;
			isExam = false;
		}
		if (ID == "Options" || ID == "OPTIONS" || ID == "options" || ID == "Option" || ID == "OPTION" || ID == "option")
		{
			isOptions= true;
		}
		if (ID == "game" || ID == "GAME" || ID == "Game" || ID == "games" || ID == "Games" || ID == "GAMES") 
		{
			system("cls");
			system("color 3e");
			cout << "Enter the number of the game you want to play:\n\n1 Tictac-toe AI. (Works with special case mode)\n2 Survivroll. (Not available in the special case mode)\n\nEnter anything else to exit.\n";
			if (isSpecialCase == true) speak("Say \"Type 1\" if you want to play tic tac toe with A I or type anything else to leave.\n",6000);
				cin >> ID; //used to 
				if (ID == "1") tictac(isSpecialCase); 
				if(isSpecialCase==false)	if (ID == "2") survivroll();
			continue;
		}
		if (isHelp == false && isOptions==false) 
		{
			cout << "Enter your password\n";
			if (isSpecialCase == true)
				speak("Enter your password.", 1500);
			cin >> password;
			ifstream text("database/admin.txt");
			ifstream text1("database/ins.txt");
			ifstream text2("database/stu.txt");

			text >> inputID >> inputPassword;
			if (ID == inputID && password == inputPassword) isAdmin = true;
			inputID = inputPassword = "";

			//instructor_______________________________________
			for (size = 0; size < numInstructors; size++) 
			{
				text1 >> tempname >> inputID >> inputPassword;
				if (ID == inputID && password == inputPassword) isInstructor = true;
				inputID = inputPassword = "";
			}
			//instructor_______________________________________


			//STUDENT__________________________________________
			for (size = 0; size < numStudents; size++) 
			{
				text2 >> tempname >> inputID >> inputPassword;
				if (ID == inputID && password == inputPassword) 
				{ isStudent = isExam = true; 
				isHelp = false;
				}
				inputID = inputPassword = "";
			}
			//STUDENT__________________________________________
			text.close();
			text1.close();
			text2.close();
			if (isStudent == false && isAdmin == false && isInstructor == false) {
				cout << "Try again.\n";
				speak("Try again", 1000);
			}
		}
		//Options loop_____________________________________
		while (isOptions == true) 
		{
			system("color 4e");
			system("cls");
			string optionstemp;
			cout << "Type the option's number to activate/deactivate a feature.\n1 Fullscreen Off or On. ["<<isFullscreen<<"]\n2 Generate random colors. ["<<isGenerateRand<<"]\n3 Change the song. ["<< songname <<"]\n4 Mute or unMute the sounds. ["<<isNotMuted<<"]\n5 Special Case's mode. ["<<isSpecialCase<<"]\n6 to quit.\n";
			cin >> optionstemp;
			if (isSpecialCase == true && (optionstemp == "3" || optionstemp == "4")) {
				cout << "Background music will only play with the Special case's mode OFF, type \"Yes\" if you want it to turn off.\n";
				cin >> temp;
				if (temp == "yes" || temp == "YES" || temp == "Yes" || temp == "y" || temp == "Y" || temp == "ye" || temp == "Ye") isSpecialCase=false;
			}
			if (optionstemp == "1") 
			{
				if(isFullscreen==true)
				isFullscreen = false;
				else isFullscreen = true;
			}
			if (optionstemp == "2") 
			{
				if (isGenerateRand == true)
					isGenerateRand = false;
				else isGenerateRand = true;
			}
			if (optionstemp == "3") 
			{
				cout << "Enter the song's number from 1 to 6\n";//you might want to write the songs names 1- stuff 2- thing
				cin >> songname;
				if (songname == "1" || songname == "2" || songname == "3" || songname == "4" || songname == "5" || songname == "6") {
					songname = "sounds/" + songname + ".ogg";
					al_stop_sample_instance(stuff);
					goto initializeAgain;
				}
			}
			if (optionstemp == "4") 
			{
				if (isNotMuted == true) 
				{
					isNotMuted = false;
					if (isStuSound == true) 
					isStuSound = false;
					al_stop_sample_instance(stuff);
				}
				else {
					isStuSound = true;
					isNotMuted = true;
					al_play_sample_instance(stuff);
				}
			}
			if (optionstemp == "5") 
			{
				if (isSpecialCase == false)
				{ 
					isSpecialCase = true;
					isStuSound = false;
					al_stop_sample_instance(stuff);
					cout << "Use microsoft's commands like: \"Type (Letter)\".\nMy Voice Commands in the Student's GUI: \n\"True\" \n\"False\" \n\"A\" \n\"B\" \n\"C\" \n\"Switch/Change\" \n\"Leave\": Leave the exam before finishing it. \n\"Quit\"\n";
					system("PAUSE");
				}
				else { isSpecialCase = false; 
				isStuSound = true;
				al_play_sample_instance(stuff);
				}
			}
			if (optionstemp == "6") 
			{
				isOptions = false;
			}
		}

		//admin's loop_____________________________________
		while (isAdmin == true) 
		{
			system("color 0a");
			system("cls");
			cout << "Press:\n1 to add Instructor.\n2 to add Student.\n3 to delete all Instructor.\n4 to delete all Students.\n5 to reset all database.\n6 to reset questions.\n7 to exit.\n";
			cin >> temp;
			ofstream text2("database/stu.txt", ios::app);
			ofstream text1("database/ins.txt", ios::app);
			if (temp == "1") 
			{
				insAgain:
				system("cls");
				cout << "Enter name, userID and password.\n";
				cin >> name >> ID >> password;
				if (ID == "help" || ID == "HELP" || ID == "Help" || ID == "quit" || ID == "QUIT" || ID == "Quit" || ID == "game" || ID == "GAME" || ID == "Game" || ID == "games" || ID == "Games" || ID == "GAMES" || ID == "Options" || ID == "OPTIONS" || ID == "options"|| ID == "Option" || ID == "OPTION" || ID == "option" || ID == "hep") goto insAgain;
				text1 << name << ' ' << ID << ' ' << password << '\n';
				text1.close();
				tool.sendto("database/numInstructor.txt", ++numInstructors);//magic
			}

			if (temp == "2") 
			{
				stuAgain:
				system("cls");
				cout << "Enter name, userID and password.\n";
				cin >> name >> ID >> password;
				if (ID == "help" || ID == "HELP" || ID == "Help" || ID == "quit" || ID == "QUIT" || ID == "Quit"|| ID == "game" || ID == "GAME" || ID == "Game" || ID == "games" || ID == "Games" || ID == "GAMES" || ID == "Options" || ID == "OPTIONS" || ID == "options" || ID == "Option" || ID == "OPTION" || ID == "option" || ID == "hep") goto stuAgain;
				text2 << name << ' ' << ID << ' ' << password << '\n';
				text2.close();

				tool.sendto("database/numStudents.txt", ++numStudents);
			}

			if (temp == "3") 
			{
				text1.close();
				ofstream text1("database/ins.txt");
				text1.close();
			}

			if (temp == "4")
			{
				text2.close();
				ofstream text2("database/stu.txt");
				text2.close();
			}
			if (temp == "5") tool.resetAll();
			if (temp == "6")tool.resetQuestions();
			if (temp == "7") 
			{ 
				isAdmin = false; 
			}
		}
		//end of admin's loop______________________________

		//instructor loop__________________________________
		while (isInstructor == true) 
		{
			system("color 9B");
			system("cls");
			cout << "Press:\n1 to add true/false Question.\n2 to add multiple-choice Question.\n3 to get students average.\n4 to reset questions.\n5 to exit.\n";
			cin >> temp;
			if (temp == "1") 
			{
				cout << "Enter the Question's text and click 'Enter' when you're done.\n";
				cin.ignore(' ', '\n');
				getline(std::cin, truefalse);
				cout << "Enter the Question's grade.\n";
				cin >> qgrade;
				cout << "Enter the Question's penalty\n";
				cin >> qpenalty;
				cout << "Enter \"1\" or \"0\" to determine if the answer is True or False.\n";
				cin >> qanswer;
				tf.newQuestionTF(truefalse, qgrade, qpenalty, qanswer);
				ofstream tfqu("database/TF.txt", ios::app);
				ofstream tfqunumbers("database/TFnumbers.txt", ios::app);
				tfqunumbers << tf.getQgrade() << ' ' << tf.getQpentality() << ' ' << tf.getQanswer() << "\n";
				tfqu << tf.getQtext() << '\n';
				tfqunumbers.close();
				tfqu.close();
				exam.addQ(tf);
				tool.sendto(++numTF, "database/numTF.txt");
				goto initializeAgain;
			}
			if (temp == "2") 
			{
				cout << "Enter the Question's text and click 'Enter' when you're done.\n";

				cin.ignore(' ', '\n');

				getline(std::cin, multi);
				cout << "Enter the first choice and click 'Enter' when you're done.\n";
				getline(std::cin, mulAnsTemp[0]);
				cout << "Enter the second choice and click 'Enter' when you're done.\n";
				getline(std::cin, mulAnsTemp[1]);
				cout << "Enter the third choice and click 'Enter' when you're done.\n";
				getline(std::cin, mulAnsTemp[2]);
				writeAgain:
				cout << "Enter the number of the right choice, from 1 to 3.\n";
				cin >> rightAns;
				if (rightAns > 3 || rightAns < 1) goto writeAgain;
				cout << "Enter the Question's grade.\n";
				cin >> qgrade;
				cout << "Enter the Question's penalty\n";
				cin >> qpenalty;
				
				mul.newQuestionMul(multi,mulAnsTemp[0], mulAnsTemp[1], mulAnsTemp[2],rightAns, qgrade, qpenalty);
				ofstream mulqu("database/MUL.txt", ios::app);
				ofstream mulqunumbers("database/MULnumbers.txt", ios::app);
				ofstream mulquchar("database/MULchar.txt", ios::app);
				ofstream MULquanswers("database/MULanswers.txt",ios::app);
				mulqu << mul.getQtext() << '\n'; //create loading Questions for the streams
				MULquanswers << mulAnsTemp[0] << '\n' << mulAnsTemp[1] << '\n' << mulAnsTemp[2] << '\n';
				mulqunumbers << mul.getQgrade() << ' ' << mul.getQpentality() << ' '<<rightAns<<'\n';
				mulquchar << mul.getSAnswer() << '\n';
				mulquchar.close();
				mulqunumbers.close();
				mulqu.close();
				MULquanswers.close();
				exam.addQ(mul);
				tool.sendto(++numMUL, "database/numMUL.txt");
				goto initializeAgain;
			}

			if (temp == "3") 
			{
				if(numExamTakers>0)
				cout << "The average of "<< numExamTakers << " Students is: "<<numGrades/numExamTakers << endl;//working
				else cout << "No one Took the exam\n";
				system("PAUSE");
			}
			if (temp == "4") tool.resetQuestions();
			if (temp == "5") 
			{ 
				isInstructor = false; 
			}
		}
		//end of instructor loop___________________________

		//Student's start__________________________________
		maxMUL = numMUL;
		maxTF = numTF;
		if (maxMUL > 5)maxMUL = 5;
		if (maxTF > 5)maxTF = 5;
		//colors___________________________________________
		srand(time(NULL));
			ALLEGRO_COLOR blue = al_map_rgb(100, 150, 255);
			ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
			ALLEGRO_COLOR gold = al_map_rgb(230, 230, 0);
			ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
			ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
			ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
			ALLEGRO_COLOR sano = al_map_rgb(0, 255, 255);
			ALLEGRO_COLOR pink = al_map_rgb(255, 0, 255);
		
			if (isGenerateRand == true) 
		{
color1 = rand() % 256;
color2 = rand() % 256;
color3 = rand() % 256;
		blue = al_map_rgb(color1, color2, color2);
		gold = al_map_rgb(color1, color1, color2);
		black = al_map_rgb(color1, color2, color3);
		red = al_map_rgb(color2, color3, color1);
		green = al_map_rgb(color3, color2, color1);
		sano = al_map_rgb(color2, 0, color3);
		pink = al_map_rgb(color1, color3, 0);
		}
		//fullscreen tweaks________________________________
			if (isFullscreen == false) 
			{
				newX = 300.0;
				newY = 125.0;
			}
			else 
			{
				newX = 0.0;
				newY = 0.0;
			}
			//reset the score
			tempStu.addScore(-tempStu.getScore());
		
		if (isStudent == true) 
		{
			al_init_image_addon();
			ALLEGRO_BITMAP* psut = al_load_bitmap("pictures/psut.jpg");//problem here
			ALLEGRO_BITMAP* pics[20] = {al_load_bitmap("pictures/1.jpg"),al_load_bitmap("pictures/2.jpg"),al_load_bitmap("pictures/3.jpg"),al_load_bitmap("pictures/4.jpg"),al_load_bitmap("pictures/5.jpg"),al_load_bitmap("pictures/6.jpg"),al_load_bitmap("pictures/7.jpg"),al_load_bitmap("pictures/8.jpg"),al_load_bitmap("pictures/9.jpg"),al_load_bitmap("pictures/10.jpg"),al_load_bitmap("pictures/11.jpg"),al_load_bitmap("pictures/12.jpg"), al_load_bitmap("pictures/13.jpg"),al_load_bitmap("pictures/14.jpg"),al_load_bitmap("pictures/15.jpg"),al_load_bitmap("pictures/16.jpg"),al_load_bitmap("pictures/17.jpg"),al_load_bitmap("pictures/18.jpg"),al_load_bitmap("pictures/19.jpg"),al_load_bitmap("pictures/20.jpg") };
			ALLEGRO_BITMAP* helpPics[17] = { al_load_bitmap("pictures/help1.jpg"),al_load_bitmap("pictures/help2.jpg"),al_load_bitmap("pictures/mainmenu.jpg"),al_load_bitmap("pictures/adminmenu.jpg"),al_load_bitmap("pictures/instructormenu.jpg"),al_load_bitmap("pictures/optionsmenu.jpg"),al_load_bitmap("pictures/gamesmenu.jpg"),al_load_bitmap("pictures/features.jpg"),al_load_bitmap("pictures/help3.jpg"),al_load_bitmap("pictures/help4.jpg"),al_load_bitmap("pictures/help5.jpg"),al_load_bitmap("pictures/help6.jpg"),al_load_bitmap("pictures/help7.jpg"),al_load_bitmap("pictures/help8.jpg"),al_load_bitmap("pictures/help9.jpg"),al_load_bitmap("pictures/help10.jpg"),al_load_bitmap("pictures/help11.jpg") };
			ALLEGRO_BITMAP* target[2] = { al_load_bitmap("pictures/target1.png"),al_load_bitmap("pictures/target2.png") };
			ALLEGRO_BITMAP* soundIcon[2] = { al_load_bitmap("pictures/mute.png") , al_load_bitmap("pictures/voice.png") };
			system("cls"); 
			ALLEGRO_DISPLAY* display = al_create_display(800, 600);
				if (!display) return -1;
				
				al_show_mouse_cursor(display);

			ALLEGRO_FONT* font = al_create_builtin_font();
			ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
			al_register_event_source(event_queue, al_get_display_event_source(display));
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			al_register_event_source(event_queue, al_get_mouse_event_source());
			al_get_standard_path(ALLEGRO_EXENAME_PATH);
			ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
			al_register_event_source(event_queue, al_get_timer_event_source(timer));
			size = 0;
			if (isSpecialCase == false)
			if (isNotMuted == true) 
				al_play_sample_instance(stuff);
			MrBreaker = 0;
			//HELP__________________________________________________
			
				if(isFullscreen == true)
				al_set_display_flag(display, ALLEGRO_MAXIMIZED, true);
				else al_set_display_flag(display, ALLEGRO_WINDOWED, true);

				//for special case mode
					string helperString="Welcome to the Reworked Project Exam System. Here you will have two types of Questions, true or false and multiple choices Questions, you answer with A B C for multiple choices or answer true false for true or false Questions, you can also leave the exam before answering by saying \"Leave\", the number of questions is 10. Please say Escape to go back to the main menu.";
				
			
			while(isHelp==true)
			{
				ALLEGRO_EVENT helpevent; 
				al_flip_display();
				al_wait_for_event(event_queue, &helpevent);
				if (helpevent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
				if (helpevent.type == ALLEGRO_EVENT_KEY_DOWN)
					if (helpevent.keyboard.keycode == ALLEGRO_KEY_ESCAPE) break;

				if (isDummy == true && isSpecialCase==true) 
				{
					speak(helperString, 24000);
					isDummy = false;
				} 

				if (helpevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
				{
					if (helpevent.mouse.button & 1)
						++MrBreaker;
					if (helpevent.mouse.button & 2)--MrBreaker;
				}
				if (helpevent.type == ALLEGRO_EVENT_KEY_UP) 
				{
					++MrBreaker;
				}
				if (MrBreaker >= 17)break;
				if (MrBreaker <=0)MrBreaker=0;
				al_draw_bitmap(helpPics[MrBreaker], 0, 0, NULL);
			}
			isDummy = true;

			if (isHelp == false) 
			{

				if (numMUL > 0) 
				{
				tryAgainMULDude:
					the_MULQuestion = exam.getRandomMULQuestion(numMUL, 2);
					if (the_MULQuestion.getQtext() == "" || the_MULQuestion.getAnswer1() == "" || the_MULQuestion.getAnswer2() == "" || the_MULQuestion.getAnswer3() == "") goto tryAgainMULDude;
				}

				if (numTF > 0) 
				{
				//tryAgainTFDude:
					the_TFQuestion = exam.getRandomTFQuestion(numTF, 2);
					//if (the_TFQuestion.getQtext() == "") goto tryAgainTFDude;
				}
			}
			
			//EXAM__________________________________________________
			if(isExam == true && isFullscreen==true)
			al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);

			while (isExam==true && (maxMUL>0 || maxTF>0)) 
			{
				ALLEGRO_EVENT mainevent;
				al_wait_for_event(event_queue, &mainevent);

				isScore = true;
				if (picChanger >= 20)picChanger = 0;
				al_clear_to_color(al_map_rgb(255, 255, 255));
				al_draw_scaled_bitmap(psut, 0, 0, 500, 500, 650, 0, 150, 150, NULL);
				al_draw_filled_rounded_rectangle(23, 23, 652, 402, 250, 25, black);
				al_draw_filled_rounded_rectangle(25, 25, 650, 400, 250, 25, sano);
				al_draw_filled_rounded_rectangle(23, 423, 652, 602, 250, 25, black);
				al_draw_filled_rounded_rectangle(25, 425, 650, 600, 250, 25, blue);
				//change the question from TF to Mul and vice versa
				al_draw_rectangle(300, 0, 350, 30, black,2);
				al_draw_filled_rectangle(300, 0, 350, 30, green);
				if (size == 0) al_draw_text(font24, gold, 310, 10, NULL, "T&F");
				else al_draw_text(font24, gold, 310, 10, NULL, "Mul");

				//change the Question
				if (mainevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || specialNum == 8)
					if (tool.collision(x, y, 310, 0, 40, 30) == true || specialNum == 8)
						if (size == 0)size = 1;
						else size = 0;

				//change pic manually
						if (isFullscreen == true) 
						{
							if (mainevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
								if (tool.collision(x, y, 1100, 0, 300, 640) == true)
									if (mainevent.mouse.button & 1) 
									{
										if (++picChanger >= 20) picChanger = 0;
									}
									else if (--picChanger <= 0) picChanger = 19;
						}
				//mute the voice
				if (mainevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
					if (tool.collision(x, y, 0, 0, 64,64) == true)
						if (isNotMuted == true) 
						{
							if (isStuSound == true && isSpecialCase==false)isStuSound = false;
							else if(isSpecialCase==false) isStuSound = true;
						}
						al_draw_bitmap(soundIcon[isStuSound], 0, 0, NULL);

				if (isStuSound == true && isSpecialCase==false) al_play_sample_instance(stuff);
				else al_stop_sample_instance(stuff);

				//draw a line along the display screen under the choices in the mul questions
				if (size == 0) 
				{

					if (isFullscreen == true) 
					{
						al_draw_filled_rectangle(797, 0, 1366, 642, black);
						al_draw_bitmap_region(pics[picChanger], 0, 0, 800, 1000, 800, 0, NULL);
						if (isSpecialCase == false) al_draw_text(font24, black, 900, 660, NULL, "Click on the picture to change it manually.");
						else al_draw_text(font24, black, 400, 660, NULL, "Voice Commands: \"True\" \"False\" \"A\" \"B\" \"C\" \"Switch/Change\" \"Leave\" \"Quit\"");
					}
					if (the_MULQuestion.getQtext().size() < 50) 
					{
						al_draw_textf(font20, black, 50, 115, NULL, "%s", the_MULQuestion.getQtext().c_str());//use stringvar.c_str();
						al_draw_line(40, 135, 625, 135, black, 3);
					}
					else seperate(the_MULQuestion.getQtext());

					al_draw_textf(font, red, 50, 465, NULL, "%s", the_MULQuestion.getAnswer1().c_str());
					al_draw_line(40, 480, 625, 480, black, 2);
					al_draw_textf(font, gold, 50, 520, NULL, "%s", the_MULQuestion.getAnswer2().c_str());
					al_draw_line(40, 530, 625, 530, black, 2);
					al_draw_textf(font, pink, 50, 560, NULL, "%s", the_MULQuestion.getAnswer3().c_str());
					al_draw_line(40, 575, 625, 575, black, 2);
					al_flip_display();
					if (isSpecialCase == true && size == 0) 
					{
						specialNum = voiceRecognition("Multiple choice Question: "+the_MULQuestion.getQtext()+"\n A is: "+the_MULQuestion.getAnswer1()+"\n B is: "+the_MULQuestion.getAnswer2()+"\n C is: "+the_MULQuestion.getAnswer3());	//beware me
						Sleep(500);
					}
					if (specialNum == 7) break;
					if (mainevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || specialNum>0)
					{
							//y=465
						if (tool.collision(x, y, 50, 455, 600, 15) == true || specialNum == 3)
						{
								tryAgainMUL:
									the_MULQuestion = exam.getRandomMULQuestion(numMUL, 2);
									if (the_MULQuestion.getQtext() == "" || the_MULQuestion.getAnswer1() == "" || the_MULQuestion.getAnswer2() == "" || the_MULQuestion.getAnswer3() == "") goto tryAgainMUL;
								if (++picChanger > 20)picChanger = 0;
								size = 1;
								--maxMUL;
								rightAns = 1;
								if (the_MULQuestion.getRightAns() == rightAns)tempStu.addScore(the_MULQuestion.getQgrade());
								else tempStu.addScore(-the_MULQuestion.getQpentality());
								continue;
						}
							//y=520
						if (tool.collision(x, y, 50, 510, 600, 15) == true || specialNum == 4)
							{
								tryAgainMUL2:
									the_MULQuestion = exam.getRandomMULQuestion(numMUL, 2);
									if (the_MULQuestion.getQtext() == "" || the_MULQuestion.getAnswer1() == "" || the_MULQuestion.getAnswer2() == "" || the_MULQuestion.getAnswer3() == "") goto tryAgainMUL2;
								if (++picChanger >= 20)picChanger = 0;
								size = 1;
								--maxMUL;
								rightAns = 2;
								if (the_MULQuestion.getRightAns() == rightAns)tempStu.addScore(the_MULQuestion.getQgrade());
								else tempStu.addScore(-the_MULQuestion.getQpentality());
								continue;
							}
							//y=560
						if (tool.collision(x, y, 50, 550, 600, 15) == true || specialNum == 5)
							{
								tryAgainMUL3:
									the_MULQuestion = exam.getRandomMULQuestion(numMUL, 2);
									if (the_MULQuestion.getQtext() == "" || the_MULQuestion.getAnswer1() == "" || the_MULQuestion.getAnswer2() == "" || the_MULQuestion.getAnswer3() == "") goto tryAgainMUL3;
								if (++picChanger >= 20)picChanger = 0;
								size = 1;
								--maxMUL;
								rightAns = 3;
								if (the_MULQuestion.getRightAns() == rightAns)tempStu.addScore(the_MULQuestion.getQgrade());
								else tempStu.addScore(-the_MULQuestion.getQpentality());
								continue;
							}
					}
				}
				if (size==1)
				{
					al_draw_rectangle(75, 460, 135, 570, black, 5);
					al_draw_line(80, 465, 130, 565, red, 5);
					al_draw_line(130, 465, 80, 565, red, 5);
					al_draw_rectangle(545, 460, 605, 570, black, 5);
					al_draw_line(555, 515, 550, 565, green, 5);
					al_draw_line(600, 465, 550, 565, green, 5);
					
					if (isFullscreen == true) 
					{
						al_draw_filled_rectangle(797, 0, 1366, 642, black);
						al_draw_bitmap_region(pics[picChanger], 0, 0, 800, 1000, 800, 0, NULL);

						if(isSpecialCase==false) al_draw_text(font24, black, 900, 660, NULL, "Click on the picture to change it manually.");
						else al_draw_text(font24, black, 400, 660, NULL, "Voice Commands: \"True\" \"False\" \"A\" \"B\" \"C\" \"Switch/Change\" \"Leave\" \"Quit\"");
					}

					if (the_TFQuestion.getQtext().size() < 50) 
					{
						al_draw_textf(font20, black, 50, 115, NULL, "%s", the_TFQuestion.getQtext().c_str());//use stringvar.c_str();
						al_draw_line(40, 135, 625, 135, black, 3);
					}
					else seperate(the_TFQuestion.getQtext());
					al_flip_display();
					if (isSpecialCase == true && size == 1) {
						specialNum = voiceRecognition("True or false Question: "+the_TFQuestion.getQtext());	//beware me
						Sleep(500);
					}
					if (specialNum == 7) break;
					if (mainevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || specialNum >0)
					{
						if (tool.collision(x, y, 75, 420, 75, 200) == true || specialNum ==2)
					{
						//tryAgainTF:
							the_TFQuestion = exam.getRandomTFQuestion(numTF, 2);
							//if (the_TFQuestion.getQtext() == "") goto tryAgainTF;
						if (++picChanger >= 20)picChanger = 0;
						size = 0;
						--maxTF;
						qanswer = false;
						if (the_TFQuestion.getQanswer() == qanswer)tempStu.addScore(the_TFQuestion.getQgrade());
						else tempStu.addScore(-the_TFQuestion.getQpentality());
						continue;
						}
						if (tool.collision(x, y, 545, 420, 60, 200) == true || specialNum == 1)
					{
					//	tryAgainTF2:
							the_TFQuestion = exam.getRandomTFQuestion(numTF, 2);
							//if (the_TFQuestion.getQtext() == "") goto tryAgainTF2;
						if (++picChanger >= 20)picChanger = 0;
						size = 0;
						--maxTF;
						qanswer = true;
						if (the_TFQuestion.getQanswer() == qanswer)tempStu.addScore(the_TFQuestion.getQgrade());
						else tempStu.addScore(-the_TFQuestion.getQpentality());
						continue;
					}
					}
				}
				if (mainevent.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					if (isSpecialCase == false)
					{
						x = mainevent.mouse.x;
						y = mainevent.mouse.y;
					}
					else
					{
						x = 688.0 - newX;
						y = 384.0 - newY;
					}
				}
				if (maxTF == 0 && maxMUL > 0) size = 0;
				if (maxMUL == 0 && maxTF > 0) size = 1;
				if (picChanger >= 20)picChanger = 0;
				al_flip_display();
				if(mainevent.type == ALLEGRO_EVENT_KEY_DOWN) if (mainevent.keyboard.keycode == ALLEGRO_KEY_ESCAPE) break;
				if (mainevent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
			}
			//the pew pew pew part
			if (isScore == true) 
			{
				size = 2;
				if(isSpecialCase==true)
				speak("say fire!",1000);

				while (true) 
				{
					al_hide_mouse_cursor(display);
					ALLEGRO_EVENT mouseevent;
					al_wait_for_event(event_queue, &mouseevent);
					if (mouseevent.type == ALLEGRO_EVENT_MOUSE_AXES )
					{
						if (isSpecialCase == false)
						{
							x = mouseevent.mouse.x;
							y = mouseevent.mouse.y;
						}
						else
						{
							x = 688.0 - newX;
							y = 384.0 - newY;
						}
					}
					al_clear_to_color(white);

					al_draw_rectangle(x, y, x+110, y+170, black, 2);

					if (isShot == true) 
					{
						al_draw_text(font24, black, x + 10, y + 10, NULL, "Your score:");
						al_draw_textf(font75, black, x + 35, y + 95, NULL, "%d", tempStu.getScore());
						if(isFullscreen==true)
						al_draw_text(font75, black, 288, 84, NULL, "Press any button to continue.");
						else al_draw_text(font24, black, 300, 50, NULL, "Press any button to continue.");
						if (isSpecialCase == true && isDummy==true) 
						{
							temp = "";
							temp = temp + "Your score is: " + tempStu.getScore() + " Press any button to continue.";
							al_flip_display();
							speak(temp,7500);
							isDummy = false;
						}
					}
					else al_draw_bitmap(target[0], 688.0 - newX, 384.0 - newY, NULL);
					//special case shoot
					if (isSpecialCase == true) 
					{
						x = 688.0 - newX;
						y = 384.0 - newY;
						if (isDummy == true)
						{
							al_draw_text(font24, red, 300, 400, NULL, "Psst...say: Fire or left-click");
							al_flip_display();
							specialNum = voiceRecognition(emptyy);
							specialNum = 1;
						}
					}

					if(isDummy == false) al_draw_text(font24, red, 150, 200, NULL, "Say: Press/Type (Letter).");
					//1366x768
					if (mouseevent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || specialNum >0) 
					{
						if(isNotMuted==true) al_play_sample(shot, 1, 1, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						if (tool.collision(x, y, 658.0 - newX, 334.0 - newY, 70.0, 85.0) == true) isShot = true; 
						size = 0;
						specialNum = 0;
					}
					if (size < 2) 
					{
						al_draw_bitmap(target[1], 688.0 - newX, 384.0 - newY, NULL);
						++size;
					}
					else al_draw_bitmap(target[0], 688.0 - newX, 384.0 - newY, NULL);
					if (mouseevent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
					if (mouseevent.type == ALLEGRO_EVENT_KEY_DOWN) 
					{
						if (isShot == true) break;
						if (mouseevent.keyboard.keycode == ALLEGRO_KEY_ESCAPE) break;
					}
					al_flip_display();
				}
				//end of shooting loop_______________________________________

				numGrades += tempStu.getScore();
				ofstream grade("database/numGrades.txt");
				grade << numGrades;
				grade.close();
				tool.sendto("database/stuGrade.txt", tempStu.getScore());
				ofstream ExamTakers("database/numExamTakers.txt");//put numbers and character in one line
				ExamTakers << ++numExamTakers;
				ExamTakers.close();
			}
			al_destroy_bitmap(psut);
			al_destroy_display(display);
			al_destroy_font(font);
			
			for (short s = 0; s < 20; s++) { 
				if (s < 2) { 
					al_destroy_bitmap(soundIcon[s]);
					al_destroy_bitmap(target[s]); 
				}
				if (s<17)al_destroy_bitmap(helpPics[s]);
			 al_destroy_bitmap(pics[s]); 
			}
			isShot = isStudent = isExam = isHelp =isScore= false;
		}//end of Student's area_______________________________
		if(isNotMuted==false) al_stop_sample_instance(stuff);
	}
	//end of the system's loop_________________________________
	//Deallocating memory______________________________________
	delete[] TFarr;
	delete[] MULarr;
	delete[] MultipleArr;
	delete[] mulAns;
	al_destroy_sample(shot);
	al_destroy_sample(song);
	al_destroy_sample_instance(stuff);
	al_destroy_font(font20);
	al_destroy_font(font24);
	al_destroy_font(font75);
	return 0;
}//2719 total lines used to be 2545 //main is 928