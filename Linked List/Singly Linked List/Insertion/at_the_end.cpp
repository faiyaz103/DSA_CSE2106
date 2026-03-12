#include<bits/stdc++.h>
using namespace std;

int n;

class Node{
    public:
    int data;
    Node* next;

    Node(int new_data){
        this->data=new_data;
        this->next=nullptr;
    }
};

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

void traverse(Node** head){
    Node *temp=*head;
    while(temp!=nullptr){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

void insertAtBeginning(int data, Node** head){

    Node* ptr = new Node(data);
    ptr->next=*head;
    *head=ptr;

    cout<<"After insertion"<<endl;
    traverse(head);
    
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

void insertAtPos(int pos, int data, Node**  head){

    if(pos==0){
        insertAtBeginning(data,head);
        return;
    }
    else if(pos==n+1){
        insertAtEnd(data,head);
        return;
    }

    Node* temp=*head;
    Node *aux;
    for(int i=0; i<pos; i++){
        aux=temp;
        temp=temp->next;
    }

    Node* ptr=new Node(data);
    ptr->next=aux->next;
    aux->next=ptr;

    cout<<"After insertion at pos: "<<pos<<endl;
    traverse(head);
}

int main(){
    Node* head=nullptr;
    cin>>n;

    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        createAndLink(data,&head);
    }

    cout<<"Before insertion"<<endl;
    traverse(&head);

    int pos;
    cin>>pos;

    insertAtPos(pos,12,&head);

    return 0;
}