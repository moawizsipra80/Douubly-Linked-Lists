#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template <typename T>
class CircularList
{
public:
    Node<T> *head;

    CircularList()
    {
        head = NULL;
    }

    void inserStart(T value)
    {
        if (head == NULL)
        {
            Node<T> *t = new Node<T>(value);
            head = t;
            t->next = head;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node<T> *t = new Node<T>(value);
        temp->next = t; // lastnode new node ko point karega
        t->next = head;
        head = t; // fixed: correct linking for circular head insert
    }

    void insertEnd(T value)
    {
        if (head == NULL)
        {
            Node<T> *newnode = new Node<T>(value);
            head = newnode;
            newnode->next = head;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node<T> *newnode = new Node<T>(value);
        temp->next = newnode; // previous node link to new node
        newnode->next = head;
    }

    int countNodes()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node<T> *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void insertafter(T value, T data1)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node<T> *temp = head;
        do
        {
            if (temp->data == value)
            {
                Node<T> *t = new Node<T>(data1);
                cout << "New Node created" << endl;
                t->next = temp->next;
                temp->next = t;
                cout << "value inserted" << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value not found\n";
    }

    void insertBefore(T value, T data1)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node<T> *temp = head;
        do
        {
            if (temp->next->data == value)
            {
                Node<T> *newnode = new Node<T>(data1);
                cout << "New node created" << endl;
                newnode->next = temp->next;
                temp->next = newnode;
                return;
            }
            temp = temp->next;
        } while (temp->next != head);

        cout << "Value not found for insertBefore\n";
    }

    void removestart()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node<T> *t = head;
        temp->next = head->next;
        head = head->next;
        delete t;
    }

    void removeend()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node<T> *temp = head;
        Node<T> *prev = nullptr;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    void removeknode(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1)
        {
            removestart();
            return;
        }

        Node<T> *curr = head;
        Node<T> *prev = nullptr;
        int count2 = 1;

        do
        {
            prev = curr;
            curr = curr->next;
            count2++;
            if (count2 == pos)
            {
                prev->next = curr->next;
                delete curr;
                cout << "Node deleted at position " << pos << endl;
                return;
            }
        } while (curr->next != head);

        cout << "Position exceeds list size\n";
    }

    void sorting()
    {
        if (head == NULL || head->next == head)
        {
            return;
        }

        Node<T> *i = head;
        do
        {
            Node<T> *j = i->next;
            while (j != head)
            {
                if (i->data > j->data)
                {
                    T temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        } while (i->next != head);
    }

    void reverse()
    {
        if (head == nullptr || head->next == head)
        {
            return;
        }

        Node<T> *prev = NULL;
        Node<T> *current = head;
        Node<T> *next = NULL;
        Node<T> *tail = head;

        do
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node<T> *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }


    bool search(T value)
    {
        if (head == NULL)
            return false;
        Node<T> *temp = head;
        do
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void clear()
    {
        if (head == NULL)
            return;

        Node<T> *temp = head->next;
        while (temp != head)
        {
            Node<T> *del = temp;
            temp = temp->next;
            delete del;
        }
        delete head;
        head = NULL;
    }

    ~CircularList()
    {
        clear();
    }

    void merge(CircularList& list1,CircularList& list2)
    {
        Node<T>*temp1=list1.head;
         Node<T>*temp2=list2.head;
         Node<T>*last1=head->prev;
         Node<T>*last2=head->prev;
        last1->next=list2->prev;
         while (temp2->next!=head)
       {
         if(temp1->data>temp2->data){
            T tempd;
            tempd=temp1->data;
            temp1->data=temp2->data;
            temp2->data=tempd;
            return;
         }
         temp2=temp2->next;
        
       }
       

    }
};

int main()
{
    CircularList<int>l1;
  
    l1.inserStart(4);
    l1.inserStart(7);
    l1.inserStart(10);
    l1.inserStart(12);
    
    CircularList<int>l2;
   l2.inserStart(1);
   l2.inserStart(3);
   l2.inserStart(6);
   l2.inserStart(8);
   l2.inserStart(9);
   l2.inserStart(15);
   CircularList<int>l3;
   l3.merge(l1,l2);
}
