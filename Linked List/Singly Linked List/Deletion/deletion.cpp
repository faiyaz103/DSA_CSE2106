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

// Traverse list
void traverse(Node** head){

    Node* temp=*head;
    while(temp!=nullptr){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

// Create and link nodes
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

// Delete the beignning node
void deleteFromBeginning(Node** head){

    if(*head==nullptr){
        cout<<"Already empty"<<endl;
        return;
    }

    Node* temp=*head;
    *head=(*head)->next;

    delete temp;

    cout<<"After deleting from beginning"<<endl;
    traverse(head);
}

// Delete the end node
void deleteEndNode(Node** head){

    if(*head==nullptr){
        cout<<"Already empty"<<endl;
        return;
    }

    if((*head)->next==nullptr){
        deleteFromBeginning(head);
        return;
    }

    Node* temp=*head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    Node* toBeDeleted=temp->next;
    temp->next=nullptr;

    delete toBeDeleted;

    cout<<"After deleting the end node"<<endl;
    traverse(head);

}

// Delete at a specific position
void deleteSpecificPos(int pos, Node** head){

    if(pos==0){
        deleteFromBeginning(head);
        return;
    }

    Node* temp=*head;
    Node* aux;
    for(int i=0; i<pos; i++){
        aux=temp;
        temp=temp->next;
    }

    aux->next=temp->next;

    delete temp;

    cout<<"After deleting from position "<<pos<<endl;
    traverse(head);
}

// Main
int main(){
    int a[]={1,2,3,4,5};
    Node* head=nullptr;

    int ln=sizeof(a)/sizeof(a[0]);

    for(int i=0; i<ln; i++){
        createAndLink(a[i],&head);
    }

    cout<<"After creation"<<endl;
    traverse(&head);

    while(true){

        cout<<"-----Perform delete operation-----"<<endl;
        cout<<"1 --> Delete the first node"<<endl;
        cout<<"2 --> Delete the last node"<<endl;
        cout<<"3 --> Delete at specific position"<<endl;
        cout<<"0 --> Exit the operation"<<endl;
        int ops;
        cin>>ops;
        if(!ops) break;

        switch (ops)
        {
        case 1:
            // Delete from beginning
            deleteFromBeginning(&head);
            break;

        case 2:
            // Delete the end node
            deleteEndNode(&head);
            break;

        case 3:
            // Delete at specific position
            cout<<"Enter position"<<endl;
            int pos;
            cin>>pos;
            deleteSpecificPos(pos,&head);
            break;
        
        default:
            cout<<"Enter valid option number"<<endl;
            break;
        }
    }

       
    
    return 0;
}