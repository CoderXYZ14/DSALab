#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    CircularQueue() {//default constructor
        front = rear = nullptr;
        size = 0;
    }

    ~CircularQueue() {//deconstructor
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {/check whether the queue is empty
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void enqueue(int data) {//add an element in front
        Node* newNode = new Node();
        newNode->data = data;
	newNode->next=nullptr;
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;  
        } 
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  
        }

        size++;
    }

    int dequeue() {//delete the first entered element
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }

        int data = front->data;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } 
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front; 
            delete temp;
        }

        size--;

        return data;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to display.\n";
            return;
        }
	cout<<"Circular Queue: ";
        Node* temp = front;
        while (temp->next != front) {
            cout << temp->data << " ";
            temp = temp->next;
        } 
       	cout << temp->data << endl;
    }
};

int main() {
    CircularQueue cq;

    int choice;
    int data;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> data;
                cq.enqueue(data);
                cq.displayQueue();
                break;
            case 2:
                if (!cq.isEmpty()) {
                    cout << "Dequeued: " << cq.dequeue() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                cq.displayQueue();
                break;
            case 3:
                if (!cq.isEmpty()) {
                    cout << "Front element: " << cq.peek() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                cq.displayQueue();
                break;
            case 4:
                cq.displayQueue();
                break;
            case 5:
                cout << "Size: " << cq.getSize() << endl;
                break;
            case 6:
                cout << "Exit\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

