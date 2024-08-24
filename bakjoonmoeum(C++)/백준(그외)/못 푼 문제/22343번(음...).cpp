#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    string input;
    cin >> T;
    for(int i = 0;i<T;i++){
        int A = 0,B = 0;
        stack <int> st;
        cin >> input;
        
        for(int j = 0;j<input.length();j++){
            int sum = 0;
            if(input[j] == '(') st.push(-1);
            else if(input[j] == ')'){
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }else{
                    while(!st.empty() && st.top() != -1){
                        sum += st.top();
                        st.pop();
                    }
                    if(st.top() == -1){
                        st.pop();
                        st.push(sum*2);
                    }
                }
            }
        }
        while(!st.empty()){
            A += st.top();
            st.pop();
        }
        
        cin >> input;
        for(int j = 0;j<input.length();j++){
            int sum = 0;
            if(input[j] == '(') st.push(-1);
            else if(input[j] == ')'){
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }else{
                    while(!st.empty() && st.top() != -1){
                        sum += st.top();
                        st.pop();
                    }
                    if(st.top() == -1){
                        st.pop();
                        st.push(2*sum);
                    }
                }
            }
        }
        while(!st.empty()){
            B += st.top();
            st.pop();
        }

        if(A>B) cout << '>' << '\n';
        else if(A==B) cout << '=' << '\n';
        else cout << '<' << '\n';
    }
}