#include <iostream>

// Node class to represent individual elements in the linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor to initialize the node with a value and set next to nullptr
    Node(T value) : data(value), next(nullptr) {}
};

// Linked List class definition
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Pointer to the first node in the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to append a new node with the given value at the end of the list
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to prepend a new node with the given value at the beginning of the list
    void prepend(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node with the given value at a specific index
    void insertAt(int index, T value) {
        if (index < 0) {
            std::cerr << "Invalid index." << std::endl;
            return;
        }

        if (index == 0) {
            prepend(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            std::cerr << "Invalid index." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to remove the first occurrence of a node with the given value
    void remove(T value) {
        if (!head) {
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to display the contents of the linked list
    void display() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to clean up memory by deleting all nodes
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Create a linked list instance
    LinkedList<int> list;

    // Append values to the linked list
    list.append(10);
    list.append(20);
    list.append(40);

    std::cout << "Linked List: ";
    list.display();

    // Prepend and insert values at specific positions
    list.prepend(5);
    list.insertAt(2, 30);

    std::cout << "Linked List after modifications: ";
    list.display();

    // Remove a value from the linked list
    list.remove(20);

    std::cout << "Linked List after removing 20: ";
    list.display();

    return 0;
}