
#include "Proxy.h"
#include <string>
using namespace std;

//[DP]�ϵĶ��壺Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ������ֳ��õ������
//��1��Զ�̴�����2���������3������������4���������á�������Ҫ���������������������������

//����һ���������ĵ���Ƕ��ͼ�ζ�����ĵ��༭������Щͼ�ζ���Ĵ��������ܴ�
//���Ǵ��ĵ������Ѹ�٣���������ڴ��ĵ�ʱӦ����һ���Դ������п����ܴ�Ķ���
//����Ϳ������ô���ģʽ���ڴ��ĵ�ʱ��������ͼ�ζ��󣬶��Ǵ�ͼ�ζ���Ĵ����������ʵ��ͼ�Ρ�
//����������Ҫ��ͼ��ʱ�����ɴ�����򿪡�����[DP]һ���ϵĸ������ӡ������������ģʽ��UMLͼ��
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
	BigImage *m_bigImage;	//��ʼ���������󣬵�Show��ʱ���ٴ���
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

 //����������������������������������������õ����ӡ�һ����C++�е�auto_ptr����һ����smart_ptr��
//�Լ�ʵ����һ�¡��ȸ���auto_ptr�Ĵ���ʵ�֣�
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
//�Ķ�����Ĵ��룬���ǿ��Է��� auto_ptr �����һ�������ͻ�ֻ�����auto_prt�Ķ���
//������Ҫ�뱻�����ָ��pointee�򽻵���
//auto_ptr �ĺô�����Ϊ��̬����Ķ����ṩ�쳣��ȫ��
//��Ϊ����һ������洢��Ҫ���Զ��ͷŵ���Դ��Ȼ����������������������ͷ���Դ��
//�����ͻ��Ͳ���Ҫ��ע��Դ���ͷţ���auto_ptr �����Զ���ɡ�
//ʵ���е�һ���ؼ����������˽����ò������ͼ�ͷ���������Ӷ�ʹ��auto_ptr��ʹ������ʵָ�����ơ�

 //����֪��C++��û���������ջ��ƣ�����ͨ������ָ�����ֲ��������������ָ���һ��ʵ�֣����������ü����Ĳ��ԡ�

template<typename T>
class smart_ptr
{
public:
	smart_ptr(T *p=0) : pointee(p), count(new size_t(1)) {
		cout<<"smart_ptr (T* p)"<<endl;
	} //��ʼ�����ü���Ϊ1
	smart_ptr(const smart_ptr &rhs) : pointee(rhs.pointee), count(rhs.count) {++*count;} //�������캯����������1
	~smart_ptr() { decr_count(); }	//������������1������0ʱ�����������գ����ͷſռ�
	smart_ptr& operator=(const smart_ptr& rhs) //���ظ�ֵ������
	{
		//��������Ҳ�ԣ���Ϊ��������ƣ��������ȼ�1���ټ�1����δ�����ı�
		++*count;
		decr_count();
		pointee = rhs.pointee;
		count = rhs.count;
		return *this;
	}
	//���ؼ�ͷ�������Ͻ����ò�������δ�ṩָ��ļ��
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
//���� http://blog.csdn.net/wuzhekai1985
emJRet CProxy::Run()
{
	//Image *image = new BigIamgeProxy("proxy.jpg"); //����
	//image->Show(); //��Ҫʱ�ɴ������
	//delete image;
	//smart_ptr<Image> pimage = new BigIamgeProxy("proxy.jpg");
	//pimage->Show();
	auto_ptr<Image> pimage (new BigIamgeProxy("proxy.jpg") );
	pimage->Show();
	return emJOk;
}
