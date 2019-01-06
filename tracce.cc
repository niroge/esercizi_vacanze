/*
 * Copyright (c) 2018 Nitu Robert Georgian
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* including the required libraries... */
#include <iostream>                                             /* contains std::cin and std::cout */
#include <iomanip>                                              /* for formatting functions like setw() for std::cout */
#include <cstring>                                              /* for strlen() */

/* define the ID's for print_banner to make the code look easier to read */
#define PRINT_BANNER 1
#define PRINT_END_LINE 2

/* creating the functions... */
void exercise_1(void);
void exercise_2(void);
void exercise_3(void);
void exercise_4(void);
void exercise_5(void);
void exercise_6(void);

void function(const char *msg, void (*exercise) (void));        /* runs a function */
void print_banner(const char *msg, int id);                     /* prints the banner or the end line based on the id */


/* run all the functions xD */
int main(void)
{
    //function("First exercise ~ print from 0 to 9", exercise_1);
    //function("Second exercise ~ print from 9 to 0", exercise_2);
    //function("Third exercise ~ print all odd numbers till n included", exercise_3);
    //function("Fourth exercise ~ print the sum of the first n numbers", exercise_4);
    //function("Fifth exercise ~ print the product of the first n numbers", exercise_5);
    function("Sixth exercise ~ print in a column in pair of 3 with a distance of 10 the first 18 numbers", exercise_6);

    return 0;
}

/* Now it's a great time to get fucked */
/* defining *ALL* the functions */
void function(const char *msg, void (*exercise) (void))
{
    print_banner(msg, PRINT_BANNER);
    (*exercise)();
    print_banner(msg, PRINT_END_LINE);
    return;
}

void print_banner(const char *msg, int id)
{
    if (id == PRINT_BANNER) {
        std::cout << msg << std::endl;
        for (unsigned long int i = 0; i < (strlen(msg) / sizeof(char)); i++)
            std::cout << "=";

        std::cout << std::endl;
    } else if (id == PRINT_END_LINE) {
        for (unsigned long int i = 0; i < (strlen(msg) / sizeof(char)); i++)
            std::cout << "=";

        std::cout << "\r==[ end ]" << std::endl << std::endl << std::endl;
    }
}

void exercise_1(void)
{
    for (int i = 0; i < 10; i++)
        std::cout << i << " ";

    std::cout << std::endl;
}

void exercise_2(void)
{
    for (int i = 9; i >= 0; i--)
        std::cout << i << " ";

    std::cout << std::endl;
}

void exercise_3(void)
{
    unsigned long long int number;

    std::cout << "Number: ";

    if (std::cin >> number && number > 0) {
        for (unsigned long long int i = 1; i <= number; i += 2)
            std::cout << i << " ";

        std::cout << std::endl;
    } else {
        std::cerr << "[-] Invalid input..." << std::endl;
        std::cin.ignore();
        std::cin.clear();
        exercise_3();
    }
}

void exercise_4(void)
{
    unsigned long long sum = 0, number;

    std::cout << "Number: ";
    
    if (std::cin >> number) {
        for (unsigned long long int i = 0; i < number; i++) /* 0 is a number sooo count until n - 1 */
            sum += i;

        std::cout << "Sum of the first " << number << " numbers: " << sum << std::endl;
    } else {
        std::cerr << "[-] Invalid input..." << std::endl;
        std::cin.ignore();
        std::cin.clear();
        exercise_4();
    }
}

void exercise_5(void)
{
    unsigned long long product = 1, number;

    std::cout << "Number: ";

    if (std::cin >> number) {
        for (unsigned long long int i = 1; i <= number; i++) /* 0 is not available and so count until n */
            product *= i;

        std::cout << "Product of the first " << number << " numbers: " << product << std::endl;
    } else {
        std::cerr << "[-] Invalid input..." << std::endl;
        std::cin.ignore();
        std::cin.clear();
        exercise_5();
    }
}

void exercise_6(void)
{
    for (int i = 0; i < 18; i += 3) {
        for (int j = i; j < i + 3; j++) {
            std::cout.width(10);
            std::cout << j << "     ";
        }

        std::cout << std::endl;
    }
}
