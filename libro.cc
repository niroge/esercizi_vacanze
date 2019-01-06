// Esercizi del libro
// Copyright (C) 2018   <robert@battlestation>
// 
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// Except as contained in this notice, the name(s) of the above copyright
// holders shall not be used in advertising or otherwise to promote the
// sale, use or other dealings in this Software without prior written
// authorization.

// include the required libraries
#include <iostream>
#include <string>
#include <cstring>

// define the required functions
void number_19(void);
void number_20(void);
void number_21(void);
void number_22(void);
void number_23(void);
void number_24(void);
void number_25(void);
void number_26(void);
void number_27(void);
void number_28(void);
void number_29(void);
void number_30(void);

void run_function(void (*func)(void), const char *descri); // run a function through a function pointer
void print_banner(const char *msg);			   // print the banner if msg is not empty

// create the main function
int main(void)
{
	// run_function(number_19, "Read the numbers until 0");
	// run_function(number_20, "Inputs 10 names");
	// run_function(number_21, "Given names and cities, count how many are from Milan");
	// run_function(number_22, "Given a list of items' descriptions and prices, count how many are over €100");
	// run_function(number_23, "Given the item's name, original price and the increased price's percentage, print the new price");
	// run_function(number_24, "Find the average consuption of the fuel of some vehicles given the KMs and the liters of fuel for each vehicle");
	// run_function(number_25, "Transform a while loop in a for loop n1");
	// run_function(number_26, "Transform a while loop in a for loop n2");
	run_function(number_27, "Given in input the number of items and the prices, sum the prices");
	run_function(number_28, "Given names and final grades of secondary school , find the average of the grades");
	run_function(number_29, "Given N students at a speed race (name, category, time), print the winner in the category students");
	run_function(number_30, "THE LAST ONE STANDING");
	return 0;
}

// create the function runner
void run_function(void (*func)(void), const char *descri) {
	print_banner(descri);
	(*func)();
	print_banner("");
}

void print_banner(const char *msg) {
	// this function prints the banner
	
	if (strlen(msg) < 5)
		// description is empty, this means end of function
		std::cout << "===[ END OF FUNCTION ]===========================================================" << std::endl << std::endl << std::endl << std::endl;
	
	else
		// print the description of a function
		std::cout << "===[ " << msg << " ]==================" << std::endl;
}

void number_19(void)
{
	for (int i = 1; i != 0; ) {
		std::cout << "Number (insert 0 to terminate): ";
		if (!(std::cin >> i)) { // if input is invalid, print anscuola media error message
			std::cerr << "[-] You can NOT insert letters" << std::endl;
			std::cin.ignore(10000, '\n');
			std::cin.clear();
		}
	}
}

void number_20(void)
{
	std::string name;
	std::cin.ignore(10000, '\n');
	for (int i = 0; i < 10; i++) {
		std::cout << "name " << i + 1 << ": ";
		std::getline(std::cin, name);
	}
}

void number_21(void)
{
	int milan_citizens = 0;
	std::string name, city;

	for (int i = 0; i < 10; i++) {
		// input the name of the citizen
		std::cout << "Name " << i + 1 << ": ";
		std::getline(std::cin, name);

		// input the citizen's city name
		std::cout << "City: ";
		std::getline(std::cin, city);

		for (unsigned int i = 0; i < city.length(); i++)
			city[i] = std::toupper(city[i]);
		
		// is the city Milan?
		if (city == "MILAN" || city == "MILANO")
			milan_citizens++;
	}

	std::cout << "Number:";
	std::cout.width(2);
	std::cout << std::right << milan_citizens;
	std::cout << std::endl;
}

void number_22(void)
{
	float price;
	int overpriced = 0;
	std::string name, description;

	std::cout << "Type << go fund yourself >> instead of name to close" << std::endl;
	for (;;) {
		std::cout << "Item's name: ";
		std::getline(std::cin, name);

		if (name == "go fund yourself")
			break;

		std::cout << "Item's description: ";
		std::getline(std::cin, description);

		std::cout << "Price of <<" << name << ">>: ";
		while (!(std::cin >> price)) {
			std::cerr << "[-] Wait wait wait, you aren't a retard, are ya?" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

		if (price > 100)
			overpriced++;

		std::cin.get();
	}

	std::cout << "Overpriced items: " << overpriced << std::endl;
}

void number_23(void)
{
	std::string item_name;
	float original_price = 0.0, increment = 0.0;

	std::cout << "Item name: ";
	std::getline(std::cin, item_name);

	std::cout << "Original price: ";
	while (!(std::cin >> original_price) || original_price <= 0) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "[-] Waaaaait a sec, you aren't a retard, are ya?" << std::endl;
		std::cout << "Original price: ";
	}

	std::cout << "Incremental percentage (no % please): ";
	while (!(std::cin >> increment) || increment <= 0) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "[-] Wow, such genius" << std::endl;
		std::cout << "Incremental percentage (no % please): ";
	}

	original_price += original_price * (increment / 100);

	std::cout << "[+] New price: " << original_price << std::endl;
}

void number_24(void)
{
	double fuel_ratio = 0;
	int number_cars;
	double kilometers, liter;

	std::cout << "Number of cars: ";
	while (!(std::cin >> number_cars) || number_cars <= 0) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "[-] Wow, r/iamverysmart" << std::endl;
	}

	for (int i = 0; i < number_cars; i++) {
		std::cout << "Kilometers: ";
		while (!(std::cin >> kilometers) || kilometers <= 0) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "[-] Fucking idiot" << std::endl;
		}

		std::cout << "Liters: ";
		while (!(std::cin >> liter) || liter < 0) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "[-] Fucking smartass" << std::endl;
		}

		fuel_ratio += kilometers / liter;
	}

	std::cout << "km/l ratio of " << number_cars << " cars: " << fuel_ratio / number_cars << std::endl;
}

void number_25(void)
{
	for (int a = 1; a <= 10; a++)
		std::cout << a << std::endl;
}

void number_26(void)
{
	std::cout << 11 << std::endl;
}

void number_27(void)
{
	int number_elements;
	double price;
	double sum_of_all = 0;
	
	std::cout << "Number of elements: ";
	while (!(std::cin >> number_elements) || number_elements <= 0) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "[-] Yeah, go fund yourself" << std::endl;
	}

	for (int i = 0; i < number_elements; i++) {
		std::cout << "Element " << i + 1 << ": ";
		while (!(std::cin >> price) || price <= 0) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "[-] What the actual fuck?" << std::endl;
		}

		sum_of_all += price;
	}

	std::cout << "[+] You have to pay " << sum_of_all << "..." << std::endl;
}

void number_28(void)
{
	std::string name;
	int grade;
	double average = 0;

	for (int i = 0; i < 20; i++) {
		std::cin.ignore(10000, '\n');
		std::cout << "Name: ";
		std::getline(std::cin, name);

		std::cout << "Final grade: ";
		while (!(std::cin >> grade) || grade <= 0 || grade > 10) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "[-] Fucking genius, I have to say" << std::endl;
		}

		average += grade;
	}

	average /= 20;

	std::cout << "[+] Average: " << average << std::endl;
}

void number_29(void)
{
	std::string name, category, current;
	float timer, record = 0;

	for (int i = 0; i < 25; i++) {
		std::cin.ignore(10000, '\n');
		std::cout << "Name: ";
		std::getline(std::cin, name);

		std::cout << "Category: ";
		std::getline(std::cin, category);

		std::cout << "Time (in milliseconds): ";
		std::cin >> timer;
		
		if (category == "students") {
			if (record > timer || i == 0) {
				record = timer;
				current = name;
			}
		}
	}

	std::cout << "Winner: " << current << " (" << record << ")." << std::endl;
}

void number_30(void)
{
	std::string name;
	int type;
	float price, max_price = -1;

	for (int i = 0; i < 20; i++) {
		std::cin.ignore(10000, '\n');
		std::cout << "Name: ";
		std::getline(std::cin, name);

		std::cout << "Type: ";

		while (!(std::cin >> type)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "Only the number please :3" << std::endl;
		}

		std::cout << "Price: ";

		while (!(std::cin >> price)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "Fucking genius m8!" << std::endl;
		}
		
		
		if (type == 50 && max_price < price)
			max_price = price;
	}

	std::cout << "Max price: " << max_price << std::endl;
}
