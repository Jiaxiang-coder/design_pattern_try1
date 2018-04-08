cmake_minimum_required(VERSION 2.8)
project (design_pattern)
add_executable(patterns 
	main.cpp
	ITry.cpp
	Adapter/Adapter.cpp
	Appearance/Appearance.cpp
	AssemblyPattern/AssemblyPattern.cpp
	Bridge/Bridge.cpp
	Builder/Builder.cpp
	ChainOfResponsibility/ChainOfResponsibility.cpp
	Condition/Condition.cpp
	Decker/Decker.cpp
	Factory/Factory.cpp
	Flyweight/Flyweight.cpp
	Mediator/Mediator.cpp
	Memo/Memo.cpp
	Observer/Observer.cpp
	Prototype_TemplateMethod/Prototype_TemplateMethod.cpp
	Proxy/Proxy.cpp
	Singleton/Singleton.cpp
	Strategy/Strategy.cpp)
