#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;
    stack <int> tmp;
    int N, input;
    cin >> N;
    int res[N];
    for(int i = 0;i<N;i++){
        cin >> input;
        st.push(input);
    }

    for(int i = 0;i<N;i++){
        while(!st.empty() && 
        !tmp.empty() && (st.top() >= tmp.top())){
            tmp.pop();
        }
        if(tmp.empty()) res[i] = -1;
        else res[i] = tmp.top();
        
        if(st.empty()) continue;
        else{
            tmp.push(st.top());
            st.pop();
        }
    }

    for(int i = N-1;i>-1;i--){
        cout << res[i] << ' ';
    }
}   
/*
2493번과 같은 모노톤 스택을 이용한 문제이다.
다른 점은 왼쪽을 확인하는 2493번과 달리
오른쪽을 확인한다는 점이다.
이 때문에 스택 하나로만 풀긴 불가능하다고 생각해서
두 스택으로 풀고 값을 마지막부터 출력한다.

중요! N을 받기 전에 미리 N배열을 선언하지 말고
N을 받은 후 선언하자!
*/