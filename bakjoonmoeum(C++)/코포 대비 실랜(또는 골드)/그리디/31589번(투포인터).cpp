#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, K, inp;
vector <int> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> K;

    int l = 0, r = N - 1;

    for(int i = 0;i<N;i++){
        cin >> inp;
        vt.push_back(inp);
    }
    sort(vt.begin(), vt.end());

    int cnt = 1; 
    ll sum = vt[r--];
    while(cnt < K){
        cnt++;
        if(cnt >= K) break;
        sum += (vt[r] - vt[l++]);
        
        r--;
        cnt++;
    }
    cout << sum;
}
/*
투 포인터 문제. 
양쪽에 포인터를 두고 한 칸씩 가운데로 이동시킨다.

양 쪽을 차례 차례 마시면서 제거

15 >> 3 >> 8 >> 6 >> 8

15 >> 0 >> 5
*/