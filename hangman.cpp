#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 30;

void clear();
void display_dash(char g[],char w[]);
void check_guess(char g[], char w[], char k);
void word_input(char w[]);
bool is_match(char w[], char g[]);

int main()
{
    char word[SIZE];
	char guess[SIZE];
	char a;
	int counter = 0;

    // word to be guessed
	word_input(word);

    int len = strlen(word);
	clear();
    // display word blanked by dashes
	display_dash(guess, word);
/////
    do 
	{
		check_guess(guess,word, a);
    	clear();
    	cout << guess << endl;
		counter++;
    } while (!is_match(word,guess) && counter <  len + 3 );
//////
    if (strcmp(word,guess) == 0)
        cout <<"Correct " << " " << counter << endl;
    else
        cout <<"sorry, incorrect " << endl;

    return 0;
}
////////////////////////////////////////////////////////////
void clear()
{
    for (int i=0;i<50;i++)
        cout << endl;
}
///////////////////////////////////////
void display_dash(char g[], char w[])
{
	cout << "Please enter your guess " << endl;			
	for (int i = 0; i < strlen(w); i++)
	{
		if (w[i] == ' ')
			g[i] = ' ';
		else
			g[i] = '_';

	}
	cout << g << endl;
}
//////////////////////////////////////
void check_guess(char g[], char w[], char k)
{
	cout << "Enter your guess" << endl;
	cin >> k;
	cin.ignore();
	for (int i = 0; i < strlen(w) ; i++)
	{
		if (w[i] == k)
			g[i] = k;		
	}
}
//////////////////////////////////////
void word_input(char w[])
{
	cout << "Enter a word to  guess " << endl;	
	cin.get(w,SIZE,'\n');
	cin.ignore(100,'\n');
}
/////////////////////////////////////
bool is_match(char w[],char g[])
{
	if(strcmp(w,g) == 0)	
		return true;

	return false;
}
