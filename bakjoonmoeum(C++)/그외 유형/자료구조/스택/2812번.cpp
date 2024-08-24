#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;
    int N, K, cnt = 0;
    string input, res;
    cin >> N >> K;
    cin >> input;

    st.push(input[0]-'0');
    for(int i = 1;i<N;i++){
        if(cnt == K){
            st.push(input[i]-'0');
        }else{
            while(cnt != K && !st.empty() &&
            (st.top() < input[i]-'0')){
                st.pop();
                cnt++;
            }
            st.push(input[i]-'0');
        }
    }
    while(cnt < K){
        st.pop();
        cnt++;
    }
    while(!st.empty()){
        res += to_string(st.top());
        st.pop();
    }
    for(int i = res.length()-1;i>=0;i--){
        cout << res[i];
    }
}
/*
여러 비슷한 유형들이 많다.
모노톤 스택을 이용한 하나의 사례
*/