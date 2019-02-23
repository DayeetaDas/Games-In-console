#include "pch.h"
#include<iostream>
using namespace std;
int board[3][3] = { 1,2,3,4,5,6,7,8,9};
int playboard[3][3] = { 1,0,3,0,1,0,2,0,0 };
int n = 0, num = 0;
void instructions()
{
	cout << "This is one block of a sudoku game." << endl;
	cout << "You will be able to place a number in the spaces ranging from (1-3)" << endl;
	cout << "The positions in the box is listed below." << endl;
	cout << "U can change a number that u have already entered. But remember that u have only 5 tries!" << endl;
	cout << "This means one try for one blank!" << endl;
	cout << "ALL THE BEST!" << endl;
}
void positions()
{
	cout << "The following board displays the position of the boxes in the playboard:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void draw_board()
{
	cout << "This is the playboard:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << playboard[i][j] << " ";
		}
		cout << endl;
	}
}
void user_input()
{
	cout << "Enter the number of the box where u want to place ur input:" << endl;
	cin >> n;
	cout << "Enter the number u want to place in the box:" << endl;
	cin >> num;
}
void check_board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == n)
			{
				playboard[i][j] = num;
			}
		}
	}
}
void success()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((playboard[i][j] + playboard[i + 1][j] + playboard[i + 2][j] == 6) && (playboard[i][j] + playboard[i][j + 1] + playboard[i][j + 2] == 6))
			{
				cout << "Congratulations the sum of the row and column is the same and is equal to 6!" << endl;
			}
		}
	}
}
int main()
{
	instructions();
	cout << endl;
	int c = 0;
	while (1)
	{
	    positions();
		cout << endl; 
		draw_board();
		cout << endl;
		user_input();
		cout << endl;
		check_board();
		success();
		c++;
		if (c == 5)
		{
			cout << "Game over!" << endl;
			break;
		}
	}
	cout << endl;
	return 0;
}
