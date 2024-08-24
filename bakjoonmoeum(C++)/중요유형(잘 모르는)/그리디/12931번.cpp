#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)
#define mod 1'000'000'009

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp;
ll ret = 0;
vector <int> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> inp;
        vt.push_back(inp);
    }sort(vt.rbegin(),vt.rend());

    while(!vt.empty()){
        while(!vt.empty() && !vt.back()) vt.pop_back();
        
        if(vt.empty()) break;

        int cnt = 0;

        for(int i = 0;i<vt.size();i++){
            if(vt[i] % 2) {vt[i]--; ret++;}
            vt[i] /= 2;
            //cout << vt[i] << ' ';
            if(!vt[i]) cnt++;
        }

        if(cnt == vt.size()) break;

        ret++;
    }
    cout << ret;
}
/*
배열 B의 모든 요소를 0으로 만들자.
*/