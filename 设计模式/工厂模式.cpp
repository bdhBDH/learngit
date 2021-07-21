#include <iostream>
#include <assert.h>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
};
// 产品
class Circle:public Shape{
public:
    void draw(){}
};
// 产评
class Square:public Shape{
public:
    void draw(){}
};
// 产品
class Rectangle:public Shape{
public:
    void draw(){}
};
// 工厂
class ShapeFactory{
private:
    string shapeType;
public:
    ShapeFactory(string type)
    {
        shapeType = type;
    }
    Shape* getShape()
    {
        assert(shapeType != " ");
        if (shapeType == "Circle")
            return new Circle();
        else if (shapeType == "Square")
            return new Square();
        else if (shapeType == "Rectangle")
            return new Rectangle();
        return NULL;
    }
};