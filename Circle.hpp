#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(Color c) : Shape(c) {};
    //HW zad 4//
    Circle(double r, Color c) : Circle(c) {r_ = r;}

    Circle(const Circle & other) = default;
    Circle(Circle&& other) noexcept = default;
    Circle& operator=(Circle&& other) noexcept = default;
    Circle& operator=(const Circle& other) = default;
 
    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    void print() const override;
    [[deprecated("**  deprecated  **")]]double getPi();

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
