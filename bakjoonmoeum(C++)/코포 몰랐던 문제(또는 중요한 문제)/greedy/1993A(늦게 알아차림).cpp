#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int T, N;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N; 
        vector <int> earr;
        int o = 0, e = 0;
        ll inp, maxo = 0, ret = 0;
        for(int i = 0;i<N;i++) {
            cin >> inp;
            if(inp % 2) { o++;
                maxo = max(inp, maxo);
            }
            else {earr.push_back(inp); e++;}
        }
        if(!o || !e) cout << 0 << '\n';
        else{
            sort(earr.begin(), earr.end());
            for(int i = 0;i<earr.size();i++){
                if(maxo > earr[i]){
                    maxo = max(maxo + earr[i], maxo);
                    ret++;
                }
                else{
                    while(maxo < earr[i]){
                        maxo += earr.back();
                        ret++;
                    }ret++;
                }
            }
            cout << ret << '\n';
        }
    }
}
/*
짝 + 짝 = 짝
짝 + 홀 = 홀 + 짝 = 홀
홀 + 홀 = 짝

짝이나 홀만 존재 >> 0 출력

그 외,

홀 > 짝 >> 모든 짝을 홀로 바꾼다.
홀 < 짝 >> 모든 짝을 홀로 바꾼다.

결국은 홀이 1개 이상 존재하면 모든 짝을 홀로 바꿔야 함.

바꿀 때 주의할 점은 항상 큰 홀을 선택하여 작은 짝을 홀로 바꾸도록 해야 함.
*/