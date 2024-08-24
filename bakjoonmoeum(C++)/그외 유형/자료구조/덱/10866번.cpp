#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 10001
typedef int element;
class Deque{
    int front;
    int back;
    element data[MAX_SIZE];
public:
    Deque(){
        front = 0;
        back = 0;
    }
    void push_front(element item){
        data[(front-- + MAX_SIZE) % MAX_SIZE] = item;
    }
    void push_back(element item){
        data[(++back + MAX_SIZE) % MAX_SIZE] = item;
    }
    void pop_front(){
        if(empty()) cout << -1 << endl;
        else cout << data[(++front + MAX_SIZE) % MAX_SIZE] << endl;
    }
    void pop_back(){
        if(empty()) cout << -1 << endl;
        else cout << data[(back-- + MAX_SIZE) % MAX_SIZE] << endl;
    }
    void size(){
        cout << back - front << endl;
    }
    int empty(){
        if(front == back) return 1;
        else return 0;
    }
    void front_peek(){
        if(empty()) cout << -1 << endl;
        else cout << data[(front + 1 + MAX_SIZE) % MAX_SIZE] << endl;
    }
    void back_peek(){
        if(empty()) cout << -1 << endl;
        else cout << data[(back + MAX_SIZE) % MAX_SIZE] << endl;
    }
};

int main(){
    int N;//명령어의 개수
    string input;//명령어를 담을 스트링
    int num;//주어지는 정수
    Deque dq;
    cin >> N;
    
    for(int i = 0;i<N;i++){
        cin >> input;
        if(input == "push_front"){
            cin >> num;
            dq.push_front(num);
        }
        if(input == "push_back"){
            cin >> num;
            dq.push_back(num);
        }
        if(input == "pop_front") dq.pop_front();
        if(input == "pop_back") dq.pop_back();
        if(input == "front") dq.front_peek();
        if(input == "back") dq.back_peek();
        if(input == "empty") cout << dq.empty() << endl;
        if(input == "size") dq.size();
    }
}