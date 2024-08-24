#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque <char> left;
    deque <char> right;
    string input;
    int M;//명령어의 개수
    cin >> input;
    for(int i = 0;i<input.length();i++){//문자열을 left 스택에 삽입한다
        left.push_back(input[i]);
    }
    cin >> M;

    for(int i = 0;i<M;i++){
        cin >> input;
        if(input == "P"){
            cin >> input;
            left.push_back(input[0]);
        }else if(input == "L"){
            if(left.empty()) continue;
            else{
                right.push_back(left.back());
                left.pop_back();
            }
        }else if(input == "D"){
            if(right.empty()) continue;
            else{
                left.push_back(right.back());
                right.pop_back();
            }
        }else if(input == "B"){
            if(left.empty()) continue;
            else{
                left.pop_back();
            }
        }
    }

    while(!left.empty()){
        cout << left.front() ;
        left.pop_front();
    }
    while(!right.empty()){
        cout << right.back();   
        right.pop_back(); 
    }
}
/*
left, right 스택을 커서의 기준으로 두고 만든다.
P $: $라는 문자를 커서 왼쪽에 추가함
L: 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D: 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B: 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 
실제로 커서의 오른쪽에 있던 문자는 그대로임

abcd
3
P x
L
P y

abc
9
L
L
L
L
L
P x
L
B
P y

dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z

*/