#include <iostream>

#define capacity 10

class Queue{
	public:
		int Q[capacity];
		int front=-1, rear=-1;
		bool isEmpty();
		void enqueue(int x);
		int dequeue();
		int peek();
};

bool Queue::isEmpty(){
	return (front==-1 && rear==-1);
}
void Queue::enqueue(int x){
	if (rear == capacity-1){
		std::cout << "buffer overflow" << std::endl;
		return;
	}
	if (front==-1)
		front=0;
	rear++;
	Q[rear] = x;
}
int Queue::dequeue(){
	if(isEmpty()) {
		std::cout << "Queue is empty" << std::endl;
	}
	if(front == rear)
	{
		front = rear = -1;
		return -1;
	}
	int value = Q[front];
	front++;
	return value;
}
int Queue::peek(){
	if (isEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		return -1;
	}
	return Q[front];
}

int main() {
	Queue q;
	q.enqueue(5);
	std::cout << q.peek() << std::endl;
	q.dequeue();
	q.dequeue();
	std::cout << q.peek() << std::endl;
	q.enqueue(67);
	q.enqueue(5);
	std::cout << q.peek() << std::endl;
	return 0;
}