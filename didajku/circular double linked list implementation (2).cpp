#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

class CircularDoublyLinkedList {
	private:
		Node *head;

	public:
		CircularDoublyLinkedList() {
			head = nullptr;
		}

		Node *createNode(int value) {
			Node *newNode = new Node();
			newNode->data = value;
			newNode->next = newNode->prev = nullptr;
			return newNode;
		}

		void insertAtStart(int value) {
			Node *newNode = createNode(value);
			if (!head) {
				newNode->next = newNode->prev = newNode;
				head = newNode;
				return;
			}
			Node *tail = head->prev;
			newNode->next = head;
			newNode->prev = tail;
			head->prev = tail->next = newNode;
			head = newNode;
		}

		void insertAtEnd(int value) {
			if (!head) {
				insertAtStart(value);
				return;
			}
			Node *newNode = createNode(value);
			Node *tail = head->prev;
			newNode->next = head;
			newNode->prev = tail;
			tail->next = head->prev = newNode;
		}

		void insertAtPosition(int value, int pos) {
			if (pos <= 1 || !head) {
				insertAtStart(value);
				return;
			}

			Node *temp = head;
			int count = 1;

			while (count < pos - 1 && temp->next != head) {
				temp = temp->next;
				count++;
			}

			if (temp->next == head) {
				insertAtEnd(value);
				return;
			}

			Node *newNode = createNode(value);
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}

		void deleteAtStart() {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}

			if (head->next == head) {
				delete head;
				head = nullptr;
				return;
			}

			Node *tail = head->prev;
			Node *temp = head;
			head = head->next;
			head->prev = tail;
			tail->next = head;
			delete temp;
		}

		void deleteAtEnd() {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}

			if (head->next == head) {
				delete head;
				head = nullptr;
				return;
			}

			Node *tail = head->prev;
			Node *newTail = tail->prev;
			newTail->next = head;
			head->prev = newTail;
			delete tail;
		}

		void deleteAtPosition(int pos) {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}

			if (pos <= 1) {
				deleteAtStart();
				return;
			}

			Node *temp = head;
			int count = 1;

			while (count < pos && temp->next != head) {
				temp = temp->next;
				count++;
			}

			if (temp->next == head && count < pos) {
				cout << "Position out of range.\n";
				return;
			}

			if (temp == head) {
				deleteAtStart();
				return;
			}

			Node *prevNode = temp->prev;
			Node *nextNode = temp->next;

			prevNode->next = nextNode;
			nextNode->prev = prevNode;

			delete temp;
		}

		void display() {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}

			Node *temp = head;
			cout << "<->";
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
			cout << "back to head:1 " << endl;
		}
};

int main() {
	CircularDoublyLinkedList list;
	int choice, value, pos;

	do {
		cout << "\n--- MENU ---\n";
		cout << "1. Insert at start\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert at position\n";
		cout << "4. Delete at start\n";
		cout << "5. Delete at end\n";
		cout << "6. Delete at position\n";
		cout << "7. Display\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value to insert at start: ";
				cin >> value;
				list.insertAtStart(value);
				break;

			case 2:
				cout << "Enter value to insert at end: ";
				cin >> value;
				list.insertAtEnd(value);
				break;

			case 3:
				cout << "Enter value and position to insert: ";
				cin >> value >> pos;
				list.insertAtPosition(value, pos);
				break;

			case 4:
				list.deleteAtStart();
				break;

			case 5:
				list.deleteAtEnd();
				break;

			case 6:
				cout << "Enter position to delete: ";
				cin >> pos;
				list.deleteAtPosition(pos);
				break;

			case 7:
				list.display();
				break;

			case 0:
				cout << "Exiting...\n";
				break;

			default:
				cout << "Invalid choice!\n";
		}

	} while (choice != 0);

	return 0;
}
