#include <iostream>
using namespace std;

class Queue{
    int rear;
    int front;
    int size;
    int *arr;
    public:
    Queue(int maxsize){
        size=maxsize;
        arr=new int[size];
        rear=-1;
        front=-1;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    int dequeue();
    ~Queue(){delete[] arr;}
};
bool Queue:: isEmpty(){
    if(front==-1 || front>rear)
        return true;
    return false;
}
bool Queue:: isFull(){
    if(rear==size-1)
        return true;
    return false;
}
void Queue:: enqueue(int item){
    if(isEmpty()){
        front++;
    }
    if(isFull()){
        cout<<"Queue overflow!";
    }
    else{
        rear++;
        arr[rear]=item;
    }
}
int Queue:: dequeue(){
    int item;
    if(isEmpty()){
        cout<<"Queue underflow!";
        return -1;
    }
    else{
        item = arr[front];
        front++;
        return item;
    }
}


int main() {
    Queue q(4);
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    q.enqueue(3);
    q.enqueue(7);
    cout<<q.dequeue()<<endl;
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(3);
    return 0;
}