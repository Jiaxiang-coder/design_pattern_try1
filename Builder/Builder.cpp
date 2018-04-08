
#include "Builder.h"
using namespace std;


//������ģʽ�Ķ��彫һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��DP����
//�������ģʽ������һ���ܺõ����ӡ�������С�ˣ�һ���轨��6�����֣�ͷ�������塢�����֡����ҽš�
//�빤��ģʽ��ͬ��������ģʽ���ڵ����ߵĿ�����һ��һ�������Ʒ�ġ�
//����С�˾����ڿ�����һ������������ġ�������ģʽ�����ܸ���ϸ�Ŀ��ƹ������̣�
//�Ӷ��ܸ���ϸ�Ŀ������ò�Ʒ���ڲ��ṹ���������������ģʽ��UMLͼ���Խ���С��Ϊʵ����

 //���ڿͻ���˵��ֻ��֪�������߾Ϳ����ˣ�ͨ�������ߣ��ͻ����ܹ��츴�ӵĶ��󣬶�����Ҫ֪������Ĺ�����̡�
//�������С�����ӵĴ���ʵ�֡�

class Builder
{
public:
	virtual void BuildHead(){}
	virtual void BuildBody(){}
	virtual void BuildLeftArm(){}
	virtual void BuildRightArm(){}
	virtual void BuildLeftLeg(){}
	virtual void BuildRightLeg(){}
};
//��������
class ThinBuilder : public Builder
{
public:
	void BuildHead() { cout<< "build thin head" <<endl;}
	void BuildBody() { cout<< "build thin body" <<endl;}
	void BuildLeftArm() { cout<< "build thin leftarm" <<endl;}
	void BuildRightArm() { cout<< "build thin rightarm" <<endl;}
	void BuildLeftLeg() { cout<< "build thin leftleg" <<endl;}
	void BuildRightLeg() { cout<< "build thin rightleg" <<endl;}
};
//class FatBuilder : public Builder;'

//�����ָ�ӹ�
class Director
{
private:
	Builder *m_pBuilder;
public:
	Director(Builder* builder){m_pBuilder = builder;}
	void Create(){
		m_pBuilder->BuildHead();
		m_pBuilder->BuildBody();
		m_pBuilder->BuildLeftArm();
		m_pBuilder->BuildRightArm();
		m_pBuilder->BuildLeftLeg();
		m_pBuilder->BuildRightLeg();
	}
};
//���� http://blog.csdn.net/wuzhekai1985

emJRet CBuilder::Run()
{
	//FatBuilder thin;
	ThinBuilder thin;
	Director director(&thin);
	director.Create();
	return emJOk;
}
