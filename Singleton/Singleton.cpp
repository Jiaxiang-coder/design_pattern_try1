#include "Singleton.h"
#include <string.h>
using namespace std;

//������һ��ʵ�ֱȽϼ򵥣������Ǵ����UMLͼ��
//���ڹ��캯����˽�еģ�����޷�ͨ�����캯��ʵ������Ψһ�ķ�������ͨ�����þ�̬����GetInstance��
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

 //����ֻ��һ���࣬���ʵ��Singleton��������أ�Ҳ��˵Singleton�кܶ����࣬��һ��Ӧ���У�ֻѡ�����е�һ����
//�����׾�����GetInstance���������жϣ�������Դ���һ���ַ����������ַ��������ݴ�����Ӧ������ʵ����
//��Ҳ��DP���ϵ�һ�ֽⷨ�����ϸ��Ĵ��벻ȫ��
//��������ʵ����һ�£����ֲ��������е���ô�򵥣����ʵ�ֵİ汾����ȥ�ܹ��졣��VS2008�²���ͨ����

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
		friend class Singleton;	//����Ϊ��Ԫ�࣬�������޷���������Ĺ��캯��
	public:
		void Show() {cout<<"SingletonA"<<endl;}
	private:
		SingletonA(){}
	};
	class SingletonB : public Singleton
	{
		friend class Singleton;	//����Ϊ��Ԫ�࣬�������޷���������Ĺ��캯��
	public:
		void Show() {cout<<"SingletonB"<<endl;}
	private:									//Ϊ�������ԣ���������޷�ͨ�����캯������ʵ����
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
//���� http://blog.csdn.net/wuzhekai1985
emJRet CSingleton::Run()
{
	Inherit_Singleton::Singleton *st = Inherit_Singleton::Singleton::GetInstance("SingletonA");
	st->Show();
	return emJOk;
}
