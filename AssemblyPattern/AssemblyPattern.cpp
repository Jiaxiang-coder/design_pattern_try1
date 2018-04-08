
#include "AssemblyPattern.h"
#include <string>
#include <list>
using namespace std;

//���ģʽ�ڹ�������ϵͳʱ�ǳ����á�������������һ��ģʽ����Ϊ���ģʽ���о��е������ģʽ���ղ�����ʵ�����ģʽʱ����Compiler������а����˶����Ķ��󣬾������Щ���������һ�����ģʽ�ǲ��������˼���е����ƣ���ʵ��Ȼ��
//
//DP���ϸ����Ķ��壺��������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ�����ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�ע�������֡����Ρ����������νṹ����ʵ�������洦�ɼ�������һ�����Ź�˾������һ��ĸ��˾������ܶ���ӹ�˾��������ĸ��˾�����ӹ�˾�����и���ֱ���Ĳ��񲿡�������Դ�������۲��ȡ�����ĸ��˾��˵���������ӹ�˾������ֱ���Ĳ��񲿡�������Դ�����������Ĳ��š�������˾�Ĳ�������ͼ����һ�����νṹ��
//
//����������ģʽ��UMLͼ����ͼ�п��Կ�����FinanceDepartment��HRDepartment��������ΪҶ��㣬���û�ж�����Ӻ�������ConcreteCompany�������Ϊ�м��㣬���Կ�������Ӻ�������ô��ô����أ�������ж�����һ��������������ӵ�Ԫ�ء�

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

//���幫˾
class ConcreteCompany : public Company
{
public:
	ConcreteCompany(string name) : Company(name) {}
	virtual ~ConcreteCompany() {}
	void Add(Company *pCom) { m_listCompany.push_back(pCom); } //λ�������м䣬������������
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
//����Ĳ��ţ�����
class FinanceDepartment : public Company
{
public:
	FinanceDepartment(string name) : Company(name){}
	virtual ~FinanceDepartment(){}
	virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ�ڵ�
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
	Company *root = new ConcreteCompany("�ܹ�˾");
	Company *leaf1 = new FinanceDepartment("����");
	Company *leaf2 = new HRDepartment("������Դ��");
	root->Add(leaf1);
	root->Add(leaf2);
	//�ֹ�˾A
	Company *mid1 = new ConcreteCompany("�ֹ�˾A");
	Company *leaf3 = new FinanceDepartment("����");
	Company *leaf4 = new HRDepartment("������Դ��");
	mid1->Add(leaf3);
	mid1->Add(leaf4);
	root->Add(mid1);
	//�ֹ�˾B
	//�ֹ�˾A
	Company *mid2 = new ConcreteCompany("�ֹ�˾B");
	Company *leaf5 = new FinanceDepartment("����");
	Company *leaf6 = new HRDepartment("������Դ��");
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
//�����ʵ�ַ�ʽ��ȱ�㣬�����ڴ���ͷŲ��ã���Ҫ�ͻ��Լ����֣��ǳ������㡣�д��Ľ����ȽϺõ���������ConcreteCompany�����ͷš���Ϊ���е�ָ�붼�Ǵ���ConcreteCompany��������С�C++���鷳��û���������ջ��ơ�
//���� http://blog.csdn.net/wuzhekai1985

emJRet CAssemblyPattern::Run()
{
	UseCompany();
	return emJOk;
}
