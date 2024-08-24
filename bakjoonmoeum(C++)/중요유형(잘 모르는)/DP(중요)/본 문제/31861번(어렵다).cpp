#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define mod 1'000'000'007

int N, M;
long long dp[27][1001];

int main(){
    cin >> N >> M;

    for(int j = 1;j < 27;j++){//기저값
        dp[j][0] = 1;
    }

    for(int i = 1;i < M + 1;i++){//M자리까지 dp연산
        for(int j = 1;j < 27;j++){//비교 알파벳 1 
            for(int h = 1;h < 27;h++){//비교 알파벳 2 (모든 알파벳과 비교하게 됨)
                if (abs(j-h) < N) continue;
                dp[j][i] += dp[h][i-1];
                dp[j][i] %= mod;
            }
        }
    }
    long long res = 0LL;
    for(int i = 1;i < 27;i++) {res += dp[i][M-1] % mod; res %= mod;}
    cout << res % mod;
}
/*
알파벳 26개를 A부터 1~26으로 번호를 붙일 때, 두 번째 글자부터 i 위치의 글자와 i-1위치의 글자의 차이가 N이상인 경우를 만족해야함.

알파벳의 차이를 N, 글자 수를 M이라 할 때  위 경우를 만족하는 모든 경우의 수를 구하기
*/