#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <char> st;
    int N, cnt = 0;
    string input;
    cin >> N;

    for(int i = 0;i<N;i++){
        cin >> input;
        st.push(input[0]);
        for(int j = 1;j<input.length();j++){
            if(!st.empty() && (input[j] == st.top())){
                st.pop();
            }
            else{
                st.push(input[j]);
            }
        }
        if(st.empty()){
            cnt++;
        }else{
            while(!st.empty()){
                st.pop();
            }
        }
    }
    cout << cnt;
}