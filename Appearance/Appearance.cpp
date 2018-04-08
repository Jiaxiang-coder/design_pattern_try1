
#include "Appearance.h"
using namespace std;


//外观模式应该是用的很多的一种模式，特别是当一个系统很复杂时，
//系统提供给客户的是一个简单的对外接口，而把里面复杂的结构都封装了起来。
//客户只需使用这些简单接口就能使用这个系统，而不需要关注内部复杂的结构。
//DP一书的定义：为子系统中的一组接口提供一个一致的界面， 外观模式定义了一个高层接口，
//这个接口使得这一子系统更加容易使用。举个编译器的例子，
//假设编译一个程序需要经过四个步骤：词法分析、语法分析、中间代码生成、机器码生成。
//学过编译都知道，每一步都很复杂。
//对于编译器这个系统，就可以使用外观模式。
//可以定义一个高层接口，比如名为Compiler的类，里面有一个名为Run的函数。
//客户只需调用这个函数就可以编译程序，至于Run函数内部的具体操作，客户无需知道。下面给出UML图，以编译器为实例。

class Scanner
{
public:
	void Scan() { cout<<"词法分析"<<endl; }
};
class Parser
{
public:
	void Parse() { cout<<"语法分析"<<endl; }
};
class GenMidCode
{
public:
	void GenCode() { cout<<"产生中间代码"<<endl; }
};
class GenMachineCode
{
public:
	void GenCode() { cout<<"产生机器码"<<endl;}
};
//高层接口
class Compiler
{
public:
	void Run() 
	{
		Scanner scanner;
		Parser parser;
		GenMidCode genMidCode;
		GenMachineCode genMacCode;
		scanner.Scan();
		parser.Parse();
		genMidCode.GenCode();
		genMacCode.GenCode();
	}
};

//这就是外观模式，它有几个特点（摘自DP一书），
//（1）它对客户屏蔽子系统组件，因而减少了客户处理的对象的数目并使得子系统使用起来更加方便。
//（2）它实现了子系统与客户之间的松耦合关系，而子系统内部的功能组件往往是紧耦合的。
//（3）如果应用需要，它并不限制它们使用子系统类。
//结合上面编译器这个例子，进一步说明。
//对于（1），编译器类对客户屏蔽了子系统组件，客户只需处理编译器的对象就可以方便的使用子系统。
//对于（2），子系统的变化，不会影响到客户的使用，体现了子系统与客户的松耦合关系。
//对于（3），如果客户希望使用词法分析器，只需定义词法分析的类对象即可，并不受到限制。
//出处 http://blog.csdn.net/wuzhekai1985
emJRet CAppearance::Run()
{
	//FatBuilder thin;
	Compiler compiler;
	compiler.Run();
	return emJOk;
}
