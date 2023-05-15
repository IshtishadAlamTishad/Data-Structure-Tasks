#include<iostream>
using namespace std;

class QUEUE{
    int *Queue,Front,rear,maxSize;
 public :
     QUEUE(int Size) {
     maxSize=Size;
     Queue = new int[maxSize];
     Front= -1;
     rear=-1;
     }

     bool isEmpty(){
         if((Front==-1) && (rear==-1)) return true;
         else return false;
     }
      bool isFull(){
         if(((rear+1)%maxSize)==Front) return true;
         else return false;
     }
        int EnQueue(int element){
         if(isFull()) {
                cout << "Queue is Full\n";
         }
         else if(isEmpty()) {
            Front=rear=0;
            Queue[rear] = element;
            return element;
         }
         else {
            rear = (rear+1)%maxSize;
            Queue[rear] = element;
            return element;
         }
     }
     int DeQueue(){
         if(isEmpty()) {
                cout << "Queue is Empty\n..DeQueue not possible\n\n";
         }
         else if(Front==rear) {
            Front=rear=-1;

         } else {
             Front = (Front+1)%maxSize;
         }
     }
      int FrontElement(){
        cout << Queue[Front];
     }
     void show() {
         if(isEmpty()) cout << "Can't show queue it's empty\n";
         else if(Front <= rear){
            for(int i=Front;i<=rear;++i) {
                cout << Queue[i] << " ";
            }
            cout << '\n';
         } else if(rear <= Front) {
         for(int i=0;i<=rear;++i) {
            cout << Queue[i] << " ";
          }

         for(int i=Front;i<=(maxSize-1);++i) {
            cout << Queue[i] << " ";
         }
         cout << '\n';
         }


     }
};
void display()
{
    cout << "\n.............................\n";
    cout << "1) EnQueue Element to Queue    \n";
    cout << "2) DeQueue Element from Queue  \n";
    cout << "3) Show Front Value of Queue   \n";
    cout << "4) Show Queue                  \n";
    cout << "5) Exit                        \n";
    cout << "\n.............................\n";
}
int main()
{
    int sz;
    cout << "Please Enter Size of Queue : \n";
    cin >> sz;

    QUEUE Queue(sz);

    int op;
    do {
        display();
        cout << "Enter Queue operation : \n";
        cin >> op;

        switch(op)
        {
        case 1 :
            int x;
            cout << "Enter Elements to Enqueue : ";
            cin >> x;
            Queue.EnQueue(x);
            break;
        case 2:
            Queue.DeQueue();
            break;
        case 3:
            cout << "Showing Queue Elements : ";
            Queue.FrontElement();
            break;
             case 4:
            cout << "Showing Queue Elements : ";
            Queue.show();
        }

    }
    while(op!=5);

}
