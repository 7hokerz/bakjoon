#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int Q, x, n;
ll val = 1, mul = 1, add = 0;//val = ax + b(현재 원소), mul = 곱, add = 합

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> Q;
    for(int i = 0;i<Q;i++){
        cin >> x;
        if(x == 0){//더하기
            cin >> n; add += n;
        }
        else if(x == 1){//곱하기(d(ax + b)의 형태이기 때문)
            cin >> n; mul *= n; add *= n;
        }
        else if(x == 2){//원소 작은 거 부터 빼기
            cin >> n; val += n;
        }   
        else if(x == 3) {
            cout << mul * val + add << '\n';
        }
    }
}
/*
더하고 곱하는 명령으로 원소의 크기 순서가 바뀌지 않는다.

** 곱하는 것의 경우, val = ax+b라 하면 
mul(ax+b)라고 볼 수 있다.

그렇다면 mul * a x + mul * b의 상태가 적절할 것이다.

값을 ax + b의 형태로 표현할 줄을 생각도 못했다. 허어...기발한 아이디어는 끝도 없는 것 같다.

*/