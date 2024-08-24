#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, A, K = 0, inp, ret = 0;
string str;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> str;

    for(int i = 0;i<N;i++){
        if(str[i] - 48) ret++;
    }
    cout << ret;
}
/*
정리:
K = K-(K&((~K)+1))라는 식을 풀어보면 알 수 있다.
~K+1 >> 2의 보수
K & ~K+1 >> K의 마지막 1 비트가 위치한 지점
K - K-(K&((~K)+1)) >> K의 마지막 1 비트를 0으로 바꾼다고 생각하면 된다.

결국은 K의 비트 1의 개수가 연산 횟수다.


K = K-(K&((~K)+1))

(K&((~K)+1)) >> K의 마지막 1이 위치한 곳이 된다.

10110
1
10100
2
10000
3
00000

결국은 K의 1의 비트의 개수가 답이 됨.
*/