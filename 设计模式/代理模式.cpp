#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Image{
public:
    virtual void display() = 0;
};

class RealImage:public Image{
private:
    string filename;
public:
    RealImage(string name){
        filename = name;
        loadFromDisk(filename);
    }
    void display(){
        cout << filename << endl;
    }
    void loadFromDisk(string filename){
        cout << filename << endl;
    }
};
/*
    代理类：创建一个真实类filename
    对应的函数调用对应真实类的函数
*/
class ProxyImage:public Image{
public:
    string filename;
    RealImage* realimage;

public:
    ProxyImage(string filename){
        filename = filename;
    }
    // ** **/
    void display(){
        if (realimage == nullptr)
        {
            realimage = new RealImage(filename);
        }
        realimage->display();
    }
};

class ProxyPatternDemo{
public:
    void main()
    {
        string filename;
        Image* image = new ProxyImage(filename);
        image->display(); 
        cout << "---------------0" << endl;
        image->display();
    }
};