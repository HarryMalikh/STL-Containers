#pragma once
#include <iostream>
#include <limits>

template <class T>
class Vector {
public:
	using value_type = T;

	class Iterator
	{
	public:
		Iterator() : m_ptr(nullptr) {}
		Iterator(T* ptr) : m_ptr(ptr) {}

		//операторы итератора
		T operator * () 
		{
			if (m_ptr == nullptr)
				throw std::exception("Iterator is empty!");
			return *m_ptr;
		}
		bool operator == (Iterator iter)
		{
			return m_ptr == iter.m_ptr;
		}
		bool operator != (Iterator iter)
		{
			return m_ptr != iter.m_ptr;
		}
		Iterator operator ++ ()
		{
		
		}
	private:
		T* m_ptr;
		//операторы ++,по ссылке, удаление в векторе, insert() 

	};
	//конструкторы
	Vector() : size(0), capacity(0),data(nullptr) {}
	Vector(size_t count) : size(count), capacity(count), data(new T[count]){}
	Vector(size_t count, T val) : size(count), capacity(count), data(new T[count])
	{
		for (size_t i = 0; i < count; i++)
		{
			data[i] = val;
		}
	}
	Vector(std::initializer_list <T> init_list) :
		size(init_list.size()),
		capacity(init_list.size()),
		data (new T[init_list.size()])
	{
		auto iter = init_list.begin();
		for (int i = 0; i < init_list.size(); i++)
		{
			data[i] = *iter;
			++iter;
		}
	}
	Vector(const Vector<T>& ref)
	{
		data = nullptr;
		*this = ref;
	}
	Vector(Vector<T>&& doubleref) noexcept
	{
		*this = std::move(doubleref);
	}
	~Vector()
	{
		Clear();
	}
	//методы
	const T& At(size_t index) const
	{
		if (index > size - 1)
			throw std::invalid_argument("Invalid argument!");
		return data[index];
	}
	size_t GetSize() const
	{
		return size;
	}
	void PushBack(const T& val)
	{
		Emplace(size, val);
	}
	void Emplace(size_t index, const T& val)
	{
		size++;
		if (capacity < size)
		{
			capacity==0 ? capacity++ : capacity *= 1.5;
			auto previous_data = data;
			data = new T[capacity];
			for (size_t i = 0; i < size; i++)
			{
				data[i] = previous_data[i > index ? i-1 : i ];
			}
		}
		else
		{
			for (size_t i = size-1; i > index; i--)
			{
				data[i] = data[i-1];
			}
		}
		data[index] = val;
	}
	void Swap(Vector& ref)
	{
		auto temp_size = size;
		auto temp_capacity = capacity;
		auto temp_data = data;

		size = ref.size;
		capacity = ref.capacity;
		data = ref.data;

		ref.size = temp_size;
		ref.capacity = temp_capacity;
		ref.data = temp_data;
	}
	void Clear() 
	{
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}
	size_t Max_size()
	{
		const size_t Max_size = std::numeric_limits<int>::max();
			return Max_size;
	}
	size_t GetCapacity()
	{
		return capacity;
	}
	void Reserve(size_t new_cap)
	{
		if (new_cap > Max_size()) 
			throw std::invalid_argument("Capacity is already bigger than entered argument");

		if (new_cap <= capacity)
			return;

		capacity = new_cap;
		auto* previous_data = data;
		data = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = previous_data[i];
		}
		delete[] previous_data;
	}
	void Resize (size_t new_size, const T val = T())
	{
		if (capacity < new_size)
		{
			auto new_capacity = static_cast<size_t>(capacity * 1.5);
			Reserve(std::max(new_capacity, new_size));
		}
		for (size_t i = size; i < new_size; i++)
		{
			data[i] = val;
		}
		size = new_size;
	}
	Iterator Begin()
	{
		Iterator Iter(data);
		return Iter;
	}
	Iterator End()
	{
		Iterator Iter;
		return Iter;
	}
	Iterator Insert(Iterator where, std::initializer_list<T> init_list)
	{
		size_t expected_size = size + init_list.size();
		if (capacity < expected_size)
		{
			capacity = expected_size;

		}
		
		/*принимать кол-во элемент init list	
			равнить с capacity
			если не хватает то перевыделить память, старую память удалили
			если хватает то скип

		увеличение вектора*/
	}
	//операторы
	const T& operator [] (size_t i) const// оператор доступа к элементу индекса [i]
	{
		return data[i];
	}
	T& operator [] (size_t i)// оператор доступа к элементу индекса [i]
	{
		return data[i];
	}
	const Vector<T>& operator = (const Vector<T>& ref) 
	{
		if (*this == ref)
			return *this;

		size = ref.size;
		capacity = ref.capacity;
		delete[] data;
		data = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = ref.data[i];
		}
		return *this;
	}
	const Vector<T>& operator = (Vector<T>&& doubleref)
	{
		if (this != &doubleref)
		{
			Swap(doubleref);
			doubleref.Clear();
		}
		return *this;
	}
	bool operator == (const Vector<T>& ref) const 
	{
		if (size != ref.size)
			return false;
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] != ref.data[i])
				return false;
		}
		return true;
	}
	bool operator != (const Vector<T>& ref) const
	{
		return !(*this == ref);
	}

private:
	size_t size;
	size_t capacity;
	T* data;
protected:
	
};

// итератор (begin, end) вложенный класс,  