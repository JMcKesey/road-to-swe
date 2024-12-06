#include <iostream>

#define capacity 10

class Stack{
	public:
		int top;
		int A[capacity];
		Stack();
		void push(int x);
		int pop();
		bool isEmpty();
};

Stack::Stack(){
	top = -1;
}
bool Stack::isEmpty(){
	if(top == -1) return true;
	return false;
}
void Stack::push(int x){
	if(top < capacity - 1) {
		top++;
		A[top] = x;
		std::cout << x << " has been pushed onto the stack" << std::endl;
	} else {
		std::cout << "Stack overflow" << std::endl;	
	}
}
int Stack::pop(){
	if(!isEmpty()){
		int value = A[top];
		top--;
		std::cout << value << " has been popped" << std::endl;
		return value;
	}
	std::cout << "Stack underflow" << std::endl;
	return -999;
}

int main() {
	Stack stack;
	std::cout << stack.isEmpty() << std::endl;
	stack.push(68);
	std::cout << stack.pop() << std::endl;
	std::cout << "The top of the stack is: " << stack.top;
	return 0;
}