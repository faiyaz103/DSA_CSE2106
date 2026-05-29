/**
 * Queue Operations
 * - front(): Access the front element of the queue.
 * - back() : Access the end element of the queue.
 * - empty(): Check whether a queue is empty or not.
 * - size() : Returns the number of elements in the queue.
 * - push() : Adding an element at the back of the queue.
 * - pop()  : Delete the front element of the queue.
 */
#include<bits/stdc++.h>
using namespace std;

class Queue{

private:
    static const int maxSize=10;
    int a[maxSize];
    int frontIdx, rearIdx; //-1 -> empty

    // check overflow
    bool overflow(){
        if((this->rearIdx+1)%maxSize==this->frontIdx) return true;
        return false;
    }

public:
    Queue(){
        this->frontIdx=-1;
        this->rearIdx=-1;
    }

    // check if empty
    bool empty(){
        if(this->frontIdx==-1 && this->rearIdx==-1) return true;
        return false;
    }

    // return size
    int size(){
        if(this->empty()) return 0;

        return (this->rearIdx + maxSize - this->frontIdx) % maxSize + 1;
    }

    // push
    void push(int val){
        if(this->overflow()){
            cout<<"OVERFLOW!!!"<<endl;
            return;
        }
        else if(this->empty()){
            this->frontIdx=0;
        }

        this->rearIdx=(this->rearIdx+1)%maxSize;
        this->a[this->rearIdx]=val;
        cout<<"PUSH: "<<this->a[this->rearIdx]<<endl;
    }

    // pop
    void pop(){
        if(this->empty()){
            cout<<"EMPTY!!!"<<endl;
            return;
        }
        else if(this->frontIdx==this->rearIdx){
            cout<<"POP: "<<this->a[this->frontIdx]<<endl;
            this->frontIdx=this->rearIdx=-1;
            return;
        }

        cout<<"POP: "<<this->a[this->frontIdx]<<endl;
        this->frontIdx=(this->frontIdx+1)%maxSize;

    }

    // front
    int front(){
        if(this->empty()){
            cout<<"EMPTY!!!"<<endl;
            return 0;
        }
        return this->a[this->frontIdx];
    }
    
    // back
    int back(){
        if(this->empty()){
            cout<<"EMPTY!!!"<<endl;
            return 0;
        }
        return this->a[this->rearIdx];
    }

};

int main(){

    Queue q1;

    for(int i=0; i<10; i++){
        q1.push((i+1)*20);
    }
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.push(8);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.pop();
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.pop();
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.pop();
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.push(12);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.push(18);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.push(88);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    q1.push(90);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;


    return 0;
}