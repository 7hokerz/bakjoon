#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int t, N, pa, pb, inp;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> t;
    while(t--){
        vector <int> vt;

        cin >> N >> pa >> pb;
        for(int i = 0;i<N;i++){
            cin >> inp;
            vt.push_back(inp);
        }

        ll resa = 0, resb = 0; int mid = 0;

        for(int i = 0;i<N;i++){
            int la = abs(pa - vt[i]); int lb = abs(pb - vt[i]);
            if(la > lb){
                resb += lb * 2;
            }
            else if(la < lb){
                resa += la * 2;
            }
            else{
                mid++;
            }
        } //cout << resa << ' ' << resb << ' ';

        while(mid--){
            ll vala = resa + abs(pa - pb);
            ll valb = resb + abs(pa - pb);

            if(abs(vala - resb) > abs(valb - resa)){
                resb = valb;
            }
            else{
                resa = vala;
            }
        }

        cout << resa + resb << ' ' << abs(resa - resb) << '\n';
    }
}
/*
조건 1: 두 사람이 이동한 거리의 총 합이 최소가 되도록 하고 싶다.
조건 2: 조건 1을 만족하는 방법이 여러가지라면, 두 사람이 이동한 거리의 차이가 최소가 되도록 하고 싶다.

A와 B의 이동 경로가 겹치면 안된다. 그렇지 않으면 최단 거리가 아님.

우선적으로 A에서 가까운 지점과 B에서 가까운 지점의 거리를 먼저 구해놓고, A와 B의 누적 이동거리를 저장한다.
그 다음 중간 지점의 차를 줄이는 방법을 사용하자.

결론: 중간 지점만 따로 신경써주면 풀린다.
*/