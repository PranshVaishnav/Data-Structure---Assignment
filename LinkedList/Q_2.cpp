// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
 class Linkedlist
{
    

public:
Node *head;
    // Default constructor
    Linkedlist() { head = NULL; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int);

    void deleteNodeIndex(int);

    void insertNodeIndex(int,int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL)
    {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < nodeOffset)
    {
        cout << "Index out of range"
             << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1)
    {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1)
    {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

void Linkedlist::deleteNodeIndex(int index)
{
    Node * temp=head;
    Node * prev=head;
    while(index--)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=prev->next->next;
    return;
}

// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node *newNode = new Node(data);

    // Assign to head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node *temp = head;
    while (temp->next != NULL)
    {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

void Linkedlist::insertNodeIndex(int data,int index)
{
    // Create the new Node.
    Node *newNode = new Node(data);

     if (head == NULL)
    {
        head = newNode;
        return;
    }
    
    Node *temp=head;
    Node * prev=new Node(data);
    while(index--)
    {
        prev=temp;
        temp=temp->next;
    }

    prev->next=newNode;
    newNode->next=temp;

    return;
}


// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node *temp = head;

    // Check for empty list.
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


Node *Merge(Node *head1,Node*head2)
{
    
    Node * h1=head1;
    Node * h2=head2;
    Node *final_=NULL;
    if(h1->data<=h2->data) final_=h1;  
     else final_=h2;
    while(h1->next and h2->next)
    {
        if(h1->data<=h2->data)
        {
            Node *temp=h1->next;
            h1->next=h2;
            h1=temp;
        }
        else{
           Node *temp=h2->next;
            h2->next=h1;
            h2=temp;  
        }
    }
    if(h1)
    {
      h2->next=h1;  
    }
    if(h2)
    {
       h1->next=h2; 
    }

return final_;
}

Node *findEvenOdd(Node *head)
{
    Node *even = new Node(0);
    Node *odd = new Node(0);
    Node *even_n = even;
    Node *odd_n = odd;
    while (head)
    {
        if (head->data & 1)
        {
            odd_n->next = head;
            odd_n=odd_n->next;
        }
        else
        {
             even_n->next = head;
             even_n=even_n->next;
        }

        head = head->next;
    }
    odd_n->next=NULL;
    even_n->next=NULL;
    even_n->next=odd->next;
    return even->next;
}

Node *findMidPointer(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    Node* previous=NULL;
    while (fast != NULL and fast->next != NULL) {
        previous=slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return previous;
}

Node *MergeSorted(Node *head1)
{
    if(head1 and head1->next)
    {
        Node * mid=findMidPointer(head1);
        Node *midNext=mid->next; 
        mid->next=NULL;

        Node *head2=midNext;

        head1=MergeSorted(head1);
        head2=MergeSorted(head2);
        head1=Merge(head1,head2);
        return head1;
    }
    return head1;
}

void print(Node* temp)
{

    // Check for empty list.
    if (temp == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

///Add Two Number
Node* addTwoNumbers(Node* p, Node* q) {
        Node*head=new Node(0);
        Node*curr=head;
        int carry=0;
        while(p!=0 || q!=0)
        {
            int x=(p!=0)? p->data:0;
            int y=(q!=0)? q->data:0;
            int sum=x+y+carry;
            carry=sum/10;
            curr->next=new Node(sum%10);
            curr=curr->next;
            if(p!=0) p=p->next;
            if(q!=0) q=q->next;
        }
        if(carry>0)
        {
            curr->next=new Node(carry);
        }
        return head->next;
    }



// Driver Code
int main()
{
    Linkedlist list;

    // Inserting nodes
    list.insertNode(2);
    list.insertNode(4);
    list.insertNode(3);

    Linkedlist list2;
    list2.insertNode(4);
    list2.insertNode(5);
    list2.insertNode(6);

    cout << "Add Two Elements: "<<endl;

    // Print the list
    list.printList();
    cout << endl;

    list2.printList();
    cout << endl;

    
    Node * newHead=addTwoNumbers(list.head,list2.head);

    print(newHead);
    
        
    cout << endl;
    return 0;
}
