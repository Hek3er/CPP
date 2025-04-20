#pragma once

# include <iostream>
# include <algorithm>

template <typename T>
int easyfind( T& con, int val ) {
    typename T::iterator it = std::find( con.begin(), con.end(), val );
    if (it == con.end()) {
        return -1;
    }
    return std::distance(con.begin(), it);
}