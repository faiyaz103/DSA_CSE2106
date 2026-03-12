#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int new_data){
        this->data=new_data;
        this->next=nullptr;
    }
};

void traverse(Node** head){
    Node *temp=*head;
    while(temp!=nullptr){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

void createAndLink(int data, Node** head){

    Node* ptr=new Node(data);

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
}

void insertAtEnd(int data, Node** head){

    Node* ptr=new Node(data);

    Node* temp = *head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=ptr;

    cout<<"After insertion at end"<<endl;
    traverse(head);
}

int main(){
    int n;
    Node* head=nullptr;
    cin>>n;

    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        createAndLink(data,&head);
    }

    cout<<"Before insertion"<<endl;
    traverse(&head);

    insertAtEnd(12,&head);

    return 0;
}