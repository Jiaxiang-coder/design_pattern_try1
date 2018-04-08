
#include "Prototype_TemplateMethod.h"
#include <string.h>
using namespace std;

//DP���ϵĶ���Ϊ����ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
//������һ���ʺ���Ҫ���Ǿ��ǿ���������˵��������ԭ��ģʽ�ľ������ڡ�
//�ٸ���ʵ�е�����������ԭ��ģʽ���ҹ�����ʱ��������Ҫ׼��������
//����û�д�ӡ�豸���������д��������Щ���������ݶ���һ���ġ�
//�����и�ȱ�ݣ����Ҫ�޸ļ����е�ĳ���ô������д�õļ�����Ҫ�޸ģ��������ܴ�
//���ſƼ��Ľ����������˴�ӡ�豸������ֻ����дһ�ݣ�Ȼ�����ô�ӡ�豸��ӡ��ݼ��ɡ�
//���Ҫ�޸ļ����е�ĳ���ô�޸�ԭʼ�İ汾�Ϳ����ˣ�Ȼ���ٸ�ӡ��
//ԭʼ���Ƿ���д���൱����һ��ԭ�ͣ����������Ϳ���ͨ����ӡ�������������������¼�����
//�����ԭ��ģʽ�Ļ���˼�롣�������ԭ��ģʽ��UMLͼ���Ըղ��Ǹ�����Ϊʵ����

//ԭ��ģʽʵ�ֵĹؼ�����ʵ��Clone����������C++��˵����ʵ���ǿ������캯������ʵ��������������һ��ʵ�֡�


namespace UsePrototypeClone
{
//����
class Resume
{
protected:
	char *name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return NULL;}
	virtual void Set(char *n) {}
	virtual void Show() {}
};

class ResumeA : public Resume
{
public:
	ResumeA(const char *str);		//���캯��
	ResumeA(const ResumeA &r);	//�������캯��
	~ResumeA();									//��������
	ResumeA* Clone();						//��¡���ؼ�����
	void Show();								//��ʾ����
};
ResumeA::ResumeA(const char *str){
	if(str == NULL){
		name = new char[1];
		name[0] = '\0';
	}else{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeA::~ResumeA() {delete [] name;}
ResumeA::ResumeA(const ResumeA &r){
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeA* ResumeA::Clone(){
	return new ResumeA(*this);
}
void ResumeA::Show(){
	cout<<"ResumeA name: "<<name<<endl;
}

//����ֻ������ResumeA��ʵ�֣�ResumeB��ʵ�����ơ�ʹ�õķ�ʽ���£�
	void UseResume(){
		Resume *r1 = new ResumeA("A");
		//Resume *r2 = new ResumeB("B");
		Resume *r3 = r1->Clone();
		r1->Show();
		//ɾ��r1,r2
		delete r1; 
		//������Զ�r3,r4��Ӱ��
		r3->Show();
		delete r3;
	}
}

//����и���Ƹ�ᣬ���Դ��ϼ���ȥӦƸ�ˡ�
//���ǣ�������һ�ҹ�˾�����ܼ��������Ǹ�ӦƸ�߷���һ�ż�������
//�����л�����Ϣ����������������������������ӦƸ�߰���Ҫ����д������
//ÿ�����õ���ݱ���󣬾Ϳ�ʼ��д��
//����ó���ʵ��������̣���������أ�
//һ�ַ���������ģ�巽��ģʽ��
//����һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������С�
//ģ�巽��ʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض����衣
//���ǵ������У�����������д������һ���̣����ǿ����ڸ����ж���������㷨�Ǽܣ��������ʵ����������ɡ�
//�����������UMLͼ��

//����FillResume() �����˲����ĹǼܣ����ε�������ʵ�ֵĺ������൱��ÿ������д������ʵ�ʹ��̡�
//���Ÿ�����Ӧ��C++����
namespace Template_Method
{
	class Resume
	{
	protected:
		virtual void SetPersonalInfo(){}
		virtual void SetEducation() {}
		virtual void SetWorkExp() {}
	public:
		void FillResume()
		{
			SetPersonalInfo();
			SetEducation();
			SetWorkExp();
		}
	};
	class ResumeA : public Resume
	{
	protected:
		void SetPersonalInfo() { cout<<"A's PersonalInfo"<<endl; }
		void SetEducation() { cout<<"A's Education"<<endl; }
		void SetWorkExp() { cout<<"A's Work Experience"<<endl; }
	};
	class ResumeB : public Resume
	{
	protected:
		void SetPersonalInfo() { cout<<"B's PersonalInfo"<<endl; }
		void SetEducation() { cout<<"B's Education"<<endl; }
		void SetWorkExp() { cout<<"B's Work Experience"<<endl; }
	};
	void UseResume(){
		Resume* r1;
		r1 = new ResumeA();
		r1->FillResume();
		delete r1;
		r1 = new ResumeB();
		r1->FillResume();
		delete r1;
		r1 = NULL;
	}
}

//���� http://blog.csdn.net/wuzhekai1985
emJRet CPrototype_TemplateMethod::Run()
{
	UsePrototypeClone::UseResume();
	Template_Method::UseResume();
	return emJOk;
}