#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int T, N, val[1001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;

    val[2] = 2; val[3] = 5;
    for(int i = 4;i<N+1;i++){
        val[i] = val[i-2] + (i-1) * 2;
    }
    cout << val[N];
}
/*
상하좌우로 위치한 '2'개의 인접 스위치 동시에

홀수와 짝수는 다르게?

아니다..결국 똑같은 공식이네 ㅋㅋㅋㅋㅋㅋ

8 = 4 + 2 + 1

a5 = a3 + a4*2
a6 = a4 + (6/2 + 4/2)

a4 = 2 + ()

ai = ai-2 + (i/2) + ((i-1)/2) 짝수

ai = ai-2 + ai-1 * 2 홀수

1 0

0 0
0 0
2

0 0 0
0 0 0
0 0 0
5

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
8

0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
13

달팽이 마냥 파고 들어가면서 확인하면 되는 듯 하다?
*/