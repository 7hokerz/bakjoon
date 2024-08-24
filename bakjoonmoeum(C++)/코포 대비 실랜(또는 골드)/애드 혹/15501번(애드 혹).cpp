#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, M, K, prob[1'000'005], ans[1'000'005];
int adjp[1'000'005][2], adja[1'000'005][2];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++) {
        cin >> prob[i];
        adjp[prob[i]][0] = prob[i-1]; adjp[prob[i-1]][1] = prob[i];
    }
    adjp[prob[N]][1] = prob[1]; adjp[prob[1]][0] = prob[N];

    for(int i = 1;i<N+1;i++) {
        cin >> ans[i];
        adja[ans[i]][0] = ans[i-1]; adja[ans[i-1]][1] = ans[i];
    }
    adja[ans[N]][1] = ans[1]; adja[ans[1]][0] = ans[N];

    for(int i = 1;i<N+1;i++){
        if(!((adjp[i][0] == adja[i][0] && adjp[i][1] == adja[i][1]) || (adjp[i][0] == adja[i][1] && adjp[i][1] == adja[i][0]))){
            cout << "bad puzzle"; return 0;
        }
    }

    cout << "good puzzle";
}
/*
1. 뒤집기
2. 밀기

중요한 건 인접한 수는 항상 인접할 수 밖에 없음.

즉 arr[i]의 인접 수는 항상 arr[i-1]과 arr[i+1]이어야 함.

그냥 인접 수 넣고 비교하면 끝.
*/