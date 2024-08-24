#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <pair<int,int>> st;
    stack <pair<int,int>> res;
    int N, input;
    long long total = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        st.push({input,i+1});
    }

    while(!st.empty()){
        int cnt = 0;
        while(!res.empty() && st.top().first > res.top().first){
            res.pop();
            cnt++;
        }
        if(cnt > 0){
            if(res.empty()) total += N - st.top().second*1LL;
            else total += res.top().second*1LL - st.top().second - 1;
        } 
        res.push(st.top());
        st.pop();
    }
    cout << total;
}
/*
구현이고 뭐고 아무 문제 없는데 long long 안붙여서 시간 낭비...
*/