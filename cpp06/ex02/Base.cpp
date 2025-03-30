#include "Base.hpp"

Base::~Base() {

}

Base * generate(void) {
    srand(time(NULL));
    int r = rand() % 3;
    switch (r) {
    case 0:
        return new A;
        break;
    case 1:
        return new B;
        break;
    case 2:
        return new C;
    }
    return NULL;
}
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Type is <A>" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Type is <B>" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Type is <C>" << std::endl;
    }
}
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        // (void)p;
        std::cout << "Type is <A>" << std::endl;
        return ;
    } catch(...) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type is <B>" << std::endl;
        return ;
    } catch(...) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type is <C>" << std::endl;
        return ;
    } catch(...) {
    }
}