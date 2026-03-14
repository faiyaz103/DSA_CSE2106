#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int newData){
        this->data=newData;
        this->next=nullptr;
    }
};

void traverse(Node** head){

    Node* temp=*head;
    while(temp!=nullptr){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

void create(int data, Node** head){

    Node *ptr = new Node(data);

    if(*head==nullptr){
        *head=ptr;
    }
    else{
        Node* temp=*head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=ptr;
    }

    cout<<"Node created:"<<endl;
    traverse(head);
}

// reverse linked list
void reverse(Node** head){

    Node* curr=*head;
    Node* prev=nullptr;
    Node* nextNode=nullptr;

    while(curr->next!=nullptr){

        nextNode=curr->next;
        curr->next=prev;
        prev=curr;

        curr=nextNode;
    }
    curr->next=prev;
    *head=curr;

    cout<<"After reverse opertaion"<<endl;
    traverse(head);
}

int main(){

    int a[]= {1,2,3,4,5};
    int ln = sizeof(a)/sizeof(a[0]);

    Node* head = nullptr;

    for(int i=0; i<ln; i++){
        create(a[i], &head);
    }

    reverse(&head);

    return 0;
}