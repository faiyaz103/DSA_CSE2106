#include<bits/stdc++.h>
using namespace std;

// Node Structure
class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int new_data){
        this->data=new_data;
        this->next=nullptr;
    }
};

// Create and link nodes
void createAndLinkNode(Node** head, int data){

    Node* ptr = new Node(data);

    if(*head == nullptr){
        *head = ptr;
    }
    else{
        // traverse till next is null
        Node* temp= *head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

// Traverse
void traverse(Node** head){
    Node* temp = *head;

    while(temp!=nullptr){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    int numOfElements;
    Node* head=nullptr; //To keep track of the start of the list
    
    cout<<"Enter num of nodes you wanna generate:"<<endl;
    cin>>numOfElements;

    for(int i=0; i<numOfElements; i++){
        cout<<"Enter data for "<<i+1<<" node"<<endl;
        int data;
        cin>>data;
        createAndLinkNode(&head, data);
    }

    traverse(&head);

    return 0;
}
