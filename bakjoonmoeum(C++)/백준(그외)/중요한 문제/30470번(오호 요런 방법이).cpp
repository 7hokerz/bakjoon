#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <pair<int,int>> st;
    int N, a, b;//a: 1-통나무 2-마법, b: 수치
    long long sum = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a >> b;
        if(a == 1){
            st.push({b,1});
        }else if(a == 2){
            if(st.empty()) continue;
            else{
                int val = 0, cnt = 0;
                val = st.top().first - b;
                if(val < 0) val = 0;
                while(!st.empty() && st.top().first > val){
                    cnt += st.top().second;
                    st.pop();
                }
                st.push({val, cnt});
            } 
        }
    }
    while(!st.empty()){
        sum += st.top().first*1LL*st.top().second;
        st.pop();
    }
    cout << sum;
}
/*
처음에 시간초과 걸렸다. 왜냐하면 쌩으로 스택에 빼고 넣고를 반복했기 때문이다.(왠지 그럴거 같았어)
그래서 두번째로 생각해낸게 pop은 똑같이 하고 cnt도 똑같이 세는데 이걸 스택에 넣을 때는 {값, 개수} 형태로 넣는 것이다.
즉, 스택을 pair로 바꾸고 시행했다.

4 7

2 5가 사용되면 탑 값을 계산하여 나온 값은 7-5=2 이상의 모든 통나무들을 7-5=2로 만들어 버린다.

2 2 

2 2 11

2 2가 사용되면 11-2 = 9 이상의 모든 통나무들을 11-2 = 9로 만들어 버린다.

2 2 9 = 13

모든 통나무의 길이의 합은 long long으로?
*/