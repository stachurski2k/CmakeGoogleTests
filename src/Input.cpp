#include "Input.h"
void Mouse::SetX(double x){
    this->x=x;
    NotifyAll();
}
void Mouse::SetY(double y){
    this->y=y;
    NotifyAll();
}
double Mouse::GetX(){return x;}
double Mouse::GetY(){return y;}