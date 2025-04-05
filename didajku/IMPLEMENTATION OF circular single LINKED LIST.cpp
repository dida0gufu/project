#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace

// Define a structure for the Node of the circular singly linked list
struct Node {
	int data; // Data stored in the node
	Node *next; // Pointer to the next node
};

// Define a class for the CircularSinglyLinkedList
class CircularSinglyLinkedList {
	private:
		Node *head; // Pointer to the head (first node) of the list

	public:
		//  to initialize the head to nullptr
		CircularSinglyLinkedList() : head(nullptr) {}

		//  to insert a node at the end of the list
		void insertAtEnd(int data) {
			Node *newNode = new Node(); // Create a new node
			newNode->data = data; // Set the data of the new node
			if (head == nullptr) { // if no have any data
				head = newNode; // when newnode exist on first node
				newNode->next = head; // Point the next pointer of the new node to itself
			} else {
				Node *temp = head; // Create a temporary pointer to cross the list
				while (temp->next != head) { // cross to the last node
					temp = temp->next; // cross to the next node
				}
				temp->next = newNode; // Set the next pointer of the last node to the new node
				newNode->next = head; // Point the next pointer of the new node to the head
			}
		}

		// to insert a node at the start of the list
		void insertAtStart(int data) {
			Node *newNode = new Node(); // Create a new node
			newNode->data = data; // Set the data of the new node
			if (head == nullptr) { // If the list is empty
				head = newNode; // Set the new node as the head of the list
				newNode->next = head; // Point the next pointer of the new node to itself
			} else {
				Node *temp = head; // Create a temporary pointer to traverse the list
				while (temp->next != head) { // Traverse to the last node
					temp = temp->next; // Move to the next node
				}
				newNode->next = head; // Point the next pointer of the new node to the head
				temp->next = newNode; // Set the next pointer of the last node to the new node
				head = newNode; // Set the new node as the head of the list
			}
		}

		// Function to delete a node at the start of the list
		void deleteAtStart() {
			if (head == nullptr) { // If the list is empty
				cout << "List is empty" << endl; // Print an error message
				return; // Exit the function
			}
			if (head->next == head) { // If the list has only one node
				delete head; // Delete the head node
				head = nullptr; // Set the head to nullptr
			} else {
				Node *temp = head; // Create a temporary pointer to the head
				while (temp->next != head) { // Traverse to the last node
					temp = temp->next; // Move to the next node
				}
				Node *toDelete = head; // Create a pointer to the node to be deleted
				head = head->next; // Move the head to the next node
				temp->next = head; // Set the next pointer of the last node to the new head
				delete toDelete; // Delete the old head node
			}
		}

		// Function to delete a node at the end of the list
		void deleteAtEnd() {
			if (head == nullptr) { // If the list is empty
				cout << "List is empty" << endl; // Print an error message
				return; // Exit the function
			}
			if (head->next == head) { // If the list has only one node
				delete head; // Delete the head node
				head = nullptr; // Set the head to nullptr
			} else {
				Node *temp = head; // Create a temporary pointer to traverse the list
				while (temp->next->next != head) { // Traverse to the second last node
					temp = temp->next; // Move to the next node
				}
				Node *toDelete = temp->next; // Create a pointer to the node to be deleted
				temp->next = head; // Set the next pointer of the second last node to the head
				delete toDelete; // Delete the last node
			}
		}

		// Function to display the list
		void display() {
			if (head == nullptr) { // If the list is empty
				cout << "List is empty" << endl; // Print an error message
				return; // Exit the function
			}
			Node *temp = head; // Create a temporary pointer to traverse the list
			do {
				cout << temp->data << " "; // Print the data of the current node
				temp = temp->next; // Move to the next node
			} while (temp != head); // Continue until we reach the head again
			cout << endl; // Print a newline character
		}
};

int main() {
	CircularSinglyLinkedList csll; // Create an instance of the CircularSinglyLinkedList class
	int choice, data; // Variables for user input

	while (true) {
		// Display the menu
		cout << "1. Insert at start:" << endl;
		cout << "2. Insert at end:" << endl;
		cout << "	3. Delete at start:" << endl;
		cout << "4. Delete at end:" << endl;
		cout << "5. Display:" << endl;
		cout << "6. Exit:" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice; // Get the user's choice

		switch (choice) {
			case 1:
				cout << "Enter data: ";
				cin >> data; // Get the data from the user
				csll.insertAtStart(data); // Insert the data at the start
				csll.display(); // Display the list
				break;
			case 2:
				cout << "Enter data: ";
				cin >> data; // Get the data from the user
				csll.insertAtEnd(data); // Insert the data at the end
				csll.display(); // Display the list
				break;
			case 3:
				csll.deleteAtStart(); // Delete the node at the start
				csll.display(); // Display the list
				break;
			case 4:
				csll.deleteAtEnd(); // Delete the node at the end
				csll.display(); // Display the list
				break;
			case 5:
				csll.display(); // Display the list
				break;
			case 6:
				return 0; // Exit the program
			default:
				cout << "Invalid choice" << endl; // Print an error message for invalid choice
		}
	}
}
