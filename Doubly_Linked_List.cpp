#include <iostream>

//Doubly Linked List

struct Node
{
    Node *head = NULL;
    Node *next, *prev;
    unsigned int size;
    int data;
    Node() : size(0)
    {
    }
    void insertBeginning(int data = 0)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
            size++;
            std::cout << "data is added!" << std::endl;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            size++;
            std::cout << "data is added!" << std::endl;
        }
    }

    void insertAfter(unsigned int index = 0, int data = 0)
    {
        Node *newnode = new Node;
        newnode->data = data;
        if (index >= 0 && index < size)
        {
            if (head == NULL)
            {
                newnode->next = NULL;
                newnode->prev = NULL;
                head = newnode;
                size++;
            }
            else if (head->next == NULL && head->prev == NULL)
            {
                head->next = newnode;
                newnode->prev = head;
                newnode->next = NULL;
                size++;
            }
            else
            {
                Node *temp = head, *temp2;
                for (size_t i = 0; i < index; i++)
                    temp = temp->next;
                if (temp->next != NULL)
                {
                    temp2 = temp->next;
                    temp->next = newnode;
                    newnode->prev = temp;
                    newnode->next = temp2;
                    temp2->prev = newnode;
                    size++;
                }
                else
                {
                    temp->next = newnode;
                    newnode->prev = temp;
                    newnode->next = NULL;
                    size++;
                }
            }
        }
        else
            std::cout << "Your entered index negative or exceed the size of the linked list!" << std::endl;
    }

    void insertEnd(int data = 0)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            size++;
            std::cout << "data is added!" << std::endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            size++;
            std::cout << "data is added!" << std::endl;
        }
    }

    void deleteBeginning()
    {
        if (head == NULL)
            std::cout << "List is Empty!" << std::endl;
        else
        {
            Node *temp = head;
            if (head->prev == NULL && head->next == NULL)
            {
                head = NULL;
                delete temp;
                size--;
                return;
            }
            temp->next->prev = NULL;
            head = temp->next;
            delete temp;
            size--;
        }
    }
    //deletes at specific position
    void deleteAt(unsigned int index = 0)
    {
        Node *temp = head;
        if (index >= 0 && index < size)
        {
            if (head == NULL)
                std::cout << "List Empty!" << std::endl;
            else if (head->next == NULL && head->prev == NULL)
            {
                delete temp;
                head = NULL;
                size--;
            }
            else
            {
                Node *temp2;
                for (size_t i = 0; i < index; i++)
                    temp = temp->next;
                if (index == 0)
                {
                    temp->next->prev = NULL;
                    head = temp->next;
                    delete temp;
                    size--;
                    return;
                }
                if (temp->next != NULL)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    size--;
                }
                else
                {
                    temp2 = temp->prev;
                    temp2->next = NULL;
                    delete temp;
                    size--;
                }
            }
        }
        else
            std::cout << "Your entered index is negative or exceed the size of the linked list!" << std::endl;
    }

    void deleteEnd()
    {
        if (head == NULL)
            std::cout << "List Empty!" << std::endl;
        else
        {
            Node *temp = head;
            if (head->prev == NULL && head->next == NULL)
            {
                head = NULL;
                delete temp;
                size--;
                return;
            }
            while (temp->next != NULL)
                temp = temp->next;
            temp->prev->next = NULL;
            delete temp;
            size--;
        }
    }
    //delete it if specified value founded but doesn't return deleted value so it should be obtain before deletion by using searchByIndex() function
    void deleteSpecificValue(int val)
    {
        if (head == NULL)
        {
            std::cout << "linked list is empty!" << std::endl;
            return;
        }
        else
        {
            Node *temp = head;
            do
            {
                if (temp->data != val)
                    temp = temp->next;
                else
                {
                    if (temp->prev == NULL && temp->next == NULL)
                    {
                        head = NULL;
                        delete temp;
                        size--;
                        return;
                    }
                    else if (temp->prev == NULL && temp->next != NULL)
                    {
                        temp->next->prev = NULL;
                        head = temp->next;
                        delete temp;
                        size--;
                        return;
                    }
                    else if (temp->next == NULL)
                    {
                        temp->prev->next = NULL;
                        delete temp;
                        size--;
                        return;
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                        size--;
                        return;
                    }
                }

            } while (temp != NULL);
            std::cout << "Searched value couldn't find!" << std::endl;
            return;
        }
    }

    void deleteAll()
    {
        if (head == NULL)
        {
            std::cout << "linked list is empty!" << std::endl;
            return;
        }
        else
        {
            while (head != NULL)
                deleteEnd();
            size = 0;
        }
        std::cout << "All linked list members deleted successfully!" << std::endl;
    }
    //returns its value
    int searchByIndex(unsigned int index = 0)
    {
        if (index >= 0 && index <= size - 1)
        {
            if (head == NULL)
            {
                std::cout << "linked list is empty!" << std::endl;
                return -1;
            }
            else
            {
                Node *temp = head;
                for (size_t i = 0; i < index; i++)
                    temp = temp->next;
                return temp->data;
            }
        }
        else
        {
            std::cout << "Your entered index negative or exceed the size of the linked list!" << std::endl;
            return -1;
        }
    }
    //returns its index
    int searchByValue(int val)
    {
        unsigned int index = 0;
        if (head == NULL)
        {
            std::cout << "linked list is empty!" << std::endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            do
            {
                if (temp->data != val)
                    index++;
                else
                    return index;

                temp = temp->next;
            } while (temp != NULL);
            std::cout << "Searched value couldn't find! [ RETURNED -1 ]" << std::endl;
            return -1;
        }
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

    void printReverseLinkedList()
    {
        if (head == NULL)
            std::cout << "linked list is empty!" << std::endl;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            while (temp != NULL)
            {
                std::cout << temp->data << std::endl;
                temp = temp->prev;
            }
            delete temp;
        }
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    return 0;
}