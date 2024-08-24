#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }\

int n, k, input, dp[10001];
vector <int> vt;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> input;
        vt.push_back(input);
    }
    for(int i = 1;i<k+1;i++){
        for(int j = 0;j<vt.size();j++){
            if(vt[j] > i) continue;

            if(dp[i-vt[j]] != 0 || i-vt[j] == 0){
                if(dp[i] == 0) dp[i] = dp[i-vt[j]] + 1;
                else dp[i] = min(dp[i-vt[j]] + 1, dp[i]);
            }
        }
    }
    if(dp[k] == 0) cout << -1;
    else cout << dp[k];
}
/*
i: 원 이라고 한다면
입력된 모든 입력값을 빼서 비교한다.

dp[i] == 0 >> dp[i] = dp[i-a];
dp[i] = min(dp[i-a], dp[i])

즉 입력된 값을 더해서 i가 되는 경우이므로 i-입력값 dp값 중 최소값을 넣으면 된다.

단 i-a==0 또는 dp[i-a] != 0(이 경우는 동전을 만들 수 없는 경우임.)

for(int i = 1;i<k+1;i++){
        cout << i << ' ' << dp[i] << '\n';
    }
1 5 12


dp 
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
0 1 2 3 4 1 2 3 4 5 2   3  1  2  3  3

dp[i] = dp[i-12]+1, dp[i-5]+1, dp[i-1]+1중 작은거

15 >> 3+1, 2+1, 3+1


*/