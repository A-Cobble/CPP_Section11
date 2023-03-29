
/*
		This challenge is about using a collection (list) of integers and allowing the user to select
		options from a menu to perform operations on the list.

		Your program should display a menu options to the user as follows:

		P - Print numbers
		A - Add a number
		M - Display mean of the numbers
		S - Display the smallest number
		L - Display the largest number
		Q - Quit

		Enter your choice:

		The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
		If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu
		options should be displayed again.

		If the user enters 'P' or 'p' you should display all of the elements (ints) in the list.
		If the list is empty you should display "[] - the list is empty"
		If the list is not empty then all the list elements should be displayed inside square brackets separated by a space.
		For example, [ 1 2 3 4 5 ]

		If the user enters 'A' or 'a' then you should promp the user for an integer to add to the list which you
		will add to the list and then display it was added. For example, if the user enters 5
		You should display, "5 added".
		Duplicate list entries are OK

		If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
		If the list is empty you should display, "Unable to calculate the mean - no data"

		If the user enters 'S' or 's' you hsould display the smallest element in the list.
		For example, if the list contains [2 4 5 1], you should display, "The smallest number is 1"
		If the list is empty you should display, "Unable to determine the smallest number - list is empty"

		if the user enters 'L' or 'l' you should display the largest element in the list
		For example, if the list contains [2 4 5 1] you should display, "The largest number is 5"
		If the list is empty you should display, "Unable to determine the largest number - list is empty"

		if the user enters 'Q' or 'q' then you should display 'Goodby" and the program should terminate.

		Before you begin. Write out the steps you need to take and decide in what order they should be done.
		Think about what loops you should use as well as what you will use for your selection logic.

		Hint: Use a vector!

		Additional functionality if you wish to exten this program
			-search for a number in the list and if found display the number of times it occurs in the list
			-clearing out the list (make it empty again)(Hint: the vector class has a .clear() method)
			-don't allow duplicate entries
	*/

/*
	Recall the challenge from Section 9 above.
	Your challenge for section 11 is to modularize your solution to the Section 9 challenge by
	refactoring your solution so that it uses functions.

	You decide how to modularize the program.
	
	Here are a few hints:
		-Create functions for each major function
		-Keep the functions small
		-Remember the Boss/Worker analogy
		-Keep the vector declaration in the main function and pass the vector object to any function that requires it

		DO NOT move the vector object outside the main and make it a global variable.

		-You can start by defining a function that displays the menu
		-You can then define a function that reads the selection from the user and returns it in uppercase
		-Create functions for each menu option
		-Create functions that display the list of numbers, calculates the mean and so forth

	Take it one function at a time and take your time.
	If you get frustrated, take a break

	Finally, don't forget to use function prototypes!
*/

#include <iostream>
#include <vector>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

char makeLowercase(char &userInput);
void printNumbers(vector <int> numbers);
void addNumber(int &userInput, vector <int> &numbers);

void menu() {
	cout << "P - Print numbers";
	cout << "\nA - Add a number"; 
	cout << "\nM - Display mean of the numbers";
	cout << "\nS - Display the smallest number";
	cout << "\nL - Display the largest number";
	cout << "\nQ - Quit" << endl;

	cout << "\nEnter your choice: ";
}

char makeLowercase(char &userInput) {
	return toupper(userInput);
}

void printNumbers(vector <int> numbers) {
	if (numbers.size() == 0) {
		cout << "[] - the list is empty" << endl;
	}
	else {
		cout << "[ ";
		for (auto num : numbers) {
			cout << num << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;
}

void addNumber(int &userInput, vector <int> &numbers) {
	cout << "Enter an Integer to add: ";
	cin >> userInput;
	numbers.push_back(userInput);
	cout << userInput << " added." << endl;
	cout << endl;
}

void quit() {
	cout << "Goodbye..." << endl;
}


int main() {


	char userSelection{};
	vector <int> numbers{};
	int userInput{};

	do {
		menu();
		cin >> userSelection;
		userSelection = makeLowercase(userSelection);
		if (userSelection == 'P'){
			printNumbers(numbers);
		}
		else if (userSelection == 'A') {
			addNumber(userInput, numbers);
		}
		else if (userSelection == 'Q') {
			quit();
		}

	} while (userSelection != 'Q');


	cout << endl;
	return 0;
}