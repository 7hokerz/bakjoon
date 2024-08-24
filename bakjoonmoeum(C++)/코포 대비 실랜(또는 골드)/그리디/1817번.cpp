#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9
 
int M, N, inp;
vector <int> vt;
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> inp; vt.push_back(inp);
    }
    int sum = 0, ret = 1;
    for(int i = 0;i<N;i++){
        if(sum + vt[i] > M){
            sum = vt[i]; ret++;
        }
        else sum += vt[i];
    }
    if(!N) cout << 0;
    else cout << ret;
}
/*

*/