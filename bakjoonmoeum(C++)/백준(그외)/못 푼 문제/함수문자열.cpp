#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cntst = 0;
    stack <char> st;
    stack <int> res;
    string input;
    cin >> input;
    for(int i = input.length()-1;i>=0;i--){//유효성 검증
        if(input[i] == 'x'){
            if(!st.empty() && st.top() == 'x'){
                cout << -1;
                return 0;
            }
            else{
                st.push('x');
                cntst++;
            }
        }
        else if(input[i] == 'g'){
            if(st.empty()){
                cout << -1;
                return 0;
            }else st.push('g');
        }
        else if(input[i] == 'f'){
            if(cntst < 2){
                cout << -1;
                return 0;
            }
            else{
                st.push('f');
                cntst--;
            }
        }
    }
    for(int i = input.length()-1;i>=0;i--){
        if(input[i] == 'x'){
            res.push(0);
            continue;
        }
        else if(input[i] == 'g'){
            res.top()++;
        }
        else if(input[i] == 'f'){
            int tmp = res.top();
            res.pop();
            int val = (tmp>res.top())?res.top():tmp;
            res.pop();
            res.push(val);
        }
    }  
    int val = 0;
    while(!res.empty()){
        val = res.top();
        res.pop();
    }
    cout << val;
}
/*


*/