
#include "Decker.h"
#include <string>
#include <vector>
using namespace std;


//装饰模式：动态地给一个对象添加一些额外的职责。
//就增加功能来说，装饰模式相比生成子类更为灵活。
//有时我们希望给某个对象而不是整个类添加一些功能。
//比如有一个手机，允许你为手机添加特性，比如增加挂件、屏幕贴膜等。
//一种灵活的设计方式是，将手机嵌入到另一对象中，由这个对象完成特性的添加，我们称这个嵌入的对象为装饰。
//这个装饰与它所装饰的组件接口一致，因此它对使用该组件的客户透明。下面给出装饰模式的UML图。

//在这种设计中，手机的装饰功能被独立出来，可以单独发展，进而简化了具体手机类的设计。下面给出Phone类的实现：

//公共抽象类
class Phone
{
public:
	Phone(){}
	virtual ~Phone(){}
	virtual void ShowDecorate() {}
};
//具体的手机类
class iPhone : public Phone
{
private:
	string m_name;
public:
	iPhone(string name) : m_name(name) {}
	~iPhone() {}
	void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};
//具体的手机类
class NokiaPhone : public Phone
{
private:
	string m_name;
public:
	NokiaPhone(string name) : m_name(name) {}
	~NokiaPhone() {}
	void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};

//装饰类的实现：
//装饰类
class DecoratorPhone : public Phone
{
private:
	Phone *m_phone; //要装饰的手机
public:
	DecoratorPhone(Phone *phone) : m_phone(phone) {}
	virtual void ShowDecorate() {m_phone->ShowDecorate();}
};
//具体的装饰类
class DecoratorPhoneA : public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
	virtual void ShowDecorate() {
		DecoratorPhone::ShowDecorate(); 
		AddDecorate();
	}
private:
	void AddDecorate(){ cout<<"增加挂件"<<endl;}
};

//具体的装饰类
class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
	virtual void ShowDecorate() {
		DecoratorPhone::ShowDecorate(); 
		AddDecorate();
	}
private:
	void AddDecorate(){ cout<<"增加贴膜"<<endl;}
};

void UseDecorator()
{
	Phone *phone = new NokiaPhone("6300");
	Phone *dpa = new DecoratorPhoneA(phone); //装饰，增加挂件
	Phone *dpb = new DecoratorPhoneB(dpa);		//装饰，屏幕贴膜
	Phone *dpc = new DecoratorPhoneB(dpb);		//装饰，屏幕贴膜
	//dpb->ShowDecorate();
	dpc->ShowDecorate();

	//Phone *dpb = new DecoratorPhoneB(phone);		//装饰，屏幕贴膜
	//dpb->ShowDecorate();
	//dpa->ShowDecorate();

	delete dpa;
	delete dpb;
	delete dpc;
	delete phone;
}

//装饰模式提供了更加灵活的向对象添加职责的方式。
//可以用添加和分离的方法，用装饰在运行时刻增加和删除职责。装饰模式提供了一种“即用即付”的方
//法来添加职责。它并不试图在一个复杂的可定制的类中支持所有可预见的特征，
//相反，你可以定义一个简单的类，并且用装饰类给它逐渐地添加功能。可以从简单的部件组合出复杂的功能。[DP]
//
//在本文的例子中，我们定义了两个具体的手机类，iPhone类和NokiaPhone类，通过单独的装饰类为它们添加特性，
//从而组合出复杂的功能。
//出处 http://blog.csdn.net/wuzhekai1985
emJRet CDecker::Run()
{

	UseDecorator();
	return emJOk;
}
