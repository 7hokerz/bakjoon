#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, A, K, inp, ret = 0;
char arr[501][501], res[501][501];
int num[26][501][501];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1;i<N+1;i += K){
        for(int j = 1;j<M+1;j += K){
            for(int h = i;h<i+K;h++){
                for(int k = j;k<j+K;k++){
                    num[arr[h][k] - 65][h-i+1][k-j+1]++;
                }
            }
        }
    }
    
    for(int h = 1;h<K+1;h++){
        for(int k = 1;k<K+1;k++){
            int mx = 0;
            for(int i = 0;i<26;i++){
                if(num[i][h][k] > mx){
                    mx = num[i][h][k];
                    res[h][k] = i + 65;
                }
            }
        }
    }

    for(int h = 1;h<K+1;h++){
        for(int k = 1;k<K+1;k++){
            for(int i = h;i<N+1;i += K){
                for(int j = k;j<M+1;j += K){
                    if(res[h][k] != arr[i][j]) ret++;
                    res[i][j] = res[h][k];
                }
            }
        }
    }

    cout << ret << '\n';

    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cout << res[i][j];
        }cout << '\n';
    }
}
/*
그냥 K*K로 나눈 다음 같은 위치에서 가장 빈도가 많은 걸 택하고 나머진 바꾸면 됨.

*/