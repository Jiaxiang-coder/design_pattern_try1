
#include "Builder.h"
using namespace std;


//建造者模式的定义将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示（DP）。
//《大话设计模式》举了一个很好的例子——建造小人，一共需建造6个部分，头部、身体、左右手、左右脚。
//与工厂模式不同，建造者模式是在导向者的控制下一步一步构造产品的。
//建造小人就是在控制下一步步构造出来的。创建者模式可以能更精细的控制构建过程，
//从而能更精细的控制所得产品的内部结构。下面给出建造者模式的UML图，以建造小人为实例。

 //对于客户来说，只需知道导向者就可以了，通过导向者，客户就能构造复杂的对象，而不需要知道具体的构造过程。
//下面给出小人例子的代码实现。

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
//构造瘦人
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

//构造的指挥官
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
//出处 http://blog.csdn.net/wuzhekai1985

emJRet CBuilder::Run()
{
	//FatBuilder thin;
	ThinBuilder thin;
	Director director(&thin);
	director.Create();
	return emJOk;
}
