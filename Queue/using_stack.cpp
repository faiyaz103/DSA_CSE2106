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
    stack<int> primary, secondary;

public:
    Queue(){}

    // check if empty
    bool empty(){
        if(primary.empty() && secondary.empty()) return true;
        return false;
    }

    // return size
    int size(){
        return primary.size()+secondary.size();
    }

    // push
    void push(int val){
        while(!secondary.empty()){
            primary.push(secondary.top());
            secondary.pop();
        }
        primary.push(val);
    }

    // pop
    void pop(){
        if(this->empty()){
            cout<<"EMPTY!!!"<<endl;
            return;
        }

        while(!primary.empty()){
            secondary.push(primary.top());
            primary.pop();
        }
        secondary.pop();
    }

    // front
    int front(){
        if(this->empty()){
            cout<<"EMPTY!!!"<<endl;
            return;
        }

        while(!primary.empty()){
            secondary.push(primary.top());
            primary.pop();
        }
        return secondary.top();
    }
    
    // back
    int back(){
        if(this->empty()){
            cout<<"EMPTY!!!"<<endl;
            return;
        }
        
        while(!secondary.empty()){
            primary.push(secondary.top());
            secondary.pop();
        }
        return primary.top();
    }

};

int main(){

    Queue q1;

    for(int i=0; i<10; i++){
        cout<<"Push: "<<(i+1)*20<<endl;
        q1.push((i+1)*20);
    }
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;
    
    cout<<"Push"<<endl;
    q1.push(8);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Pop"<<endl;
    q1.pop();
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Pop"<<endl;
    q1.pop();
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Pop"<<endl;
    q1.pop();
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Push"<<endl;
    q1.push(12);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Push"<<endl;
    q1.push(18);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Push"<<endl;
    q1.push(88);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;

    cout<<"Push"<<endl;
    q1.push(90);
    cout<<"Front: "<<q1.front()<<endl;
    cout<<"Back: "<<q1.back()<<endl;
    cout<<"Empty: "<<q1.empty()<<endl;
    cout<<"Size: "<<q1.size()<<endl;
    cout<<endl;


    return 0;
}