namespace mystring
{
	class string
	{
	public:
		typedef char* iterator;
#define npos -1;
	public:
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
	public:
		string(const char * str = "")
		{
			_size = strlen(str);
			_capacity = _size + 15;
			_str = new char[_capacity];
			strcpy(_str, str);
		}
		string(int n, char ch);
		string(const string& str)
		{
			_size = str._size;
			_capacity = str._capacity;
			_str = new char[_capacity];
			strcpy(_str, str._str);
		}
		string& operator=(string str)
		{
			swap(str);
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete _str;
				_str = nullptr;
			}
		}
	public:
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		bool empty()
		{
			return _size == 0;
		}
	public:
		void resize(size_t newsize, char ch = '\0')
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
					reserve(newsize);
				memset(_str + _size, ch, newsize - _size);
			}
			_size = newsize;
			_str[_size] = '\0';
		}
		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				char* str = new char[newcapacity + 15];
				strcpy(str, _str);

				delete[] _str;
				_str = str;
				_capacity = newcapacity;
			}
		}
	public:
		void append(const char* str)
		{
			if (_size + strlen(str) > _capacity)
				reserve(_size + strlen(str));
			strcpy(_str + _size, str);
			_size += strlen(str);
			_str[_size] = '\0';
		}
		void append(const string& str)
		{
			if (_size + str._size > _capacity)
				reserve(_size + str._size);
			strcpy(_str + _size, str.c_str());
			_size += str._size;
			_str[_size] = '\0';
		}
	public:
		string& operator+=(char ch)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
			return *this;
		}
		string& operator+=(const char* str)
		{
			if (_size + strlen(str) > _capacity)
				reserve(_size + strlen(str));
			strcpy(_str + _size, str);
			_size += strlen(str);
			_str[_size] = '\0';
			return *this;
		}
		string& operator+=(const string& str)
		{
			if (_size + str._size > _capacity)
				reserve(_size + str._size);
			strcpy(_str + _size, str.c_str());
			_size += str._size;
			_str[_size] = '\0';
			return *this;
		}
	public:
		char operator[](int index)
		{
			return _str[index];
		}
		friend ostream& operator<<(ostream& out, string str);
	public:
		bool operator<(const string& str) const
		{
			return strcmp(_str, str._str) < 0;
		}
		bool operator>(const string& str) const
		{
			return strcmp(_str, str._str) > 0;
		}
		bool operator==(const string& str) const
		{
			return strcmp(_str, str._str) == 0;
		}
		bool operator!=(const string& str) const
		{
			return !(operator==(str));
		}
		bool operator>=(const string& str) const
		{
			return !(operator<(str));
		}
		bool operator<=(const string& str) const
		{
			return !(operator>(str));
		}
	public:
		size_t find(char ch, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(char *str, size_t pos = 0) const
		{
			while (pos < _size - strlen(str))
			{
				int i = pos, j = 0;
				while (*(str + j) != '\0')
				{
					if (*(_str + i) != *(str + j))
						break;
					++i;
					++j;
				}
				if (*(str + j) == '\0')
					return pos;
				++pos;
			}
			return npos;
		}
		size_t find(string& str, size_t pos = 0) const
		{
			return find(str.c_str(), pos);
		}
	public:
		string& insert(size_t pos, char ch)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			strcpy(_str + pos + 1, _str + pos);
			_str[pos] = ch;
			return *this;
		}
		string& insert(size_t pos, char *str)
		{
			if (_size + strlen(str) >= _capacity)
				reserve(_size + strlen(str));
			memmove(_str + pos + strlen(str), _str + pos, _size - pos + 1);
			strncpy(_str + pos, str, strlen(str));
			return *this;
		}
		string& insert(size_t pos, string& str)
		{
			return insert(pos, str.c_str());
		}
	public:
		void erase(size_t pos, size_t len = 1)
		{
			strcpy(_str + pos, _str + pos + len);
		}
	public:
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		char* c_str() const
		{
			return _str;
		}
	private:
		char * _str;
		size_t _size;
		size_t _capacity;
	};
	ostream& operator<<(ostream& out, string str)
	{
		for (size_t i = 0; str[i] != '\0'; ++i)
			out << str[i];
		return out;
	}
}
