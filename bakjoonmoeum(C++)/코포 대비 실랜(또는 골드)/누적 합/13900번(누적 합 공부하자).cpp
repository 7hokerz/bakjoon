#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9
 
int N, inp;
vector <ll> vt, accu;
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> inp; 
        vt.push_back(inp);
    }
    accu.push_back(vt[0]);
    for(int i = 1;i<N;i++){
        accu.push_back(accu[i-1] + vt[i]);
    }
    ll ret = 0;
    for(int i = 1;i<N;i++){
        ret += accu[i-1] * vt[i];
    }
    cout << ret;
}
/*
누적 합을 못알아차리는 나는 병신
*/