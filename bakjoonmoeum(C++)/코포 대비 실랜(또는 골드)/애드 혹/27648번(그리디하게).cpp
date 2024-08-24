#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, M, K;

int arr[1001][1001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            arr[i][j] = i+j-1;
        }
    }

    if(arr[N][M] > K) cout << "NO";
    else{ cout << "YES" << '\n';
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                cout << arr[i][j] << ' ';
            }cout << '\n';
        }
    }
}
/*
i,j+1이나 i+1,j의 요소 값은 i,j + 1로 구성하면 된다.
*/