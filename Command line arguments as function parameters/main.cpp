#include <iostream>
#include <cctype> // needed for tolower(char) and toupper(char) functions
#include <cstring> // needed for strcpy()
using namespace std;

// the built in toupper only works for a single character, you'll write an
//   overloaded function that works for C Strings.
// You should use a while loop and look for '\0'
// Don't forget to increment looping variable
void toupper(char word[]) {
	int i = 0;
	while(word[i] != '\0')
	{
		word[i] = toupper(word[i]);
		i++;
	}
}

// the built in tolower only works for a single character, you'll write an
//   overloaded function that works for C Strings.
// You should use a while loop and look for '\0'
// Don't forget to increment looping variable
void tolower(char word[]) {
	int i = 0;
	while(word[i] != '\0')
	{
		word[i] = tolower(word[i]);
		i++;
	}
}

// angle braces <> for required parameters
// square braces [] for optional parameters
// ... for option to repeat previous
void printUsage(char programName[]) {
    cout << "Usage: " << programName << " <-u | -l> <term> [term] ..." << endl;
    exit(1); // exits from program from any function
}

// this program outputs the parameters in all upper or all lower case.
//  2nd parameter should be a flag that starts with a -
//    -u or -U means make output uppercase
//    -l or -L means make output lowercase
// Minimum number of parameters is 3 (program_name flag Term [...])
int main(int argc, char* argv[]) {
    bool upper=false, lower=false;
    // check if enough arguments and output usage statement if not
    if (argc < 3) {
        printUsage(argv[0]);
    }
    
    // determine which flag
    if ('-' == argv[1][0]) { // check if 2nd argument is a flag
        if ('U' == toupper(argv[1][1])) { // check if flag is a valid option
            upper = true;
        }
        else if ('L' == toupper(argv[1][1])) { // check if flag is a valid option
            lower = true;
        }
        else { // invalid flag option
            printUsage(argv[0]);
        }
    }
    else { // 2nd argument is not a flag
        printUsage(argv[0]);
    }
    
    // output terms
    for (int i=2; i<argc; ++i) {
         if (upper) {
            toupper(argv[i]);
        }
        else if (lower) {
            tolower(argv[i]);
        }
        cout << argv[i] << " ";
    }
    cout << endl;
    
}