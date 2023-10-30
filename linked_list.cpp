#include <iostream>

using namespace std;

class List_Node
{

public:
    List_Node *next;
    int value;

    List_Node(int val)
    {
        value = val;
        next = nullptr;
    };
};

class Linked_list
{

protected:
    List_Node *head{nullptr};
    int length{0};

public:
    static int instanses;

    Linked_list() {
        instanses++;
    }

    void print()
    {
        List_Node *temp = head;

        if (length == 0)
        {
            cout << "List empty" << endl;
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << '\n';
            cout << "Length: " << length << endl;
        }
    }
};

class Stack : public Linked_list
{
public:
    Stack(){}

    void push(int val)
    {
        List_Node *temp = head;
        List_Node *newNode = new List_Node(val);

        // check if element is last
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        length++;
    }

    void pop()
    {
        List_Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete (temp->next);
        temp->next = nullptr;
        length--;
    }

    void peek() {
        List_Node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        cout << "Last element is: " << temp ->value << endl;
    }
};

class Queue : public Linked_list
{
public:
    Queue(){}

    void enqueue(int val)
    {
        List_Node *newNode = new List_Node(val);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void dequeue()
    {
        if (length > 0) {
            List_Node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete (temp->next);
            temp->next = NULL;
            length--;
        }else {
            throw runtime_error("Queue is empty!");
        }
    }

    void print_first() {
        if (length > 0) {
            cout << "First element is: " << head->value << endl;
        }else {
           cout << "Queue is empty!" << endl;
        }
    }
};

int Linked_list::instanses = 0;

int main()
{
    cout << "stack: " << endl;
    Stack stack;
    stack.print();
    stack.push(10);
    stack.push(15);
    stack.push(14);
    stack.print();
    stack.pop();
    stack.print();
    stack.peek();

    cout << '\n';

    cout << "queue: " << endl;
    Queue queue;
    queue.print();
    queue.enqueue(12);
    queue.enqueue(3);
    queue.enqueue(5);
    queue.print();
    queue.dequeue();
    queue.print();
    queue.enqueue(2);
    queue.print();
    queue.print_first();

    cout << "Количество вызовов linkedList: " << Linked_list::instanses << endl;

}