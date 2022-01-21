/* 
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
------------------------------------------------------
Workshop 1 part 2
Module: phone
Filename: phone.cpp
Version 1
Student	Noel Ibruli
Seneca ID: 117745216
Seneca Email: nibruli@myseneca.ca
Date: 1/20/22 (MM/DD/YY)
------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"
#include "Phone.h"

#define MAX_CHAR_ARRAY 50 // const variable

namespace sdds 
{

	void welcome(const char* title)
	{
		std::cout << title << " phone direcotry search\n-------------------------------------------------------" << std::endl;
	}

	// takes input from user and returns a character array
	char* input_function()
	{
		std::cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << std::endl << "> ";
		static char user_input[MAX_CHAR_ARRAY]; 
		std::cin >> user_input;
		return user_input; // return char aray
	}

	// phone directory application
	void phoneDir(const char* programTitle, const char* fileName) 
	{
		char exit = '!';
		char input[MAX_CHAR_ARRAY] = { '0' };

		char name[MAX_CHAR_ARRAY]; // stores the name from the file
		char area[MAX_CHAR_ARRAY]; // stores the area from the file
		char prefix[MAX_CHAR_ARRAY]; // stores the prefix from the file
		char number[MAX_CHAR_ARRAY]; // stores the number from the file
		char lower_name[MAX_CHAR_ARRAY];

		welcome(programTitle);

		FILE* file; // create a file pointer
		file = fopen(fileName, "r"); // open the file in read mode

		if (file == NULL)
		{
			// if file doesn't exist print error message to the screen
			std::cerr << fileName << " file not found!" << std::endl;
		}
		else
		{
			do
			{
				toLowerCaseAndCopy(input, input_function()); // copy the returned character array to input
				// while scanning the file and not end of file
				while ((fscanf(file, "%[^\t]\t%s\t%s\t%s\n", name, area, prefix, number) && !feof(file)) == true)
				{
					toLowerCaseAndCopy(lower_name, name); // copy name to lower_name
					// looping through each element of the array
					for (int i = 0; i < MAX_CHAR_ARRAY; i++)
					{
						lower_name[i] = toLower(name[i]); // toLower returns the elemnts of the array in lower case
						input[i] = toLower(input[i]); // toLower returns the elemnts of the array in lower case
					}
					// checks if the name is the same as the input
					if (strStr(lower_name, input))
					{
						std::cout << name << ":" << " (" << area << ") " << prefix << "-" << number << std::endl; // if name same as input print the line
					}
				}
				fseek(file, 0, SEEK_SET); // moves file pointer to the beginning of the file
			} while (input[0] != exit); // run until user enters "!" to terminate program
			fclose(file); // close the file
		}
		std::cout << "Thank you for using " << programTitle << " directory." << std::endl; // goodbye message
	}
}