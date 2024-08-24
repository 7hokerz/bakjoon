#include <iostream>
#define MAX_STACK_SIZE 1000000//계속 틀렸던 이유가 size가 부족해서...ㅋㅋㅋ
using namespace std;

//typedef int element;
class stack{
    long long top;
    unsigned long long data[MAX_STACK_SIZE];
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
            return;
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
    cin >> N;
    stack s;

    int com;
    for(int i = 0;i<N;i++){
    cin >> com;
    cin.tie(NULL);
        switch(com){
        case 1:
            int push;
            cin >> push;
            s.push(push);
            continue;
        case 2:
            s.pop();
            continue;
        case 3:
            s.size();
            continue;
        case 4:
            cout << s.is_empty() << '\n';
            continue;
        case 5:
            s.peek();
            continue;
        }
    }
}