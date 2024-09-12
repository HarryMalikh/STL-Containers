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
	
	myTree.Print();

	myTree.Erase(20);
	myTree.Erase(17);
	myTree.Erase(25);



	std::cout << myTree.Find(15) <<"\n";
	std::cout << myTree.Find(9) << "\n";
	std::cout << myTree.Find(8) << "\n";
	std::cout << myTree.Find(10) << "\n";
	std::cout << myTree.Find(20) << "\n";
	std::cout << myTree.Find(25) << "\n";
	std::cout << myTree.Find(17) << "\n";
	std::cout << myTree.Find(16) << "\n";
	std::cout << myTree.Find(23) << "\n";

	
	myTree.Print();
	


} 

//рефактор файнда
//