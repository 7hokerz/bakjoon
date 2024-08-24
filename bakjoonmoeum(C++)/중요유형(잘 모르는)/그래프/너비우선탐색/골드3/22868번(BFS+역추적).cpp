#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, a, b, c, s, e, res = 0;
int visited[10'001][2];
vector <int> gr[10'001];

queue <pii> q;
vector <int> vt;

void track(int node){
    int pre = node;
    while(pre != -1){
        vt.push_back(pre);
        pre = visited[pre][1];
    }
    fill(visited[0], visited[10001], 0);
    while(!q.empty()) q.pop();
}

void bfs(bool mod){
    while(!q.empty()){
        int x = get<0>(q.front());
        int cnt = get<1>(q.front());

        q.pop(); //cout << x << ' ' << cnt << ' ' << visited[x][1] << '\n';

        if(!mod && x == e){ //cout << cnt << '\n';
            res += cnt;
            track(e);
            return;
        }
        else if(mod && x == s){ //cout << cnt << '\n';
            res += cnt;
            return;
        }

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];

            if(!visited[nx][0]){
                visited[nx][0] = 1; visited[nx][1] = x;
                q.push({nx,cnt + 1});
            }
        }
    }
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0;i<M;i++){
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int i = 1;i<N+1;i++) sort(gr[i].begin(), gr[i].end());
    
    cin >> s >> e;

    visited[s][0] = 1; visited[s][1] = -1; q.push({s,0});
    bfs(0);
    
    for(int i = 0;i<vt.size();i++){
        //cout << vt[i] << ' '; 
        visited[vt[i]][0] = 1;
    }//cout << '\n';

    visited[s][0] = 0; q.push({e,0});
    bfs(1);
    cout << res;
}
/*

*/