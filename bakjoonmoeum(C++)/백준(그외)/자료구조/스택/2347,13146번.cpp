#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    long long res = 0LL;
    stack <int> st;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> input;
        if(st.empty() || !st.empty() && st.top() > input) st.push(input);
        else if(st.top() == input) continue;
        else if(st.top() < input){
            res += (input - st.top())*1LL;
            while(!st.empty() && st.top() <= input){
                st.pop();
            }
            st.push(input);
        }
    }
    while(st.size() > 1){
        int tmp = st.top();
        st.pop();
        res += (st.top() - tmp)*1LL;
    }
    cout << res;
}
/*
1. 스택이 비었을 경우 단순 삽입 (값 형태로)

2. st.top과 input의 값이 같으면 삽입하지 않는다.

3. st.top보다 input의 값이 높으면 먼저 연산횟수  += (input-st.top) 하고,
st.top의 값이 input보다 높을때까지 st.pop()한다.

4. st.top보다 input의 값이 낮으면 단순 삽입한다.
*/