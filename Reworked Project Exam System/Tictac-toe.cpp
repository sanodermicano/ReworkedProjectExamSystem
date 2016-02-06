#include"allHeaders.h"

unsigned short AI(char board[][3]) 
{
	unsigned char test = 48;
	unsigned short select = 0;

	//Attack!

	for (short i = 0; i < 3; i++) 
	{
		//columns
		test = 48;
		select = 0;
		for (int i = 0; i < 3; i++) 
		{
			if (board[i][0] == 'O' & board[i][1] == 'O') 
			{
				select += 3;
				test += 3;
				if (board[i][2] == test) return select;
			}
		}
		test = 47;
		select = -1;
		for (int i = 0; i < 3; i++) 
		{
			if (board[i][0] == 'O' && board[i][2] == 'O') 
			{
				select += 3;
				test += 3;
				if (board[i][1] == test) return select;
			}
		}
		test = 46;
		select = -2;
		for (int i = 0; i < 3; i++) 
		{
			if (board[i][1] == 'O'&& board[i][2] == 'O') 
			{
				select += 3;
				test += 3;
				if (board[i][0] == test) return select;
			}
		}
		//rows
		test = 54;
		select = 6;
		for (int i = 0; i < 3; i++) 
		{
			if (board[0][i] == 'O' && board[1][i] == 'O') 
			{
				select++;
				test++;
				if (board[2][i] == test) return select;
			}
		}
		test = 51;
		select = 3;
		for (int i = 0; i < 3; i++) 
		{
			if (board[0][i] == 'O' && board[2][i] == 'O') 
			{
				select++;
				test++;
				if (board[1][i] == test) return select;
			}
		}
		test = 48;
		select = 0;
		for (int i = 0; i < 3; i++) 
		{
			if (board[1][i] == 'O' && board[2][i] == 'O') 
			{
				select++;
				test++;
				if (board[0][i] == test) return select;
			}
		}
	}
	//diagonal o 3aks

	if (board[0][0] == 'O' && board[2][2] == 'O')
		if (board[1][1] == '5') return 5;
	if (board[1][1] == 'O' && board[2][2] == 'O')
		if (board[0][0] == '1') return 1;
	if (board[0][0] == 'O' && board[1][1] == 'O')
		if (board[2][2] == '9') return 9;

	//anti diagonal

	if (board[0][2] == 'O' && board[2][0] == 'O')
		if (board[1][1] == '5') return 5;
	if (board[0][2] == 'O' && board[1][1] == 'O')
		if (board[2][0] == '7') return 7;
	if (board[2][0] == 'O' && board[1][1] == 'O')
		if (board[0][2] == '3') return 3;

	//defence

	//columns 

	//XX[] 3 5 9
	if (board[0][0] == 'X'&& board[0][1] == 'X') if (board[0][2] == '3') return 3;
	if (board[1][0] == 'X'&& board[1][1] == 'X') if (board[1][2] == '6') return 6;
	if (board[2][0] == 'X'&& board[2][1] == 'X') if (board[2][2] == '9') return 9;

	//X[]X 2 5 8
	if (board[0][0] == 'X'&& board[0][2] == 'X') if (board[0][1] == '2') return 2;
	if (board[1][0] == 'X'&& board[1][2] == 'X') if (board[1][1] == '5') return 5;
	if (board[2][0] == 'X'&& board[2][2] == 'X') if (board[2][1] == '8') return 8;

	//[]XX 1 4 7
	if (board[0][1] == 'X'&& board[0][2] == 'X') if (board[0][0] == '1') return 1;
	if (board[1][1] == 'X'&& board[1][2] == 'X') if (board[1][0] == '4') return 4;
	if (board[2][1] == 'X'&& board[2][2] == 'X') if (board[2][0] == '7') return 7;

	//rows

	//7 8 9
	if (board[0][0] == 'X'&& board[1][0] == 'X') if (board[2][0] == '7') return 7;
	if (board[0][1] == 'X'&& board[1][1] == 'X') if (board[2][1] == '8') return 8;
	if (board[0][2] == 'X'&& board[1][2] == 'X') if (board[2][2] == '9') return 9;

	//4 5 6
	if (board[0][0] == 'X'&& board[2][0] == 'X') if (board[1][0] == '4') return 4;
	if (board[0][1] == 'X'&& board[2][1] == 'X') if (board[1][1] == '5') return 5;
	if (board[0][2] == 'X'&& board[2][2] == 'X') if (board[1][2] == '6') return 6;

	//1 2 3
	if (board[2][0] == 'X'&& board[1][0] == 'X') if (board[0][0] == '1') return 1;
	if (board[2][1] == 'X'&& board[1][1] == 'X') if (board[0][1] == '2') return 2;
	if (board[2][2] == 'X'&& board[1][2] == 'X') if (board[0][2] == '3') return 3;


	//diagonal o 3aks

	if (board[0][0] == 'X' && board[2][2] == 'X') if (board[1][1] == '5') return 5;
	if (board[1][1] == 'X' && board[2][2] == 'X') if (board[0][0] == '1') return 1;
	if (board[0][0] == 'X' && board[1][1] == 'X') if (board[2][2] == '9') return 9;

	//anti diagonal

	if (board[0][2] == 'X' && board[2][0] == 'X') if (board[1][1] == '5') return 5;
	if (board[0][2] == 'X' && board[1][1] == 'X') if (board[2][0] == '7') return 7;
	if (board[2][0] == 'X' && board[1][1] == 'X') if (board[0][2] == '3') return 3;

	//first step
	if (board[0][1] == 'X' || board[1][0] == 'X' || board[1][2] == 'X' || board[2][1] == 'X')
		if (board[1][1] == '5') return 5;
	if (board[0][0] == 'X' || board[2][2] == 'X') 
	{
		if (board[0][2] == '3') return 3;
		if (board[2][0] == '7') return 7;
	}
	if (board[0][2] == 'X' || board[2][0] == 'X') 
	{
		if (board[0][0] == '1') return 1;
		if (board[2][2] == '9') return 9;
	}
	if (board[1][1] == 'X') {
		if (board[0][2] == '3') return 3;
		if (board[2][0] == '7') return 7; //bug
		if (board[0][0] == '1') return 1;
		if (board[2][2] == '9') return 9;
	}
	if (board[1][1] == '5') return 5;
	if (board[0][2] == '3') return 3;
	if (board[2][0] == '7') return 7;
	if (board[0][0] == '1') return 1;
	if (board[2][2] == '9') return 9;
	if (board[0][1] == '2') return 2;
	if (board[1][0] == '4') return 4;
	if (board[1][2] == '6') return 6;
	if (board[2][1] == '8') return 8;
	return 1;
}
//game for blind people doesn't even need graphics but need voices and other sensing abilities.
void tictac(bool isSpecialCase)//make the blind-player able to know what is going on in the game, every section status and also make a talking guide about how the game works and what should the player do.
{
	const char c = 3;
	const char r = 3;
	char turn = 'X'; //to switch turns and to restart or end the game (2 uses)
	char board[c][r]; //the tic tac toe board
	short e = 49; //to fill the characters with numbers 1-9 in board
	short col, row; //the player inputs the location in the board
	bool isTie = false;
	string choice;
	string boardTrack[c][r];
	system("cls");
	system("color 8F");


	unsigned short ans; //for AI
	do 
	{
		isTie=false;
		cout << "Human, you are X, do you want to start first?\n(y/n)\n";
		if (isSpecialCase == true)
		{
			cout << "Say: \"Type (Letter)\"\n";
			speak("Welcome to tic tac toe, Say: \"Type H\" if you do not know what is tic tac toe. If you want to start first, say \"type Y\" or if you want the A I to start first say \"type N\"", 12000);
		}
		cin >> turn;
		if (isSpecialCase == true)
		{
			if (turn == 'H' || turn == 'h')
			{
				speak("Tic tac toe is a board game, the board is shaped in this order: If you do not know what is a line, try to swing your hand in the air, and now you have a line, we use lines to create the board's shape and now the shape is: Two parallel lines are lines that goes in the same direction but never cross each others. Now imagine two horizontal parallel lines and two verticle parallel lines crossing each others lines, you will have 9 square areas, from 1 to 9, to win you got to create any 3 filled areas as a line in that board, a vertical line like 1 4 and 7 connected together, a horizontal line like 1 2 and 3, a diagonal line like 1 5 and 9 and an anti-diagonal line like 3 5 and 7", 44000);//check timers in speak
				turn = 'y';
				system("cls");
				continue;
			}
		}
		if (turn == 'y' || turn == 'Y')
			turn = 'X';
		else turn = 'O';
		system("CLS");
		e = 49;
		for (short i = 0; i < c; i++) {
			for (short j = 0; j < r; j++)  board[i][j] = e++; 
		}
		if (isSpecialCase == true) {
			for (short i = 0; i < c; i++) {
				for (short j = 0; j < r; j++)
					boardTrack[i][j] = "Empty";
			}
		}
		while (turn != 'Z')
		{
			for (short i = 0; i < c; i++) 
			{
				for (short j = 0; j < r; j++) cout << '|' << board[i][j]; //to draw the board
				cout << endl;
			}
			if (turn == 'X') 
			{
				cout << "Enter the location in numbers (from 1 to 9)\nNumber:\t";
				if (isSpecialCase == true)
				{
					speak("To track the present state of the game's board say \"Type 0\".",4000);
					cout << "Say: \"Type (Number)\"\n";
					speak("Your turn to Say: \"Type a number from 1 to 9\"\n", 3000);
				}
				cin >> ans;
				if (isSpecialCase == true)
				{
					if (ans == 0)
					{
						speak(" The area 1 is: " + boardTrack[0][0] + " The area 2 is: " + boardTrack[0][1] + " The area 3 is: " + boardTrack[0][2] + " The area 4 is: " + boardTrack[1][0] + " The area 5 is: " + boardTrack[1][1] + " The area 6 is: " + boardTrack[1][2] + " The area 7 is: " + boardTrack[2][0] + " The area 8 is: " + boardTrack[2][1] + " The area 9 is: " + boardTrack[2][2], 25000);//check timers in speak
						system("cls");
						continue;
					}
				}
				else 
					if (ans == 0) 
				{ 
					cout << "try again\n"; 
					Sleep(500); 
					system("cls");
					continue; 
				}
				 if (ans < 0 && ans > 9)
					{
						speak("Try again!",1250);
						if (ans == 0 && isSpecialCase == false)continue;
						continue;
					}
			}
			else 
			{
				cout << "The AI will make a move" << endl;
				Sleep(1000);
				ans = AI(board);
				
			}
			switch (ans) 
			{
			case 1: col = 0;
				row = 0;
				break;
			case 2:col = 0;
				row = 1;
				break;
			case 3:col = 0;
				row = 2;
				break;
			case 4:col = 1;
				row = 0;
				break;
			case 5:col = 1;
				row = 1;
				break;
			case 6:col = 1;
				row = 2;
				break;
			case 7:col = 2;
				row = 0;
				break;
			case 8:col = 2;
				row = 1;
				break;
			case 9:col = 2;
				row = 2;
				break;
			default: break;
			}

			if ((board[col][row] == 'X') || (board[col][row] == 'O')) //checks if the player's input was valid
				cout << "Try again!\n";
			
			else
			{
				if (turn == 'X')
				{
					board[col][row] = 'X';
					if (isSpecialCase == true) boardTrack[col][row] = 'X';
					turn = 'O'; //switches turn to O
				}
				else
				{
					board[col][row] = 'O';

					turn = 'X'; //switches turn to X
					if (isSpecialCase == true)
					{	
						boardTrack[col][row] = 'O';
						choice = "";
						choice = choice + "From 1 to 9 the A I decided to put O in the section: " + ans + " The A I ends his turn.";
						speak(choice, 5500);
					}
			}
				system("CLS");
				for (short i = 0; i < c; i++) 
				{
					//6ooly o 3amoody conditions
					if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
					{
						for (short i = 0; i < c; i++) 
						{
							for (int j = 0; j < r; j++) cout << '|' << board[i][j];
							cout << endl;
						}
						if (turn == 'X') turn = 'O';
						else turn = 'X';
						cout << '\n' << turn << " won!" << endl;
						if (isSpecialCase == true) 
						{
							choice = "";
							choice = choice + turn + " Won the game!";
							speak(choice, 1500);
						}
						turn = 'Z'; //to end 2nd the do loop
						break;
					}
					//Diagonal o 3aks conditions
					if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
					{
						for (short i = 0; i < c; i++) {
							for (int j = 0; j < r; j++) cout << '|' << board[i][j];
							cout << endl;
						}
						if (turn == 'X') turn = 'O';
						else turn = 'X';
						cout << '\n' << turn << " won!" << endl;
						if (isSpecialCase == true)
						{
							choice = "";
							choice = choice + turn + " Won the game!";
							speak(choice, 1500);
						}
						turn = 'Z'; //to end the 2nd do loop
						break;
					}
				}
			}
			//turns++
			//if (turns > 8) 
			if(board[0][0]!='1' && board[0][1]!='2' && board[0][2]!='3' && board[1][0]!='4' && board[1][1]!='5' && board[1][2]!='6' && board[2][0]!='7' && board[2][1]!='8' && board[2][2]!='9')
			{
				turn = 'Z';
				cout << "it's a tie!\n";

				if (isSpecialCase == true)
					speak("It's a tie.", 1500);

				Sleep(500);
			}
		}
		cout << "\nDo you want to try agian? (y/n)\t"; //to finish the 1st loop
		if (isSpecialCase == true)
		{
			cout << "Say: \"Type (Letter)\"\n";
			speak("Do you want to try agian? say \"Type Y\" or \"Type N\"", 5000);
		}
		cin >> turn;
		system("cls");
	} while (turn == 'y' || turn == 'Y');
}