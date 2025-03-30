#include "iter.hpp"

class Base {
public:
    virtual std::string getType() {
        return "Base";
    }
    virtual ~Base() {
        
    }   
};

// class A : public Base {
// public:
//     std::string getType() {
//         return "A";
//     }
// };

// class B : public Base {
//     public:
//     std::string getType() {
//         return "B";
//     }

// };

void print(int v) {
    std::cout << "value: " << v << std::endl;
}

void prints(std::string v) {
    std::cout << "strvalue: " << v << std::endl;
}

// void PrintType(Base *p) {
//     std::cout << "Type is : " << p->getType() << std::endl;
// }

int main() {
    {
        std::string arr[3] = {"hello", "world", "welcome"};
        iter(arr, 3, prints);
    }

    {
        int arr[3] = {4, 1, 3};
        iter(arr, 3, print);
    }

    // {
    //     Base *ptr[] = {new Base, new A, new B};
    //     iter(ptr, 3, PrintType);
    // }
}