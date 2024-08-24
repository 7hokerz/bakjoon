#include <iostream>
using namespace std;
int inp[301];
int dp[301];//바꾸기
/*
계단 오르기 문제: 세 칸 연속해서 올라갈 수 없는 조건을 어떻게 설정해야 하는가?
경우 2가지
1. 한 칸을 건너뛰고 현재 칸에 온 경우 즉, inp[n]+dp[n-2]
2. 전 칸에서 바로 온 경우 이때는 전전칸에 들르지 않았다는 조건이 필수다. inp[n] + inp[n-1] + dp[n-3]
또한 n>=3이어야 하므로 0, 1, 2의 dp값은 초기 설정이 필요하다. 
++
단순 dp배열만 놓고 풀면 안되는 이유: dp에 값을 저장하고 나면 입력값은 사라지는 데, 이때 다른 dp에서 재귀 방문을 또 할 수도 있다.
하지만 inp값이 없고 다른 값이 놓여있으므로 값이 왜곡될 수 있기 때문이다.
재방문의 가능성이 있는 경우는 입력값과 dp배열을 따로 저장하자.
*/
int calc(int n){
    if(dp[n] != 0) return dp[n];
    dp[n] = inp[n] + max(calc(n-2), inp[n-1] + calc(n-3));
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        inp[i] = input;
    }
    dp[0] = inp[0];
    dp[1] = inp[0]+inp[1];
    dp[2] = max(inp[0]+inp[2], inp[1]+inp[2]);
    for(int i = 3;i<N;i++){
        calc(i);
    }
    cout << dp[N-1];
}
/*

*/