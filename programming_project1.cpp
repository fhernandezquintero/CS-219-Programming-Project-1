/*
    Course: CS 219 File purpose: Programming Project 1 Due: 1/28/2022
    @file programming_project1.cpp
    @author Azael Hernandez Quintero
    @version 2.4 1/28/2022
*/

#include<iostream>

using namespace std;

#include <bits/stdc++.h>
#include<math.h>
#include<cstdint>
#include<string>

/*
	Map for converting hexadecimal values to decimal.
	@param A char corresponding to its hexadecimal symbol
	@return An int corresponding to the decimal value of the corresponding hexadecimal symbol
*/
map<char, int> hex_value(void)
{
    //Map symbols to decimal values
    map<char, int> hex
	{ 
		{ '0', 0 }, { '1', 1 },
		{ '2', 2 }, { '3', 3 },
		{ '4', 4 }, { '5', 5 },
		{ '6', 6 }, { '7', 7 },
		{ '8', 8 }, { '9', 9 },
		{ 'A', 10 }, { 'B', 11 },
		{ 'C', 12 }, { 'D', 13 },
		{ 'E', 14 }, { 'F', 15 }
	};
    return hex;
}

/*
	Function Add_Hex is used to add two hexadecimal numbers from the provided text file.
	@param Two strings (string a and string b) corresponding to the hexadecimal numbers used in the ADD operation
	@return Cout stream containing the hexadecimal sum
*/
void Add_Hex(string a, string b)
{
	map<char, int> hex2dec = hex_value();
	uint32_t sum = 0;
	int power = 0;
	string ans = "";

	//Check if length of first string is greater than or equal to second string
    if (a.length() > b.length())
        swap(a, b);

    //Store length of both strings
    int l1 = a.length(), l2 = b.length();

    //Traverse till the second string is traversed completely
    for (int i = l1 - 1, j = l2 - 1;j >= 0; i--, j--) 
	{
        //Decimal value of element at a[i]
        //Decimal value of element at b[j]
		sum += pow(16,power)*hex2dec[a[i]] + pow(16,power)*hex2dec[b[j]];
		power++;
    }
	//Output sum in stream
	cout << "ADD " << a << " + " << b << " = 0x" << hex << uppercase << sum << endl;
}

//Main (driver)
int main(void)
{
	//Open designated text file to read
	ifstream readFile("Programming-Project-1.txt");

	//If statement for file open error detection
	if(readFile.fail())
	{
		cout << "The file could not be opened. Please verify integrity of files.\n" << endl;
	}
	else
	{
		string wordEntry;

		//While looop to extract the strings from the text file to be used in an operation
		while(readFile >> wordEntry)
		{
			if(wordEntry=="ADD")
			{
				string word1;
				string word2;
				readFile >> wordEntry;
				word1 = wordEntry;
				readFile >> wordEntry;
				word2 = wordEntry;
				Add_Hex(word1, word2);
			}
		}
		readFile.close();
	}
  
	return 0;
}
