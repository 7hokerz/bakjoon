#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N;
int ret[10001], powarr[15];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<16;i++){
        powarr[i] = pow(2,i);
    }

    for(int i = N;i>=1;i--){
        int idx = upper_bound(powarr, powarr+15, i) - powarr;

        int pownum = powarr[idx];
        
        int val = pownum - i;

        if(!ret[val] && !ret[i]){
            ret[val] = i; ret[i] = val;
        }
    }
    for(int i = 1;i<N+1;i++) cout << ret[i] << '\n';
}
/*
미리 제곱 수를 배열에 저장한 후,

큰 수부터 차례로 수를 부여한다. 
2의 거듭제곱이 i보다 커지는 수를 찾은 후 i를 빼준다. 해당 수는 짝이 된다.

ret에 값을 저장해주는데, 마치 방문 배열처럼 저장하여 값이 두 번 이상 들어가지 않게 만들어 준다.
*/