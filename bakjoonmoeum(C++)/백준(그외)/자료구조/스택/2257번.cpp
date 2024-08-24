#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    stack <int> st;
    int sum = 0;
    cin >> input;

    for(int i = 0;i<input.length();i++){

        if(input[i] == 'C' || input[i] == 'H' || input[i] == 'O'){
            switch(input[i]){
                case 'C': st.push(12); break;
                case 'H': st.push(1); break;
                case 'O': st.push(16); break;
            }
        }else if(isdigit(input[i])){
            int num = st.top();
            st.pop();
            num *= input[i] - '0';
            st.push(num);
        }else if(input[i] == '('){
            st.push(-1);
        }else if(input[i] == ')'){
            while(st.top() != -1){
                int num = st.top();
                st.pop();
                if(st.top() == -1){
                    st.pop();
                    st.push(num);
                    break;
                }
                num += st.top();
                st.pop();
                st.push(num);
            }
            if(st.top() == -1){
                st.pop();
            }
        }
    }
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum;
}
/*
1. H,C,O는 1, 12, 16으로 치환한 후 스택에 삽입한다.

2. input[i]가 숫자면 스택 상단 값을 곱해준 값을 삽입한다.

3. //가 왼쪽 괄호면 -1로 치환한 후 삽입한다.

4. //가 오른쪽 괄호면 -1을 만날때까지 스택 요소들을 더해주면서
pop해준다.

5. 스택에 남아있는 값들은 모두 더해준 후 결과를 출력한다.
*/