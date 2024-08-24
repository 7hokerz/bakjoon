#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;
    string input;
    int sum = 0;
    int res = 0;
    cin >> input;
    for(int i = 0;i<input.length();i++){
        //부호를 발견하면 부호 전까지 값을 스택에 삽입하고 제거한다.
        if(input[i] == '+'){
            st.push(stoi(input.substr(0,i+1)));
            input.erase(0, i);
            i=0;
        }else if(input[i] == '-'){
            st.push(stoi(input.substr(0,i+1)));
            st.push(-100000);
            input.erase(0, i+1);
            i=0;
        }
    }
    //마지막 값은 값 뒤에 부호가 없어서 남게 되므로 마지막 값을 따로 넣어준다.
    if(input.length()>0) st.push(stoi(input.substr(0)));
    while(!st.empty()){
        if(st.top() == -100000){
            res -= sum;
            sum = 0;
        }else{
            sum += st.top();
        }
        st.pop();
    }
    res += sum;
    cout << res;
}
/*
최솟값을 구하는 방법은 -가 나오면 거기서부터
괄호를 씌워주기? -가 나오면 계속해서 왼쪽 괄호를 씌운다.
왼쪽 괄호는 -100000로 취급하여 넣자.
(-1로 넣으려 했으나 수 자체가 -1이 나오기도 하므로 안됨)
스택을 이용하는 것도 좋을듯
*/