#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <int> buffer;
    int N,input;//버퍼의 크기, 입력값
    cin >> N;

    while(1){
        cin >> input;
        if(input == -1) break;
        if(!buffer.empty() && input == 0){
            buffer.pop();
        }else if(buffer.size() >= N){
            continue;
        }else if(input != 0){
             buffer.push(input);
        }
    }
    if(buffer.empty()) cout << "empty" << '\n';
    while(!buffer.empty()){
        cout << buffer.front() << ' ';
        buffer.pop();
    }
}
/*
양의 정수: 버퍼가 처리해야할 패킷
0: 패킷 하나를 처리했다는 뜻
-1: 입력의 끝
*/