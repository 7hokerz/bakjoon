#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define mod 998'244'353

int N;
int arr[5001];
ll dp[5001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++) cin >> arr[i];

    dp[1] = 1;

    for(int i = 2;i<N+1;i++){
        for(int j = i;j>=1;j--){
            if(arr[j] < arr[i]){
                dp[i] += dp[j];
                dp[i] %= mod;
            }
        }
        dp[i]++;
    }
    for(int i = 1;i<N+1;i++) cout << dp[i] << ' ';
}
/*



*/