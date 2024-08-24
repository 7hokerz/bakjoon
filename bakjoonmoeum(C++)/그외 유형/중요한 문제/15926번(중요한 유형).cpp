#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;
    string input;
    int N, sum = 0, result = 0;
    cin >> N >> input;
    for(int i = 0;i<N;i++){
        if(input[i] == '('){
            st.push(-1);
        }else if(input[i] == ')'){
            if(!st.empty() && st.top() == -1){
                st.pop();
                st.push(2);
            }else{
                while(!st.empty()){
                    if(st.top() == -1 || st.top() == -2){
                        break;
                    }else{
                        sum += st.top();
                        st.pop();
                    }
                }
                if(!st.empty()&&st.top() == -1){
                    st.pop();
                    st.push(sum+2);
                }else{
                    if(sum != 0) st.push(sum);
                    st.push(-2);
                }
                sum = 0;
            }
        }
    }
    while(!st.empty()){
        
        if(st.top() != -1 && st.top() != -2){
            sum += st.top();
        }else{
            result = (sum>result)?sum:result;
            sum = 0;
        }
        st.pop();
    }
    result = (sum>result)?sum:result;
    cout << result;
}
/*
오큰수와 오등큰수?
이따가 다시 풀이를 분석하고 요약하자.

우선 처음에 풀었다가 틀린 이유는
(()())와 같은 식이 있을 때 6이 아닌 4가 나왔다.
아마도 왼쪽을 -1, 오른쪽을 -2로 했는데 
-1과 -2를 제외하고 sum +=하고 -1이나 -2는 애초에 생략시켜서
인 듯 하다.
즉 바깥쪽의 괄호가 포함이 안되는 것이다.

많은 고민 끝에 문제를 풀어냈다.

분석:
1. 왼쪽 괄호면 스택에 -1을 삽입한다.

2. 오른쪽 괄호면 우선 스택이 비어있지 않으면 
-1또는 -2. 즉 괄호가 보이면 멈추고 아니면 
해당 탑 값을 sum +=한다.

2-1. 그 후 스택의 상단 값이 -1이면 
위의 (()())와 같이 바깥쪽이 짝을 만난 것이므로 
-1을 제거한 후 sum+2한 값을 스택에 삽입해준다.

2-2. 스택이 비어있거나 -2라면 
(sum != 0) sum을 삽입 후 -2를 삽입한다.

3. 스택에 남아있는 값을 확인하는데, 상단 값이 -1이나 -2가
아닐때까지 실 값을 합해주고 경계(-1,-2)를 만나면
result와 sum 중 더 큰 값을 result에 넣고 sum을 초기화한다.
그 후 st.pop()한다.

4. sum이 남아있을 수 있으므로 마지막으로 값을 비교하여 더 큰 값을
result에 대입해준다.

(()())
(()()(

-1 -1)
-1 2
-1 2 -1)
-1 2 2 )
*/