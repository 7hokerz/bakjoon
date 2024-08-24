#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <char> st;
    stack <char> tmp;
    string str, bomb, cp;
    cin >> str >> bomb;
    for(int i = 0;i<str.length();i++){
        st.push(str[i]);
        if(!st.empty() && st.top() == bomb.at(bomb.length()-1)){
            for(int i = 0;i<bomb.length();i++){
                if(st.empty()) break;
                tmp.push(st.top());
                st.pop();
            }
            while(!tmp.empty()){
                cp += tmp.top();
                tmp.pop();
            }
            if(bomb.compare(cp) != 0) {
                for(int i = 0;i<cp.length();i++){
                    st.push(cp[i]);
                }
            }
            cp = "";
        }
    }
    if(st.empty()){cout << "FRULA";}
    else{
        while(!st.empty()){
            cp += st.top();
            st.pop();
        }
        for(int i = cp.length()-1;i>=0;i--){
            cout << cp[i];
        }
    }
}
/*
왜인지 모르겠지만 며칠을 고민해도 방법을 모르겠어서 결국 다른 사람 블로그를 참고했다.

방법:
1. 스택에 문자를 계속 담다가 폭발 문자열의 끝을 발견하면 그 문자까지 담고 폭발 문자열 길이만큼
스택에서 빼낸다.
2. 스택에서 빼낸 후, 문자열을 폭발 문자열과 비교하여 같지 않은 경우에 다시 순서대로 스택에 담는다.
(같은 경우는 스택에 넣지 않고 그대로 진행)
3. 위 과정을 반복해서 과정이 끝난 후 스택에 남아있는 문자들을 스트링에 담는다.
4. 스트링에 담긴 순서는 반대이므로 끝부터 차례대로 출력해준다.

아이디어 자체는 간단한데 이걸 왜 못 떠올렸을까....
*/