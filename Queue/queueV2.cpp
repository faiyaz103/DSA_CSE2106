/**
 * Queue Operations
 * - front(): Access the front element of the queue.
 * - back() : Access the end element of the queue.
 * - empty(): Check whether a queue is empty or not.
 * - size() : Returns the number of elements in the queue.
 * - push() : Adding an element at the back of the queue.
 * - pop()  : Delete the front element of the queue.
 */

/**
 * The Flaw: "False Overflow"
In a linear array queue, every time you push(), rearIdx moves forward. Every time you pop(), frontIdx moves forward.

Imagine this scenario with your code (maxSize = 10):
You push() 10 elements. Your array is now full. (frontIdx = 0, rearIdx = 9).
You pop() 5 elements. The first 5 slots of your array are now completely empty. (frontIdx = 5, rearIdx = 9).
You try to push() another element.
Your overflow() function checks: if (this->rearIdx >= maxSize - 1). Since rearIdx is 9, it throws OVERFLOW!!!. Even though there are 5 perfectly empty slots at the beginning of your array, your queue thinks it is full and prevents you from adding data.

The Solution: Circular Queue
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
        if(this->rearIdx>=maxSize-1) return true;
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

        return (this->rearIdx-this->frontIdx)+1;
    }

    // push
    void push(int val){
        if(this->overflow()) throw "OVERFLOW!!!";
        else if(this->empty()){
            this->frontIdx=0;
        }

        this->rearIdx+=1;
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
        this->frontIdx+=1;

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
    
    q1.push(12);
    q1.push(2);
    q1.push(8);
    cout<<"Front: "<<q1.front()<<endl;
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


    return 0;
}