#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp, ret = INF;
string str;
ll arr[100'001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    int S;
    cin >> N >> S;
    for(int i = 1;i<N+1;i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int l = 1, r = 1;
    while(l != N + 1){
        while(r < N && arr[r] - arr[l-1] < S) r++;
    
        if(arr[r] - arr[l-1] >= S) ret = min(ret, r - l + 1);
        l++;
    }
    
    if(ret == INF) cout << 0;
    else cout << ret;
}
/*
자연수니까 쉽게 가능

*/