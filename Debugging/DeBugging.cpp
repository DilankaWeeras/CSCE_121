// Example program
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "int size:    " << sizeof(int) << endl;
    cout << "float size:  " << sizeof(float) << endl;
    cout << "Max int val: " << numeric_limits<int>::max() << endl << endl;
    for (unsigned int i=0; i < numeric_limits<int>::max(); i = i*3+1) {
        float num = i;
        int int2 = num;
        if (i != int2)
            cout << i << endl << int2 << endl << endl;
    }
}
