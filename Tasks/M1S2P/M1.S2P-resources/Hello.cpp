#include <iostream>

//
int arraySize = 4;

int sum(int n)
{
    static int result = 0;

    result += n;

    return result;
}

int main()
{
    int *p;
    int i = 0;

    p = new int[arraySize];

    int total = 0;

    for (i = 0; i < arraySize; i++)
    {
        std::cout << "enter number " << i + 1 << ": ";
        std::cin >> p[i];
        total = sum(p[i]);
    }

    delete p;

    std::cout << "the final result is " << total;

    return 0;
}