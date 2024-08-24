#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> st;
    stack <int> tmp;
    int N, input;
    cin >> N;
    int cnt[1000000];
    int res[N];
    for(int i = 0;i<sizeof(cnt)/sizeof(cnt[0]);i++){
        cnt[i] = 0;//전부 0으로 채워넣기
    }
    for(int i = 0;i<N;i++){//배열에 넣으므로 input-1
        cin >> input;
        st.push(input);
        cnt[input-1]++;
    }

    for(int i = 0;i<N;i++){
        /*tmp top 숫자의 개수보다 st top 숫자의 개수가 많거나 같을 동안
        tmp.pop 계속하기
        */
        while(!st.empty() &&
        !tmp.empty() && cnt[st.top()-1] >= cnt[tmp.top()-1]){
            tmp.pop();
        }

        /*만약 st.top이 tmp.top의 모든 수보다 개수가 많아서 다 지워지면
        -1이고, 그렇지 않으면 tmp.top을 넣는다.
        */
        if(tmp.empty()) res[i] = -1;
        else res[i] = tmp.top();
        
        //그 다음 해당 수를 넣고 다음 대상과 비교할 준비를 한다.
        if(st.empty()) continue;
        else{
            tmp.push(st.top());
            st.pop();
        }
    }

    for(int i = N-1;i>-1;i--){
        cout << res[i] << ' ';
    }
}
/*
7
1 1 2 3 4 2 1

-1 -1 1 2 2 1 -1

오큰수와 거의 다를 바 없는 풀이다.
다른 점은 숫자 크기를 비교하는 게 아닌 개수를 비교하는 것
그래서 개수를 따로 배열에 저장하였다.
*/