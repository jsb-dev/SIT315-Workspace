#include <iostream>

// This was the main problem, using a variable name included in the std namespace
// using namespace std;
// int size = 4;

// the var name needs to be unique

// I also revisited some best-practise principles that emphasised the inline reference
// to the namespace to avoid things like namespace pollution and source-ambiguity

// All this in mind, I swapped the using statement for std inline,
// using a more descriptive var name that doesn't conflict with std declarations

int arraySize = 4; // holds the collection of user inputs

// Helper function for adding together arrySize entries consecutively,
// requires prompted input from user for each value via loop
int sum(int n)
{
    static int result = 0;

    result += n;

    return result;
}

int main()
{
    int *p; // introduced without initialisation, no size determined
    int i = 0;

    p = new int[arraySize]; // use new to instantitate the pointer with a valid address of arraySize

    int total = 0;

    for (i = 0; i < arraySize; i++) // loop through the size of input declared globally
    {
        std::cout << "enter number " << i + 1 << ": ";
        std::cin >> p[i];
        total = sum(p[i]); // pass the consecutive value to sum() for each entry 1 - n
    }

    delete p; // clean up memory

    std::cout << "the final result is " << total; // print result

    return 0;
}