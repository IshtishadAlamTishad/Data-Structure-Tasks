
// Author : Tishad

#include<iostream>
using namespace std;

class STACK
{
public :
    int *Stack,top=-1,maxSize=100;

    STACK(int Size) {
    maxSize = Size;
	Stack = new int[maxSize];
	top = 0;
    }
    ~STACK() {
    delete[] Stack;
    }

 bool isEmpty() {
 return (top==-1) ? true:false;
 }
 bool isFull() {
 if(top==maxSize) return true ;
 else return false;
 }
bool push(int element) {
    if(isFull()) cout << "\nResizing with Constructor & Destructor\n";
    Stack[top++] = element;
}
bool pop() {
    if(isEmpty()) { cout << "Stack Underflow\n";
    return false;
} else {
    top--;
    return true;
}
}
void show() {
    if(isEmpty()) cout << "Stack is empty\n";
    else {
        for(int i=top-1;i>=0;--i) {
            cout << Stack[i] << '\n';
        }
    }
}

};

void display()
{
    cout << "\n............................\n";
    cout << "1) Push Elements to Stack   \n";
    cout << "2) Pop Elements from Stack  \n";
    cout << "3) View Stack's Elements    \n";
    cout << "4) Exit                     \n";
    cout << "\n............................\n";
}
int main()
{
 int s;
 cout << "Enter size of Stack : ";
 cin >> s;

 STACK st(s);
 int op;
 do {
     display();
     cout << "Enter option : ";
     cin >> op;

     switch(op)
     {
     case 1:
        int n;
        cout << "Enter Element to push : ";
        cin >> n;
        st.push(n);
        break;

     case 2:
        cout << "Popping elements from stack \n";
        st.pop();
        break;

     case 3 :
        cout << "Showing Stack's Elements : \n";
        st.show();
        break;
 }
 } while(op!=4);

    return 0;
}
