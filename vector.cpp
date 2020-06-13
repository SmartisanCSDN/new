namespace myvector
{
	template<class T>
	class vector
	{
	public:
		void show()
		{
			iterator it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}
	public:
		typedef T* iterator;
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
	public:
		vector()
			: _start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{}
		vector(int n, const T& value = T())
			: _start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(vector<T>& v)
			: _start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = v.begin();
			while (it != v.end())
			{
				(*_finish) = *it;
				++_finish;
				++it;
			}
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	public:
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}
		bool empty() const
		{
			return _finish == _start;
		}
	public:
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* temp = new T[n];
				for (size_t i = 0; i < size(); ++i)
					temp[i] = _start[i];
				_start = temp;
				_finish = _start + oldSize;
				_endOfStorage = _start + n;
			}
		}
		void resize(size_t n, T value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
				reserve(n);
			iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
	public:
		void push_back(T value)
		{
			insert(end(), value);
		}
		void pop_back()
		{
			iterator it = end();
			erase(--it);
		}
	public:
		iterator insert(iterator it, T value)
		{
			assert(it <= _finish);
			if (size() == capacity())
			{
				size_t it_index = it - _start;
				size_t newcapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newcapacity);
				it = _start + it_index;
			}
			iterator final = end();
			while (final > it)
				*final = *(--final);
			*it = value;
			++_finish;
			return it;
		}
		iterator erase(iterator it)
		{
			if (empty())
				return it;
			assert(it < _finish);
			iterator move = it;
			while (move != _finish)
				*move = *(++move);
			--_finish;
			return it;
		}
	public:
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}
	private:
		iterator _start;             //指向数据块的开始
		iterator _finish;            //指向有效数据的尾
		iterator _endOfStorage;      //指向存储容量的尾
	};
}