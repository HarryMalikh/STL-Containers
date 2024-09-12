#pragma once
#include <iostream>
#include "List.h"

template <typename T> 
class Queue : public List<T>
{
public:
	using Node = List<T>::Element;
	
	Queue();
	Queue(const Queue& ref);
	Queue(const Queue&& doubleref);
	void Pop() override;
	void Push(T data) override;
	void Swap(Queue<T>& ref);


	const Queue<T>& operator = (Queue<T>& ref) noexcept;
	const Queue<T>& operator = (Queue<T>&& ref) noexcept;
private:
	Node* bottom = nullptr;
};
template <typename T>
Queue<T>::Queue()
{
	List<T>::size = 0;
	List<T>::top = nullptr;
	bottom = nullptr;
}
template <typename T>
Queue<T>::Queue(const Queue& ref)
{
	Node* temp = ref.top;
	for (int i = 0; i < ref.size; i++)
	{
		Push(temp->GetData());
		temp = temp->GetNextPtr();
	}
}
template <typename T>
Queue<T>::Queue(const Queue && doubleref)
{
	*this = std::move(doubleref);
}
template <typename T>
void Queue<T>::Pop()
{
	List<T>::Pop();
	if (List<T>::Empty())
		bottom = nullptr;
}
template <typename T>
void Queue<T>::Push(T data)
{
	Node* temp = new Node(data, nullptr);
	if (bottom!=nullptr)
	{
		bottom->SetNextPtr(temp);
	}	
	bottom = temp;
	List<T>::size++;
	if (List<T>::top == nullptr)
		List<T>::top = bottom;
}
template <typename T>
void Queue<T>::Swap(Queue<T>& ref)
{
	int temp_size = List<T>::size;
	Node* temp_top = List<T>::top;
	List<T>::size = ref.size;
	List<T>::top = ref.top; 
	ref.size = temp_size;
	ref.top = temp_top;
	Node* temp_bottom = bottom;
	bottom = ref.bottom;
	ref.bottom = temp_bottom;
}
template <typename T>
const Queue<T>& Queue<T>::operator = (Queue<T>& ref) noexcept
{
	if (!List<T>::Empty())
	{
		List<T>::Clear();
	}
	
	Node* temp = ref.top;
	for (int i = 0; i < ref.size; i++)
	{
		Push(temp->GetData());
		temp = temp->GetNextPtr();
	}

	return *this;
}
template <typename T>
const Queue<T>& Queue<T>::operator = (Queue<T>&& ref) noexcept
{
	if (this != &ref)
	{
		List<T>::Clear();
		List<T>::size = ref.size;
		List<T>::top = ref.top;
		bottom = ref.bottom;
		ref.size = 0;
		ref.top = nullptr;
		ref.bottom = nullptr;
	}
	return *this;
}