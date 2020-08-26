#include <iostream>

using namespace std;

int main() {
    char choice = 'Y';
    char first[50] = "first";
    char second[50] = "second";
    do {
        bool equal = true;
        
        // get inputsy
		
        cout << "Enter first word: ";
        cin >> first;
        cout << "Enter second word: ";
        cin >> second;
        
        // Add code here to
        //   set equal to true or false;
		for(int i = 0; i < 50; i++)
		{
			if(first[i] != second[i])
			{
				equal = false;
			}
			if(first[i] == 0 && second[i] == 0)
			{
				break;
			}
		}

        // output results
        cout << first << " is ";
        if (!equal) {
            cout << "not ";
        }
        cout << "equal to " << second << endl;
        
        // determine whether to continue
        cout << "Do another? (y/n) ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
}