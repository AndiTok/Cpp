#include <iostream>
// #include <Array.hpp>
#include "Array.hpp"

#define MAX_VAL 5 // 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    // {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    // }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << '\n';
        std::cout << mirror[i] << "\n\n";
    }

    std::cout << "=====\n\n";
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0; // if size is 5 max [] is 4 coz 0 to 4
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    for (int i = 0; i < MAX_VAL; i++) // check deep copy if different is correct
    {
        std::cout << numbers[i] << '\n';
        std::cout << tmp[i] << "\n\n"; // use tmp or test (refer to SCOPE)
        // tmp or test should maintain value assigmen by number
        // number should be different
    }
    delete [] mirror;//
    return 0;
}