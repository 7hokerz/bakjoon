#include <iostream>
#include <deque>
#include <stack>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    if(a>b) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <long long> plus;
    deque <long long> minus;
    stack <long long> st[2];
    stack <long long> st2[2];
    int n;
    long long input;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> input;
        if(input < 0) minus.push_back(input*1LL);
        else if(input >= 0) plus.push_back(input*1LL);
    }
    sort(plus.begin(),plus.end());
    sort(minus.begin(),minus.end(), comp);

    if(plus.size() > 3){
        st[0].push(plus.front()); plus.pop_front();
        st[1].push(plus.front()); plus.pop_front();
        int size = plus.size();

        for(int i = 0;i<(size/2)-1;i++){
            long long first = plus.front();
            plus.pop_front();
            
            if(st[0].top()*first + st[1].top()*plus.front() > st[0].top()*plus.front() + st[1].top()*first){
                st[0].push(first);
                st[1].push(plus.front()); plus.pop_front();
            }else{
                st[0].push(plus.front()); plus.pop_front();
                st[1].push(first);
            }
        }
    }else if(plus.size() == 3){
        plus.push_back(plus.front());
        plus.pop_front();
    }

    if(minus.size() > 3){
        st2[0].push(minus.front()); minus.pop_front();
        st2[1].push(minus.front()); minus.pop_front();
        int size = minus.size();

        for(int i = 0;i<(size/2)-1;i++){
            long long first = minus.front();
            minus.pop_front();
            
            if(st2[0].top()*first + st2[1].top()*minus.front() < st2[0].top()*minus.front() + st2[1].top()*first){
                st2[0].push(first);
                st2[1].push(minus.front()); minus.pop_front();
            }else{
                st2[0].push(minus.front()); minus.pop_front();
                st2[1].push(first);
            }
        }
    }else if(minus.size() == 3){
        int back = minus.back();
        minus.pop_back();
        int back2 = minus.back();
        minus.pop_back();
        minus.push_back(back);
        minus.push_front(back2);
    }

    while(!st[0].empty()){
        plus.push_front(st[0].top());
        st[0].pop();
    }
    while(!st[1].empty()){
        plus.push_back(st[1].top());
        st[1].pop();
    }
    while(!st2[0].empty()){
        minus.push_front(st2[0].top());
        st2[0].pop();
    }
    while(!st2[1].empty()){
        minus.push_back(st2[1].top());
        st2[1].pop();
    }

    if(!plus.empty() && plus.front() > plus.back()){
        while(!plus.empty()){
            cout << plus.front() << ' ';
            plus.pop_front();
        }
    }else{
        while(!plus.empty()){
            cout << plus.back() << ' ';
            plus.pop_back();
        }
    }
    if(!minus.empty() && minus.front() > minus.back()){
        while(!minus.empty()){
            cout << minus.front() << ' ';
            minus.pop_front();
        }
    }else{
        while(!minus.empty()){
            cout << minus.back() << ' ';
            minus.pop_back();
        }
    }
}
/*
두 수의 차이가 아주 적게 날 수록 곱이 커진다는 법칙이 존재함.

단 음수가 등장하면 이야기는 달라진다.
음수와 양수를 따로 담아 최댓값으로 정렬 후 -와+가 만나는 곳을 최소가 되도록 붙여야 한다.

*/