
#include "Memo.h"
#include <string>
#include <vector>
using namespace std;

//����¼ģʽ���ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��
//�����Ժ�Ϳɽ��ö���ָ���ԭ�ȱ����״̬[DP]��
//�ٸ��򵥵����ӣ���������Ϸʱ���ᱣ����ȣ�������Ľ������ļ�����ʽ���ڡ�
//�����´ξͿ��Լ����棬�����ô�ͷ��ʼ��
//����Ľ�����ʵ������Ϸ���ڲ�״̬����������ļ��൱��������Ϸ֮�Ᵽ��״̬��
//�������´ξͿ��Դ��ļ��ж��뱣��Ľ��ȣ��Ӷ��ָ���ԭ����״̬������Ǳ���¼ģʽ��

//��������¼ģʽ��UMLͼ���Ա�����Ϸ�Ľ���Ϊ����

//Memento�ඨ�����ڲ���״̬����Caretake����һ��������ȵĹ����ߣ�GameRole������Ϸ��ɫ�ࡣ
//���Կ���GameRole�Ķ���������Memento���󣬶���Caretake�����޹ء��������һ���򵥵���ʵ�֡�

//�豣�����Ϣ
class Memento
{
public:
	int m_vitality; //����ֵ
	int m_attack;		//����ֵ
	int m_defense;	//����ֵ
public:
	Memento(int vitality, int attack, int defense) :
			m_vitality(vitality), m_attack(attack), m_defense(defense){}
	Memento& operator=(const Memento &memento)
	{
		m_vitality = memento.m_vitality;
		m_attack = memento.m_attack;
		m_defense = memento.m_defense;
		return *this;
	}
};
//��Ϸ��ɫ
class GameRole
{
private:
	int m_vitality;
	int m_attack;
	int m_defense;
public:
	GameRole() : m_vitality(100), m_attack(100),m_defense(100){}
	Memento Save() //������ȣ�ֻ��Memento���󽻻�������ǣ�浽Caretake
	{
		Memento memento(m_vitality, m_attack, m_defense);
		return memento;
	}
	void Load(Memento memento) //������ȣ�ֻ��Memento���󽻻�������ǣ�浽 Caretake
	{
		m_vitality = memento.m_vitality;
		m_attack = memento.m_attack;
		m_defense = memento.m_defense;
	}
	void Show() { cout<<"vitality : "<<m_vitality<<",attack: "<<m_attack<<",defense: "<<m_defense<<endl;}
	void Attack() {m_vitality -=10; m_attack -=10; m_defense -=10;}
};
//����Ľ��ȿ�
class Caretake
{
public:
	Caretake() {}
	void Save(Memento memento) { m_vecMemento.push_back(memento); }
	Memento Load(int state) { return m_vecMemento[state]; }
private:
	vector<Memento> m_vecMemento;
};

//���� http://blog.csdn.net/wuzhekai1985
emJRet CMemo::Run()
{
	Caretake caretake;
	GameRole role;
	role.Show();
	caretake.Save(role.Save()); 
	role.Attack();
	role.Show();
	role.Load(caretake.Load(0));
	role.Show();
	return emJOk;
}