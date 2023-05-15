/* 
  Author : Tishad
  
  Tree Traversal : 
  1) Infix Traversal Function
  2) Prefix Traversal Function
  3) Postfix Traversal Function
*/

#include<iostream>
using namespace std;

void preorder(int pos, int tree[], int len)
{
    int l,r;
    if(pos<len){
        if(tree[pos]!=0){
            cout<< tree[pos] << "   ";
        }
        l = 2*pos + 1;
        preorder(l, tree, len);

        r = 2*pos +2;
        preorder(r,tree, len);
   }
}

void inorder(int pos, int tree[], int len)
{
    int l,r;
    if(pos<len){
        l = 2*pos + 1;
        inorder(l, tree, len);
        if(tree[pos]!=0){
            cout<< tree[pos] << "   ";
        }
        r = 2*pos +2;
        inorder(r,tree, len);
   }
}
void postorder(int pos, int tree[], int len)
{
    int l,r;
    if(pos<len){
        l = 2*pos + 1;
        postorder(l, tree, len);
        r = 2*pos +2;
        postorder(r,tree, len);
        if(tree[pos]!=0){
            cout<< tree[pos] << "   ";
        }
   }
}

int main()
{
    int arr[100]={1,2,3,4,'\0',5,6,'\0','\0','\0','\0',7};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<< "Pre order: "<<"\t";
    preorder(0, arr, len);
    cout<< endl;
    cout<< "In order: "<<"\t";
    inorder(0, arr, len);
    cout<< endl;
    cout<< "Post order: "<<"\t";
    postorder(0, arr, len);
}
