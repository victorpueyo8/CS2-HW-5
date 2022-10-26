// Victor Pueyo 
// Homework 5
// Soccer scores

#include<iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Info
{
	string name;
	int number;
	int pointsScored;
};

void highest(Info[], int);

int main()
{
	const int NUM_PLAYERS = 12;
	Info players[NUM_PLAYERS];
	int index;
	int totalPoints = 0;
	string input;

	cout << "Enter the info of the " << NUM_PLAYERS << " players. " << endl;

	for (index = 0; index < NUM_PLAYERS; index++)
	{
		cout << "\nEnter Player's " << (index + 1) << " name: ";
		getline(cin, players[index].name);
		cout << "Enter Player's " << (index + 1) << " number: ";
		cin >> players[index].number;
		while (players[index].number < 0)
		{
			cout << "Number cannot be negative." << endl;
			cout << "Enter Player's " << (index + 1) << " number: ";
			cin >> players[index].number;
		}
		cout << "Enter Player's " << (index + 1) << " points scored: ";
		cin >> players[index].pointsScored;
		while (players[index].pointsScored < 0)
		{
			cout << "Number cannot be negative." << endl;
			cout << "Enter Player's " << (index + 1) << " points scored: ";
			cin >> players[index].pointsScored;
		}
		cin.ignore();
	}

	cout << "\nWhat is the name of the file where you want to store the info: ";
	cin >> input;

	fstream file;

	file.open("Input.txt", ios::out);
	
	file << "\n\nSOCCER TEAM" << endl;
	file << "-----------------------------------------------" << endl << endl;

	file << setw(8) << "NAME ";
	file << setw(20) << "NUMBER";
	file << setw(20) << "PTS SCORED";

	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		file << "\n\n" << setw(8) << players[index].name << setw(18) << players[index].number << setw(20) << players[index].pointsScored;
	}

	file << "\n\n-----------------------------------------------" << endl;

	for (index = 0; index < NUM_PLAYERS; index++)
	{
		totalPoints += players[index].pointsScored;
	}
	cout << "\n\nThe total points of the team is: " << totalPoints << endl;

	highest(players, NUM_PLAYERS);

	system("pause");
	return 0;
}

void highest(Info players[], int size)
{
	int highest = players[0].pointsScored;
	int index = 0;
	for (int count = 1; count < size; count++)
	{
		if (players[count].pointsScored > highest)
		{
			highest = players[count].pointsScored;
			index = count;
		}
	}
	cout << "\nThe name of player who scored the most points is: " << players[index].name << endl << endl;
}
