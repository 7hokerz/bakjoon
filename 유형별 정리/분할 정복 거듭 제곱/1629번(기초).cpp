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

ll A, B, C;

ll calc(ll a, ll n){
    if(n == 1) return a % C;

    ll tmp = calc(a, n/2) % C;

    if(n % 2 == 0) return (tmp * tmp) % C;
    
    else return (tmp * tmp) % C * a % C;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    cout << calc(A, B) % C;

}
/*
분할 정복을 이용한 거듭제곱

2를 5번 곱한다고 하자. 이때 2를 5번 곱하면 O(N)이다.

하지만 이를 분할 정복 한다면?
2를 5번 >> (2를 2번), (2를 2번)...

위와 같이 풀면 O(logN)만으로 풀 수 있다.

과정:
1. n==1일 때까지 재귀 호출, n==1 이면 a반환
2. tmp에 값 저장
3. n이 짝수면 tmp*tmp
3.1 n이 홀수면 tmp*tmp*a
3.1의 이유?
n/2로 재귀 호출을 시키는데, 이 때 나머지는 버려진다. 따라서
그 나머지를 포함하기 위해 추가로 a를 곱해준다.
*/