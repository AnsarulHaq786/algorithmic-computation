#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;   
    }
};
class Queue{
    private:
    Node *rear;
    Node *front;
    public:
    Queue(){    
        rear=nullptr;
        front=nullptr;
    }
    bool isEmpty();
    void enqueue(int);
    int dequeue();
    ~Queue();
};
Queue:: ~Queue(){
    while (!isEmpty()) {
        dequeue();
    }
}
bool Queue:: isEmpty(){
    if(front==nullptr)
        return true;
    return false;
}
void Queue:: enqueue(int item){
    Node* newNode=new Node(item);
    if(isEmpty()){
        front=newNode;
        rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
    
}
int Queue:: dequeue(){
    if(isEmpty()){
        cout<<"Queue underflow!";
        return -1;  
    }
    int item=front->data;
    Node* temp=front;
    front=front->next;
    if(front==nullptr)
        rear=nullptr;
    delete temp;
    return item;
}

int main(){
    Queue q;
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    q.enqueue(3);
    q.enqueue(7);
    cout<<q.dequeue()<<endl;
    q.enqueue(3);
    q.enqueue(7);
    cout<<q.dequeue()<<endl;
    return 0;
}