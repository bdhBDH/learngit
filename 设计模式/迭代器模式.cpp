#include <iostream>
#include <vector>
using namespace std;

// 迭代器实现
class iterator1{
public:
    virtual bool hasNext(){}
    virtual string next(){}
};

class NameIterator:public iterator1{
public:
    bool hasNext(){}
    string next(){}
};
// 外部接口层
class Container{
public:
    virtual iterator1* getiterator(){}
};
class NameReposity:public Container{
private:
    string name;
public:
    iterator1* getiterator(){
        return new iterator1();
    }
};

//
class IteratorPatternDemo{
public:
    void main(){}
};