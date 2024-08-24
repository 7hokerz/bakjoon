#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, A, K, inp, ret = 0;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> A >> K;
    while(K != A){
        if(K % 2 || K / 2 < A){
            K--; ret++;
        }
        else{
            K /= 2; ret++;
        }
    }
    cout << ret;
}
/*


*/