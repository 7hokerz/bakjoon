#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define mod 998'244'353

int N, Q, Qi, ret = 0;
int arr[200'005], sum[200'005];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> Q;
    for(int i = 1;i<N+1;i++) cin >> arr[i];
    arr[N+1] = arr[1]; arr[N+2] = arr[2]; arr[N+3] = arr[3];
    
    for(int i = 4;i<N+4;i++) sum[i-3] = arr[i-3] * arr[i-2] * arr[i-1] * arr[i];
    
    for(int i = 1;i<N+1;i++) ret += sum[i];

    for(int i = 1;i<Q+1;i++){
        cin >> Qi;
        for(int j = Qi;j>Qi-4;j--){
            if(j < 1) {
                sum[j+N] *= -1; ret += sum[j+N] * 2;
            }
            else {
                sum[j] *= -1; ret += sum[j] * 2;
            }
        }
        cout << ret << '\n';
    }
}
/* 누적 합 문제. 코포에 어느 정도 자주 나오는 유형이라고 생각한다.
1: 1234
2: 2345
3: 3456
4: 4567
5: 5678
6: 6781
7: 7812
8: 8123
*/