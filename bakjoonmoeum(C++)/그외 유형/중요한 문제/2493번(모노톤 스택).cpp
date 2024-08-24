#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <pair<int, int>> st;
    int N, input;
    cin >> N;
    int res[N];

    for(int i = 0;i<N;i++){
        cin >> input;
   
        while(!st.empty() && st.top().first < input){
            st.pop();
        }
        if(st.empty()){
            res[i] = 0;
        }
        else if(st.top().first > input){
            res[i] = st.top().second + 1;
        }
        else if(st.top().first == input){
            res[i] = st.top().second + 1;
            st.pop();
        }
        else{
            res[i] = st.top().second + 1;
        }
        st.push({input, i});
    }
    for(int i = 0;i<N;i++){
        cout << res[i] << ' ';
    }
}
/*
5
6 9 5 7 4
0 0 2 2 4

탑의 높이와 번호 i를 pair하고, 요소를 스택에 담는다. 
단 스택 상단 값이 스택에 들어오려는 요소보다 작은 경우 pop한다. 
pop을 반복하다 스택 상단값이 더 큰 경우 멈추고, 
큰 경우는 상단 값의 번호를 결과 배열에 삽입, 이후 pop연산 한번 더 해준다. 
그 후에 들어오려는 요소를 삽입해준다. 
만약 pop을 반복하여 스택이 비었을 경우 스택에 해당 요소를 삽입해주고 0을 결과 배열에 삽입시킨다.

우연히 떠오른 아이디어...
쉽게 말해 스택에 값을 저장하는데 탑보다 작으면 스택에 넣고 
탑보다 크면 top을 계속 탑보다 작을때까지 pop해나간다.

인터넷 검색 결과
monotone stack:
일련의 값에서 바로 다음 큰값이나, 
바로 다음 작은 값을 구해야할 때 사용할 수 있는 Stack 풀이법.

increasing
삽입하려는 값이 stack의 top보다 클때만 push, 
삽입하려는 값보다 작은 값은 모두 stack에서 pop.
배열에서 다음 작은 값이 무엇인지 알아낼 수 있음.

decreasing
삽입하려는 값이 stack의 top보다 작을 때만 push, 
삽입하려는 값보다 큰값은 모두 stack에서 pop.
배열에서 다음 큰 값이 무엇인지 알 수 있음.
*/