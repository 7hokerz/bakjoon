#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;//리버스용
    deque <int> dq;
    vector <pair<int,int>> cmd;
    int N, Q, k;
    int input, val;
    cin >> N >> Q >> k;
    for(int i = 0;i<Q;i++){
        cin >> input;
        if(input == 0){
            cin >> val;
            cmd.push_back({input,val});
        }else if(input == 1){
            while(!cmd.empty()){
                if(cmd.back().first == 0) dq.push_back(cmd.back().second); 
                cmd.pop_back();
            }
        }else if(input == 2){
            cmd.push_back({input,-1});
        }
    }
    sort(dq.begin(), dq.end());
    for(int i = 0;i<cmd.size();i++){
        if(cmd[i].first == 0){
            dq.push_front(cmd[i].second);
        }else if(cmd[i].first == 2){
            while(!dq.empty()){
                st.push(dq.back());
                dq.pop_back();
            }
            while(!st.empty()){
                dq.push_front(st.top());
                st.pop();
            }
        }
    }
    int cnt = 0;
    while(!dq.empty()){
        cnt++;
        if(cnt == k) {
            cout << dq.front();
            break;
        }
        else dq.pop_front();
    }
}
/*
여러 번 수정 결과 성공!
스택이라고 써있지만 여러 작업들을 수행하려면 덱이 필요하다.
또한 단순히 명령어를 한 번씩 받을때마다 작업을 수행하는 것은
특정 작업에서 시간이 낭비될 수 있다. 1번 정렬 작업이 그렇다.

**중요한 건 정렬 작업이 시행되면 그 전에 했던 작업들은 큰 의미가 없다.
정렬 작업 전 추가된 값이 뭔지만 알면 된다. 이거 때문에 시간초과 났었다.

*그리고 덱을 쓸 경우 front와 back 구분을 명확히 해야 한다.
sort 정렬 함수를 쓰면은 오름차순이므로 front부터 1~이다. 즉 상단 값은 front가 된다는 뜻
이거 제대로 안하면 틀린다.(물론 반대로 정렬시키면 되겠지만 sort함수만 쓰니까 난)

과정:
1. 우선 0,2가 들어오면 cmd벡터에 추가해준다. 단 0은 val을 추가하고 2는 -1을 추가한다.
2. 1이 들어오면 벡터를 비워준다. 단 0 명령어를 찾으면 val을 덱에 추가해준다.
3. 모든 명령 입력이 완료되면 덱을 먼저 정렬해준다.
4. 벡터에 명령어가 남아있으면 나머지 명령어들을 순서대로 실행해주면 된다.

1
2 1
3 2 1
1 2 3(오름차순 정렬)
4 1 2 3
5 4 1 2 3
3 2 1 4 5
*/