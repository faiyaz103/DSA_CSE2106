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

void deleteFirstNode(Node** head){
    *head=(*head)->next;
    (*head)->prev=nullptr;

    cout<<"___After delete (FIRST)___"<<endl;
    traverse(head);
}

void deleteLastNode(Node** targetNode, Node** head){
    (*targetNode)->prev->next=nullptr;

    cout<<"___After delete (LAST)___"<<endl;
    traverse(head);
}

void del(int pos, Node** head){
    if(pos==0){
        deleteFirstNode(head);
        return;
    }

    Node* temp=*head;
    for(int i=0; i<pos; i++){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        deleteLastNode(&temp,head);
        return;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    cout<<"___After delete___"<<endl;
    traverse(head);

}

int main(){

    int a[]={1,2,3};
    Node* head=nullptr;
    int len=sizeof(a)/sizeof(a[0]);

    for(int i=0; i<len; i++){
        create(a[i],&head);
    }

    del(2,&head);

    return 0;
}