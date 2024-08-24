#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp, ret = 0;

int arr[100'001];
int dp[101];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;

    for(int i = 1;i<N+1;i++) cin >> arr[i];
    
    for(int d = -99;d<100;d++){//모든 공차에 대하여 조사
        memset(dp, 0, sizeof(dp));

        for(int j = 1;j<N+1;j++){
            int x = arr[j];//현재 요소

            //현재 요소에 대하여 공차를 만족하는 다른 요소가 존재할 수 있는지 확인한다.
            if(x - d > 0 && x - d < 101) dp[x] = max(dp[x], dp[x - d] + 1);
            else dp[x] = 1;   
        }
        for(int i = 1;i<101;i++) ret = max(ret, dp[i]);
    }
    
    cout << ret;
}
/*
O(200N)
*/