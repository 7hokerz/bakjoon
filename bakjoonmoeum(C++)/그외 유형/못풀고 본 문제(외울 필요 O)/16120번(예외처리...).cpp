#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <char> st;
    string input;
    cin >> input;

    for(int i = 0;i<input.length();i++){
        if(input[0] == 'A' ||//중요했던 예외처리...
        (input[i-1] == 'A' && input[i] == 'A')){
            cout << "NP";
            return 0;
        }
        if(st.size() > 2 && st.top() == 'A' &&
        input[i] == 'P'){
            st.pop();
            st.pop();
        }else{
            st.push(input[i]);
        }
    }
    if(st.size() == 1){
        cout << "PPAP";
    }else{
        cout << "NP";
    }
}
/*
도저히 못찾겠어서 다른 사람 풀이를 참고함.

중요한 것은 A의 존재였다.
PPAP >> P가 성립하려면 
A앞에는 P문자 2개, A뒤에는 P문자 1개가 반드시 있어야 한다.
그래서 내가 추가로 생각한 것은
A까지 넣고 바로 다음 문자 차례일 때 조건을 검사하는 것이다.
즉 A가 먼저 들어갈일은 거의 없으므로 size > 2이고 
(왜냐하면 PPA라고 치면 최소 3글자가 있어야 해서)
top이 A일때, input[i]가 P면 PPAP 글자인 것이다.
그 후 이 PPAP를 P로 바꿔 스택에 삽입하고 과정을 반복한다.

여기서 빼먹은 예외조건!
A가 맨 처음이나 2번째에 들어갈 수도 있다.
그래서 input[0] == 'A'이거나(문자열 첫번째에 있는 것)
A가 연속하는 조건을 예외처리하였더니 풀렸다.

예외처리뭐고 자시고 일단 어떻게 풀지 생각하기 참 어렵다...


PPPAPAP PPAP
PPAPAPP NP

(다른 사람 것 참고...)
P가 나오면 스택에 계속 쌓다가
A가 나오면
st.size및 input[i+1] == p확인
st.size가 2이상이면서 input[i+1] == p이면
pop 1번
i += 2(a와 p를 건너뛴다.)
과정 반복...
st.size가 1이면 PPAP 아니면 NP

또는 

st.size() >2 && st.top == A && input[i] == P이면
st.pop 2번
과정 반복...

처음 생각한 풀이(시간 초과)
string input, part, mid, res;
    int len;
    cin >> input;
    res = input;

    while(1){
        for(int i = 0;i<res.length();i++){
            int j = i;
            while(q.size() < 4){
                q.push(res[j]);
                j++;
            }
            while(!q.empty()){
                part += q.front();
                q.pop();
            }
            if(part == "PPAP"){
                mid += 'P';
                i += 3;
            }else{
                mid += res[i];
            }
            part = "";
        }
        if(res.compare(mid) != 0){
            res = mid;
            mid = "";
        }
        else{
            if(res == "PPAP" || res == "P"){
                cout << "PPAP";
            }else{
                cout << "NP";
            }
            return 0;
        }
    }
*/