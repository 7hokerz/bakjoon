#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp; ll ret = 0;

unordered_map<ll,ll> m1, m2;

ll A[1001], B[1001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> A[i];
        A[i] += A[i-1];
    }
    cin >> M;
    for(int i = 1;i<M+1;i++){
        cin >> B[i];
        B[i] += B[i-1];
    }

    //A, B 따로 나올 수 있는 모든 부분 합을 계산하고 개수를 저장한다.
    for(int i = 1;i<N+1;i++){
        for(int j = i;j<N+1;j++){
            m1[A[j] - A[i-1]]++;
        }
    }

    for(int i = 1;i<M+1;i++){
        for(int j = i;j<M+1;j++){
            m2[B[j] - B[i-1]]++;
        }
    }

    //m1 또는 m2를 기준으로 T에서 부분 합을 뺀 값 중 다른 배열에서 만족하는 부분 합의 개수를 더해준다.
    for(auto &[k,v] : m2){
        ret += m1[T - k] * v;
    }

    cout << ret;
}
/*


*/