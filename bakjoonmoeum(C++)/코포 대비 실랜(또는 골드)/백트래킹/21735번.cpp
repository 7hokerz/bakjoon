#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int N, M, arr[101], dp[101], ret = 0;

void bfs(){
    queue<t3>q;
    q.push({0,0,1});
    while(!q.empty()){
        auto[x,cnt,score] = q.front();

        q.pop();

        if(x == N || cnt == M){
            ret = max(ret, score);
            continue;
        }

        if(x + 1 <= N){
            int ns = score + arr[x + 1];
            if(dp[x + 1] < ns) {
                dp[x + 1] = ns;
                q.push({x+1, cnt + 1, ns});
            }
        }

        if(x + 2 <= N) {
            int ns = score / 2 + arr[x + 2];
            if(dp[x + 2] < ns) {
                dp[x + 2] = ns;
                q.push({x+2, cnt + 1, ns});
            }
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++) cin >> arr[i];
    
    bfs();
    cout << ret;
}
/*


*/