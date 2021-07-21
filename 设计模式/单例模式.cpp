#include <iostream>
using namespace std;

class SingleObject{
    static SingleObject* instance;
private:
    SingleObject()
    {
        instance = new SingleObject();
    }
public:
// 唯一可用的对象，不能构造因为私有，不能继承
    static SingleObject* getInstance(){
        return instance;
    }
    void showMessage(){
        cout << "end" << endl;
    }
};

class SingeletDemo{
public:
    static void main(string args)
    {
        SingleObject object = SingleObject.;
        object.showMessage();
    }
};