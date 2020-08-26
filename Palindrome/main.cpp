#include <iostream>
#include <cctype> // needed for tolower(char) and toupper(char) functions
#include <cstring> // needed for strcpy()
#include "functions.h"
using namespace std;


int main(int argc, char* argv[])
{
	bool includeSpaces = false;
	bool caseSensitive = false;
	bool run = true;
	bool terms = false;
	bool in = false;
	
	char copy[500];
	char state = '\0';
	
	string printer = "";
	
	for(int i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-')
		{
			strcpy(copy,argv[i]);
			
			for(int j = 0; copy[j] != '\0'; j++)
			{
				state = tolower(copy[j]);
				if(state == 'c')caseSensitive = true;
				if(state == 's')includeSpaces = true;
				if(!(state == 'c' || state == 's' || state == '\0' || state == '-')){
					in = true;
					run = false;
				}
			}	
		}
		else if(i != 0)
		{
			terms = true;
		}	
	}
	
	if(argc == 1 || !terms && in || in || (caseSensitive || includeSpaces) && !terms)
	{
		printUsageInfo(argv[0]);
		run = false;
	}
	
	//cout << includeSpaces << caseSensitive;
	if(run)
	{		
		for(int i = 1; i < argc; i++)
		{
			if(argv[i][0] != '-')
			{
				printer = argv[i];
				if(isPalindrome(argv[i],caseSensitive,includeSpaces))
				{
					cout << "\"" << printer << "\" is a palindrome.\n";
					//cout << endl << isPalindrome(argv[i],caseSensitive,includeSpaces);
				}	
				else
				{
					cout << "\"" << printer << "\" is not a palindrome.\n";
					//cout << endl << isPalindrome(argv[i],caseSensitive,includeSpaces);
				}
			}
		}
	}
	
	//char w[] = "M o  m";
	//cout << isPalindrome(w,0,1);
	
	
	
	
	return 0;
}