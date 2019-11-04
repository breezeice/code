#include<stdio.h>
#include<assert.h>
#include<string.h>
using namespace std;
class String
{
public:
	typedef char* Iterator;
	String(const char* str = "")
	{
		assert(str != nullptr);
		size = strlen(str);
		capacity = size;
		str = new char[capacity + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[s.capacity + 1])
		,size(s.size)
		,capacity(s.capacity)
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this !=&s)
		{
			char* str = new char[s.Capacity + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
			size = s.size;
			capacity = s.capacity;
		}
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		 }
	}

	size_t Size()const
	{
		return size;
	}

	size_t Capacity()const
	{
		return capacity;
	}

	Iterator Begin()
	{
		return _str;
	}

	Iterator end()
	{
		return _str + size;
	}


	void Reserve(int n)
	{
		if ( n > capacity)
		{
			char *str = new char[n + 1];
			strcpy(str, _str);
			delete[]_str;
			_str = str;
			capacity = n;
		}
	}
	void PushBack(char c)
	{
		if (size == capacity)
		{
			Reserve(2 * capacity);
		}
		_str[size + 1] = c;
		size = size + 1;
		_str[size] = '\0';
	}

	void Append(size_t n, char c)
	{
		for (size_t i = 0; i < n; i++)
		{
			PushBack(c);
		}
	}

	String& operator+=(char c)
	{
		PushBack(c);
		return *this;
	}

	void Append(const char* str)
	{
		size_t len = strlen(str);
		for (size_t i = 0; i < len; i++)
		{
			PushBack(*str++);
		}
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	void Clear()
	{
		size = 0;
		_str[size] = '\0';
	}

	const char*C_str()const
	{
		return _str;
	}

	bool Empty() const
	{
		return size == 0;
	}

	void Resize(size_t newsize, char c = char())
	{
		if (newsize > size)
		{
			if (newsize > capacity) Reserve(newsize);
			memset(_str + size, c, newsize - size);
		}
		size = newsize;
		_str[size] = '\0';
	}

	char& operator[](size_t index)
	{
		assert(index < size);
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		assert(index < size);
		return _str[index];
	}

	bool operator<(const String& s)
	{
		int tmp = strcmp(_str, s._str);
		if (tmp == ) return ture;
		else return false;
	}


private:
	char *_str;
	size_t size;
	size_t capacity;
};