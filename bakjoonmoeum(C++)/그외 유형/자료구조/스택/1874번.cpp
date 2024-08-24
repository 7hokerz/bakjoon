#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    queue <int> q;
    stack <int> st;
    int N, input;
    string res;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        q.push(input);
    }
    for(int i = 0;i<N;i++){
        st.push(i+1);
        res += '+';
        while(!q.empty() &&!st.empty() && q.front() == st.top()){
            q.pop(); st.pop();
            res += '-';
        }
    }
    if(!q.empty()){
        cout << "NO" <<'\n';
        return 0;
    }else{
        for(int i = 0;i<res.length();i++){
            cout << res[i] << '\n';
        }
    }
}
/*
목표 수열을 큐에 넣고 최초 수열은 스택에 넣는다(+).
스택 상단 값과 qfront값이 같을 동안 지우고 -를 출력한다.
이 과정을 거치면 가능한 경우는 큐와 스택이 모두 비고, 그렇지 않은 경우는 요소가 남아있게 된다.
*/