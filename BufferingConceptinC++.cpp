#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <fstream>
#include <iostream>
// Asad Haroon
using namespace std;

int main()
{

	char b1[4096];
	char b2[4096];

	ifstream obj;
	obj.open("qwe.txt"); // read content from file.

	char* curr_buff = b1;
	obj.get(curr_buff, 4096, EOF);

	int count = 0, c;
	int starting = 0;
	int ending = 0;
	int previousBuffer = 1;

	while (curr_buff[count] != '\0')
	{
		ending++;
		if (isspace(curr_buff[count]))
		{
			cout << "\n";
			if (starting < ending)
			{
				for (c = starting; c < ending; c++)
				{
					cout << curr_buff[c];
				}
			}
			else
			{
				if (previousBuffer == 1)
				{
					while (b1[starting] != NULL)
					{
						cout << b1[starting];
						starting++;
					}
					for (c = 0; c < ending; c++)
					{
						cout << curr_buff[c];
					}
				}
				else if (previousBuffer == 2)
				{

					while (b2[starting] != NULL)
					{
						cout << b2[starting];
						starting++;
					}
					for (c = 0; c < ending; c++)
					{
						cout << curr_buff[c];
					}
				}
			}
			cout << "\n";
			starting = ending;
		}
		count++;
		if (count > 4094)
		{
			if (curr_buff == b1)
			{
				curr_buff = b2;
				previousBuffer = 1;
				ending = 0;
				cout << endl << endl << endl << "buffer changed 1" << endl << endl << endl;
			}
			else if (curr_buff == b2)
			{
				curr_buff = b1;
				previousBuffer = 2;
				ending = 0;
				cout << endl << endl << endl << "buffer changed 2" << endl << endl << endl;
			}
			obj.get(curr_buff, 4096, EOF);
			count = 0;
		}
	}
	for (c = starting; c < ending; c++)
	{
		cout << curr_buff[c];
		count++;
	}
	printf("\n");
	cout << "count is " << count;
	system("pause");

	return 0;
}

