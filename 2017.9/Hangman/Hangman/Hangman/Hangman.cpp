// Hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	//setup
	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed

	vector<string> words; //collection of possible words to guess
	words.push_back("SMELT");
	words.push_back("CHUNKY");
	words.push_back("STRESSER");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFAR(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Hangman. Good luck! \n";

	while ((wrong < MAX_WRONG) && (soFAR != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFAR << endl;

		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); //make uppercase since secret word in uppercase
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";

			//update soFAR to include newly guessed letter
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFAR[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word.\n";
			++wrong;
		}
	}

	//shut down
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou've been hanged!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}

	cout << "\nThe word was " << THE_WORD << endl;
    return 0;
}

