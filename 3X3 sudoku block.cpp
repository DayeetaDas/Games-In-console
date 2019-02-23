#include "pch.h"
#include<iostream>
using namespace std;
int board[3][3] = { 1,2,3,4,5,6,7,8,9 };
int playboard[3][3] = { 0,2,0,3,0,2,0,0,1 };
int n = 0, num = 0;
void instructions()
{
	cout << "This is a 3X3 single block of a sudoku game" << endl;
	cout << "The player will have only one chance to put a number in place of the zeroes!" << endl;
	cout << "The number should be in the range of(1-3)" << endl;
	cout << "The position of the boxes in the block is as printed below" << endl;
	cout << "All the best!" << endl;
}
void positions()
{
	cout << "Here are the positions for the boxes:" << endl;
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
	cout << "This is the playboard." << endl;
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
	cout << "Enter the number that u want to place in that box:" << endl;
	cin >> num;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == n)
				playboard[i][j] = num;
			cout << playboard[i][j] << " ";
		}
		cout << endl;
	}
}
void check_box()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((playboard[i][j] + playboard[i + 1][j] + playboard[i + 2][j] == 6) && (playboard[i][j] + playboard[i][j + 1] + playboard[i][j + 2] == 6))
			{
				cout << "Congratulations! U have been successful in making the sum of the row and the column to 6!" << endl;
			}
		}
	}
}
int main()
{
	int c = 0;
	instructions();
	cout << endl;
	while (1)
	{
		positions();
		cout << endl;
		draw_board();
		cout << endl;
		user_input();
		cout << endl;
		check_box();
		c++;
		if (c == 5)
		{
			cout << "Game over!" << endl;
			break;
		}
	}
}