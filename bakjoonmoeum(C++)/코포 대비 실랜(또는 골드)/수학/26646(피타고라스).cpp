#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 0x7F7F7F7F7F

int N, arr[50001], loc[50001], ret = 0;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++) cin >> arr[i];
    
    for(int i = 2;i<N+1;i++){//위치 누적 합
        loc[i] = arr[i] + arr[i-1] + loc[i-1];
    }//for(int i = 1;i<N+1;i++) cout << loc[i] << ' ';

    for(int i = 2;i<N+1;i++){
        int d = loc[i] - loc[i-1];
        int h = arr[i] - arr[i-1];
        ret += d*d + h*h;
    }
    cout << ret;
}
/*
비용 = (두 산의 위치 차이) ^ 2 + (두 산의 높이 차이) ^ 2
*/