#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e19

int D, K, dp[31][2];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> D >> K;

    //0은 A의 개수, 1은 B의 개수
    dp[1][0] = 1; dp[1][1] = 0;
    dp[2][0] = 0; dp[2][1] = 1;

    for(int i = 3;i<D+1;i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    
    for(int i = 1;i<K+1;i++){
        int tmp = K - dp[D][0] * i;//i는 어떤 수
        if(!(tmp % dp[D][1])){
            cout << i << '\n' << tmp / dp[D][1];
            return 0;
        }
    }
}
/*
3 5 8 13 21 34

(봄) 피보나치 응용 버전. 식처럼 생각하면서 아래처럼 풀어나가야 했다. 난 빡대갈이 분명해
A
B
A+B
A+2B
2A+3B
3A+5B
...dp배열에는 해당 계수가 저장되어 있다.

식에 맞는 수가 나와야 함.
3A+5B = 41일 때

5B = 41 - 3A, 
나머지가 없어야 B를 구할 수 있다.
*/