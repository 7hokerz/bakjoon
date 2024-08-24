#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <pair<char,int>> st;
    string input;
    int N, check, result = 0;
    cin >> N >> input;
    for(int i = 0;i<N;i++){
        if(input[i] == '('){
            st.push({input[i], i});
        }else if(input[i] == ')'){
            if(!st.empty() && st.top().first == '(') st.pop();
            else st.push({input[i],i});
        }
    }
    check = input.length();
    while(!st.empty()){
        result = (check - st.top().second - 1 > result)?
        check - st.top().second -1 :result;
        check = st.top().second;
        st.pop();
    }
    
    result = (check > result)?
    check:result;

    cout << result;
}
/*
다른 분께서 알려주신 방법으로 
인덱스를 이용하여 길이를 구하는 방법을 사용하였다.

즉 스택 pair를 이용하여 i를 같이 삽입하고
그와 별개로 문자는 ()짝이 되면 반드시 지우게 된다.
그러면 남아있는 요소는 잘못된 요소이면서 인덱스를 가지고 있으므로 길이
를 구하기 쉬워진다.

먼저 문자열 길이에서 상단 값을 빼고 -1을 빼면 올바른 문자의 개수가 된다.
이를 반복하고, 마지막에 인덱스 0부터 가장 낮은 스택 상단인 check
를 저장하였으므로 한 번 더 비교한 후 값을 도출해낸다.
*/