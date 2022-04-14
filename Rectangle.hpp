#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(Color c) : Shape(c) {};
    //HW zad 4//
    Rectangle(double x, double y, Color c) : Rectangle(c)
    {
        x_ = x;
        y_ = y;
    }
    ////////////
    Rectangle(const Rectangle & other) = default;
    Rectangle(Rectangle&& other) noexcept = default;
    Rectangle& operator=(Rectangle&& other) noexcept = default;
    Rectangle& operator=(const Rectangle& other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;  //trzeba bylo wstawic virtual
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_;
    double y_;
};
