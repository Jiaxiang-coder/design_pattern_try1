#include "Singleton.h"
#include <string.h>
using namespace std;

//单例的一般实现比较简单，下面是代码和UML图。
//由于构造函数是私有的，因此无法通过构造函数实例化，唯一的方法就是通过调用静态函数GetInstance。
namespace Brief_Singleton
{
	class Singleton
	{
	public:
		static Singleton* GetInstance();
	private:
		Singleton() {}
		static Singleton *singleton;
	};

	Singleton* Singleton::singleton = NULL;
	Singleton* Singleton::GetInstance()
	{
		if(singleton == NULL)
			singleton = new Singleton();
		return singleton;
	}
}

 //这里只有一个类，如何实现Singleton类的子类呢？也就说Singleton有很多子类，在一种应用中，只选择其中的一个。
//最容易就是在GetInstance函数中做判断，比如可以传递一个字符串，根据字符串的内容创建相应的子类实例。
//这也是DP书上的一种解法，书上给的代码不全。
//这里重新实现了一下，发现不是想象中的那么简单，最后实现的版本看上去很怪异。在VS2008下测试通过。

namespace Inherit_Singleton
{
	class Singleton
	{
	public:
		static Singleton* GetInstance(const char* name);
		virtual void Show() {}
	protected:
		Singleton() {}
	private:
		static Singleton * singleton;
	};
	class SingletonA : public Singleton
	{
		friend class Singleton;	//必须为友元类，否则父类无法访问子类的构造函数
	public:
		void Show() {cout<<"SingletonA"<<endl;}
	private:
		SingletonA(){}
	};
	class SingletonB : public Singleton
	{
		friend class Singleton;	//必须为友元类，否则父类无法访问子类的构造函数
	public:
		void Show() {cout<<"SingletonB"<<endl;}
	private:									//为保护属性，这样外界无法通过构造函数进行实例化
		SingletonB(){}
	};
	Singleton* Singleton::singleton = NULL;
	Singleton* Singleton::GetInstance(const char* name)
	{
		if(singleton == NULL)
		{
			if(strcmp(name, "SingletonA") == 0)
				singleton = new SingletonA();
			else if(strcmp(name, "SingletonB") == 0)
				singleton = new SingletonB();
			else
				singleton = new Singleton();
		}
		return singleton;
	}
}
//出处 http://blog.csdn.net/wuzhekai1985
emJRet CSingleton::Run()
{
	Inherit_Singleton::Singleton *st = Inherit_Singleton::Singleton::GetInstance("SingletonA");
	st->Show();
	return emJOk;
}
