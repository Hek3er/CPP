#include "easyfind.hpp"
#include <vector>
#include <stack>
#include <queue>
int main() {

    std::vector<int> arr;
    std::stack<int> st;
    std::queue<int> q;

    int def[] = {1, 5, 55, 93};
    
    for (size_t i = 0; i < sizeof(def) / sizeof(def[0]); i++) {
        arr.push_back(def[i]);
    }

    // {1, 5, 55, 93} // vector
    // [0][1] [2]  [3]

    int val = 93;
    std::cout << "pos of " << val << " is " << easyfind(st, val) << std::endl;

}