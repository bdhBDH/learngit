/*
non-local static对象（函数外）

C++规定，non-local static 对象的初始化发生在main函数执行之前，
也即main函数之前的单线程启动阶段，所以不存在线程安全问题。
但C++没有规定多个non-local static 对象的初始化顺序，
尤其是来自多个编译单元的non-local static对象，他们的初始化顺序是随机的。

local static 对象（函数内）
对于local static 对象，其初始化发生在控制流第一次执行到该对象的初始化语句时.
多个线程的控制流可能同时到达其初始化语句。
在C++11之前，在多线程环境下local static对象的初始化并不是线程安全的。
具体表现就是：如果一个线程正在执行local static对象的初始化语句但还没有完成初始化，
此时若其它线程也执行到该语句，
那么这个线程会认为自己是第一次执行该语句并进入该local static对象的构造函数中。
这会造成这个local static对象的重复构造，进而产生**内存泄露**问题。
所以，local static对象在多线程环境下的**重复构造**问题是需要解决的。

而C++11则在语言规范中解决了这个问题。
C++11规定，在一个线程开始local static 对象的初始化后到完成初始化前，
其他线程执行到这个local static对象的初始化语句就会等待,
直到该local static 对象初始化完成。
*/



#include <iostream>
#include <vector>
using namespace std;

// lazy singleton
class Singleton{
	private:
	// static ----- 
		static Singleton* instance;
	private:
		Singleton() {};
		~Singeton() {};
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
	public:
	// static -----  constents
		static Singleton* getInstance()
		{
			if (instance == nullptr)
			{
				instance = new Singleton();
			}
			return instance;
		}
}; 
// init static member
Singleton* Singleton::instance = nullptr;

// Lazy Singleton存在内存泄露的问题，有两种解决方法
/*
	    使用智能指针
		使用静态的嵌套类对象
*/
class Singleton2 {
	private:
		static Singleton2* instance;
	private:
		Singleton2() {}
		~Singleton2() {}
		Singleton2(const Singleton2&);
		Singleton2& operator=(const Singleton2&);
	private:
		class Delter {
			public:
				~Delter(){
					if (Singleton::instance != nullptr)
						delete Sington::instance;
				}
		};
		static Delter delteor;
	public:
		static Singleton* getInstance()
		{
			if (instance == nullptr)
			{
				Lock lock;
				if (instance == nullptr)
					instance = shared_ptr<Singleton*> (new Singleton());
			}
			return instance;
		}
};
Singleton* Singleton::instance = nullptr;

// 在多线程环境下实现单例模式,线程安全
// 利用同步机制来正确的保护我们的shared data
// 双检测锁模式（DCL: Double-Checked Locking Pattern）：

class Singleton3{
private:
	Singleton3 () {};
	~Singleton3 () {};
	Singleton3(cosnt Singleton3&);
	Singleton3& operator=(cosnt Singleton3&);
public:
	static Singleton& getInstance()
	{
/*
	C++11规定了local static在多线程条件下的初始化行为，
	要求编译器保证了内部静态变量的线程安全性。在C++11标准下，
	《Effective C++》提出了一种更优雅的单例模式实现，
	使用函数内的 local static 对象。这样，
	只有当第一次访问getInstance()方法时才创建实例。
	这种方法也被称为Meyers' Singleton。
	C++0x之后该实现是线程安全的，C++0x之前仍需加锁。
*/
		static Singleton instance;
		return instance;
	}
};


// 饿汉版: 指单例实例在程序运行时被立即执行初始化
class Singleton4 {
private:
	static Singleton4 instance;
private:
	Singleton4 (){};
	~Singleton4(){};
	Singleton4(const Singleton4&);
	Singleton4& operator=(const Singleton4&);
public:
	static Singleton4& getInstance()
	{
		return instance;
	}
};

Singleton4 Singleton4::instance;






