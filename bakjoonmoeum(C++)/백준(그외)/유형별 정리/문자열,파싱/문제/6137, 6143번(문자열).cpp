#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    char input;
    cin >> N;
    deque <char> dq, res;
    for(int i = 0;i<N;i++){
        cin >> input;
        dq.push_back(input);
    }   
    for(int j = 0;j<N;j++){
        if(dq.front() - '0' > dq.back() - '0'){
            res.push_back(dq.back());
            dq.pop_back();
        }else if(dq.front() - '0' < dq.back() - '0'){
            res.push_back(dq.front());
            dq.pop_front();
        }else{
            bool chk = false;
            for(int i = 0;i<dq.size()/2;i++){//<</2를 하냐 안하냐의 차이가 존재함.
                if(dq[i] - '0' < dq[dq.size()-1-i] - '0'){
                    res.push_back(dq.front());
                    dq.pop_front();
                    chk = !chk;
                    break;
                }else if(dq[i] - '0' > dq[dq.size()-1-i] - '0'){
                    res.push_back(dq.back());
                    dq.pop_back();
                    chk = !chk;
                    break;
                }
            }
            if(!chk){
                res.push_back(dq.back());
                dq.pop_back();
            }
        }
    }
    for(int i = 0;i<N;i++){
        if(i > 0 && i % 80 == 0) cout << '\n';
        cout << res[i];
    }
}
/*
6143번은 나중에 접미사 배열을 이용하여 다시 한 번 풀어보길 권장

양 쪽의 문자 중 사전순으로 앞서는 것을 빼고 T의 마지막에 삽입
양 문자열이 같은 경우 다음 문자열 중 더 사전순으로 앞서는 것이 있는 곳을 빼자.

6
ACDBCB


A
CDBCB

AB
CDBC

ABC
CDB

ABCB
CD

ABCBC
D

ABCBCD



*/