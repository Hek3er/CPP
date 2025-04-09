#include <iostream>
#include "Array.hpp"

int main() {

    // Array<int> f(1);
    // f[1];
    Array<int> arr(10);

    for (size_t i = 0; i < arr.getSize(); i++) {
        std::cout << arr[i] << std::endl;
    }

    //causes an error
    try {
        arr[-1] = -1;
    } catch( std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // #define MAX_VAL 750
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }

    // for (size_t i = 0; i < numbers.getSize(); i++) {
    //     std::cout << "number[" << i << "] = " << numbers[i] << " | " << mirror[i] << std::endl;
    // }

    Array<char> c(5);
    c[0] = 'h';
    c[1] = 'e';
    c[2] = 'l';
    c[3] = 'l';
    c[4] = 'o';

    for (size_t i =0; i < c.getSize(); i++) {
        std::cout << c[i] << std::endl;
    }
    std::cout << "\n";

    Array<char> clone(c);
    c[4] = 'k';
    for (size_t i =0; i < clone.getSize(); i++) {
        std::cout << clone[i] << std::endl;
    }
    std::cout << "\n";

    Array<char> copy(5);
    copy = c;
    for (size_t i =0; i < copy.getSize(); i++) {
        std::cout << copy[i] << std::endl;
    }
    


}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << "error here1" << std::endl;
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << "error here" << std::endl;
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }