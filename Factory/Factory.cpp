

#include "Factory.h"
using namespace std;

enum CTYPE{COREA,COREB};
class SingleCore{
public:
	virtual void Show() = 0;
};
//���� A
class SingleCoreA  : public SingleCore
{
public:
	void Show() {cout<<"SingleCore A"<<endl;}
};
//���� B
class SingleCoreB  : public SingleCore
{
public:
	void Show() {cout<<"SingleCore B"<<endl;}
};

  //����ģʽ���ڴ�����ģʽ�����¿��Է�Ϊ���࣬�򵥹���ģʽ����������ģʽ�����󹤳�ģʽ��
	//����ȥ��࣬���ǹ���ģʽ��
	//����һ�������ܣ����Ƚ��ܼ򵥹���ģʽ��������Ҫ�ص�����Ҫ�ڹ����������жϣ��Ӷ�������Ӧ�Ĳ�Ʒ��
	//�������µĲ�Ʒʱ������Ҫ�޸Ĺ����ࡣ�е���󣬾ٸ����Ӿ������ˡ�
	//��һ�������������˵ĳ��ң���ֻ��һ���������ܹ����������ͺŵĴ������ˡ�
	//�ͻ���Ҫʲô���Ĵ������ˣ�һ��Ҫ��ʾ�ظ��������������������һ��ʵ�ַ�����

namespace Normal_Factory{
	//Ψһ�Ĺ��̣��������������ͺŵĴ������ˣ����ڲ��ж�
	class Factory
	{
	public:
		SingleCore* CreateSingleCore(enum CTYPE ctype)
		{
			if(ctype == COREA) //�����ڲ��ж�
				return new SingleCoreA();	//������A
			else if(ctype == COREB)
				return new SingleCoreB();	//������B
			else
				return NULL;
		}
	};
};
//������Ƶ���Ҫȱ��֮ǰҲ�ᵽ��������Ҫ�����µĺ�����ʱ������Ҫ�޸Ĺ����ࡣ
//���Υ���˿��ŷ��ԭ�����ʵ�壨�ࡢģ�顢������������չ�����ǲ����޸ġ�
//���ǣ���������ģʽ�����ˡ�
//��ν��������ģʽ����ָ����һ�����ڴ�������Ľӿڣ����������ʵ������һ���ࡣ
//Factory Methodʹһ�����ʵ�����ӳٵ������ࡣ

//�������ܳ��󣬻����Ըղŵ����ӽ��͡�
//��������������˵Ĳ���׬�˲���Ǯ�����Ǿ����ٿ���һ������ר����������B�ͺŵĵ��ˣ�
//��ԭ���Ĺ���ר����������A�ͺŵĵ��ˡ�
//��ʱ���ͻ�Ҫ�������Һù���������ҪA�ͺŵĺˣ�����A����Ҫ��
//������B����Ҫ��������Ҫ���߹�������Ҫʲô�ͺŵĴ��������ˡ��������һ��ʵ�ַ�����
namespace Factory_Method{
	class Factory{
	public:
		virtual SingleCore* CreateSingleCore() = 0;
	};
	//����A�˵Ĺ���
	class FactoryA : public Factory
	{
	public:
		SingleCoreA* CreateSingleCore() { return new SingleCoreA;}
	};
	class FactoryB : public Factory
	{
	public:
		SingleCoreB* CreateSingleCore() { return new SingleCoreB; }
	};
};
//��������ģʽҲ��ȱ�㣬ÿ����һ�ֲ�Ʒ������Ҫ����һ������Ĺ�����
//�����ҹ�˾��չѸ�٣��Ƴ��˺ܶ��µĴ������ˣ���ô��Ҫ������Ӧ���¹�����
//��C++ʵ���У�����Ҫ����һ�����Ĺ����ࡣ��Ȼ����ȼ򵥹���ģʽ����������ģʽ��Ҫ������ඨ�塣

//��Ȼ���˼򵥹���ģʽ�͹�������ģʽ��Ϊʲô��Ҫ�г��󹤳�ģʽ�أ���������ʲô�����أ�
//���Ǿ�������ӣ���ҹ�˾�ļ������Ͻ��������������������˴�������Ҳ��������˴�������
//���ڼ򵥹���ģʽ�͹�������ģʽ���޳�Ī�������󹤳�ģʽ�ǳ��ˡ�
//���Ķ���Ϊ�ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ
//��������Ӧ�ã���ҹ�˾���ǿ�������������һ��ר����������A�ͺŵĵ��˶�˴�������
//����һ������ר����������B�ͺŵĵ��˶�˴��������������ʵ�ֵĴ��롣
//���
class MultiCore
{
public:
	virtual void Show() =0;
};
class MultiCoreA : public MultiCore
{
public:
	void Show() {cout<<"Multi Core A"<<endl;}
};
class MultiCoreB : public MultiCore
{
public:
	void Show() {cout<<"Multi Core B"<<endl;}
};
namespace Abstract_Factory{
//����
class CoreFactory
{
public:
	virtual SingleCore* CreateSingleCore()=0;
	virtual MultiCore* CreateMultiCore()  =0;
};
//����A��ר����������A�ͺŵĴ�����
class FactoryA : public CoreFactory
{
public:
	SingleCore* CreateSingleCore(){ return new SingleCoreA();}
	MultiCore* CreateMultiCore(){	return new MultiCoreA();}
};
//����B��ר����������A�ͺŵĴ�����
class FactoryB : public CoreFactory
{
public:
	SingleCore* CreateSingleCore(){ return new SingleCoreB();}
	MultiCore* CreateMultiCore(){	return new MultiCoreB();}
};
}
//���� http://blog.csdn.net/wuzhekai1985
emJRet CFactory::Run()
{
	Normal_Factory::Factory normalFacotry;
	Factory_Method::FactoryA methodFactoryA;
	Factory_Method::FactoryB methodFactoryB;
	Abstract_Factory::FactoryA abstractFactoryA;
	Abstract_Factory::FactoryB abstractFactoryB;

	SingleCore* pSingleCore = normalFacotry.CreateSingleCore(COREA);
	pSingleCore->Show();
	delete pSingleCore;

	pSingleCore = methodFactoryB.CreateSingleCore();
	pSingleCore->Show();
	delete pSingleCore;

	pSingleCore = abstractFactoryA.CreateSingleCore();
	pSingleCore->Show();
	delete pSingleCore;
	
	MultiCore* pMultiCore = abstractFactoryB.CreateMultiCore();
	pMultiCore->Show();
	delete pMultiCore;

	return emJOk;
}
