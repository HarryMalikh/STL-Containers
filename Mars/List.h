#pragma once
#include <iostream>


template <typename T>
class List
{
public:
	using value = T;

	List();
	~List();

	int GetSize();
	virtual T GetTop();
	inline bool Empty();
	virtual void Pop();
	virtual void Push(T data) = 0;


	void Clear();

private:
protected:
	class Element
	{
	public:
		Element(T ElementData = T(), Element* ptrNext = nullptr) : data(ElementData), ptrNext(ptrNext) {}
		T GetData()
		{
			return data;
		}
		Element* GetNextPtr()
		{
			return ptrNext;
		}
		void SetNextPtr(Element* element_ptr) 
		{
			ptrNext = element_ptr;
		}
	private:
		Element* ptrNext = nullptr;
		T data;
	};
	Element* top;
	int size;
};

template <typename T>
List<T>::List()
{
	size = 0;
	top = nullptr;
}
template <typename T>
List<T>::~List()
{
	Clear();
}
template <typename T>
int List<T>::GetSize()
{
	return size;
}
template <typename T>
T List<T>::GetTop()
{
	if (top == nullptr)
		throw std::exception("List is empty");
	return top->GetData(); 
}
template <typename T>
inline bool List<T>::Empty()
{
	return size == 0;
}
template <typename T>
void List<T>::Pop()
{
	if (top == nullptr)
		throw std::exception("List is empty");

	Element* TempPtr = top;
	top = top->GetNextPtr();
	delete TempPtr;
	size--;
}
template<typename T>
void List<T>::Clear()
{
		for (int i = 0; i < size; i++)
		{
			Pop();
		}
}
