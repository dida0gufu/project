


#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
	public:
		int data;       // Data of the node
		Node *next;     // Pointer to the next node

		Node(int value) {  // Constructor to initialize the node
			data = value;
			next = nullptr;
		}
};

// LinkedList class to manage the operations on the linked list
class LinkedList {
	private:
		Node *head;     // Head pointer to track the start of the list

	public:
		LinkedList() {  // Constructor to initialize an empty linked list
			head = nullptr;
		}

		// Function to insert a new node at the start of the linked list
		void insertAtStart(int data) {
			Node *newNode = new Node(data); // Create a new node with the provided data
			newNode->next = head;           // Point the new node's next to the current head
			head = newNode;                 // Update the head to the new node
		}

		// Function to insert a new node at the end of the linked list
		void insertAtEnd(int data) {
			Node *newNode = new Node(data); // Create a new node with the provided data
			if (head == nullptr) {          // If the list is empty
				head = newNode;             // Set the new node as the head of the list
				return;
			}
			Node *current = head;           // Start traversal from the head
			while (current->next != nullptr) { // Traverse to the last node
				current = current->next;
			}
			current->next = newNode;        // Set the next of the last node to the new node
		}

		// Function to insert a new node at a specific position in the linked list
		void insertAtPosition(int data, int position) {
			if (position < 1) {             // Check if the position is valid
				cout << "Position should be >= 1" << endl;
				return;
			}
			Node *newNode = new Node(data); // Create a new node with the provided data
			if (position == 1) {            // If position is at the start
				newNode->next = head;       // Point the new node's next to the current head
				head = newNode;             // Update the head to the new node
				return;
			}
			Node *current = head;           // Start traversal from the head
			for (int i = 1; i < position - 1; i++) { // Move to the node before the desired position
				if (current == nullptr) {   // If position is out of range
					cout << "Position out of range" << endl;
					return;
				}
				current = current->next;
			}
			newNode->next = current->next;  // Point the new node's next to the next of the current node
			current->next = newNode;        // Update the current node's next to the new node
		}

		// Function to delete a node at the start of the linked list
		void deleteAtStart() {
			if (head == nullptr) {          // Check if the list is empty
				cout << "List is empty" << endl;
				return;
			}
			Node *temp = head;              // Store the current head temporarily
			head = head->next;              // Update the head to the second node
			delete temp;                    // Delete the old head
		}

		// Function to delete a node at the end of the linked list
		void deleteAtEnd() {
			if (head == nullptr) {          // Check if the list is empty
				cout << "List is empty" << endl;
				return;
			}
			if (head->next == nullptr) {    // If there's only one node in the list
				delete head;                // Delete the only node
				head = nullptr;             // Set the head to nullptr
				return;
			}
			Node *current = head;           // Start traversal from the head
			while (current->next->next != nullptr) { // Traverse to the second-last node
				current = current->next;
			}
			delete current->next;           // Delete the last node
			current->next = nullptr;        // Set the next of the second-last node to nullptr
		}

		// Function to delete a node at a specific position in the linked list
		void deleteAtPosition(int position) {
			if (position < 1) {             // Check if the position is valid
				cout << "Position should be >= 1" << endl;
				return;
			}
			if (head == nullptr) {          // Check if the list is empty
				cout << "List is empty" << endl;
				return;
			}
			if (position == 1) {            // If position is at the start
				Node *temp = head;          // Store the current head temporarily
				head = head->next;          // Update the head to the second node
				delete temp;                // Delete the old head
				return;
			}
			Node *current = head;           // Start traversal from the head
			for (int i = 1; i < position - 1; i++) { // Move to the node before the desired position
				if (current->next == nullptr) { // If position is out of range
					cout << "Position out of range" << endl;
					return;
				}
				current = current->next;
			}
			Node *temp = current->next;     // Store the node to be deleted temporarily
			if (temp == nullptr) {          // Handle out-of-range scenarios
				cout << "Position out of range" << endl;
				return;
			}
			current->next = temp->next;     // Update the next of the current node to skip the node to be deleted
			delete temp;                    // Delete the target node
		}

		// Function to display all the nodes in the linked list
		void display() {
			if (head == nullptr) {          // Check if the list is empty
				cout << "List is empty" << endl;
				return;
			}
			Node *current = head;           // Start traversal from the head
			while (current != nullptr) {    // Traverse the list until the last node
				cout << current->data << " -> "; // Print the current node's data
				current = current->next;
			}
			cout << "null" << endl;         // Indicate the end of the list
		}
};

// Main function to allow user input and manage the linked list dynamically
int main() {
	LinkedList ll;                      // Create a LinkedList object
	int choice, data, position;

	while (true) {
		// Display menu options to the user
		cout << "\nOptions:" << endl;
		cout << "1. Insert at start" << endl;
		cout << "2. Insert at end" << endl;
		cout << "3. Insert at position" << endl;
		cout << "4. Delete at start" << endl;
		cout << "5. Delete at end" << endl;
		cout << "6. Delete at position" << endl;
		cout << "7. Display list" << endl;
		cout << "8. Exit" << endl;

		// Take user input for choice
		cout << "Enter your choice: ";
		cin >> choice;
		// Perform actions based on the user's choice
		switch (choice) {
			case 1:
				cout << "Enter data: ";
				cin >> data;
				ll.insertAtStart(data); // Insert at the start
				break;
			case 2:
				cout << "Enter data: ";
				cin >> data;
				ll.insertAtEnd(data);   // Insert at the end
				break;
			case 3:
				cout << "Enter data: ";
				cin >> data;
				cout << "Enter position: ";
				cin >> position;
				ll.insertAtPosition(data, position); // Insert at a specific position
				break;
			case 4:
				ll.deleteAtStart();     // Delete the first node
				break;
			case 5:
				ll.deleteAtEnd();       // Delete the last node
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position;
				ll.deleteAtPosition(position); // Delete a specific node
				break;
			case 7:
				ll.display();           // Display the linked list
				break;
			case 8:
				return 0;               // Exit the program
			default:
				cout << "Invalid choice! Try again." << endl; // Handle invalid user input
		}
	}
	return 0;               // Exit the program
}


