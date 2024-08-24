#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, K, num, e1, e2, ene[21][2];//한 칸, 두 칸
int dp[21][2];//3칸 뛴 경우, 안 뛴 경우

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill_n(&dp[0][0], 21*2, INF);
    cin >> N;
    for(int i = 1;i<N;i++){
        cin >> e1 >> e2;
        ene[i][0] = e1; ene[i][1] = e2;
    }
    cin >> K;

    //초기값 부여
    dp[1][0] = 0;//시작 위치
    dp[2][0] = ene[1][0];//2번째 돌은 1번째 돌에서 한 칸만 가능하다.
    dp[3][0] = min(ene[2][0], ene[1][1]);//3번째 돌은 1번째에서 2칸 점프, 2번째에서 1칸 점프 중 가능하다.

    for(int i = 3;i<N+1;i++){
        int one = dp[i-1][0] + ene[i-1][0];//1칸(뛰지 않음)
        int two = dp[i-2][0] + ene[i-2][1];//2칸(뛰지 않음)

        int jone = dp[i-1][1] + ene[i-1][0];//1칸(이미 뛰었음)
        int jtwo = dp[i-2][1] + ene[i-2][1];//2칸(이미 뛰었음)
        int jp = dp[i-3][0] + K;//뛰지 않았고, 3칸을 뛰는 경우

        dp[i][0] = min(one, two);

        dp[i][1] = min(jp, min(jone, jtwo));
    }
    cout << min(dp[N][0], dp[N][1]);
}
/*
DP 점화식 기초. 아오 어려워
*/