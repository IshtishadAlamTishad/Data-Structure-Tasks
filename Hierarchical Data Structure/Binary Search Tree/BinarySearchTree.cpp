#include<iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* lptr;
    Node* rptr;

    Node(int a) {
     this->data=a;
     this->lptr=NULL;
     this->rptr= NULL;
    }
};

class BST
{
public:
    Node* root;
    BST() {
        root = NULL;
    }
 Node* Insert(Node* root,int x) {
    if(root==NULL) {
        root = new Node(x);
        return root;
    }
    if(x>root->data) {
        root->rptr = Insert(root->rptr,x);
    } else {
     root->lptr = Insert(root->lptr,x);
    }
}

bool Search(Node* root,int k) {
    Node *temp = root;
    while(temp!=NULL) {
        if(temp->data == k) {
            return true;
        }
        if(root->data > k) {
            temp = temp->lptr;
        } else {
            temp = temp->rptr;
        }
    }
    return false;
}

Node* minVal(Node* root) {
 Node* temp = root;
 while(temp->lptr != NULL) {
    temp = temp->lptr;
 }
 return temp;
}

Node* Delete(Node* root,int x) {
    if(root==NULL) {
        return root;
    }
    else if(root->data == x) {
        cout << "\n\nDeleting Node " << x << " with zero child(Leaf Node)  \n";
        if(root->lptr == NULL && root->rptr == NULL) {
            delete root;
            return NULL;
        }
        else if(root->lptr != NULL && root->rptr==NULL) {
             cout << "\n\nDeleting Node " << x << " with LEFT(one-child) \n";
            Node* temp = root->lptr;
            delete root;
            return temp;
        }
        else if(root->lptr == NULL && root->rptr!=NULL) {
             cout << "\n\nDeleting Node " << x << " with RIGHT(one-child)  \n";
            Node* temp = root->rptr;
            delete root;
            return temp;
        }
        else if(root->lptr!=NULL && root->rptr!=NULL) {
             cout << "\n\nDeleting Node " << x << " with both child  \n";
            int mini = minVal(root->rptr)->data;
            root->data = mini;
            root->rptr = Delete(root->rptr,mini);
            return root;
        }
    }
    else if(root->data > x) {
        root->lptr = Delete(root->lptr,x);
        return root;
    } else {
     root->rptr = Delete(root->rptr,x);
     return root;
    }
}

void preorder(Node* root) {
 if(root==NULL) {
    return;
 }
 cout << root->data << ' ';
 preorder(root->lptr);
 preorder(root->rptr);
}
void inorder(Node* root) {
 if(root==NULL) {
    return;
 }
 inorder(root->lptr);
 cout << root->data << ' ';
 inorder(root->rptr);
}
void postorder(Node* root) {
 if(root==NULL) {
    return;
 }
 postorder(root->lptr);
 postorder(root->rptr);
 cout << root->data << ' ';
}
};
void disp1()
{
    cout << "\n*******************\n";
    cout << "\nBinary Search Tree Operations :\n";
    cout << "1) Insert            \n";
    cout << "2) Traverse          \n";
    cout << "3) Search            \n";
    cout << "4) Delete            \n";
    cout << "5) Exit              \n";
    cout << "*********************\n";
}
int main()
{

    Node* root = NULL;
    BST b;

    int op,op2,c,f;
    bool a;
    do {
    disp1();
    cout << "\nPlease Enter option : ";
    cin >> op;

    switch(op)
    {
    case 1:
        int e;
        cout << "Enter Element to BST : ";
        cin >> e;
        if(root==NULL) {
            root = b.Insert(root,e);
        } else {
          b.Insert(root,e);
        }
        break;

    case 2:
        int op2;
        cout << "\n\n1) Preorder \n";
        cout << "2) Inorder \n";
        cout << "3) Postorder \n\n";
        cout << "Enter option : \n";
        cin >> op2;
        switch(op2) {

    case 1:
        cout << "\nPreorder Traversal : \n";
        b.preorder(root);
        cout << '\n';
        break;
    case 2:
         cout << "\nInorder Traversal : \n";
         b.inorder(root);
         cout << '\n';
        break;
    case 3:
         cout << "\nPostorder Traversal : \n";
         b.postorder(root);
         cout << '\n';
        break;
        default :
        cout << "\nEnter Valid Option\n";
    }
        break;

    case 3:
        cout << "\nEnter element to search in BST : ";
        cin >> f;
        a = b.Search(root,f);
        cout << ((a) ? "\nElement Found\n" : "\nElement Not Found\n");
        break;
    case 4:
        cout << "\nEnter element to delete in BST : ";
        cin >> c;
        b.Delete(root,c);
        break;
    }
    } while(op!=5);

}
