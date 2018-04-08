
#include "Prototype_TemplateMethod.h"
#include <string.h>
using namespace std;

//DP书上的定义为：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
//其中有一个词很重要，那就是拷贝。可以说，拷贝是原型模式的精髓所在。
//举个现实中的例子来介绍原型模式。找工作的时候，我们需要准备简历。
//假设没有打印设备，因此需手写简历，这些简历的内容都是一样的。
//这样有个缺陷，如果要修改简历中的某项，那么所有已写好的简历都要修改，工作量很大。
//随着科技的进步，出现了打印设备。我们只需手写一份，然后利用打印设备复印多份即可。
//如果要修改简历中的某项，那么修改原始的版本就可以了，然后再复印。
//原始的那份手写稿相当于是一个原型，有了它，就可以通过复印（拷贝）创造出更多的新简历。
//这就是原型模式的基本思想。下面给出原型模式的UML图，以刚才那个例子为实例。

//原型模式实现的关键就是实现Clone函数，对于C++来说，其实就是拷贝构造函数，需实现深拷贝，下面给出一种实现。


namespace UsePrototypeClone
{
//父类
class Resume
{
protected:
	char *name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return NULL;}
	virtual void Set(char *n) {}
	virtual void Show() {}
};

class ResumeA : public Resume
{
public:
	ResumeA(const char *str);		//构造函数
	ResumeA(const ResumeA &r);	//拷贝构造函数
	~ResumeA();									//析构函数
	ResumeA* Clone();						//克隆，关键所在
	void Show();								//显示内容
};
ResumeA::ResumeA(const char *str){
	if(str == NULL){
		name = new char[1];
		name[0] = '\0';
	}else{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeA::~ResumeA() {delete [] name;}
ResumeA::ResumeA(const ResumeA &r){
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeA* ResumeA::Clone(){
	return new ResumeA(*this);
}
void ResumeA::Show(){
	cout<<"ResumeA name: "<<name<<endl;
}

//这里只给出了ResumeA的实现，ResumeB的实现类似。使用的方式如下：
	void UseResume(){
		Resume *r1 = new ResumeA("A");
		//Resume *r2 = new ResumeB("B");
		Resume *r3 = r1->Clone();
		r1->Show();
		//删除r1,r2
		delete r1; 
		//深拷贝所以对r3,r4无影响
		r3->Show();
		delete r3;
	}
}

//最近有个招聘会，可以带上简历去应聘了。
//但是，其中有一家公司不接受简历，而是给应聘者发了一张简历表，
//上面有基本信息、教育背景、工作经历等栏，让应聘者按照要求填写完整。
//每个人拿到这份表格后，就开始填写。
//如果用程序实现这个过程，该如何做呢？
//一种方案就是用模板方法模式：
//定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。
//模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
//我们的例子中，操作就是填写简历这一过程，我们可以在父类中定义操作的算法骨架，而具体的实现由子类完成。
//下面给出它的UML图。

//其中FillResume() 定义了操作的骨架，依次调用子类实现的函数。相当于每个人填写简历的实际过程。
//接着给出相应的C++代码
namespace Template_Method
{
	class Resume
	{
	protected:
		virtual void SetPersonalInfo(){}
		virtual void SetEducation() {}
		virtual void SetWorkExp() {}
	public:
		void FillResume()
		{
			SetPersonalInfo();
			SetEducation();
			SetWorkExp();
		}
	};
	class ResumeA : public Resume
	{
	protected:
		void SetPersonalInfo() { cout<<"A's PersonalInfo"<<endl; }
		void SetEducation() { cout<<"A's Education"<<endl; }
		void SetWorkExp() { cout<<"A's Work Experience"<<endl; }
	};
	class ResumeB : public Resume
	{
	protected:
		void SetPersonalInfo() { cout<<"B's PersonalInfo"<<endl; }
		void SetEducation() { cout<<"B's Education"<<endl; }
		void SetWorkExp() { cout<<"B's Work Experience"<<endl; }
	};
	void UseResume(){
		Resume* r1;
		r1 = new ResumeA();
		r1->FillResume();
		delete r1;
		r1 = new ResumeB();
		r1->FillResume();
		delete r1;
		r1 = NULL;
	}
}

//出处 http://blog.csdn.net/wuzhekai1985
emJRet CPrototype_TemplateMethod::Run()
{
	UsePrototypeClone::UseResume();
	Template_Method::UseResume();
	return emJOk;
}
