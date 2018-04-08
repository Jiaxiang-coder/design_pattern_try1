
#include "Bridge.h"
#include <string>
#include <vector>
using namespace std;

//�Ž�ģʽ
//[DP]���϶��壺�����󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯��
//����װ����ϵͳ���ж������õļ������ͬ��Ҳ�ж�����ϵͳ��
//��������Ž�ģʽ�أ�
//���Խ�����ϵͳ�ͼ�����ֱ��������������Ǹ��Է�չ���������ǵ���϶ȡ�
//��Ȼ�ˣ�����֮���б�׼�Ľӿڡ�
//������ƣ������Ƕ��ڼ���������ǲ���ϵͳ���Ƿǳ������ġ�
//�������������Ƶ�UMLͼ����ʵ�����Ž�ģʽ��UMLͼ��

//����C++��һ��ʵ��:
//����ϵͳ
class OS
{
public:
	virtual void InstallOS_Imp() {}
};
class WindowOS : public OS
{
public:
	void InstallOS_Imp() {cout<<"��װWindow����ϵͳ"<<endl;}
};
class LinuxOS : public OS
{
public:
	void InstallOS_Imp() {cout<<"��װLinux����ϵͳ"<<endl;}
};
class UnixOS : public OS
{
public:
	void InstallOS_Imp() { cout<<"��װUnix����ϵͳ"<<endl; }
};
//�����
class Computer
{
public:
	virtual void InstallOS(OS *os) {}
};
class DellComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};
class AppleComputer : public Computer
{
public:
	void InstallOS(OS *os) {os->InstallOS_Imp();}
};
class HPComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};


//���� http://blog.csdn.net/wuzhekai1985
emJRet CBridge::Run()
{
	OS *os1 = new WindowOS();
	OS *os2 = new LinuxOS();
	Computer *computer1 = new AppleComputer();
	computer1->InstallOS(os1);
	computer1->InstallOS(os2);

	return emJOk;
}
