#include "whatever.hpp"

// int main() {

//     bool boolean1 = true;
//     bool boolean2 = false;
//     swap(boolean1, boolean2);
//     std::cout << "boolean 1 : " << boolean1 << " boolean2: "  << boolean2 << std::endl;

//     float f1 = 13.5;
//     float f2 = 0.5;
//     swap(f1, f2);
//     std::cout << "f1 : " << f1 << " f2 : " << f2 << std::endl;

//     std::string hello = "hello";
//     std::string world = "world";
//     swap(hello, world);
//     std::cout << hello << " " << world << std::endl;

//     {
//         int v1 = 3;
//         int v2 = 1;
//         std::cout << "min : " << min(v1, v2) << " max : " << max(v1, v2) << std::endl;
//     }

//     {
//         float v1 = 33.12;
//         float v2 = 1.111;
//         std::cout << "min : " << min(v1, v2) << " max : " << max(v1, v2) << std::endl;
//     }

// }

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
    }