#include "easyfind.hpp"
#include <vector>
#include <stack>
#include <queue>
int main() {

    std::vector<int> arr;

    int def[] = {1, 5, 55, 93};
    
    for (size_t i = 0; i < sizeof(def) / sizeof(def[0]); i++) {
        arr.push_back(def[i]);
    }

    // {1, 5, 55, 93} // vector
    // [0][1] [2]  [3]

    int val = 1;
    std::cout << "pos of " << val << " is " << easyfind(arr, val) << std::endl;

}