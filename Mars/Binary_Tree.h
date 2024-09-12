#pragma once
#include <iostream>

namespace Igor {

template <class T>
bool If_not_null(const std::vector<T>& A ) 
{
	for	( const auto B : A) 
	{
		if (B != nullptr) 
		{
			return true;
		}
	}
	return false;
}

template <class T>
class Binary_Tree 
{
private: 
	struct Node
	{
		T data;
		Node* left = nullptr;
		Node* right = nullptr;
		void operator= (Node& node)
		{
			if (&node != this) 
			{
				data = node.data;
				left = node.left;
				right = node.right;

			}
		}
	};
public:
	//конструкторы
	Binary_Tree() {}
	/*Binary_Tree(const Binary_Tree& other);
	Binary_Tree(const Binary_Tree&& )*/
	Binary_Tree(std::initializer_list<T> init);
	//деструктор
	/*~Binary_Tree()
	{}*/
	//методы
	void Insert(const T& value);
	bool Find(const T& value);
	size_t Erase(const T& key_value);
	void make_space(int times)
	{
		for (int i = 0; i < times; i++)
		{
			std::cout << " ";
		}
	}
	void Print();
private:
Node* root = nullptr;
int tree_size = 0;
};

template <class T>
Binary_Tree<T>::Binary_Tree(std::initializer_list<T> init)
{
	for( const auto& elem : init)
	{
		Insert(elem);
	}
}

template <class T>
void Binary_Tree<T>::Insert(const T& value)
{
	if (root == nullptr) 
	{
		root = new Node;
		root->data = value;
		tree_size++;
		return;
	}
	for (Node* x = root; x != nullptr; ) // добавить валидацию, рефакторинг
	{
		if (value < x->data)
		{
			if (x->left == nullptr)
			{
				x->left = new Node;
				x->left->data = value;
				tree_size++;
				break;
			}
			else
				x = x->left;
		}
		else if (value > x->data)
		{
			if (x->right == nullptr)
			{
				x->right = new Node;
				x->right->data = value;
				tree_size++;
				break;
			}
			else
				x = x->right;
		}
		else
			return;
	}
}
template <class T>
bool Binary_Tree<T>::Find(const T& value) // находит с ошибкой: после Erase(), дерево правильного размера с правильными элементами, но Find() их не находит. !!!!!!!!!!!!!
{
	Node* current_node = root;
	while (current_node != nullptr && current_node->data != value)
	{
		bool lesser = current_node->data > value;
		current_node = lesser ? current_node->left : current_node->right;
	}
	return current_node != nullptr;
}
template<class T>
size_t Binary_Tree<T>::Erase (const T& key_value)
{
	if (root == nullptr)
	{
		std::cout << "An element " << key_value << " couldnt be erased. Reason: This Binary Tree is Empty." << std::endl;
		return 0;
	}

	Node* current_node = root;
	Node* parent_node = nullptr;
	while (current_node != nullptr && current_node->data != key_value)
	{
		bool lesser = current_node->data > key_value;
		parent_node = current_node;
		current_node = lesser ? current_node->left : current_node->right;
	}
	if (current_node != nullptr) 
	{
		if( current_node->left == nullptr && current_node->right == nullptr)
		{
			if (parent_node->left == current_node)
				parent_node->left = nullptr;
			else
				parent_node->right = nullptr;
			std::cout << "Element " << current_node->data <<" is being deleted..." << std::endl;
			delete current_node;
		}
		else if (current_node->left != nullptr && current_node->right != nullptr) //!!!!!!!!!!!!!!!!!!!! удаление если есть оба потомка !!!!!!!!!!!!!!!!!!!
		{
			auto higher_to_swap = current_node->left;
			auto highers_parent = current_node;
			if (higher_to_swap->right !=nullptr)
			{
				for	(Node* moving_right = higher_to_swap; moving_right!=nullptr; )
				{
					moving_right = moving_right->right;
					highers_parent = higher_to_swap;
					higher_to_swap = moving_right;
				}
				highers_parent->right = nullptr;
				higher_to_swap->left = highers_parent;
			}
			if (parent_node->left == current_node)
				parent_node->left = higher_to_swap;
			else
				parent_node->right = higher_to_swap;
			
			higher_to_swap->right = current_node->right;

			current_node->left = nullptr;
			current_node->right = nullptr;
			delete current_node;
		}
		else 
		{
			Node* swap_node;
			if (current_node->left != nullptr)
				swap_node = current_node->left;
			else
				swap_node = current_node->right;

			if (parent_node->left == current_node)
				parent_node->left = swap_node;
			else
				parent_node->right = swap_node;

			delete current_node;
		}
		tree_size--;
		return 1;
	}
	else 
	{
		std::cout << "An element " << key_value << " couldnt be erased. Reason: There is no such element in this Binary Tree." << std::endl;
		return 0;
	}
}
template<class T>
void Binary_Tree<T>::Print()
{
	for (std::vector<Node*> A({ root }); If_not_null(A); ) // неправильное условие выхода из цикла
	{
		for (Node* B : A)
		{
			for (int tabs = 0; tabs < 40/A.size(); tabs++)
			{
				std::cout << ' ';
			}
			if (B == nullptr) 
				std::cout << "_";
			else 
				std::cout << B->data << ' ';
			for (int tabs = 0; tabs < 40 / A.size(); tabs++)
			{
				std::cout << ' ';
			}
			
		}
		std::cout << '\n';

		std::vector<Node*> buffer;
		buffer.swap(A);
		A.reserve(buffer.size()*2);
		for ( Node* element : buffer)
		{
			if (element != nullptr) 
			{
				A.emplace_back(element->left);
				A.emplace_back(element->right);
			}
			else 
			{
				A.emplace_back(nullptr);
				A.emplace_back(nullptr);
			}
		}
	}
}
}	// namespace Igor


//сделать правило 5 (деструктор), убрать Insertanье одинаковых значений, сделать Erase, 