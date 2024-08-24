#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <char> st;//stack <char> st[2];
    stack <char> chk;
    deque <char> dq;
    string A, T, tmp;
    cin >> A >> T;
    for(int i = 0;i<T.length();i++){
        dq.push_back(T[i]);
    }
    bool stat = false;
    
    while(!dq.empty()){
        for(int i = 0;!dq.empty();i++){//처음 등장하는 A를 찾아 삭제(false)
            st.push(dq.front());
            dq.pop_front();
            if(!st.empty() && st.top() == A.at(A.length()-1)){
                for(int j = 0;j<A.length();j++){
                    if(st.empty()) break;
                    chk.push(st.top());
                    st.pop();
                }
                while(!chk.empty()){
                    tmp += chk.top();
                    chk.pop();
                }
                if(tmp.compare(A) == 0){
                    while(!st.empty()){
                        dq.push_front(st.top());
                        st.pop();
                    }
                    tmp = "";
                    stat = !stat;
                    break;
                }else{
                    for(int i = 0;i<tmp.length();i++){
                        st.push(tmp[i]);
                    }
                }
                tmp = "";
            }
        }
        if(!stat) break;
        for(int i = 0;!dq.empty();i++){//마지막에 등장하는 A를 찾아 삭제(true)
            st.push(dq.back());
            dq.pop_back();
            if(!st.empty() && st.top() == A.at(0)){
                for(int j = 0;j<A.length();j++){
                    if(st.empty()) break;
                    tmp += st.top();
                    st.pop();
                }
                if(tmp.compare(A) == 0){
                    while(!st.empty()){
                        dq.push_back(st.top());
                        st.pop();
                    }
                    tmp = "";
                    stat = !stat;
                    break;
                }else{
                    for(int i = tmp.length()-1;i>=0;i--){
                        st.push(tmp[i]);
                    }
                }
                tmp = "";
            }
        }
        if(stat) break;
    }

    while(!st.empty()){
        if(stat){
            dq.push_back(st.top());
            st.pop();
        }else{
            dq.push_front(st.top());
            st.pop();
        }
    }
    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }
}
/*2개의 스택을 사용하여 둘 다 앞 뒤로 탐색하는데 3가지 경우 존재(문제의 알고리즘을 지킨다는 하에)
    1. 앞에서부터 탐색한 스택이 끝자리를 찾은 경우
    2. 뒤에서부터 탐색한 스택이 앞자리를 찾은 경우
    3. 덱이 비는 경우
    (처음 시작했다고 가정)
    1의 경우, 바로 확인하면 된다.
    2의 경우, 만약 앞에서부터 탐색한 스택이 찾지 못했다면 뒤 스택의 값을 확인하여 비교한다.
    만약 앞 스택이 찾았다면 확인 후, 맞는 경우 바로 뒤 스택의 값을 확인하여 비교해주면 된다.틀린 경우는 앞 스택이 탐색을 계속한다.
    3의 경우, 뒤 스택의 요소를 모두 앞 스택으로 보내서 확인시킨다. 
*/