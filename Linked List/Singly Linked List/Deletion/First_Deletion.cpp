//First Deletion
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *link;
};



/*-----------Creation-----------*/
void creation(node **head, int data){

    node *ptr = new node();

    ptr->data=data;
    ptr->link=NULL;

    if(*head==NULL){
        *head=ptr;
    }
    else{
        node *temp=*head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=ptr;
    }
}
/*------------------------------*/



/*--------First Deletion--------*/
void first_del(node **head){

    *head=(*head)->link;
}
/*------------------------------*/



/*-------Displaying List--------*/
void display(node **head){

    node *temp=*head;

    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->link;
    }
    cout<<endl;
}
/*------------------------------*/



int main(){

    int n,data;
    node *head=NULL;

    cout<<"Enter number of elements:"<<endl;
    cin>>n;

    for(int i=1; i<=n; i++){
        cout<<"Enter element number "<<i<<endl;
        cin>>data;
        creation(&head, data);
    }

    cout<<"The Elements are:"<<endl;
    display(&head);

    first_del(&head);
    cout<<"After first deletion the Elements are:"<<endl;
    display(&head);

    return 0;
}

