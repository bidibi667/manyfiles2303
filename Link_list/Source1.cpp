#include <iostream>

struct Node
{
	Node* pNext = nullptr;
	int data = -1;

};

struct List
{
	int len = 0;
	Node* pHead = nullptr;
};

void Print(const List& lst) {
	std::cout << "********" << std::endl;
	Node* it = lst.pHead;
	while (it) {

		std::cout << it->data << "\t";
		it = it->pNext;
	}
	std::cout << "********" << std::endl;

}

void Add(List& lst, int data) {
	lst.len++;
	Node *new_node = new Node;
	new_node->data = data;
	new_node->pNext = lst.pHead;
	lst.pHead = new_node;
	++lst.len;
}

int Pop(List &lst) {
	if (lst.len == 0) {
		return -1;
	}
	Node *pop_item = lst.pHead;
	int ret_val = pop_item->data;
	lst.pHead = lst.pHead->pNext;

	--lst.len;
	delete pop_item;
	return ret_val;
}

void Insert(List &lst, int data, int pos) {
	if (lst.len < pos) {
		return;
	}
	Node *new_node = new Node;
	new_node->data = data;
	Node* it = lst.pHead;
	int count = 0;
	while (it && count != pos) {
		++count;
		it = it->pNext;
	}

	new_node->pNext = it->pNext;
	it->pNext = new_node;



}

int GetData(const List &lst, int index) {
	if (lst.len < index + 1)
	{
		std::cerr << "Wrong index\n";
		return -1;
	}
	Node *it = lst.pHead;
	int count = 0;
	while (it && count != index) {
		++count;
		it = it->pNext;
	}
	return it->data;

}


void Swap(List &lst, int pos_a, int pos_b) {
	if (lst.len < pos_a|| lst.len < pos_b) {
		return;
	}
	Node *new_node = new Node;
	Node *new_node2 = new Node;
	
	Node* it = lst.pHead;
	int count = 0;
	while (it && count != pos_b) {
		++count;
		it = it->pNext;
	}

	new_node2->pNext = it->pNext;
	new_node->data = it->data + 100;
	//delete(it);
	count = 0;
	while (it && count != pos_a) {
		++count;
		it = it->pNext;
	}

	it->pNext = new_node2->pNext;
	
	count = 0;
	while (it && count != pos_a-1) {
		++count;
		it = it->pNext;
	}
	
	it->pNext = new_node;

	//it->pNext = new_node2->pNext;


}

int main() {
	List my_list;
	Add(my_list, 1);
	Add(my_list, 11);
	Add(my_list, 24);
	Add(my_list, 25);
	Add(my_list, 23);
	Add(my_list, 55);
	Print(my_list);
	//std::cout << Pop(my_list) << std::endl;
	//std::cout << Pop(my_list) << std::endl;
	//Add(my_list, 555555);
	Print(my_list);
	Insert(my_list, 99, 0);
	Print(my_list);
	Swap(my_list, 2, 3);
	Print(my_list);
	getchar();
	return 0;
}