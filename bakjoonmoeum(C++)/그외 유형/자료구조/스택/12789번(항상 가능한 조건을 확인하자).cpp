#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st;
    int N, input, comp = 0;
    cin >> N;

    st.push(0);
    for(int i = 0;i<N;i++){
        cin >> input;
        if(input == (comp + 1)) comp++; 
        else{
            while(st.top() == (comp + 1)){
                st.pop();
                comp++;
            }
            st.push(input);
        }
    }
    while(!st.empty()){
        if(st.top() == 0){
            st.pop();
            break;
        }
        else if(st.top() != (comp + 1)){
            cout << "Sad";
            return 0;
        }else{
            st.pop();
            comp++;
        }
    }
    cout << "Nice";
}
/*
주의! 중간에도 나올 수 있음!
예: 4 2 1 3

4는 스택, 2는 스택으로 간 후
1은 통과한다. 
이때 스택에 또 3을 넣을 게 아니라
스택 상단 값이 2잖아?
그러면 해당 스택 값도 제거하면 된다.
이 부분을 못알아차렸네...
*/