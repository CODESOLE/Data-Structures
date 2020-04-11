#include <iostream>

//Circular Linked List

struct Node
{
private:
    int data;
    Node *head = NULL;
    unsigned int size;

public:
    Node *next;
    Node() : size(0) {}

    void insertBeginning(int data = 0)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            size++;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            head = newNode;
            temp->next = head;
            size++;
            return;
        }
    }

    void insertEnd(int data = 0)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            size++;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            size++;
            return;
        }
    }

    void insertAfter(int index = 0, int data = 0)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (index >= 0 && index < size)
        {
            if (head == NULL)
            {
                head = newNode;
                newNode->next = head;
                size++;
                return;
            }
            else
            {
                Node *temp = head;
                for (size_t i = 0; i < index; i++)
                    temp = temp->next;
                if (temp->next != head)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    size++;
                    return;
                }
                else
                {
                    temp->next = newNode;
                    newNode->next = head;
                    size++;
                    return;
                }
            }
        }
        else
            std::cout << "Your entered index negative or exceed the size of the linked list!" << std::endl;
    }

    void deleteBeginning()
    {
        if (head == NULL)
            std::cout << "linked list is empty!" << std::endl;
        else if (head->next == head)
        {
            delete head;
            head = NULL;
            size--;
        }
        else
        {
            Node *temp = head, *last = NULL;
            while (temp->next != head)
                temp = temp->next;
            last = temp;
            temp = head;
            head = head->next;
            free(temp);
            last->next = head;
            size--;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
            std::cout << "linked list is empty!" << std::endl;
        else if (head->next == head)
        {
            delete head;
            head = NULL;
            size--;
        }
        else
        {
            Node *temp = head, *temp2;
            while (temp->next != head)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = head;
            delete temp;
            size--;
        }
    }

    void deleteAt(unsigned int index = 0)
    {
        Node *temp = head;
        if (index >= 0 && index < size)
        {
            if (head == NULL)
                std::cout << "List is Empty!" << std::endl;
            else if (head->next == head)
            {
                delete head;
                head = NULL;
                size--;
            }
            else if (index == 0)
            {
                Node *temp2 = head;
                while (temp->next != head)
                    temp = temp->next;
                head = temp2->next;
                temp->next = temp2->next;
                delete temp2;
                size--;
            }
            else
            {
                Node *temp2;
                for (size_t i = 0; i < index; i++)
                {
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                size--;
            }
        }
        else
            std::cout << "Your entered index negative or exceed the size of the linked list!" << std::endl;
    }

    void printLinkedList()
    {
        if (head == NULL)
            std::cout << "linked list is empty!" << std::endl;
        else
        {
            Node *temp = head;
            do
            {
                std::cout << temp->data << std::endl;
                temp = temp->next;
            } while (temp != head);
        }
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Node data;
    data.printLinkedList();
    data.insertBeginning(1);
    data.insertBeginning(2);
    data.insertBeginning(3);
    data.printLinkedList();
    data.insertEnd(5);
    data.insertAfter(1, 9);
    data.deleteEnd();
    data.deleteBeginning();
    data.deleteAt(0);
    data.printLinkedList();

    return 0;
}