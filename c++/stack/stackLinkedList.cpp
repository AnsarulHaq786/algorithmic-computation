#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Stack{
    private:
    Node *head;

    public:
    //constructor
    Stack(){
        head=NULL;
    }
    //push
    void push(int item){
        Node* newNode=new Node(item);
        newNode->next=head;
        head=newNode;
    }
    //pop
    int pop(){
        
    }
    //topElememt
    //isEmpty
    //isFull
    
};
int main(){
    
}