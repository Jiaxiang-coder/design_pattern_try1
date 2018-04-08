
#include "Adapter.h"

using namespace std;

 //DP�ϵĶ��壺������ģʽ��һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڣ�
	//ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������
	//���������������Ͷ�����������������Ե��Ƕ�����������
	//�ٸ����ӣ���STL�о��õ���������ģʽ��
	//STLʵ����һ�����ݽṹ����Ϊ˫�˶��У�deque����֧��ǰ�����εĲ�����ɾ����
	//STLʵ��ջ�Ͷ���ʱ��û�д�ͷ��ʼ�������ǣ�����ֱ��ʹ��˫�˶���ʵ�ֵġ�
	//����˫�˶��оͰ������������Ľ�ɫ��
	//�����õ������ĺ�˲��룬ǰ��ɾ����
	//��ջ�õ������ĺ�˲��룬���ɾ����
	//����ջ�Ͷ��ж���һ��˳�������������ֲ�����ѹ��͵��������������Ӧ��UMLͼ����DP�ϵ�ͼ��ࡣ

//˫�˶���
class Deque
{
public:
	void push_back(int x){ cout<<"Deque push_back"<<endl; }
	void push_front(int x){ cout<<"Deque push_front"<<endl; }
	void pop_back() { cout<<"Deque pop_back"<<endl; }
	void pop_front() { cout<<"Deque pop_front"<<endl; }
	
};
//˳������ [Adapter]
class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
	virtual ~Sequence(){}
};
//ջ
class Stack : public Sequence
{
public:
	void push(int x) {deque.push_back(x);}
	void pop() {deque.pop_back();}
	~Stack() { std::cout<<"~Stack destructor"<<std::endl; }
private:
	Deque deque;	//˫�˶���
};

//����
class Queue : public Sequence
{
public:
	void push(int x) { deque.push_back(x); }
	void pop() { deque.pop_front(); }
		~Queue() { std::cout<<"~Queue destructor"<<std::endl; }
private:
	Deque deque; //˫�˶���
};
//���� http://blog.csdn.net/wuzhekai1985
emJRet CAdapter::Run()
{
	Sequence *s1 = new Stack();
	Sequence *s2 = new Queue();
	s1->push(1); s1->pop();
	s2->push(1); s2->pop();
	delete s1;	delete s2;
	return emJOk;
}
