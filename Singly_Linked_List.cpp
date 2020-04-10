#include <iostream>

//Singly Linked List

struct Node
{
    Node *head = NULL;
    int data;
    unsigned int size;
    Node *next;
    Node() : size(0) {}

    void insertBeginning(int data = 0)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
            size++;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
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
            newNode->next = NULL;
            size++;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = NULL;
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
                newNode->next = NULL;
                size++;
                return;
            }
            else
            {
                Node *temp = head;

                for (size_t i = 0; i < index; i++)
                    temp = temp->next;
                if (temp->next != NULL)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    size++;
                    return;
                }
                else
                {
                    temp->next = newNode;
                    newNode->next = NULL;
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
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            size--;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
            size--;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
            std::cout << "linked list is empty!" << std::endl;
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            size--;
        }
        else
        {
            Node *temp = head, *temp2;
            while (temp->next != NULL)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = NULL;
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
                std::cout << "List Empty!" << std::endl;
            else if (head->next == NULL)
            {
                delete head;
                head = NULL;
                size--;
            }
            else if (index == 0)
            {
                head = temp->next;
                delete temp;
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
            while (temp != NULL)
            {
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
            delete temp;
        }
    }
};

int main()
{
    return 0;
}