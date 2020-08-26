#include <iostream>
#include <cctype> // needed for tolower(char) and toupper(char) functions
#include <cstring> // needed for strcpy()

using namespace std;

char word[500];
char wordCopy0[500];
char wordCopy1[500];
int length = 0;



void printUsageInfo(char arg[])
{
	cout << "Usage: "<< arg << " [-c] [-s] <term> ..." << endl << "  -c: turn on case sensitivity\n  -s: turn off ignoring spaces\n";
}

void removeDumb(char word[]) {
    int i=0;
    int offset = 0;
	while (word[i+offset] != '\0') {
		char character = word[i+offset];
		if (ispunct(character)) {
            offset++;
		}
        else {
            word[i] = word[i+offset];
            ++i;
        }
	}
    // set \0
    word[i] = '\0'; // logically the same as word[i] = word[i+offset];
}

void removeSpace(char word[]) {
    int i=0;
    int offset = 0;
	while (word[i+offset] != '\0') {
		char character = word[i+offset];
		if (isspace(character)) {
            offset++;
		}
        else {
            word[i] = word[i+offset];
            ++i;
        }
	}
    // set \0
    word[i] = '\0'; // logically the same as word[i] = word[i+offset];
}

bool isPalindromeR(char word[])
{
	length = strlen(word);
	removeDumb(wordCopy0);
	
	for(int i = 0; i < 500; i++)
	{
		wordCopy0[i] = '\0';
	}
	
	for(int i = 0; i < length; i++)
	{
		wordCopy0[i] = word[i];
	}
	
	for(int i = 0; i < 500; i++)
	{
		wordCopy1[i] = '\0';
	}
	
	//cout << wordCopy0 << " ";
	
	if(wordCopy0[0] != wordCopy0[length-1])
	{
		return false;
	}
	
	if(length < 2)
	{
		return true;
	}
	
	else
	{
		for(int i = 1; i < length - 1; i++)
		{
			wordCopy1[i-1] = wordCopy0[i];
		}
		isPalindromeR(wordCopy1);
	}
}

bool isPalindrome(char word[],bool caseSen, bool spaces)
{
	length = strlen(word);
	removeDumb(word);
	
	if(!spaces)
	{
		removeSpace(word);
	}
	if(!caseSen)
	{
		for(int i = 0; i < length; i++)
		{
			word[i] = tolower(word[i]);
		}
	}
	return isPalindromeR(word);
}
