#include "pch.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int score = 0;
string ans = "";
char board[4][4] = { 'c','o','w','a','a','x','y','n','t','i','l','t','r','o','s','e' };
string questions[100] = { "1) This is a herbivore that eats grass:",
						  "2)This is a six legged insect which is black in colour : ",
						  "3)This is a feline that can also be a pet:",
						  "4)This is a mammal similar to a cow but with a small hump :",
						  "5)This is a synonym for leaning:",
						  "6)This is a red coloured flower with a beautiful fragrance but with sharp thorns :" };
string answers[50] = { "cow" , "ant" , "cat" ,"ox" , "tilt" , "rose" };
void new_board();
void draw_board()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void user_input()
{
	for (int i = 0; i < 6; i++)
	{
		cout << questions[i];
		cin >> ans;
		if (ans == answers[i])
		{
			cout << "Correct!" << endl;
			score += 10;
			new_board();
		}
		else if (ans != answers[i])
		{
			cout << "Wrong!" << endl;
			cout << answers[i];
		}
	}
}
void new_board()
{
	char *word = new char[10];
	for (int i = 0; i < 6; i++)
	{
		if (ans == answers[i])
		{
			word[i] = ans[i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == word[i])
				board[i][j] = ' ';
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	draw_board();
	user_input();
	new_board();
	return 0;
}