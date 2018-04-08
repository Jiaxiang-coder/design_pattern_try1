
#include "Mediator.h"
#include <string>
#include <vector>
using namespace std;

//�н���ģʽ����һ���н��������װһϵ�еĶ��󽻻���
//�н���ʹ��������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����
//�н���ģʽ�����Ӻܶ࣬�����Ϲ�����ᣬС�������н飬���������м��ߵĽ�ɫ��Э���������档

//���ľ����ⷿΪ���ӣ����û�з����н飬��ô����Ҫ�Լ��ҷ�����������ҲҪ�Լ��ҷ��ͣ��ǳ������㡣
//���˷����н�����ͷ����ˣ��������԰�Ҫ����ķ�����Ϣ�ŵ��н�����������Ϳ���ȥ�н������ѯ��
//������У����Ƕ������֮����Ҫͨ�ţ����û���н飬�������Ҫ֪����������
//�����£�������Ҫ֪�������������󣬶������н����ͷ�����ˣ�����ֻ�����н����ͨ�ţ�
//������֪�������Ķ���������н���ģʽ���������ⷿΪ���������н���ģʽ��UMLͼ��

//ʵ�ֲ��ѣ��������C++��ʵ�֣�
namespace UseMediator{
	class Mediator;
	//������
	class Person
	{
	protected:
		Mediator *m_mediator; //�н�
	public:
		virtual void SetMediator(Mediator *mediator) { } //�����н�
		virtual void SendMessage(string message) {} //���н鷢����Ϣ
		virtual void GetMessage(string message) { } //���н��ȡ��Ϣ
	};

	//�����н����
	class Mediator
	{
	public:
		virtual void Send(string message, Person *person){}
		virtual void SetA(Person *A) {}  //��������һ��
		virtual void SetB(Person *B) {}
	};

	//�ⷿ��
	class Renter : public Person
	{
	public:
		void SetMediator(Mediator *mediator) { m_mediator = mediator; }
		void SendMessage(string message) { m_mediator->Send(message, this); }
		void GetMessage(string message) { cout<<"�ⷿ���յ���Ϣ: " <<message;}
	};
	//����
	class Landlord : public Person
	{
	public:
		void SetMediator(Mediator *mediator) { m_mediator = mediator; }
		void SendMessage(string message) { m_mediator->Send(message, this); }
		void GetMessage(string message) { cout<<"�����յ���Ϣ��"<<message; }
	};
	//�����н�
	class HouseMediator : public Mediator
	{
	private:
		Person *m_A; //�ⷿ��
		Person *m_B; //����
	public:
		HouseMediator() : m_A(0), m_B(0) {}
		void SetA(Person *A) {m_A = A;}
		void SetB(Person *B) {m_B = B;}
		void Send(string message, Person *person)
		{
			if(person == m_A) //�ⷿ�߸���������Ϣ
				m_B->GetMessage(message); // �����յ���Ϣ
			else
				m_A->GetMessage(message);
		}
	};
}


//���� http://blog.csdn.net/wuzhekai1985
emJRet CMediator::Run()
{
	using namespace UseMediator;
	Mediator *mediator = new HouseMediator();
	Person *person1 = new Renter(); //�ⷿ��
	Person *person2 = new Landlord(); //����
	mediator->SetA(person1);
	mediator->SetB(person2);
	person1->SetMediator(mediator);
	person2->SetMediator(mediator);
	person1->SendMessage("�������Ͼ�·�����ⷿ�ӣ��۸�800Ԫһ����\n");
	person2->SendMessage("���ⷿ�ӣ��Ͼ�·100�ţ�70ƽ�ף�1000Ԫһ����\n");
	delete person1; delete person2; delete mediator;
	return emJOk;
}
