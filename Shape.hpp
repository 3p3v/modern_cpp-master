#pragma once

enum class Color : unsigned char
{
    BLACK,
    RED,
    BLUE
};

class Shape
{
public:
    virtual ~Shape() {}
    Shape(Color c) : color(c) {};
    Shape() {};
    
    Shape(Shape&& other) noexcept = default;
    Shape& operator=(Shape&& other) noexcept = default;
    //HW zad3//
    Shape(const Shape& other) noexcept = default;
    Shape& operator=(const Shape& other) = default;
    ///////////

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

    Color color;
};
