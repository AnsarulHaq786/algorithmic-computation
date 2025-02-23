// stack as ADT
#include<iostream>
using namespace std;
class Stack{
    private:
    int top, size;
    int *arr;
    public:
    //constructor
    Stack(int s){
        size=s;
        top=-1;
        arr=new int[size];
    }
    //push
    void push(int item){
        if(this->isFull()){
            cout<<"Stack is full!"<<endl;
        }
        else{
            top++;
            arr[top]=item;
        }
    }
    //pop
    void pop(){
        if(this->isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            top--;
        }
    }
    //isempty
    bool isEmpty(){
        if(top==-1)
            cout<<"yes empty!"<<endl;
            return 1;
        cout<<"no empty!"<<endl;
        return 0;
    }
    //isfull
    bool isFull(){
        if(top==size-1){
            cout<<"yes full!"<<endl;
            return 1;
        }
        cout<<"no full!"<<endl;
        return 0;
    }
    //top
    int topElement(){
        return arr[top];
    }
    void display(){
        if (top==-1) {
            cout << "Stack is empty!\n";
            return;
        }
        for(int i=0; i<=top; i++){
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    Stack s(4);
    s.isEmpty();
    s.push(2);
    s.push(3);
    s.isEmpty();
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.pop();
    return 0;
}