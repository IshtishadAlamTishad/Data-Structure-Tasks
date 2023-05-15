
// Author : Tishad

#include<iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next=NULL;
    }
};
void insertAtTail(Node* &head,int x)
{
    Node* n = new Node(x);

    if(head==NULL) {
        head=n;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL) {
        temp= temp->next;
    }
    temp->next=n;

}
void insertAtHead(Node* &head,int x)
{
    Node* n = new Node(x);
    n->next=head;
    head=n;
}

void disp(Node* head)
{
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

bool search(Node* head,int key)
{
    Node* temp = head;
    while(temp!=NULL) {
        if(temp->data==key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtHead(head,4);
    insertAtTail(head,3);

    disp(head);

    int se;
    cin >> se;      // Element for search

    cout << se << ((search(head,se)) ? " is present in the LinkedList" : " is not present in the LinkedList");
    
}
