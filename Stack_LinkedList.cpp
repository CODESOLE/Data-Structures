#include <iostream>

struct stackLinkedList {
private:
  int data;
  stackLinkedList *next;
  stackLinkedList *top = NULL;

public:
  stackLinkedList(int _data = 0) : data(_data) {}
  void push(int val) {
    stackLinkedList *newdata = new stackLinkedList(val);
    if (top == NULL)
      newdata->next = NULL;
    else
      newdata->next = top;
    top = newdata;
    std::cout << "data " << val << " is inserted!" << std::endl;
  }

  void pop() {
    if (top == NULL)
      std::cout << "underflow. Stack is empty!" << std::endl;
    else {
      stackLinkedList *temp = top;
      std::cout << "deleted elemt is : " << temp->data << std::endl;
      top = temp->next;
      delete temp;
    }
  }
};

int main(int argc, char *argv[]) {
  stackLinkedList s1;
  s1.push(54);
  s1.push(342);
  s1.push(5555);
  s1.pop();
  s1.pop();
  s1.pop();
  s1.pop();

  return 0;
}
