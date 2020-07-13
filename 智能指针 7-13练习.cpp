class A
{
public:
	int a;
	char b;
};
int main()
{
	/*vcauto_ptr::auto_ptr<int> ptr1 = new int(5);
	cout << *ptr1 << endl;*/
	vcauto_ptr::auto_ptr<A> ptr = new A;
	cout << ptr->a << endl;
	return 0;
}

namespace vcauto_ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* p = nullptr) : _ptr(p), own(true)
		{}

		~auto_ptr()
		{
			if (own)
				delete _ptr;
		}
	public:
		T& operator *()
		{
			return *_ptr;
		}

		T* operator ->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		bool own;
	};
}