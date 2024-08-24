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

ll N, K;

void bisearch(){
    ll start = 1, mid = 0, end = N;

    while(start <= end){
        mid = (start + end) / 2;
        ll val = mid * (N - mid + 2);//색종이 조각의 개수
        //cout << val << ' ';
        if(val > K){
            end = mid - 1;
        }
        else if(val < K){
            start = mid + 1;
        }
        else{
            cout << "YES"; return;
        }
    }
    cout << "NO"; return;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    bisearch();
}
/*
처음에 모든 값의 경우를 벡터에 저장하고 풀려 했으나, 생각해보면 최대 21억개의 원소를 담아야 하므로 불가능했었다.

제일 좋은 방법은 어차피 값은 가로 자른횟수 +1 * 세로 자른횟수+1 이므로
start와 end를 최소 자르는 횟수, 최대 자르는 횟수? 로 둬서 푸는 것이었다.

이 때 val은 처음 mid의 값일 때 가장 클 것이다.

val에 공식을 이용해 색종이 조각의 개수를 대입하고 이를 K값과 비교하여 차차 줄여나갔다.

4번 자르는 경우
나오는 조각의 경우의 수
1 5 5
2 4 8
3 3 9
4 2 8
5 1 5
*/



