#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
여는 괄호와 닫는 괄호가 짝이 맞아야 안정적인 괄호이다.(항상 짝수로 주어짐)
방법
1. 스택에 괄호를 1개씩 넣는다.
2. 1개씩 넣을때마다 짝이 맞는지 검사하여 짝이 맞으면 제거한다.
3. 남은 괄호의 개수를 토대로 최소 연산의 수를 출력한다.
4. 문자에 행할 수 있는 연산은 여는 괄호를 닫는 괄호로 바꾸거나, 그 반대거나 두 개 이다.
*/
int main(){
    stack <char> st;
    string br;
    char ch;
    int count = 1, result = 0;//시행한 횟수

    while(1){
        cin >> br;
        if(*(br.begin()) == '-'){
            break;
        }
        for(int i = 0;i<br.length();i++){ 
            if((br[i] == '}') && (!st.empty()) && (st.top() == '{')){//스택이 비어있지 않고 상단에 '{'가 있으면 '{'를 제거한다.
                st.pop();
            }else{//그 외에는 요소를 삽입한다.
                st.push(br[i]);
            }
        }
        //경우의 수 3가지 {{ }} }{ (항상 길이는 짝수이므로)
        while(!st.empty()){
            ch = st.top();
            st.pop();
            if(st.top() == ch){
                st.pop();
                result++;
            }else{
                st.pop();
                result += 2;
            }
        }
        cout << count << ". "<< result << '\n';
        count++;
        result = 0;
    }
}