#pragma once

#include <iostream>
#include "List.h"

template <typename T>
class Stack : public List<T>
{
public:
	using Node = List<T>::Element;

	Stack() : List<T>() {}
	Stack(const Stack& ref);
	Stack(Stack&& doubleref) noexcept;

	void Push(T data) override;
	void Swap(Stack<T>& ref);

	const Stack<T>& operator = (const Stack<T>& ref) noexcept;
	const Stack<T>& operator = (Stack<T>&& ref) noexcept;
private:
};
template <typename T>
Stack<T>::Stack(const Stack& ref) 
{
	Node* temp = ref.top;
	Stack<T> Temp_stack;
	
	for (int i = 0; i < ref.size; i++)
	{
		Temp_stack.Push(temp->GetData());
		temp = temp->GetNextPtr();
	}
	Node* temp_2 = Temp_stack.top;
	for (int i = 0; i < ref.size; i++)
	{
		Push(temp_2->GetData());
		temp_2 = temp_2->GetNextPtr();
	}
}
template <typename T>
Stack<T>::Stack (Stack&& doubleref) noexcept 
{
	*this = std::move(doubleref);
}
template <typename T>
void Stack<T>::Push(T data)
{
	List<T>::top = new Node(data, List<T>::top);
	List<T>::size++;
}
template <typename T>
void Stack <T> ::Swap(Stack<T>& ref)
{
	int temp_size = List<T>::size;
	Node* temp_top = List<T>::top;
	List<T>::size = ref.size;
	List<T>::top = ref.top;
	ref.size = temp_size;
	ref.top = temp_top;
}
template <typename T>
const Stack<T>& Stack<T>::operator = (const Stack<T>& ref) noexcept
{
	if (List<T>::top != nullptr)
	{
		List<T>::Clear();
	}
	Node* temp = ref.top;
	Stack<T> Temp_stack;

	for (int i = 0; i < ref.size; i++)
	{
		Temp_stack.Push(temp->GetData());
		temp = temp->GetNextPtr();
	}
	Node* temp_2 = Temp_stack.top;
	for (int i = 0; i < ref.size; i++)
	{
		Push(temp_2->GetData());
		temp_2 = temp_2->GetNextPtr();
	}
	return *this;
}
template <typename T>
const Stack<T>& Stack<T>::operator = (Stack<T>&& ref) noexcept
{
	if (this != &ref)
	{
		List<T>::Clear();
		List<T>::size = ref.size;
		List<T>::top = ref.top;
		ref.size = 0;
		ref.top = nullptr;
	}
	std::cout << "Operator = used" << std::endl;
	return *this;
}