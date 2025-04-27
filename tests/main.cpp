#include <gtest/gtest.h>
#include "Input.h"
TEST(MouseTests, Move) {
    Mouse m;
    double x =7.0;
    m.Register([&x](IObservable& o){
        auto mouse = static_cast<Mouse&>(o);
        ASSERT_EQ(mouse.GetX(),x);
    });
    m.SetX(x);
}

TEST(MouseTests, Move2) {
    Mouse m;
    double x =7.0;
    m.Register([&x](IObservable o){
        auto mouse = static_cast<Mouse&>(o);
        //this will fail
        ASSERT_EQ(mouse.GetX(),x);
    });
    m.SetX(x);
}