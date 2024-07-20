#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;
#define INF 1e9+1

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, num[101];
ll dp[101][21];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++) cin >> num[i];
    
    dp[0][num[0]] = 1;//초기값의 경우의 수 1

    for(int i = 1;i<N - 1;i++){
        for(int j = 0;j<21;j++){
            if(j - num[i] <= 20 && j - num[i] >= 0){
                dp[i][j - num[i]] += dp[i-1][j];
            }// - 경우의 수 누적

            if(j + num[i] <= 20 && j + num[i] >= 0){
                dp[i][j + num[i]] += dp[i-1][j];
            }// + 경우의 수 누적
        }
    }

    cout << dp[N - 2][num[N - 1]];
}
/*
DP는 역시 점화식 떠올리기...언제쯤 점화식 달인이 될까??

for(int i = 0;i<N - 1;i++){ cout << i << "  ";
        for(int j = 0;j<21;j++){
            cout << dp[i][j] << ' ';
        }cout << '\n';
    }
*/
