#ifndef _VSAUTO_H_
#define _VSAUTO_H_

#include"common.h"

namespace vsauto_ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* p = nullptr) : _ptr(p)
		{}
		~auto_ptr()
		{
			delete _ptr;
		}
	public:
		auto_ptr(auto_ptr<T>& p)
		{
			_ptr = p.release();
		}
		auto_ptr<T>& operator=(const auto_ptr<T>& p)
		{
			if (this != &p && _ptr != p._ptr)
			{
				if (_ptr != nullptr)
				{
					delete _ptr;
				}
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
			T* temp = _ptr;
			(auto_ptr<T> * const)this->_ptr = nullptr;
			return temp;
		}
	private:
		T* _ptr;
	};
}






#endif