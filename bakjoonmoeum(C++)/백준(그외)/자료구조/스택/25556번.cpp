#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st[4];
    int N, input, check = 0;
    cin >> N;

    for(int i = 0;i<N;i++){
        cin >> input;
        for(int j = 0;j<4;j++){
            if(!st[j].empty() && (st[j].top() < input)){
                st[j].push(input);
                check++;
                break;
            }else if(st[j].empty()){
                st[j].push(input);
                check++;
                break;
            }
        }
        if(check == 0){
            cout << "NO";
            return 0;
        }else{
            check = 0;
        }
    }
    cout << "YES";
}
/*
작은 수가 위로 위치하게 넣어야 함 즉 스택 최초값>상단 값. 
만약 저 규칙이 지켜지지 않으면 청소 불가

10
4 3 6 7 8 9 10 2 1 5 YES

5
5 4 3 2 1 NO
*/