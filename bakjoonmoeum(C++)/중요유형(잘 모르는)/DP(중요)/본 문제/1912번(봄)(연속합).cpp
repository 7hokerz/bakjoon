#include <iostream>
using namespace std;
/*
풀지 못하고 본 문제.
연속된 수 중 그 수의 합이 가장 큰 경우를 구하는 문제다

풀지 못한 이유?
재귀로 풀어보려고 했으나 어째서인지 잘 안풀렸다.
이 문제는 재귀가 필요없이 단순히 값을 기억하면 풀린다.

3 5 6 -35 12 21 -1
과정:
1번까지 포함한 최대 연속합은 3이다. dp 3
2번까지 포함한 최대는 3+5 = 8이다. dp 8
3번까지 포함한 최대는 8+6 = 14이다. dp 14
4번까지 포함한 최대는 직전에 기억한 값인 14이다. dp -21
(이때 dp[i]에는 14-35 = -21이 들어가고, maxnum에는 14가 그대로 유지된다.)
(5번째에 갈 때 dp를 더하면 손해라는 것을 적용 가능)
5번까지 포함한 최대는 12이다. dp 12 maxnum 14
6번까지 포함한 최대는 33이다. dp 33 maxnum 33
7번까지 포함한 최대는 32이다. dp 32 maxnum 33
maxnum 33이므로 연속합의 최댓값은 33이다.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    cin >> n;
    int dp[n], inp[n];
    for(int i = 0;i<n;i++){
        cin >> input;
        inp[i] = input;
    }
    int ret = inp[0];
    dp[0] = inp[0];//어차피 0일땐 요소가 1개뿐이니까
    for(int i = 1;i<n;i++){
        //dp[i]에는 현재 요소와 이전 연속합의 값 + 현재 요소 중 큰 값이 들어간다.
        dp[i] = max(inp[i], dp[i-1] + inp[i]);
        //전체 최댓값을 저장한다.
        ret = max(dp[i],ret);
    }
    cout << ret;
}
