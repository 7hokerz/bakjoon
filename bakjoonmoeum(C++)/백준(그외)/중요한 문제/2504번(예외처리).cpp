#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;
    string input;
    int total = 0;
    cin >> input;

    for(int i = 0;i<input.length();i++){
        if(input[i] == '('){
            st.push(-2);
        }
        else if(input[i] == '['){
            st.push(-3);
        }
        else if(input[i] == ')'){
            if(st.empty() || st.top() == -3){
                //스택이 비었거나 짝이 맞지 않는 괄호
                cout << 0;
                return 0;
            }else{
                int cnt = 0;
                while(st.top() != -2 && st.top() != -3){
                    //열린 괄호 찾기
                    cnt += st.top();
                    st.pop();
                    if(st.empty()){
                        //괄호를 찾지 못하고 스택이 빈 경우
                        cout << 0;
                        return 0;
                    }
                }
                if(st.top() == -2){
                    if(cnt == 0) cnt += 2;
                    else cnt *= 2;
                    
                }else if(st.top() == -3){
                    //짝이 맞지 않는 괄호
                    cout << 0;
                    return 0;
                }
                st.pop();
                st.push(cnt);
            }
        }
        else if(input[i] == ']'){
            if(st.empty() || st.top() == -2){
                //스택이 비었거나 짝이 맞지 않는 괄호
                cout << 0;
                return 0;
            }else{
                int cnt = 0;
                while(st.top() != -2 && st.top() != -3){
                    //열린 괄호 찾기
                    cnt += st.top();
                    st.pop();
                    if(st.empty()){
                        //괄호를 찾지 못하고 스택이 빈 경우
                        cout << 0;
                        return 0;
                    }
                }
                if(st.top() == -2){
                    //짝이 맞지 않는 괄호
                    cout << 0;
                    return 0;
                    
                }else if(st.top() == -3){
                    if(cnt == 0) cnt += 3;
                    else cnt *= 3;
                }
                st.pop();
                st.push(cnt);
            }
        }
    }
    while(!st.empty()){
        if(st.top() == -2 || st.top() == -3){
            //괄호가 제거되지 않은 경우(갯수가 맞지 않는다는 것)
            cout << 0;
            return 0;
        }
        total += st.top();
        st.pop();
    }
    cout << total;
}
/*

열린 괄호는 -2, 열린 대괄호는 -3으로 잡고 스택에 삽입
닫힌 괄호가 만나면 괄호 하나를 지우고 2를 삽입시킨다.

예외 처리를 세세하게 잘 해야 하는 문제

예외
1. 소괄호가 대괄호가 잘못 만나면 0을 리턴(열 닫)
2. **괄호의 짝 수가 맞지 않으면 0 리턴
(대충 보고 했다고 생각해도 안되는 부분들이 존재할 수 있다...)
(방심하지 말고 코드를 많이 항상 돌려보자)

(()[[]])([]) 28

[][]((]) 0

*/
