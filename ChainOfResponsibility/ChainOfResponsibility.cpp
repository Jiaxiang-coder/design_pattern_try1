
#include "ChainOfResponsibility.h"
#include <string>
#include <vector>
using namespace std;

//ְ����ģʽ��ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ��
//����Щ��������һ���������������������ݸ�����ֱ����һ����������Ϊֹ��
//��˼��ܼ򵥣�����Ա��Ҫ���н��
	//��˾�Ĺ�����һ�����������ܾ����ܼࡢ�������һ��Ա��Ҫ���н��Ӧ�������ܵľ������룬
	//�����н�������ھ����ְȨ�ڣ���ô�������ֱ����׼�����������Ͻ����ܼࡣ
	//�ܼ�Ĵ���ʽҲһ�����ܾ�����Դ���������������ǵ��͵�ְ����ģʽ������Ĵ����γ���һ������
	//ֱ����һ�����������󡣸���������ӵ�UMLͼ��
//�����ʵ�ֱȽϼ򵥣�������ʾ��

//���������
class Manager
{
protected:
	Manager *m_manager;
	string m_name;
public:
	Manager(Manager *manager, string name) : m_manager(manager), m_name(name) {}
	virtual void DealWithRequest(string name, int num) {}
};
//����
class CommonManager : public Manager
{
public:
	CommonManager(Manager *manager, string name) : Manager(manager, name) {}
	void DealWithRequest(string name, int num){
		if(num < 500) //����ְȨ֮��
		{
			cout<<"����"<<m_name<<"��׼"<<name<<"��н"<<num<<"Ԫ"<<endl<<endl;
		}else
		{
			cout<<"����"<<m_name<<"�޷����������ܼദ��"<<endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};
//�ܼ�
class Majordomo : public Manager
{
public:
	Majordomo(Manager *manager, string name) : Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		if(num < 1000) //�ܼ�ְȨ֮��
		{
			cout<<"�ܼ�"<<m_name<<"��׼"<<name<<"��н"<<num<<"Ԫ"<<endl<<endl;
		}
		else
		{
			cout<<"�ܼ�"	<<m_name<<"�޷����������ܾ�����"<<endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};
//�ܾ���
class GeneralManager : public Manager
{
public:
	GeneralManager(Manager *manager, string name) : Manager(manager, name) {}
	void DealWithRequest(string name, int num) //�ܾ�����Դ�����������
	{
		cout<<"�ܾ���"<<m_name <<"��׼"<<name<<"��н"<<num<<"Ԫ"<<endl<<endl;
	}
};
//���� http://blog.csdn.net/wuzhekai1985
emJRet CChainOfResponsibility::Run()
{
	Manager *general = new GeneralManager(NULL, "A"); //�����ϼ����ܾ���û���ϼ�
	Manager *majordomo = new Majordomo(general, "B"); //�����ϼ�
	Manager *common = new CommonManager(majordomo, "C");
	common->DealWithRequest("D", 300); //Ա��DҪ���н
	common->DealWithRequest("E", 600);
	common->DealWithRequest("F", 1000);
	delete common; delete majordomo; delete general;
	return emJOk;
}
