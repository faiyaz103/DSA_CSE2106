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

int main(){

    int a[]={1,2,3,4,5};
    Node* head=nullptr;
    int len=sizeof(a)/sizeof(a[0]);

    for(int i=0; i<len; i++){
        create(a[i],&head);
    }

    return 0;
}