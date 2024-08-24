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
#include <map>
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

ll N, B, input;
ll m[6][6], res[6][6], tmp[6][6];

void mul(ll A[6][6], ll B[6][6]){//행렬 곱(제곱)
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            ll val = 0;
            for(int k = 1;k<N+1;k++){
                val += (A[i][k] * B[k][j]) % 1000;
                val %= 1000;
            }
            res[i][j] = val;
        }
    }
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            tmp[i][j] = res[i][j];
        }
    }
}

void calc(ll n){
    if(n == 1) {
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<N+1;j++){
                tmp[i][j] = res[i][j] = m[i][j] % 1000;
            }
        }
        return;
    }
    
    calc(n/2);
    mul(tmp, tmp);

    if(n % 2 == 1) mul(tmp, m);
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> input;
            m[i][j] = input;
        }
    }
    calc(B);
    printmap(N, N, res);
}
/*
행렬 m을 B번 곱하는 문제이지만 그대로 B번 곱하는 게 아닌 나눠서 푼다.

m을 n번>>
1. calc(n/2) 호출 
1.1 n==1이 될때까지 호출
2. 
n이 1에 도달하면 tmp와 res 배열에 m 삽입, 리턴 후 계산 
>> res에 곱한 값 저장
**이후 tmp에 저장
(요소 하나 하나를 저장할 때 같이 저장하면 원본이 망가지기 때문)
2.1
n이 홀수인 경우 한 번 더 곱해야 하므로 이때는 m과 곱한다.
...
위 과정을 쭉 반복하면 결과가 나온다.


행렬 곱셈
A,B행렬이 있다고 치자.
이때 AB의 곱 C행렬을 구하려면?

Cij = ai1 b1j + ai2 b2j ... + ain bnj

즉 a의 i번째 행과 b의 j번째 열의 성분들을 모두 곱한 값을 더한 값이 cij가 된다.

C11 = a11

예시:
A    B 
a b  e f
c d  g h

AB?
ae+bg af+bh
ce+dg cf+dh
*/