#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp, ret = 0;
string str;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        int ret = 0;
        cin >> N;
        int arr[N+1];
        for(int i = 1;i<N+1;i++) cin >> arr[i];
        
        int mx = N;
        while(mx != 1){
            for(int i = 1;i<N+1;i++){
                if(arr[i] == mx){
                    for(int j = i + 1;j<mx+1;j++){
                        arr[j - 1] = arr[j];
                        ret++;
                    }
                }
            }
            mx--;
        }
        cout << ret << '\n';
    }
}
/*
3 2 1 4
3 1 2 4
1 3 2 4
1 2 3 4

4

3 1 2

1 3 2
1 2 3

2

inversion counting?

버블 소트와 관련있는 듯 하다.
N이 충분히 많이 컸으면 다른 알고리즘이 필요하다.
*/