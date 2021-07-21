#include <iostream>
#include <assert.h>
using namespace std;

// 产品族 -- shape
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

// 产品族 -- Color
class Color{
public:
    virtual void fill() = 0;
};
class Red:public Color{
public:
    void fill(){cout << "red" << endl;}
};
class Green:public Color{
public:
    void fill(){cout << "Green" << endl;}
};
class Blue:public Color{
public:
    void fill(){cout << "Blue" << endl;}
};
// 抽象类
class Factory{
public:
    virtual Color* getcolor(string color) = 0;
    virtual Shape* getShape(string shape) = 0;
};
// 面向用户的jieko
class ShapeFactory:public Factory{
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
public:
    Color* getcolor(string color)
    {
        return NULL;
    }
};
class ColorFactory:public Factory{
private:
    string shapeType;
public:
    ColorFactory(string type)
    {
        shapeType = type;
    }
    Color* getcolor()
    {
        assert(shapeType != " ");
        if (shapeType == "red")
            return new Red();
        else if (shapeType == "Green")
            return new Green();
        else if (shapeType == "Blue")
            return new Blue();
        return NULL;
    }
public:
    Shape* getShape(string color)
    {
        return NULL;
    }
};


class Producer{
public:
    static Factory* getFactory(string choice)
    {
        if (choice == "Shape")
            return new ShapeFactory(choice);
        else if (choice == "COLOR")
            return new ColorFactory(choice);
        return NULL;
    }
};










