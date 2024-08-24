#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int S, N, E, K, L, num, ret = INF;

vector <int> loc;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> S >> N;
    for(int i = 0;i<N;i++){
        cin >> E;
        loc.push_back(E);
    }
    cin >> K >> L;

    for(int i = 0;i<N;i++){
        int val = 0, l = min(S, loc[i]), r = max(S, loc[i]), mid = (r + l) / 2;
        //cout << l << ' ' << r << ' ' << mid << '\n';

        if((r + l) % 2){//홀 
            int d = max(mid - l, r - mid);

            if(d >= K){
                if(mid - l >= K) l += K;
                else { val += K - (mid - l); l = mid;}

                if(r - mid >= K) r -= K;
                else { val += K - (r - mid); r = mid;}

                val += L * (r - l);
            }
            else val += K - (r - mid) + K - (mid - l);//요 새끼 때문에 12% 왜맞틀 ㅅㅂ
        }
        else{//짝
            int d = mid - l;

            if(d >= K){
                l += K; r -= K;
                val = L * (r - l);
            }
            else val = 2 * (K - d);
        }

        if(ret > val){ ret = val; num = i + 1;}
    }
    cout << ret << ' ' << num;
}
/*
내 수학 실력은 썩은 걸까? 섬세하지 못한 내가 문제인 듯 하다.

*/