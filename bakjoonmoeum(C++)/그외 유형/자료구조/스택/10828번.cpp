#include <iostream>
#define MAX_STACK_SIZE 1000000
using namespace std;

class stack{
    int top;
    int data[MAX_STACK_SIZE];
public:
    stack(){//기본 생성자
        top = -1;
    }

    int is_empty(){
        return (top == -1);
    }

    int is_full(){
        return (top == (MAX_STACK_SIZE-1));
    }

    void push(int item){
        if(is_full()) return;
        else data[++(top)] = item;
    }

    void pop(){
        if(is_empty()){
            cout << -1 << '\n';
        }
        else{cout << data[top--] << '\n';}
    }

    void size(){
        if(is_empty()) {cout << 0 << '\n';}
        else {cout << (top+1) << '\n';}
    }

    void peek(){
        if(is_empty()){cout << -1 << '\n';}
        else cout << data[top] << '\n';
    }
};

int main(){
    int N;
    string com;
    int ps;
    int count = 0;
    cin >> N;
    stack s;

    while(count < N){
        cin >> com;
        if(com == "push"){
            cin >> ps;
            s.push(ps);
        }
        if(com == "pop"){
           
            s.pop();
        }
        if(com == "size"){
            s.size();
        }
        if(com == "empty"){
            cout << s.is_empty() << '\n';
        }
        if(com == "top"){
            s.peek();
        }
        count++;
    }
}