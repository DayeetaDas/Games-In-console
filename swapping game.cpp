#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
int x1; int x2;
int y1; int y2;
int total_score=0;
char board[6][6];
void instructions()
{
	cout<<"Welcome to the swapping game"<<endl;
	cout<<"A board with two diffrent letters randomly arranged in different positions will be shown"<<endl;
	cout<<"Your job is to swap the letters to create a row or a column of similar variables"<<endl;
	cout<<"The minimum number of letters for a row or a column is 3 and the maximum is 6"<<endl;
	cout<<"There are 5 rounds in this game and the total score at the end of each round will be displayed"<<endl;
	cout<<"Enter the row and the column according to the positions given"<<endl;
	cout<<"All The Best! Enjoy!"<<endl;
}
void position()
{
	cout << "00  01  02  03  04  05 " << endl;
	cout << "10  11  12  13  14  15" << endl;
	cout << "20  21  22  23  24  25" << endl;
	cout << "30  31  32  33  34  35" << endl;
	cout << "40  41  42  43  44  45" << endl;
	cout << "50  51  52  53  54  55" << endl;
}
void draw_board()
{
	char c;
	int r;
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			r= rand() % 2;
			c = 'A' + r;
			board[i][j] = c;
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
}
void user_input()
{
	cout << "Enter the row of the element you want to change the position of:";
	cin >> x1;
	cout << "Enter the column of the element you want to change the position of:";
	cin >> y1;
	cout << "Enter the row of the element you want to change the position with:";
	cin >> x2;
	cout << "Enter the column of the element you want to change the position with:";
	cin >> y2;
}
void swap_positions()
{
	int temp = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			temp = board[x1][y1];
			board[x1][y1] = board[x2][y2];
			board[x2][y2] = temp;
		}
	}
}
void scoring()
{
	int score = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
				if (board[i][j] == board[x1][y1] && board[i + 1][j] == board[x1][y1] && board[i + 2][j] == board[x1][y1] && board[i + 3][j] == board[x1][y1] &&
			 	board[i + 4][j] == board[x1][y1] && board[i + 5][j]== board[x1][y1])
				score = 6;
				else if (board[i][j] == board[x1][y1] && board[i + 1][j] == board[x1][y1] && board[i + 2][j] == board[x1][y1] && board[i + 3][j] == board[x1][y1] &&
			 	board[i + 4][j] == board[x1][y1])
				score = 5;
				else if (board[i][j] == board[x1][y1] && board[i + 1][j] == board[x1][y1] && board[i + 2][j] == board[x1][y1] && board[i + 3][j] == board[x1][y1])
				score = 4;
				else if (board[i][j] == board[x1][y1] && board[i + 1][j] == board[x1][y1] && board[i + 2][j] == board[x1][y1])
				score = 3;
				else if (board[i][j] == board[x1][y1] && board[i][j+1] == board[x1][y1] && board[i][j+2] == board[x1][y1] && board[i][j+3] == board[x1][y1] &&
			 	board[i][j+4] == board[x1][y1] && board[i][j+5]== board[x1][y1])
				score = 6;
				else if (board[i][j] == board[x1][y1] && board[i][j+1] == board[x1][y1] && board[i][j+2] == board[x1][y1] && board[i][j+3] == board[x1][y1] &&
			 	board[i][j+4] == board[x1][y1])
				score = 5;
				else if (board[i][j] == board[x1][y1] && board[i][j+1] == board[x1][y1] && board[i][j+2] == board[x1][y1] && board[i][j+3] == board[x1][y1])
				score = 4;
				else if (board[i][j] == board[x1][y1] && board[i][j+1] == board[x1][y1] && board[i][j+2] == board[x1][y1])
				score = 6;
		}
	}
	total_score+=score;
	cout<<"The current score is:"<<total_score<<endl;
}
int main()
{
	int round=1;
	instructions();
	cout << endl;
	while (round<5)
	{
		cout<<"Welcome to round"<<round<<endl;
		position();
		cout<<endl;
		draw_board();
		user_input();
		swap_positions();
		scoring();
		round++;
	}
	return 0;
}
