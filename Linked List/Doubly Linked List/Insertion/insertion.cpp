#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data=d;
        this->prev=nullptr;
        this->next=nullptr;
    }
};

void traverse(Node** head){

    Node* temp=*head;
    while(temp!=nullptr){
        cout<<"|"<<(uintptr_t)temp->prev<<"|"<<temp->data<<"|"<<(uintptr_t)temp->next<<"|("<<(uintptr_t)&(*temp)<<")"<<"--->";
        temp=temp->next;
    }
    cout<<endl;
}

void create(int data, Node** head){

    Node* newNode=new Node(data);

    if(*head==nullptr){
        *head=newNode;
    }
    else{
        Node *temp=*head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    cout<<"After insertion"<<endl;
    traverse(head);
}

void insertAtBeginning(int data, Node** head){

    Node* newNode=new Node(data);

    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;

    cout<<"___After insertion (START)___"<<endl;
    traverse(head);
}

void insertAtEnd(int data, Node** targetNode, Node** head){
    Node* newNode=new Node(data);

    Node* temp=*targetNode;
    temp->next=newNode;
    newNode->prev=temp;

    cout<<"___After insertion (END)___"<<endl;
    traverse(head);
}

void insert(int pos, int data, Node** head){
    if(pos==0) {
        insertAtBeginning(data, head);
        return;
    }

    Node* temp=*head;
    for(int i=0; i<pos; i++){
        if(temp->next==nullptr){
            insertAtEnd(data,&temp,head);
            return;
        }
        temp=temp->next;
    }

    Node* newNode=new Node(data);
    temp->prev->next=newNode;
    newNode->prev=temp->prev;
    temp->prev=newNode;
    newNode->next=temp;

    cout<<"___After insertion___"<<endl;
    traverse(head);
}

int main(){

    int a[]={1,2};
    Node* head=nullptr;
    int len=sizeof(a)/sizeof(a[0]);

    for(int i=0; i<len; i++){
        create(a[i],&head);
    }

    insert(2,5,&head);

    return 0;
}