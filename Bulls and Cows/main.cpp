#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir
	int SIZE;
	int code;
	int nums[10];
	cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> SIZE;
	if(SIZE == 0)
	{
		cout << "Enter code: ";
		cin  >> code;
		cout << "Enter number of digits in code: ";
		cin  >> SIZE;
		for(int i = SIZE - 1; i >= 0; i--)
		{
			nums[i] = code % 10;
			code = code / 10;
		}
	cout << "Number to guess: ";
	for(int i = 0; i < SIZE; i++)
	{
		if(i != SIZE - 1)
		{
		cout << nums[i] << "-";
		}
		else
		cout << nums[i];
	}
	cout << endl;
	}
	else if(SIZE > 2 && SIZE < 10)
	{
		nums[0] = rand() % 10;
		for(int i = 1; i < SIZE; i++)
		{
			bool s = true;
			nums[i] = rand() % 10;
			while(s)
			{
				s = false;
			for(int j = 0; j < i; j++)
			{
				if(nums[i] == nums[j])
				{
					nums[i] = rand() % 10;
					s = true;
				}
			}
			}
		}
	cout << "Number to guess: ";
	for(int i = 0; i < SIZE; i++)
	{
		if(i != SIZE - 1)
		{
			cout << nums[i] << "-";
		}
		else
			cout << nums[i];
		}
		cout << endl;
	}
	bool run = true;
	int guess;
	int guessA[10];
	bool compute = true;
	bool repeat = false;
	while(run)
	{
		compute = true;
		repeat = false;
		int bulls = 0;
		int cows = 0;
		cout << "Enter Guess: ";
		cin >> guess;
		int temp = guess;
		int count = 0;
		for(int i = 0; i < 10; i++)
		{
			if(temp > 0)
			{
				count += 1;
			}
			temp /= 10;
		}	
		for(int i = SIZE - 1; i > -1; i--)
		{
			guessA[i] = guess % 10;
			guess = guess / 10;
		}
		for(int i = 0; i < SIZE; i++)
		{
			for(int j = 0; j < SIZE; j++)
			{
				if(i != j && guessA[i] == guessA[j])
				{
					compute = false;
					repeat = true;
				}
			}
		}
		if(count > SIZE)
		{
			cout << "You can only enter " << SIZE << " digits. \n";
			compute = false;
		}
		else if(repeat)
		{
			cout << "Each number must be different.\n";
		}
		if(compute)
		{
			for(int i = 0; i < SIZE; i++)
			{
				for(int j = 0; j < SIZE; j++)
				{
					if(guessA[i] == nums[j])
					{
						if(i == j)
						{
							bulls += 1;
						}
						else
						{
							cows += 1;
						}
					}
				}
			}
		}
		if(compute && bulls != SIZE)
		{
			cout << bulls << " bulls\n" << cows << " cows\n";
		}
		else if(bulls == SIZE && compute)
		{
			cout << bulls << " bulls... ";
			for(int i = 0; i < SIZE; i++)
				{
					if(i != SIZE - 1)
					{
						cout << nums[i] << "-";
					}
					else	cout << nums[i];
			}
			cout << " is correct!\n";
			run = false;
		}
	}
}

