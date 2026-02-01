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
        if(isEmpty()) {
            cout<<"stack is empty";
            return 0;
        }
        else {
            int item=head->data;
            Node* temp = head;
            head=head->next;
            delete temp;
            return item; 
        }
    
    //empty
    }
    bool isEmpty() {
        if(head==nullptr) return true;
        else return false;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp=temp->next;
        }
    }
};
int main(){
    Stack s;
    s.push(5);
    s.push(3);
    s.push(6);
    s.display();
    return 0;
}