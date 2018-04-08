#include "stdafx.h"
#include "Factory/Factory.h"
#include "Strategy/Strategy.h"
#include "Adapter/Adapter.h"
#include "Singleton/Singleton.h"
#include "Prototype_TemplateMethod/Prototype_TemplateMethod.h"
#include "Builder/Builder.h"
#include "Appearance/Appearance.h"
#include "AssemblyPattern/AssemblyPattern.h"
#include "Proxy/Proxy.h"
#include "Flyweight/Flyweight.h"
#include "Bridge/Bridge.h"
#include "Decker/Decker.h"
#include "Memo/Memo.h"
#include "Mediator/Mediator.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"
#include "Observer/Observer.h"
#include "Condition/Condition.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout<<"Try CFactory:"<<endl;
	CFactory factory;
	factory.Run();

	cout<<endl<<"Try CStrategy:"<<endl;
	CStrategy stategy;
	stategy.Run();

	cout<<endl<<"Try CAdapter:"<<endl;
	CAdapter adapter;
	adapter.Run();

	cout<<endl<<"Try CSingletonCSingleton:"<<endl;
	CSingleton singleton;
	singleton.Run();

	cout<<endl<<"Try CPrototype:"<<endl;
	CPrototype_TemplateMethod prototype;
	prototype.Run();

	cout<<endl<<"Try CBuilder:"<<endl;
	CBuilder builder;
	builder.Run();

	cout<<endl<<"Try CAppearance:"<<endl;
	CAppearance appearance;
	appearance.Run();

	cout<<endl<<"Try AssemblyPattern:"<<endl;
	CAssemblyPattern assemblypattern;
	assemblypattern.Run();

	cout<<endl<<"Try Proxy:"<<endl;
	CProxy proxy;
	proxy.Run();

	cout<<endl<<"Try Flyweight:"<<endl;
	CFlyweight flyweight;
	flyweight.Run();

	cout<<endl<<"Try Bridge:"<<endl;
	CBridge bridge;
	bridge.Run();

	cout<<endl<<"Try Decker:"<<endl;
	CDecker decker;
	decker.Run();

	cout<<endl<<"Try Memo:"<<endl;
	CMemo memo;
	memo.Run();

	cout<<endl<<"Try Mediator:"<<endl;
	CMediator mediator;
	mediator.Run();

	cout<<endl<<"Try CChainOfResponsibility:"<<endl;
	CChainOfResponsibility chainofresponsibility;
	chainofresponsibility.Run();

	cout<<endl<<"Try Observer:"<<endl;
	CObserver observer;
	observer.Run();

	cout<<endl<<"Try Condition:"<<endl;
	CCondition condition;
	condition.Run();
	system("pause");
	return 0;
}

