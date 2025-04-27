#pragma once
#include "IObservable.h"

class Mouse:public IObservable{
    double x,y;
public:
    void SetX(double x);
    void SetY(double y);
    double GetX();
    double GetY();
};