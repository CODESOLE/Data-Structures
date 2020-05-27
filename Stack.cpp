#include <iostream>
#define SIZE 10

// Stacks

struct _stack {
private:
  int top = -1;
  int stack[SIZE];

public:
  void push(int data = 0) {
    if (top == SIZE - 1)
      std::cout << "Stack overflow!" << std::endl;
    else {
      top++;
      stack[top] = data;
    }
  }
  void peek() {
    if (top == -1) {
      std::cout << "Stack underflow!" << std::endl;
      return;
    } else
      std::cout << stack[top] << std::endl;
  }
  void pop() {
    if (top == -1) {
      std::cout << "stack underflow" << std::endl;
    } else {
      std::cout << "data" << stack[top] << " is deleted!" << std::endl;
      top--;
    }
  }
};

int main() {
  _stack s1;
  s1.peek();
  s1.push(3);
  s1.peek();
  s1.push(34);
  s1.peek();

  return 0;
}
