#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x, y;
    cin >> n;
    stack <pair<int,int>> st;
    for(int i = 0;i<n;i++){
        cin >> x >> y;
        if(!st.empty()){
            if(st.top().second < x){//범위 밖의 선
                st.push({x,y});
            }else if(st.top().first <= x && st.top().second >= y){//포함되는 선
                continue;
            }else{//x 또는 y가 선 밖이면 스택 값 변경
                if(st.top().second < y){
                    st.top().second = y;
                }
                if(st.top().first > x){
                    st.top().first = x;
                }
            }
        }else st.push({x,y});
    }
    long long sum = 0;
    while(!st.empty()){
        sum += (st.top().second - st.top().first);
        st.pop();
    }
    cout << sum;
}
/*
*/