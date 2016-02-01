/******************************************************************************
* Bellevue Class: PROG-111
*           Term: Winter 2016
*     Instructor: Robert Main
*
* Solution/Project Name: ThorntonProject2B
*             File Name: PayPeriodGrossPay.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
*
* Programmer: Chad Thornton
*
* Assigned Project Number: Project 2B
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     01/11/2016  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  ** Asks the user whether they want to display the gross pay in bi-weekly or
*			   bi-monthly, and then asks if they would like to see the other which they 
*				would then input "yes" or "no".
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   ** Outputs text on the console and then asks whether you want the gross pay in bi-weekly
*				or bi-monthly and then displays that text on the console.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* **** Add name and description of any other methods defined in this file ****
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file is required by the Visual Studio complier and
// MUST be first in the "include" files list
#include "stdafx.h"  // Defines IDE required "pre-compiled" definition files

#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
// -----------------
// 
void toUpper(string&);      //Function created by Professor Robert Main
char toUpper(char);         //                 "
void toLower(string&);      //                 "
char toLower(char);         //                 "


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** Program asks the user whether they want to see the gross pay in bi-weekly
* ** or bi-monthly. After the user enters their input it will then display the calculated
* ** value on the console, and ask if the user wants to see the other value. If the user decided
* ** to see the other value it will be displayed on the text otherwise the program will then exit.
* ** 
*
*
* Preconditions
* -------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
*                           *** No methods invoked ***
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution Status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors

	// Uninitialized Variable Declarations

	int employeeSalary = 32500;		//Employee salary. Must change to a double if salary will have a decimal
	int biMonthlyPay = 24;			//Pay periods in a bi-monthly pay schedule
	int biWeeklyPay = 26;			//Pay periods in a bi-weekly pay schedule
	string input;
	string getAnswer;


	do
	{
		cout << "Employee salary is  $32,500 annually. Would you like to know what the gross pay will be for each pay check bi-monthly or bi-weekly?" << endl;

		getline(cin, input);

		toLower(input);

		if (input == "bi-monthly" || input == "bimonthly")
		{
			cout << "Gross pay for each pay period bi-monthly would be " << employeeSalary / biMonthlyPay << "." << endl;
			cout << "Would you like to see what the gross pay would be for bi-weekly?" << endl;

			getline(cin, getAnswer);
			toLower(getAnswer);

			if (getAnswer == "yes")
			{
				cout << "Gross pay for each pay period bi-weekly would be " << employeeSalary / biWeeklyPay << "." << endl;
			}
			else if (getAnswer == "no")
			{
				cout << "Alright, thank you for using the program!" << endl;
			}
		}
		else if (input == "bi-weekly" || input == "biweekly")
		{
			cout << "Gross pay for each pay period bi-weekly would be " << employeeSalary / biWeeklyPay << "." << endl;
			cout << "Would you like to see what the gross pay would be for bi-monthly?" << endl;

			getline(cin, getAnswer);
			toLower(getAnswer);

			if (getAnswer == "yes")
			{
				cout << "Gross pay for each pay period bi-monthly would be " << employeeSalary / biMonthlyPay << "." << endl;
			}
			else if (getAnswer == "no")
			{
				cout << "Alright, thank you for using the program!" << endl;
			}
		}
		else
		{
			cout << "Oops! Something went wrong let's try again" << endl;
		}
	}

	while (input != "bi-weekly" && input != "biweekly"&& input != "bi-monthly" && input != "bimonthly");

	


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()



void toUpper(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toUpper(str[index]);
}

char toUpper(char chr)
{
	if (chr >= 'a' && chr <= 'z')
	{
		unsigned short excludeBit = 'a' - 'A';
		chr = chr ^ excludeBit;
	}

	return chr;
}

void toLower(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toLower(str[index]);
}

char toLower(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		unsigned short includeBit = 'a' - 'A';
		chr = chr | includeBit;
	}

	return chr;
}