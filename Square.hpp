#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(Color c) : Rectangle(c) {};
    //HW zad4//
    //sSquare(double x, Color c) : Square(c) {x_ = x;}//????????
    ///////////
    Square(const Square & other) = default;
    Square(Square&& other) noexcept = default;
    Square& operator=(Square&& other) noexcept = default;
    Square& operator=(const Square& other) = default;//TODO

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

private:
    double getY() = delete; // should not have Y dimension
    Square() = delete;
};
