#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item{
public:
    virtual string name(){}
    virtual Packing* packing();
    virtual float price();
};

class Packing{
public:
    virtual string pack();
};

class Wrapper:public Packing{
public:
    string pack()
    {
        return "warp";
    }
};

class Bottle:public Packing{
public:
    string pack()
    {
        return "bottle";
    }
};

class Burger:public Item{
public:
    Packing* packing()
    {
        return new Wrapper();
    }
    virtual float price(){}

};
class Drink:public Item{
public:
    Packing* packing()
    {
        return new Bottle();
    }
    virtual float price(){}
};
class Vegbuger:public Burger{
public:
    string name()
    {
        return "Vegburger";
    }
    float price()
    {
        return 1.243;
    }
};
class Coco:public Drink{
public:
    string name()
    {
        return "Coco";
    }
    float price()
    {
        return 3.00;
    }
};




