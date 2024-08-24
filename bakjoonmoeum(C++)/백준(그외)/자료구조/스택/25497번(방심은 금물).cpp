#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <char> st1;
    stack <char> st2;
    int N, teq = 0;
    string input;
    cin >> N >> input;

    for(int i = 0;i<N;i++){
        if(input[i] == 'S'){
            st1.push(input[i]);
        }else if(input[i] == 'L'){
            st2.push(input[i]);
        }
        else if(input[i] == 'K'){
            if(!st1.empty() && input[i] == 'K' && st1.top() == 'S'){
                teq++;
                st1.pop();
            }else{
                break;
            }
        }else if(input[i] == 'R'){
            if(!st2.empty() && input[i] == 'R' && st2.top() == 'L'){
                teq++;
                st2.pop();
            }else{
                break;
            }
        }
        else{
            teq++;
        }
    }
    cout << teq;
}
/*
문제를 잘 읽고 예외 조건을 잘 살펴보자...!
*/