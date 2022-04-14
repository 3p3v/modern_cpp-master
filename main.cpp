#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;


template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return std::shared_ptr<Shape>(new DerivedType(std::forward<Arguments>(args)...));
}

constexpr auto nth_fib(const int& n) 
{
    unsigned long int num1 = 0;
    unsigned long int num2 = 1;

    for(int i = 0; i < n; i++)
    {
        num2 += num1;
        num1 = num2 - num1; 
    }

    return num1;
}

auto printCollectionElements(const Collection& collection)
{
    for(const auto& it: collection)
        if(it)
            (it)->print();
}

auto printAreas(const Collection& collection)
{
    for(const auto& it: collection)
        if(it)
            cout << (it)->getArea() << std::endl;
}

auto findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)>predicate,
                                     std::string info)
{
    const auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    auto dd = make_shape<Circle>(12);
    cout<<dd.get()->getArea()<<endl;
    
    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    };

    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };

    auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getArea() < x);
        return false;
    };
    
    cout<<"N-ty wyraz ciagu:"<<endl;
    cout<< nth_fib(45) <<endl;

    Collection shapes{
        make_unique<Circle>(Color::BLUE),
        make_unique<Square>(Color::BLACK),
        make_unique<Rectangle>(Color::RED)
        };
    shapes.push_back(make_shared<Circle>(2.0));
    shapes.push_back(make_shared<Circle>(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(make_shared<Circle>(4.0));
    shapes.push_back(make_shared<Rectangle>(10.0, 5.0));
    shapes.push_back(make_shared<Square>(3.0));
    shapes.push_back(make_shared<Circle>(4.0));
    //zad5
    Circle c1(12, Color::BLACK);
    shapes.push_back(shared_ptr<Circle>(new Circle(move(c1))));
    Circle c2(50, Color::RED);
    shapes.push_back(shared_ptr<Circle>(new Circle(move(c2))));
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}

