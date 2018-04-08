
#include "Strategy.h"

using namespace std;
//����ģʽ��ָ����һϵ�е��㷨��������һ������װ����������ʹ���ǿ��໥�滻��
//��ģʽʹ���㷨�ɶ�����ʹ�����Ŀͻ����仯��
//Ҳ����˵��Щ�㷨����ɵĹ���һ��������Ľӿ�һ����ֻ�Ǹ���ʵ���ϴ��ڲ��졣
//�ò���ģʽ����װ�㷨��Ч���ȽϺá������Ը��ٻ��棨Cache�����滻�㷨Ϊ����ʵ�ֲ���ģʽ��
//
//ʲô��Cache���滻�㷨�أ�
//�򵥽���һ�£� ������Cacheȱʧʱ��Cache����������ѡ��Cache�е�һ�У���������õ��������滻����
//�����õ�ѡ����Ծ���Cache���滻�㷨��

//����ӿ�
class ReplaceAlgorithm
{
public:
	virtual void Replace() = 0;
};
//���־�����滻�㷨
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"Least Recently Used replace algorithm"<<endl; }
};
class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"First in First out replace algorithm"<<endl; }
};
class Random_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void Replace() { cout<<"Random replace algorithm"<<endl; }
};
//���Ÿ���Cache�Ķ��壬����ܹؼ���Cache��ʵ�ַ�ʽֱ��Ӱ���˿ͻ���ʹ�÷�ʽ����ؼ��������ָ���滻�㷨��

//��ʽһ��ֱ��ͨ������ָ��������һ���ض��㷨��ָ�롣
namespace ByParam_Strategy
{
	class Cache
	{
	private:
		ReplaceAlgorithm * m_ra;
	public:
		Cache(ReplaceAlgorithm* ra) { m_ra = ra;}
		~Cache(){delete m_ra;}
		void Replace(){ m_ra->Replace(); }
	};
}
 //��������ַ�ʽ���ͻ�����Ҫ֪����Щ�㷨�ľ��嶨�塣ֻ�����������ַ�ʽʹ�ã����Կ�����¶��̫���ϸ�ڡ�
 //��ʽ����Ҳ��ֱ��ͨ������ָ����ֻ�������Ǵ���ָ�룬����һ����ǩ��
	 //�����ͻ�ֻҪ֪���㷨����Ӧ��ǩ���ɣ�������Ҫ֪���㷨�ľ��嶨�塣
namespace ByEnumParam_Strategy
{
	enum RA{ LRU, FIFO, RANDOM};
	class Cache
	{
	private:
		ReplaceAlgorithm* m_ra;
	public:
		Cache(enum RA ra){
			if(ra == LRU)
				m_ra = new LRU_ReplaceAlgorithm();
			else if(ra == FIFO)
				m_ra = new FIFO_ReplaceAlgorithm();
			else if(ra == RANDOM)
				m_ra = new Random_ReplaceAlgorithm();
			else
				m_ra = NULL;
		};
		~Cache(){delete m_ra;}
		void Replace(){ m_ra->Replace();}
	};
}
//��ȷ�ʽһ�����ַ�ʽ������������ˡ�
//��ʵ���ַ�ʽ���򵥹���ģʽ�����ģʽ�����һ���㷨�Ķ���ʹ���˲���ģʽ��
//��Cache�Ķ�����ʵʹ���˼򵥹���ģʽ��

//�������ַ�ʽ�����캯������Ҫ�βΡ����캯���Ƿ���Բ��ò����أ��������������ʵ�ַ�ʽ��
//��ʽ��������ģ��ʵ�֡��㷨ͨ��ģ���ʵ��ָ����
//��Ȼ�ˣ�����ʹ���˲�����ֻ�������ǹ��캯���Ĳ�����
//�ڲ���ģʽ�У������Ĵ������Ա��⣬�ͻ�����ָ��ĳ���㷨��
namespace Template_Strategy
{
	template<class RA>
	class Cache
	{
	private:
		RA m_ra;
	public:
		Cache(){}
		~Cache() {}
		void Replace(){ m_ra.Replace();}
	};
}
//���� http://blog.csdn.net/wuzhekai1985

emJRet CStrategy::Run()
{
	ByParam_Strategy::Cache cache1(new FIFO_ReplaceAlgorithm());
	cache1.Replace();
	ByEnumParam_Strategy::Cache cache2(ByEnumParam_Strategy::LRU);
	cache2.Replace();
	Template_Strategy::Cache<Random_ReplaceAlgorithm> cache3; //ģ��ʵ��
	cache3.Replace();
	return emJOk;
}
