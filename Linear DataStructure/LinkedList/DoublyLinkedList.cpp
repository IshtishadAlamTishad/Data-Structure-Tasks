#include<iostream>
using namespace std;

struct Node{
int data;
Node *next;
};
Node *list,*tptr,*nptr,*pptr;

void display(int n) {
    cout<<"The data elements of the link list:";
    tptr=list;
    for(int i=1;i<=n;++i) {
        cout<<tptr->data<<" ";
        tptr=tptr->next;
    }
}

void search()
{
    int item,count=1;
    cout<<"\nEnter the data to search:";
    cin>>item;
    tptr=list;
    while(tptr->data!=item && tptr->next!=NULL) {
        pptr=tptr;
        tptr=tptr->next;
         count++;
    }
    if(tptr->data==item) {
        cout<<"Data found at "<<count<<" no node"<<endl;
    }
    else
    {
        cout<<"Data not found"<<endl;
    }
}

int insert(int n)
{
    tptr=list;
    int item;
    cout<<"Enter the data element to insert:";
    cin>>item;
    nptr=new(Node);
    nptr->data=item;
    nptr->next=NULL;

   /* nptr->next=tptr;
    list=nptr;
    while(tptr->next->data<tptr->data)
    {

      tptr=tptr->next;
    }*/
    int p=n+1;
    while(n!=p)
    {
        if(nptr->data>tptr->data && nptr->data<tptr->next->data )
    {

         nptr->next=tptr->next;
         tptr->next=nptr;
         n++;
    }
    else {
        tptr=tptr->next;
    }
    }
    return n;
}

int deletion(int n)
{
    cout<<"\nGo for deleting a item:"<<endl;
    search();
   pptr->next= tptr->next;
   delete(tptr);
   n--;
   return n;
}

void option(int n)
{
    cout<<"\n=================\n"<<endl;
    cout<<"What do you want to do?"<<endl;
    cout<<"***********************"<<endl;
    cout<<"\n\t 1.SEARCH A ELEMENT FROM THE LINK LIST"<<endl;
    cout<<"\t 2.INSERT A ELEMENT IN THE LINK LIST"<<endl;
    cout<<"\t 3.DELETE A ELEMENT FROM THE LINK LIST"<<endl;
    cout<<"\t 4.DISPLAY ALL THE ELEMENTS OF THE LINK LIST "<<endl;
    cout<<"\t 5.EXIT"<<endl;
}
int main()
{
    int i,n,item;
    list=NULL;
    cout<<"Enter the numbers of the node:";
    cin>>n;
    cout<<"Enter data for node with space:";
    for(i=1; i<=n; i++)
    {
        cin>>item;
        nptr=new(Node);
        nptr->data=item;
        nptr->next=NULL;

        if(list==NULL)
        {
            list=nptr;
            tptr=nptr;
        }
        else
            tptr->next=nptr;
            tptr=nptr;
    }
    int op;
    do{
        option(n);
        cout<<"Enter your option:"<<endl;
        cin>>op;
        switch(op)
        {
        case 1:
             search();
              break;
        case 2:
             n=insert(n);
               break;
        case 3:
             n=deletion(n);
               break;
        case 4:
            display(n);
              break;
        }
    }
    while(op!=5);
    
    /*search();
    n=insert(n);
    display(n);
    n=deletion(n);
    display(n);*/

    cout<<endl;
    return 0;
}
