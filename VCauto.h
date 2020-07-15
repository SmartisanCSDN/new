#ifndef _VCAUTO_T_
#define _VCAUTO_T_

#include"common.h"


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
		auto_ptr(auto_ptr<T>& p)
		{
			own = p.own;
			_ptr = p.release();
		}
		auto_ptr<T>& operator=(const auto_ptr<T>& p)
		{
			if (this != &p)
			{
				if (_ptr == p._ptr)
				{
					if (own)
						delete _ptr;
					own = p.own;
				}
				else if (p.own)
					own = true;
				_ptr = p.release();
			}
			return *this;
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
	protected:
		T* release() const
		{
			((auto_ptr<T> * const)this)->own = false;
			T* temp = _ptr;
			((auto_ptr<T> * const)this)->_ptr = nullptr;
			return temp;
		}
	private:
		T* _ptr;
		bool own;
	};
}





#endif