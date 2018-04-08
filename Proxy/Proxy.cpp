
#include "Proxy.h"
#include <string>
using namespace std;

//[DP]上的定义：为其他对象提供一种代理以控制对这个对象的访问。有四种常用的情况：
//（1）远程代理，（2）虚代理，（3）保护代理，（4）智能引用。本文主要介绍虚代理和智能引用两种情况。

//考虑一个可以在文档中嵌入图形对象的文档编辑器。有些图形对象的创建开销很大。
//但是打开文档必须很迅速，因此我们在打开文档时应避免一次性创建所有开销很大的对象。
//这里就可以运用代理模式，在打开文档时，并不打开图形对象，而是打开图形对象的代理以替代真实的图形。
//待到真正需要打开图形时，仍由代理负责打开。这是[DP]一书上的给的例子。下面给出代理模式的UML图。
class Image
{
public:
	Image(string name) : m_imageName(name){}
	virtual ~Image() {cout<<"~Image"<<endl;}
	virtual void Show() {}
protected:
	string m_imageName;
};
class BigImage : public Image
{
public:
	BigImage(string name) : Image(name) {}
	~BigImage() {cout<<"~BigImage"<<endl;}
	void Show() { cout<<"Show big image: "<<m_imageName<<endl;}
};
class BigIamgeProxy : public Image
{
private:
	BigImage *m_bigImage;	//开始不创建对象，等Show的时候再创建
public:
	BigIamgeProxy(string name) : Image(name), m_bigImage(0) {}
	~BigIamgeProxy() {delete m_bigImage; cout<<"~BigIamgeProxy"<<endl;}
	void Show()
	{
		if(m_bigImage == NULL)
			m_bigImage = new BigImage(m_imageName);
		m_bigImage->Show();
	}
};

 //在这个例子属于虚代理的情况，下面给两个智能引用的例子。一个是C++中的auto_ptr，另一个是smart_ptr。
//自己实现了一下。先给出auto_ptr的代码实现：
template <class T>
class auto_ptr{
public:
	explicit auto_ptr(T *p =0) : pointee(p) {}
	auto_ptr(auto_ptr<T>& rhs) : pointee (rhs.release()){}
	~auto_ptr() {delete pointee;}
	auto_ptr<T>& operator= (auto_ptr<T>& rhs)
	{
		if(this != &rhs) reset(rhs.release());
		return *this;
	}
	T& operator*() const{ return *pointee; }
	T* operator->() const{ return pointee; }
	T* get() const { return pointee; }
	T* release()
	{
		T* oldPointee = pointee;
		pointee = 0;
		return oldPointee;
	}
	void reset(T *p =0)
	{
		if(pointee != p){
			delete pointee;
			pointee = p;
		}
	}
private:
	T* pointee;
};
//阅读上面的代码，我们可以发现 auto_ptr 类就是一个代理，客户只需操作auto_prt的对象，
//而不需要与被代理的指针pointee打交道。
//auto_ptr 的好处在于为动态分配的对象提供异常安全。
//因为它用一个对象存储需要被自动释放的资源，然后依靠对象的析构函数来释放资源。
//这样客户就不需要关注资源的释放，由auto_ptr 对象自动完成。
//实现中的一个关键就是重载了解引用操作符和箭头操作符，从而使得auto_ptr的使用与真实指针类似。

 //我们知道C++中没有垃圾回收机制，可以通过智能指针来弥补，下面给出智能指针的一种实现，采用了引用计数的策略。

template<typename T>
class smart_ptr
{
public:
	smart_ptr(T *p=0) : pointee(p), count(new size_t(1)) {
		cout<<"smart_ptr (T* p)"<<endl;
	} //初始的引用计数为1
	smart_ptr(const smart_ptr &rhs) : pointee(rhs.pointee), count(rhs.count) {++*count;} //拷贝构造函数，计数加1
	~smart_ptr() { decr_count(); }	//析构，计数减1，减到0时进行垃圾回收，即释放空间
	smart_ptr& operator=(const smart_ptr& rhs) //重载赋值操作符
	{
		//给自身复制也对，因为如果自身复制，计数器先减1，再加1，并未发生改变
		++*count;
		decr_count();
		pointee = rhs.pointee;
		count = rhs.count;
		return *this;
	}
	//重载箭头操作符合解引用操作符，未提供指针的检查
	T *operator->() {return pointee;}
	const T *operator->() const {return pointee;}
	T& operator*() { return *pointee; }
	const T& operator*() const { return *pointee; }
	size_t get_refcount() { return *count; }

private:
	T *pointee;
	size_t *count;
	void decr_count()
	{
		if(--*count == 0)
		{
			delete pointee;
			delete count;
		}
	}
};
//出处 http://blog.csdn.net/wuzhekai1985
emJRet CProxy::Run()
{
	//Image *image = new BigIamgeProxy("proxy.jpg"); //代理
	//image->Show(); //需要时由代理负责打开
	//delete image;
	//smart_ptr<Image> pimage = new BigIamgeProxy("proxy.jpg");
	//pimage->Show();
	auto_ptr<Image> pimage (new BigIamgeProxy("proxy.jpg") );
	pimage->Show();
	return emJOk;
}
