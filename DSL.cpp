#include <iostream>
using namespace std;

template <typename T>
struct snode
{
    T data;
    struct snode *next;
};

template <typename T>
struct dnode
{
    T data;
    struct dnode *next;
    struct dnode *prev;
};

template <class T>
class SinglyLL
{
private:
    int size;
    snode<T> *first;

public:
    SinglyLL()
    {
        size = 0;
        first = NULL;
    }

    void Display()
    {
        snode<T> *temp = first;
        if (first == NULL)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Linked List is Empty";
            cout << "\n-----------------------------------------------\n";
        }
        else
        {
            cout << "\n-----------------------------------------------\n";
            while (temp != NULL)
            {
                cout << "|" << temp->data << "| ->";
                temp = temp->next;
            }
            printf("NULL");
            cout << "\n-----------------------------------------------\n";
        }
    }

    void Count()
    {
        cout << "\n-----------------------------------------------\n";
        printf("Size of Linked List is %d", size);
        cout << "\n-----------------------------------------------\n";
    }

    void InsertFirst(T no)
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }

    void InsertLast(T no)
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            snode<T> *temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if (ipos < 1 || ipos > (size + 1))
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid Position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == size + 1)
        {
            InsertLast(no);
        }
        else
        {
            int i = 0;
            snode<T> *newn = new snode<T>;
            newn->data = no;
            newn->next = NULL;

            snode<T> *temp = first;
            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            size++;
        }
    }

    void DeleteFirst()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
        }
        else
        {
            snode<T> *temp = first;
            first = first->next;
            delete (temp);
        }
        size--;
    }

    void DeleteLast()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            free(first);
        }
        else
        {
            snode<T> *temp = first;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete (temp->next);
            temp->next = NULL;
        }
        size--;
    }

    void DeleteAtPos(int ipos)
    {
        if (ipos < 1 || ipos > size)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == size)
        {
            DeleteLast();
        }
        else
        {
            int i = 0;
            snode<T> *temp = first;
            snode<T> *targeted = NULL;
            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            targeted = temp->next;
            temp->next = targeted->next;
            delete (targeted);
            size--;
        }
    }
};

template <class T>
class DoublyLL
{
private:
    int size;
    dnode<T> *first;

public:
    DoublyLL()
    {
        size = 0;
        first = NULL;
    }

    void Display()
    {
        dnode<T> *temp = first;
        if (first == NULL)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Linked List is Empty";
            cout << "\n-----------------------------------------------\n";
        }
        else
        {
            cout << "\n-----------------------------------------------\n";
            while (temp != NULL)
            {
                cout << "|" << temp->data << "|->";
                temp = temp->next;
            }
            printf("NULL");
            cout << "\n-----------------------------------------------\n";
        }
    }

    void Count()
    {
        cout << "\n-----------------------------------------------\n";
        printf("Size of Doubly Linked Listis %d", size);
        cout << "\n-----------------------------------------------\n";
    }

    void InsertFirst(T no)
    {
        dnode<T> *newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (size == 0)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        size++;
    }

    void InsertLast(T no)
    {
        dnode<T> *newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (size == 0)
        {
            first = newn;
        }
        else
        {
            dnode<T> *temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        size++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if (ipos < 1 || ipos > size + 1)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid Position";
            cout << "\n-----------------------------------------------\n";
        }
        else if (ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == size + 1)
        {
            InsertLast(no);
        }
        else
        {
            int i = 0;
            dnode<T> *temp = first;
            dnode<T> *newn = new dnode<T>;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;

            size++;
        }
    }

    void DeleteFirst()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
        }
        else
        {
            first = first->next;
            delete (first->prev);
            first->prev = NULL;
        }
        size--;
    }

    void DeleteLast()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
        }
        else
        {
            dnode<T> *temp = first;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete (temp->next);
            temp->next = NULL;
        }
        size--;
    }

    void DeleteAtPos(int ipos)
    {
        if (ipos < 1 || ipos > size)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == size)
        {
            DeleteLast();
        }
        else
        {
            int i = 0;
            dnode<T> *temp = first;

            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            free(temp->next->prev);
            temp->next->prev = temp;

            size--;
        }
    }
};

template <class T>
class SinglyCL
{
private:
    int size;
    snode<T> *first;
    snode<T> *last;

public:
    SinglyCL()
    {
        size = 0;
        first = NULL;
        last = NULL;
    }

    void Display()
    {
        snode<T> *temp = first;
        if (first == NULL)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Linked List is Empty";
            cout << "\n-----------------------------------------------\n";
        }
        else
        {
            cout << "\n-----------------------------------------------\n";
            while (1)
            {
                cout << "|" << temp->data << "|->";
                temp = temp->next;
                if (temp == last->next)
                {
                    break;
                }
            }
            cout << "\n-----------------------------------------------\n";
        }
    }

    void Count()
    {
        cout << "\n-----------------------------------------------\n";
        cout << "Size of Circular Linked List is " << size << "\n";
        cout << "-----------------------------------------------\n";
    }

    void InsertFirst(T no)
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        if (first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        last->next = first;
        size++;
    }

    void InsertLast(T no)
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        if (first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }
        last->next = first;
        size++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if (ipos < 1 || ipos > size + 1)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid Position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == size + 1)
        {
            InsertLast(no);
        }
        else
        {
            int i = 0;
            snode<T> *temp = first;
            snode<T> *newn = new snode<T>;
            newn->data = no;
            newn->next = NULL;

            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            size++;
        }
    }

    void DeleteFirst()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete (last->next);
            last->next = first;
        }
        size--;
    }

    void DeleteLast()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
            last = NULL;
        }
        else
        {
            int i = 0;
            snode<T> *temp = first;

            while (temp->next != last)
            {
                temp = temp->next;
            }
            delete (last);
            last = temp;
            last->next = first;
        }
        size--;
    }

    void DeleteAtPos(int ipos)
    {
        if (ipos < 1 || ipos > size)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == size)
        {
            DeleteLast();
        }
        else
        {
            int i = 0;
            snode<T> *temp = first;
            snode<T> *targeted = NULL;

            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            temp->next = targeted;
            temp->next = targeted->next;
            delete (targeted);

            size--;
        }
    }
};

template <class T>
class DoublyCL
{
private:
    int size;
    dnode<T> *first;
    dnode<T> *last;

public:
    DoublyCL()
    {
        size = 0;
        first = NULL;
        last = NULL;
    }

    void Display()
    {
        dnode<T> *temp = first;
        cout << "\n-----------------------------------------------\n";
        if (first == NULL)
        {
            cout << "Linked List is Empty\n";
        }
        else
        {
            while (1)
            {
                cout << "|" << temp->data << "|->";
                temp = temp->next;
                if (temp == last->next)
                {
                    break;
                }
            }
        }
        cout << "\n-----------------------------------------------\n";
    }

    void Count()
    {
        cout << "\n-----------------------------------------------\n";
        cout << "Size of Doubly Circular Linked List is " << size << "\n";
        cout << "\n-----------------------------------------------\n";
    }

    void InsertFirst(T no)
    {
        dnode<T> *newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        last->next = first;
        first->prev = last;
        size++;
    }

    void InsertLast(T no)
    {
        dnode<T> *newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            newn->prev = last;
            last = newn;
        }
        last->next = first;
        first->prev = last;
        size++;
    }

    void InsertAtPos(T no, int ipos)
    {
        if (ipos < 1 || ipos > size + 1)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid Position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == size + 1)
        {
            InsertLast(no);
        }
        else
        {
            int i = 0;
            dnode<T> *temp = first;
            dnode<T> *newn = new dnode<T>;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
            size++;
        }
    }

    void DeleteFirst()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete (first->prev);
            last->next = first;
            first->prev = last;
        }
        size--;
    }

    void DeleteLast()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete (first);
            first = NULL;
            last = NULL;
        }
        else
        {
            last = last->prev;
            free(last->next);
            last->next = first;
            first->prev = last;
        }
        size--;
    }

    void DeleteAtPos(int ipos)
    {
        if (ipos < 1 || ipos > size)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid Position";
            cout << "\n-----------------------------------------------\n";
            return;
        }
        else if (ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == size)
        {
            DeleteLast();
        }
        else
        {
            int i = 0;
            dnode<T> *temp = first;
            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete (temp->next->prev);
            temp->next->prev = temp;
            size--;
        }
    }
};

template <class T>
class Stack
{
private:
    snode<T> *first;
    int size;

public:
    Stack()
    {
        first = NULL;
        size = 0;
    }

    void push(T no)
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }

    void pop()
    {
        snode<T> *temp = first;
        cout << "\n-----------------------------------------------\n";
        if (size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }

        if (size == 1)
        {
            cout << "popped element-> |" << first->data << "|\n";
            delete first;
            first = NULL;
        }
        else
        {
            cout << "popped element-> |" << first->data << "|\n";
            first = first->next;
            delete temp;
        }
        cout << "\n-----------------------------------------------\n";
        size--;
    }

    void Display()
    {
        snode<T> *temp = first;
        cout << "\n-----------------------------------------------\n";
        if (first == NULL)
        {
            cout << "Stack is Empty";
        }
        else
        {
            while (temp != NULL)
            {
                cout << "|" << temp->data << "|"
                     << "\n";
                temp = temp->next;
            }
        }
        cout << "\n-----------------------------------------------\n";
    }

    void Count()
    {
        cout << "\n-----------------------------------------------\n";
        cout << "Size of Stack is " << size << "\n";
        cout << "\n-----------------------------------------------\n";
    }
};

template <class T>
class Queue
{
private:
    snode<T> *first;
    int size;

public:
    Queue()
    {
        first = NULL;
        size = 0;
    }

    void Enqueue(T no)
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        if (size == 0)
        {
            first = newn;
        }
        else
        {
            snode<T> *temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }

    void Dequeue()
    {
        snode<T> *temp = first;
        cout << "\n-----------------------------------------------\n";
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        if (size == 1)
        {
            cout << first->data << " removed from Queue\n";
            delete first;
            first = NULL;
        }
        else
        {
            cout << first->data << " removed from Queue\n";
            first = first->next;
            delete temp;
        }
        cout << "\n-----------------------------------------------\n";
        size--;
    }

    void Display()
    {
        snode<T> *temp = first;
        cout << "\n-----------------------------------------------\n";
        if (first == NULL)
        {
            cout << "Queue is Empty";
        }
        else
        {
            for (int i = 1; i <= size; i++, temp = temp->next)
            {
                cout << "|" << temp->data << "|\n";
            }
        }
        cout << "\n-----------------------------------------------\n";
    }

    void Count()
    {
        cout << "\n-----------------------------------------------\n";
        cout << "Size of Queue is " << size;
        cout << "\n-----------------------------------------------\n";
    }
};

int main()
{
    int get = 1, type = 1, choice = 1, data = 0, pos = 0;
    char datac;
    float dataf;
    double datad;

    while (1)
    {
        cout << "\n-----------------------------------------------\n";
        cout << "Choose the Data Structure\n";
        cout << "1: Singly Linked list\n";
        cout << "2: Doubly Linked List\n";
        cout << "3: Singly Circular Linked List\n";
        cout << "4: Doubly Circular Linked List\n";
        cout << "5: Stack\n";
        cout << "6: Queue\n";
        cout << "0: Terminate the Application\n";
        cout << "-------------------------------------------------\n\n";
        cout << "Enter: ";
        cin >> get;
        if (get == 1)
        {
            while (1)
            {
                cout << "\n-----------------------------------------------\n";
                cout << "Enter preferred DataType:\n";
                cout << "1: Integer\n2: Character\n3: Float\n4: Double\n0: main menu\n";
                cout << "-------------------------------------------------\n\n";
                cout << "Enter: ";
                cin >> type;

                if (type == 1)
                {
                    SinglyLL<int> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertFirst(data);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertLast(data);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(data, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter the position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted", pos);
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 2)
                {
                    SinglyLL<char> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertFirst(datac);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertLast(datac);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datac, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 3)
                {
                    SinglyLL<float> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertFirst(dataf);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertLast(dataf);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(dataf, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 4)
                {
                    SinglyLL<double> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertFirst(datad);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertLast(datad);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datad, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 0)
                {
                    break;
                }
                else
                {
                    cout << "Enter valid Choice\n";
                }
            }
        }
        else if (get == 2)
        {
            while (1)
            {
                cout << "\n-----------------------------------------------\n";
                cout << "Enter preferred DataType:\n";
                cout << "1: Integer\n2: Character\n3: Float\n4: Double\n0: main menu\n";
                cout << "-------------------------------------------------\n\n";
                cout << "Enter: ";
                cin >> type;

                if (type == 1)
                {
                    DoublyLL<int> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertFirst(data);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertLast(data);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(data, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter the position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted", pos);
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 2)
                {
                    DoublyLL<char> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertFirst(datac);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertLast(datac);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datac, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 3)
                {
                    DoublyLL<float> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertFirst(dataf);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertLast(dataf);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(dataf, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 4)
                {
                    DoublyLL<double> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertFirst(datad);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertLast(datad);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datad, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 0)
                {
                    break;
                }
                else
                {
                    cout << "Enter valid Choice\n";
                }
            }
        }
        else if (get == 3)
        {
            while (1)
            {
                cout << "\n-----------------------------------------------\n";
                cout << "Enter preferred DataType:\n";
                cout << "1: Integer\n2: Character\n3: Float\n4: Double\n0: main menu\n";
                cout << "-------------------------------------------------\n\n";
                cout << "Enter: ";
                cin >> type;

                if (type == 1)
                {
                    SinglyCL<int> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertFirst(data);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertLast(data);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(data, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter the position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted", pos);
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 2)
                {
                    SinglyCL<char> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertFirst(datac);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertLast(datac);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datac, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 3)
                {
                    SinglyCL<float> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertFirst(dataf);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertLast(dataf);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(dataf, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 4)
                {
                    SinglyCL<double> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertFirst(datad);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertLast(datad);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datad, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 0)
                {
                    break;
                }
                else
                {
                    cout << "Enter valid Choice\n";
                }
            }
        }
        else if (get == 4)
        {
            while (1)
            {
                cout << "\n-----------------------------------------------\n";
                cout << "Enter preferred DataType:\n";
                cout << "1: Integer\n2: Character\n3: Float\n4: Double\n0: main menu\n";
                cout << "-------------------------------------------------\n\n";
                cout << "Enter: ";
                cin >> type;

                if (type == 1)
                {
                    DoublyCL<int> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertFirst(data);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.InsertLast(data);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(data, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter the position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted", pos);
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 2)
                {
                    DoublyCL<char> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertFirst(datac);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.InsertLast(datac);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datac, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 3)
                {
                    DoublyCL<float> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertFirst(dataf);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.InsertLast(dataf);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(dataf, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 4)
                {
                    DoublyCL<double> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Insert the node at first\n";
                        cout << "2: Insert the node at last\n";
                        cout << "3: Insert the node at desired position\n";
                        cout << "4: Delete first node\n";
                        cout << "5: Delete last node\n";
                        cout << "6: Delete node at desried postion\n";
                        cout << "7: Display the Linked list\n";
                        cout << "8: Count Linked list\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertFirst(datad);
                            printf("data added at first position\n");
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.InsertLast(datad);
                            printf("data added at last position\n");
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            cout << "Enter position:\n";
                            cin >> pos;
                            sobj.InsertAtPos(datad, pos);
                            printf("data added at %d position\n", pos);
                        }
                        else if (choice == 4)
                        {
                            sobj.DeleteFirst();
                            cout << "first node deleted\n";
                        }
                        else if (choice == 5)
                        {
                            sobj.DeleteLast();
                            cout << "last node deleted\n";
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter teh position:\n";
                            cin >> pos;
                            sobj.DeleteAtPos(pos);
                            printf("%d position node deleted");
                        }
                        else if (choice == 7)
                        {
                            sobj.Display();
                        }
                        else if (choice == 8)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 0)
                {
                    break;
                }
                else
                {
                    cout << "Enter valid Choice\n";
                }
            }
        }
        else if (get == 5)
        {
            while (1)
            {
                cout << "\n-----------------------------------------------\n";
                cout << "Enter preferred DataType:\n";
                cout << "1: Integer\n2: Character\n3: Float\n4: Double\n0: main menu\n";
                cout << "-------------------------------------------------\n\n";
                cout << "Enter: ";
                cin >> type;

                if (type == 1)
                {
                    Stack<int> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Push Node\n";
                        cout << "2: Pop Node\n";
                        cout << "3: Display the Stack\n";
                        cout << "4: Count the Node in Stack\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.push(data);
                            printf("data push\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.pop();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 2)
                {
                    Stack<char> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Push Node\n";
                        cout << "2: Pop Node\n";
                        cout << "3: Display the Stack\n";
                        cout << "4: Count the Node in Stack\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.push(datac);
                            printf("data push\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.pop();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 3)
                {
                    Stack<float> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Push Node\n";
                        cout << "2: Pop Node\n";
                        cout << "3: Display the Stack\n";
                        cout << "4: Count the Node in Stack\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.push(dataf);
                            printf("data push\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.pop();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 4)
                {
                    Stack<double> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Push Node\n";
                        cout << "2: Pop Node\n";
                        cout << "3: Display the Stack\n";
                        cout << "4: Count the Node in Stack\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.push(data);
                            printf("data push\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.pop();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 0)
                {
                    break;
                }
                else
                {
                    cout << "Enter valid Choice\n";
                }
            }
        }
        else if (get == 6)
        {
            while (1)
            {
                cout << "\n-----------------------------------------------\n";
                cout << "Enter preferred DataType:\n";
                cout << "1: Integer\n2: Character\n3: Float\n4: Double\n0: main menu\n";
                cout << "-------------------------------------------------\n\n";
                cout << "Enter: ";
                cin >> type;

                if (type == 1)
                {
                    Queue<int> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Enqueue Node\n";
                        cout << "2: Dequeue Node\n";
                        cout << "3: Display the Queue\n";
                        cout << "4: Count the Node in Queue\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> data;
                            sobj.Enqueue(data);
                            printf("data added\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.Dequeue();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 2)
                {
                    Queue<char> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Enqueue Node\n";
                        cout << "2: Dequeue Node\n";
                        cout << "3: Display the Queue\n";
                        cout << "4: Count the Node in Queue\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datac;
                            sobj.Enqueue(datac);
                            printf("data added\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.Dequeue();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 3)
                {
                    Queue<float> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Enqueue Node\n";
                        cout << "2: Dequeue Node\n";
                        cout << "3: Display the Queue\n";
                        cout << "4: Count the Node in Queue\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> dataf;
                            sobj.Enqueue(dataf);
                            printf("data added\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.Dequeue();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 4)
                {
                    Queue<double> sobj;
                    while (1)
                    {
                        cout << "\n-----------------------------------------------\n";
                        cout << "Choose which operation you want to perform:\n";
                        cout << "1: Enqueue Node\n";
                        cout << "2: Dequeue Node\n";
                        cout << "3: Display the Queue\n";
                        cout << "4: Count the Node in Queue\n";
                        cout << "0: Exit to menu\n";
                        cout << "-------------------------------------------------\n\n";
                        cout << "Enter: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter data:\n";
                            cin >> datad;
                            sobj.Enqueue(datad);
                            printf("data added\n");
                        }
                        else if (choice == 2)
                        {
                            sobj.Dequeue();
                        }
                        else if (choice == 3)
                        {
                            sobj.Display();
                        }
                        else if (choice == 4)
                        {
                            sobj.Count();
                        }
                        else if (choice == 0)
                        {
                            cout << "Main Menu\n";
                            break;
                        }
                        else
                        {
                            cout << "Enter valid Choice\n";
                        }
                    }
                }
                else if (type == 0)
                {
                    break;
                }
                else
                {
                    cout << "Enter valid Choice\n";
                }
            }
        }
        else if (get == 0)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Program Terminated";
            cout << "\n-----------------------------------------------\n\n";
            break;
        }
        else
        {
            cout << "\n-----------------------------------------------\n";
            cout << "\nEnter valid choice\n";
            cout << "\n-----------------------------------------------\n\n";
        }
    }
    return 0;
}