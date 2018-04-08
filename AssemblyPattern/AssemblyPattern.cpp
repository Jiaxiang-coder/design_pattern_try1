
#include "AssemblyPattern.h"
#include <string>
#include <list>
using namespace std;

//外观模式在构建大型系统时非常有用。接下来介绍另一种模式，称为组合模式。感觉有点像外观模式，刚才我们实现外观模式时，在Compiler这个类中包含了多个类的对象，就像把这些类组合在了一起。组合模式是不是这个意思，有点相似，其实不然。
//
//DP书上给出的定义：将对象组合成树形结构以表示“部分-整体”的层次结构。组合使得用户对单个对象和组合对象的使用具有一致性。注意两个字“树形”。这种树形结构在现实生活中随处可见，比如一个集团公司，它有一个母公司，下设很多家子公司。不管是母公司还是子公司，都有各自直属的财务部、人力资源部、销售部等。对于母公司来说，不论是子公司，还是直属的财务部、人力资源部，都是它的部门。整个公司的部门拓扑图就是一个树形结构。
//
//下面给出组合模式的UML图。从图中可以看到，FinanceDepartment、HRDepartment两个类作为叶结点，因此没有定义添加函数。而ConcreteCompany类可以作为中间结点，所以可以有添加函数。那么怎么添加呢？这个类中定义了一个链表，用来放添加的元素。

class Company
{
public:
	Company(string name) { m_name = name; }
	virtual ~Company(){}
	virtual void Add(Company *pCom){}
	virtual void Show(int depth) {}
protected:
	string m_name;
};

//具体公司
class ConcreteCompany : public Company
{
public:
	ConcreteCompany(string name) : Company(name) {}
	virtual ~ConcreteCompany() {}
	void Add(Company *pCom) { m_listCompany.push_back(pCom); } //位于树的中间，可以增加子树
	void Show(int depth){
		for(int i=0; i< depth; i++)
			cout<<"-";
		cout<<m_name<<endl;
		list<Company*>::iterator iter = m_listCompany.begin();
		for(;iter != m_listCompany.end(); ++iter)
			(*iter)->Show(depth + 2);
	}
private:
	list<Company*> m_listCompany;
};
//具体的部门，财务部
class FinanceDepartment : public Company
{
public:
	FinanceDepartment(string name) : Company(name){}
	virtual ~FinanceDepartment(){}
	virtual void Show(int depth) //只需显示，无需添加函数，因为已是叶节点
	{
		for(int i=0; i<depth ;i++)
			cout<<"-";
		cout<<m_name<<endl;
	}
};
class HRDepartment : public Company
{
public:
	HRDepartment(string name) : Company(name) {}
	virtual ~HRDepartment(){}
	virtual void Show(int depth)
	{
		for(int i=0; i<depth; i++)
			cout<<"-";
		cout<<m_name<<endl;
	}
};

void UseCompany(){
	Company *root = new ConcreteCompany("总公司");
	Company *leaf1 = new FinanceDepartment("财务部");
	Company *leaf2 = new HRDepartment("人力资源部");
	root->Add(leaf1);
	root->Add(leaf2);
	//分公司A
	Company *mid1 = new ConcreteCompany("分公司A");
	Company *leaf3 = new FinanceDepartment("财务部");
	Company *leaf4 = new HRDepartment("人力资源部");
	mid1->Add(leaf3);
	mid1->Add(leaf4);
	root->Add(mid1);
	//分公司B
	//分公司A
	Company *mid2 = new ConcreteCompany("分公司B");
	Company *leaf5 = new FinanceDepartment("财务部");
	Company *leaf6 = new HRDepartment("人力资源部");
	mid2->Add(leaf5);
	mid2->Add(leaf6);
	root->Add(mid2);
	root->Show(0);

	delete leaf1; delete leaf2;
	delete leaf3; delete leaf4;
	delete leaf5; delete leaf6;
	delete mid1; delete mid2;
	delete root;
}
//上面的实现方式有缺点，就是内存的释放不好，需要客户自己动手，非常不方便。有待改进，比较好的做法是让ConcreteCompany类来释放。因为所有的指针都是存在ConcreteCompany类的链表中。C++的麻烦，没有垃圾回收机制。
//出处 http://blog.csdn.net/wuzhekai1985

emJRet CAssemblyPattern::Run()
{
	UseCompany();
	return emJOk;
}
