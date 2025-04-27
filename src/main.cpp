#include <iostream>
#include "Input.h"
int main(int, char**){
    Mouse m;
    double x =7.0;
    m.Register([&x](IObservable& o){
        auto mouse = static_cast<Mouse&>(o);
        std::cout<<mouse.GetX()<<" "<<mouse.GetY()<<std::endl;
        std::cout<<(mouse.GetX()==x)<<std::endl;
    });
    m.SetX(x);
    return 0;
}
