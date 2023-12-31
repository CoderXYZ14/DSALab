#include <iostream>
using namespace std;
class CircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int N;
    int size;
public:
    CircularQueue(int n) {//paramertized constructor
        N = n;
        queue = new int[N];
        front = rear = -1;
        size = 0;
    }

    ~CircularQueue() {//deconstructor
        delete[] queue;
    }

    bool isEmpty() {//check whether the queue is empty
        return (front==-1 && rear==-1);//or size == 0
    }

    bool isFull() {//check whether the queue is full
        return ((rear+1)%N)==front;//or size==N
    }

    void enqueue(int x) {//add an element in front
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
	if (isEmpty()) {
            front = rear = 0;
        } 
        else {
            rear=(rear+1)%N;
        }

        queue[rear] = x;
        size++;
    }

    int dequeue() {//delete the first entered element
    	int x = queue[front];
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
	else if (front == rear){
            front = rear = -1; 	    
        }
        else{
       	    front = (front + 1) % N;
       	}
        size--;
        return x;
    }

    int peek() {//returns first element
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
	return queue[front];
    }
    
    void displayQueue(CircularQueue& cq) {
    	if (isEmpty()) {
        	cout << "Queue is empty\n";
        	return;
    	}
    	else{
    		cout << "Circular Queue:";
    		int i = front;
    		while (i != rear){
        		cout << queue[i] << " ";
        		i = (i + 1) % N;
    		}	
		cout << queue[rear]<<"\n";
	}
    }
};

int main() {
    int N;
    cout << "Enter the N of the circular queue: ";
    cin >> N;
    cout<<"\n";
    CircularQueue cq(N);

    int choice;
    while (true) {
        cout << "Circular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int data;
                cout << "Enter the element to enqueue: ";
                cin >> data;
                cout<<"\n";
                cq.enqueue(data);
                
                cq.displayQueue(cq);
                break;
            case 2:
                if (!cq.isEmpty()) {
                    cout << "Dequeued: " << cq.dequeue() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                cq.displayQueue(cq);
                break;
            case 3:
                if (!cq.isEmpty()) {
                    cout << "Front: " << cq.peek() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 4:
                cq.displayQueue(cq);
                break;
            case 5:
                cout << "Exiting program.\n";
                exit(0);
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

