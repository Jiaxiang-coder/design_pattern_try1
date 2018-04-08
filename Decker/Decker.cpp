
#include "Decker.h"
#include <string>
#include <vector>
using namespace std;


//װ��ģʽ����̬�ظ�һ���������һЩ�����ְ��
//�����ӹ�����˵��װ��ģʽ������������Ϊ��
//��ʱ����ϣ����ĳ��������������������һЩ���ܡ�
//������һ���ֻ���������Ϊ�ֻ�������ԣ��������ӹҼ�����Ļ��Ĥ�ȡ�
//һ��������Ʒ�ʽ�ǣ����ֻ�Ƕ�뵽��һ�����У����������������Ե���ӣ����ǳ����Ƕ��Ķ���Ϊװ�Ρ�
//���װ��������װ�ε�����ӿ�һ�£��������ʹ�ø�����Ŀͻ�͸�����������װ��ģʽ��UMLͼ��

//����������У��ֻ���װ�ι��ܱ��������������Ե�����չ���������˾����ֻ������ơ��������Phone���ʵ�֣�

//����������
class Phone
{
public:
	Phone(){}
	virtual ~Phone(){}
	virtual void ShowDecorate() {}
};
//������ֻ���
class iPhone : public Phone
{
private:
	string m_name;
public:
	iPhone(string name) : m_name(name) {}
	~iPhone() {}
	void ShowDecorate() { cout<<m_name<<"��װ��"<<endl;}
};
//������ֻ���
class NokiaPhone : public Phone
{
private:
	string m_name;
public:
	NokiaPhone(string name) : m_name(name) {}
	~NokiaPhone() {}
	void ShowDecorate() { cout<<m_name<<"��װ��"<<endl;}
};

//װ�����ʵ�֣�
//װ����
class DecoratorPhone : public Phone
{
private:
	Phone *m_phone; //Ҫװ�ε��ֻ�
public:
	DecoratorPhone(Phone *phone) : m_phone(phone) {}
	virtual void ShowDecorate() {m_phone->ShowDecorate();}
};
//�����װ����
class DecoratorPhoneA : public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
	virtual void ShowDecorate() {
		DecoratorPhone::ShowDecorate(); 
		AddDecorate();
	}
private:
	void AddDecorate(){ cout<<"���ӹҼ�"<<endl;}
};

//�����װ����
class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
	virtual void ShowDecorate() {
		DecoratorPhone::ShowDecorate(); 
		AddDecorate();
	}
private:
	void AddDecorate(){ cout<<"������Ĥ"<<endl;}
};

void UseDecorator()
{
	Phone *phone = new NokiaPhone("6300");
	Phone *dpa = new DecoratorPhoneA(phone); //װ�Σ����ӹҼ�
	Phone *dpb = new DecoratorPhoneB(dpa);		//װ�Σ���Ļ��Ĥ
	Phone *dpc = new DecoratorPhoneB(dpb);		//װ�Σ���Ļ��Ĥ
	//dpb->ShowDecorate();
	dpc->ShowDecorate();

	//Phone *dpb = new DecoratorPhoneB(phone);		//װ�Σ���Ļ��Ĥ
	//dpb->ShowDecorate();
	//dpa->ShowDecorate();

	delete dpa;
	delete dpb;
	delete dpc;
	delete phone;
}

//װ��ģʽ�ṩ�˸���������������ְ��ķ�ʽ��
//��������Ӻͷ���ķ�������װ��������ʱ�����Ӻ�ɾ��ְ��װ��ģʽ�ṩ��һ�֡����ü������ķ�
//�������ְ����������ͼ��һ�����ӵĿɶ��Ƶ�����֧�����п�Ԥ����������
//�෴������Զ���һ���򵥵��࣬������װ��������𽥵���ӹ��ܡ����ԴӼ򵥵Ĳ�����ϳ����ӵĹ��ܡ�[DP]
//
//�ڱ��ĵ������У����Ƕ���������������ֻ��࣬iPhone���NokiaPhone�࣬ͨ��������װ����Ϊ����������ԣ�
//�Ӷ���ϳ����ӵĹ��ܡ�
//���� http://blog.csdn.net/wuzhekai1985
emJRet CDecker::Run()
{

	UseDecorator();
	return emJOk;
}
