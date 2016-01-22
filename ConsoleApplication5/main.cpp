#include <iostream>
using namespace std;
template < class type >
class List {
	public:
		struct Node {
			type val;
			Node * next;
		};

		Node *head, *bottom;
		int length;

		List()
		{
			head = new Node;
			bottom = new Node;
			head = bottom;
			length = 0;
		}

		void push(type elem)
		{
			Node* newNode = new Node;
			newNode->val = elem;
			newNode->next = NULL;

			bottom->next = newNode;
			bottom = newNode;

			length++;
		}

		//void pop

		type* toArray() {
			type* arrayToRet = new type[length];

			Node* currentNode = head->next;
			int index = 0;

			do {
				arrayToRet[index] = currentNode->val;
				currentNode = currentNode->next;
				index++;
			} while (currentNode != NULL);

			return arrayToRet;
		}
};

void display(int* array, int length) 
{
	for (int x = 0; x < length; x++)
	{
		cout << array[x] << endl;
	}
}

int main()
{
	List<int> *lista1 = new List<int>;

	lista1->push(10);
	lista1->push(14);
	lista1->push(15);
	lista1->push(15);
	lista1->push(15);

	display(lista1->toArray(), lista1->length);

	system("PAUSE");
}