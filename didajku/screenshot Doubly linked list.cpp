#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace

// Define a structure for the Node of the doubly linked list
struct Node {
	int data; // Data stored in the node
	Node *prev; // pointer to previous node
	Node *next; // ptr to the nxt node
};

// Define a class of DoublyLinkedList
class DoublyLinkedList {
	private:
		Node *head; // ptr of head of the first node

	public:
		//  to initialize the head to nullptr
		DoublyLinkedList() : head(nullptr) {}

		// Function to insert a node at the start of the list
		void insertAtStart(int data) {
			Node *newNode = new Node(); // Create a new node
			newNode->data = data;
			newNode->prev = nullptr; // Set the previous pointer of the new node to nullptr
			newNode->next = head; // Set the next pointer of the new node to the current head
			if (head != nullptr) { // if list it have a data
				head->prev = newNode; // Set the previous pointer of the current head to the new node
			}
			head = newNode; // Set the new node as the head of the list
		}

		// insrt node at end of list
		void insertAtEnd(int data) {
			Node *newNode = new Node(); // Create a new node
			newNode->data = data; // Set the data of the new node
			newNode->next = nullptr; // Set the next pointer of the new node to nullptr
			if (head == nullptr) { //node have a data
				newNode->prev = nullptr; // prev ptr set of new node
				head = newNode; // new node to head as list
				return; // leave from function
			}
			Node *temp = head; // create temporary pttr
			while (temp->next != nullptr) { //
				temp = temp->next; // Move to the next node
			}
			temp->next = newNode; // Set the next pointer of the last node to the new node
			newNode->prev = temp; // Set the previous pointer of the new node to the last node
		}

		// Function to insert a node at a specific position in the list
		void insertAtPosition(int data, int position) {
			if (position == 1) { // If the position is the start of the list
				insertAtStart(data); // Insert at the start
				return; // Exit the function
			}
			Node *newNode = new Node(); // Create a new node
			newNode->data = data; // Set the data of the new node
			Node *temp = head; // create temporary ptr of list
			for (int i = 1; i < position - 1 && temp != nullptr; ++i) { // cross to the position
				temp = temp->next; // move to nxt
			}
			if (temp == nullptr) { // If the position is out of range
				cout << "Position out of range" << endl; // generate an error
				return; // Exit the function
			}
			newNode->next = temp->next; // nxt ptr to new node
			newNode->prev = temp; //
			if (temp->next != nullptr) { // when it has a data
				temp->next->prev = newNode; // Set the previous pointer of the next node to the new node
			}
			temp->next = newNode; // Set the next pointer of the current node to the new node
		}

		// Function to delete a node at the start of the list
		void deleteAtStart() {
			if (head == nullptr) { // If the list is empty
				cout << "List is empty" << endl; // Print an error message
				return; // Exit the function
			}
			Node *temp = head; // Create a temporary pointer to the head
			head = head->next; // Move the head to the next node
			if (head != nullptr) { // If the list is not empty
				head->prev = nullptr; // Set the previous pointer of the new head to nullptr
			}
			delete temp; // Delete the old head
		}

		// Function to delete a node at the end of the list
		void deleteAtEnd() {
			if (head == nullptr) { // If the list is empty
				cout << "List is empty" << endl; // Print an error message
				return; // Exit the function
			}
			Node *temp = head; // Create a temporary pointer to traverse the list
			while (temp->next != nullptr) { // Traverse to the end of the list
				temp = temp->next; // Move to the next node
			}
			if (temp->prev != nullptr) { // If the list has more than one node
				temp->prev->next = nullptr; // Set the next pointer of the previous node to nullptr
			} else { // If the list has only one node
				head = nullptr; // Set the head to nullptr
			}
			delete temp; // Delete the last node
		}

		// Function to delete a node at a specific position in the list
		void deleteAtPosition(int position) {
			if (position == 1) { // If the position is the start of the list
				deleteAtStart(); // Delete at the start
				return; // Exit the function
			}
			Node *temp = head; // Create a temporary pointer to traverse the list
			for (int i = 1; i < position && temp != nullptr; ++i) { // Traverse to the position
				temp = temp->next; // Move to the next node
			}
			if (temp == nullptr) { // If the position is out of range
				cout << "Position out of range" << endl; // Print an error message
				return; // Exit the function
			}
			if (temp->prev != nullptr) { // If the previous node is not nullptr
				temp->prev->next = temp->next; // Set the next pointer of the previous node to the next node
			}
			if (temp->next != nullptr) { // If the next node is not nullptr
				temp->next->prev = temp->prev; // Set the previous pointer of the next node to the previous node
			}
			delete temp; // Delete the node at the position
		}

		// Function to display the list
		void display() {
			Node *temp = head;                   // Create a temporary pointer to traverse the list
			while (temp != nullptr) {           // Traverse the list
				cout << temp->data << " <->";       // Print the data of the current node
				temp = temp->next;               // Move to the next node
			}
			cout << "back to head" << endl;                    // Print a newline character
		}
};

int main() {
	DoublyLinkedList dll; // Create an instance of the DoublyLinkedList class
	int choice, data, position; // Variables for user input

	while (true) { //loop statement
		// Display the menu
		cout << "1. Insert at start:" << endl;
		cout << "	2. Insert at end:" << endl;
		cout << "	3. Insert at position:" << endl;
		cout << "	4. Delete at start:" << endl;
		cout << "	5. Delete at end:" << endl;
		cout << "	6. Delete at position:" << endl;
		cout << "7. Display:" << endl;
		cout << "8. Exit:" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice; // Get the user's choice

		switch (choice) {
			case 1:
				cout << "Enter data: ";
				cin >> data; // Get the data from the user
				dll.insertAtStart(data); // Insert the data at the first
				break;
			case 2:
				cout << "Enter data: ";
				cin >> data; // Get the data from the us
				dll.insertAtEnd(data); // Insert the data at the end
				break;
			case 3:
				cout << "Enter data: ";
				cin >> data; //get data from us
				cout << "Enter position: ";
				cin >> position; // Get the position from us
				dll.insertAtPosition(data, position); // add data at position
				break;
			case 4:
				dll.deleteAtStart(); //delete node that exist on first node
				break;
			case 5:
				dll.deleteAtEnd(); // delete end node
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position; // enter position we want
				dll.deleteAtPosition(position); // Delete the node at the position
				break;
			case 7:
				dll.display(); // display data
				break;
			case 8:

			default:
				cout << "Invalid choice" << endl; // generate error
		}
	}
	return 0; // leave from program
}
