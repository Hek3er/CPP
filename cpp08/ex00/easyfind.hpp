#pragma once

# include <iostream>

template <typename T>
size_t easyfind( T& con, int val ) {
    typename T::iterator it = con.begin();
    int pos = 0;

    while (it != con.end()) {

        if (*it == val) {
            return pos;
        }
        pos++;
        it++;
    }
    return std::string::npos;
}