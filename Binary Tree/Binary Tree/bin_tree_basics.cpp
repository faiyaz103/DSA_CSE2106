#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

/*
CREATE/INSERT
Insert level-by-level (like filling seats in a classroom)
1. Use queue (BFS) 
2. Find first empty left/right 
3. Insert there 
*/
void createOrInsert(Node** root, int val){

    Node* newNode=new Node(val);

    if(*root==nullptr){
        *root=newNode;
        return;
    }

    queue<Node*> q;
    q.push(*root);

    while(!q.empty()){

        Node* currentNode=q.front();
        q.pop();

        if(currentNode->left!=nullptr){
            q.push(currentNode->left);
        }
        else{
            currentNode->left=newNode;
            return;
        }

        if(currentNode->right!=nullptr){
            q.push(currentNode->right);
        }
        else{
            currentNode->right=newNode;
            return;
        }
    }   
}

// TRAVERSE
// Level Order (BFS)
void levelOrderTraverse(Node *root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* currentNode=q.front();
        q.pop();

        cout<<currentNode->data<<' ';

        if(currentNode->left!=nullptr) q.push(currentNode->left);
        if(currentNode->right!=nullptr) q.push(currentNode->right);
    }
}

/**
 * inOrder(node):
    go LEFT
    process NODE
    go RIGHT
 */
void inOrderTraversal(Node* root){

    if(root==nullptr) return;

    inOrderTraversal(root->left);
    cout<<root->data<<' ';
    inOrderTraversal(root->right);
}

/**
 * Preorder (NLR) → Node → Left → Right
 */
void preOrderTraverse(Node* root){

    if(root==nullptr) return;

    cout<<root->data<<' ';
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

/**
 * Postorder (LRN) → Left → Right → Node
 */
void postOrderTraverse(Node* root){
    if(root==nullptr) return;

    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout<<root->data<<' ';
}

/**
 * HEIGHT
 */
int height(Node* root){

    if(root==nullptr){
        return -1;
    }

    int lheight=height(root->left);
    int rheight=height(root->right);

    return max(lheight,rheight)+1;
}

int main(){

    int vals[8]={10,23,1,3,45,7,6,9};
    
    Node* root=nullptr;
    for(int i=0; i<size(vals); i++){
        createOrInsert(&root, vals[i]);
    }

    cout<<"LEVEL ORDER: ";
    levelOrderTraverse(root);
    cout<<endl;

    cout<<"IN ORDER: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"PRE ORDER: ";
    preOrderTraverse(root);
    cout<<endl;

    cout<<"POST ORDER: ";
    postOrderTraverse(root);
    cout<<endl;
    
    cout<<"HEIGHT: ";
    cout<<height(root);
    cout<<endl;

    return 0;
}