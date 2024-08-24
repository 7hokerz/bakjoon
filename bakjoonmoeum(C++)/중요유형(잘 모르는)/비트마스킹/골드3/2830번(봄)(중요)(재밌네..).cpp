#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1
 
int N, inp, numcnt[(1 << 21)];
ll res = 0;
vector <int> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> inp;
        for(int j = 0;j<21;j++){
            int pos = (1 << j);
            if(inp & pos){
                numcnt[pos]++; //cout << j << ' ' << numcnt[pos] << '\n';
            }
        }
    }

    for(int j = 0;j<21;j++){
        int pos = (1 << j);
        ll onecnt = numcnt[pos];
        ll zerocnt = (N - numcnt[pos]);

        res += onecnt * zerocnt * pos;
        //cout << j << ' ' << numcnt[pos] * (N - numcnt[pos]) * pos << '\n';
    }
    cout << res;
}
/*
모든 XOR 값의 합=( 0의 개수 × 1의 개수 ) × 비트 위치 값(즉, 1 << i) 
라는 발상을 도출해야 풀 수 있다.

XOR이 1이 되는 경우는 서로 다른 비트값이 주어진 경우이다.
따라서, 어느 비트 값이 1이 되는 경우의 수를 세주면 N - 1의 개수 = 0의 개수가 되고,
XOR의 값이 1이 되는 경우의 수는 둘을 곱한 수라는 것을 도출할 수 있다.

그 후 비트 위치 값을 곱해주면 실제 10진수의 값을 알아낼 수 있다.

이야...그냥 발상은 매우 어려운 것 같다. 이런 건 많이 풀어봐야 늘 것 같다.
*/