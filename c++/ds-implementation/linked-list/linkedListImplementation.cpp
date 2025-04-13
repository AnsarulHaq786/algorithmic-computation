#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head=nullptr;
    }
    void insertBeginning(int item);
    void insertEnd(int item);
    void deleteBegining();
    void deleteEnd();
    void insertAtPosition(int item, int posi);
    void deleteAtPosition(int posi);
    void display();
};

void LinkedList:: insertBeginning(int item){
    Node *newNode = new Node();
    newNode->data=item;
    if(head==nullptr){
        head=newNode;
        newNode->next=nullptr;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}

void LinkedList:: insertEnd(int item){
    Node *newNode = new Node();
    newNode->data=item;
    if(head==nullptr){
        head=newNode;
        newNode->next=nullptr;
    }
    else{
        Node *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=nullptr;
    }
}
void LinkedList:: deleteBegining(){
    if(head==nullptr){
        cout<<"Empty List!";
    }
    else{
        Node *temp=head;
        if(temp->next==nullptr){
            head=nullptr; 
        }
        else{
            head=temp->next;
        }
        delete temp;
    }
}

void LinkedList:: deleteEnd(){
    if(head==nullptr){
        cout<<"Empty list!";
    }
    else{
        Node *temp=head;
        if(temp->next==nullptr){
            head=nullptr;
        }
        else{
            while(temp->next->next!=nullptr){
                temp=temp->next;   
            }
            temp->next=nullptr;    
        }
        delete temp;
    }
}

void LinkedList:: display(){
    Node* temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<endl;
    }
    delete temp;
}

void LinkedList::insertAtPosition(int item, int posi) {
    Node* newNode = new Node();
    newNode->data = item;
    if(posi==1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i=1; i<posi-1; i++) {
        if(temp==nullptr) {
            cout<<"position out of bound!";
            delete newNode;
            return;
        }
        temp=temp->next;
    }
    if(temp==nullptr) {
        cout<<"position couldn't exist!"<< endl;
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next = newNode;
}
// void deleteSpecific(int data);

int main() {
    return 0;
}