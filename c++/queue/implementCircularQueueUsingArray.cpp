#include <iostream>
using namespace std;

class CircularQueue{
    int rear;
    int front;
    int size;
    int *arr;
    public:
    CircularQueue(int maxsize){
        size=maxsize;
        arr=new int[size];
        rear=-1;
        front=-1;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    int dequeue();
    ~CircularQueue(){delete[] arr;}
};
bool CircularQueue:: isEmpty(){
    if(front==-1)
        return true;
    return false;
}
bool CircularQueue:: isFull(){
    if(front==(rear+1)%size)
        return true;
    return false;
}
void CircularQueue:: enqueue(int item){
    if(isEmpty()){
        front++;
    }
    if(isFull()){
        cout<<"CircularQueue overflow!";
    }
    else{
        rear=(rear+1)%size;
        arr[rear]=item;
    }
}
int CircularQueue:: dequeue(){
    int item;
    if(isEmpty()){
        cout<<"CircularQueue underflow!";
        return -1;
    }
    else{
        item = arr[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
    return item;
}


int main() {
    CircularQueue q(4);
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