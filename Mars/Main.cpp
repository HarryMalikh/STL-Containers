#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <string>

#include <set>
#include <map>
#include <unordered_map>


#include "Matrix.h"
#include "List.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"
#include "Binary_Tree.h"

class myClass 
{
public:
myClass(){}
myClass(const myClass&)
{
	std::cout << "srabotalo" << std::endl;
}
myClass(myClass&& other) noexcept
{
	std::cout << "perenos \n";
}
bool operator < (const myClass&) const
{
	return true;
}
bool operator > (const myClass&) const
{
	return false;
}

void operator = (const myClass&){}
private:

};



int main()
{
	setlocale(LC_ALL, "ru");

	Igor::Binary_Tree<int> myTree;
	
	myTree.Insert(15);
	myTree.Insert(9);
	myTree.Insert(7);
	myTree.Insert(8);
	myTree.Insert(10);
	myTree.Insert(20);
	myTree.Insert(25);
	myTree.Insert(17);
	myTree.Insert(16);
	myTree.Insert(23);
	myTree.Insert(19);
	myTree.Insert(18); // при добавлении элемента и удалении 20 удаляется и 18. исправить (178 строчка цикл, зануление)  - upd. исправлено

	myTree.Print();
	myTree.Erase(15);
	myTree.Erase(10);
	myTree.Erase(9);
	myTree.Erase(8);
	std::cout << "TEEEEEEEEEEEEEEEEST" << std::endl;

	myTree.Print();
	myTree.Erase(7);
	std::cout << "TEEEEEEEEEEEEEEEEST" << std::endl;
	myTree.Print();
} 

//рефактор файнда
//