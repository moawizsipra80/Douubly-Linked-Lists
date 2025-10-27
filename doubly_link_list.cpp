#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>
class DoublyList
{
public:
    Node<T> *head;
    Node<T> *prev;
    DoublyList()
    {
        head = NULL;
        prev = NULL;
    }

    void insertathead(T value)
    {
        if (head == NULL)
        {
            Node<T> *t = new Node<T>(value);
            head = t;
            head->next = head;
            head->prev = head;
            return;
        }
        Node<T> *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        Node<T> *newnode = new Node<T>(value);
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
        //always conncect new node's pointe r fiest then old one
        return;
    }

    void insertattail(T value)
    {
        if (head == NULL)
        {
            insertathead(value);
            return;
        }
        Node<T> *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        Node<T> *newnode = new Node<T>(value);
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        // head=newnode;
    }

    //     Operatio 	Pointers kis pehle set hote hain
    // Insertion	New Node ke pointers pehle set karo → phir baaki nodes se connect karo
    // Deletion	 Delete hone wale node ke neighbors ke pointers pehle update karo → phir node delete karo

    //  Add karte waqt:
    //  Pehle newnode ke next/prev set karte hain.
    //  Phir old links update karte hain.

    //  Delete karte waqt:
    //  Pehle old links update karte hain (taak-e chain na toote).
    //  Phir node delete karte hain.
    void removeathead()
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete at head.\n";
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node<T> *del = head;
        Node<T> *last = head->prev;
        last->next = head->next;
        head->next->prev = last;
        head = head->next;
        delete del;
    }

    void removeattail()
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete at tail.\n";
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            cout << "del hogay last\n";
            return;
        }

        Node<T> *last = head->prev;
        Node<T> *temp = last;
        last->prev->next = head;
        head->prev = last->prev;
        delete temp;
        cout << "del hogay last" << endl;
        return;
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

    bool isempty()
    {
        return head == NULL;
    }

    int count()
    {
        if (head == NULL)
            return 0;
        int c = 0;
        Node<T> *temp = head;
        do
        {
            c++;
            temp = temp->next;
        } while (temp != head);
        return c;
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

    void sort()
    {
        if (head == NULL || head->next == head)
            return;

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
        if (head == NULL || head->next == head)
            return;

        Node<T> *curr = head;
        Node<T> *temp = NULL;

        do
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        } while (curr != head);

        head = head->next;
    }


    void clear()
    {
        if (head == NULL)
            return;

        Node<T> *curr = head->next;
        while (curr != head)
        {
            Node<T> *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        head = NULL;
    }

    ~DoublyList()
    {
        clear();
    }
      void merge(DoublyList& list1,DoublyList& list2)
    {
        if(list1.head==NULL || list2.head==NULL)
        {
            return;
        }
    
        Node<T>*temp1=list1.head;
         Node<T>*temp2=list2.head;
        temp1->prev=NULL;
        temp2->prev=NULL;
        Node<T>*last1=temp1->prev;
        last1==NULL;
        Node<T>*last2=temp2->prev;
        last2=NULL;
        Node<T>* t=nullptr;
        while(temp1->next!=NULL && temp2->next!=NULL)
        {
            if(temp1->data > temp2->data)
            {
                t=t->next;
                              
                 
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        // while(temp1->next!=head && temp2->next!=head)
        // {
        //     temp1=temp1->next;
        //     temp2=temp2->next;  
        //     if(temp1->data > temp1->next->data)
            
        //     {
        //         Node<T>*t=list1.head;
        //         temp1=temp1->next->prev;
        //         temp1->next=t->prev;
        //         t->prev=temp1->next;
        //         // l3.insertathead(temp1->data);  

        //     return; 
            
        //     }
        // }
    }
};

int main()
{

        DoublyList<int>l1;
    l1.insertathead(4);
    l1.insertathead(7);
    l1.insertathead(10);
    l1.insertathead(12);
    
    DoublyList<int>l2;
   l2.insertathead(1);
   l2.insertathead(3);
   l2.insertathead(6);
   l2.insertathead(8);
   l2.insertathead(9);
   l2.insertathead(15);
   DoublyList<int>l3;
   l3.merge(l1,l2);
   l3.display();
}

