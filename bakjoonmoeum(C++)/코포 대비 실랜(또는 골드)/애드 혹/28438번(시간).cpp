#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, M, Q, a, v, u;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> Q;

    vector <int> r[N+1], c[M+1];

    for(int i = 0;i<Q;i++){
        cin >> a >> v >> u;

        if(a == 1) {
            if(r[v].empty()) r[v].push_back(u);
            else r[v].back() += u;
        }
        else{
            if(c[v].empty()) c[v].push_back(u);
            else c[v].back() += u;
        }
    }

    for(int i = 1;i<N+1;i++) {
        for(int j = 1;j<M+1;j++) {
            int val = 0;
            if(!r[i].empty()) val += r[i].back();
            if(!c[j].empty()) val += c[j].back();
            cout << val << ' ';
        }cout << '\n';
    }
}
/*
행렬 자체를 출력해야 함. 

이러한 유형의 애드 혹에 대해서 어떻게 대처할 지 배운 것 같다.

매번 쿼리가 들어올 때마다 업데이트 해줄 필요 없이 한 번에 처리하는 것과,
굳이 행렬의 결과를 배열에 담을 필요도 없다는 것이다.
*/