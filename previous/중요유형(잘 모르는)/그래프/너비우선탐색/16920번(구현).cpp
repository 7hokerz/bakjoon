#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, M, P, can[10], res[10], visited[1001][1001];//can: 최대 이동 범위, res: 결과
char m[1001][1001];
vector <pii> cas[10];//다음에 bfs를 시작할 위치 저장

struct info {
    int x, y, cnt;
};

queue <info> q;

void bfs(int player){
    while(!cas[player].empty()){
        q.push({cas[player].back().first, cas[player].back().second, 0});
        cas[player].pop_back();
    }

    while(!q.empty()){
        auto [x,y,cnt] = q.front();

        q.pop();

        if(cnt == can[player]){
            cas[player].push_back({x,y});
            continue;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] != '.') continue;

            if(!visited[ny][nx]){
                visited[ny][nx] = player;
                q.push({nx,ny,cnt + 1});
            }
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> P;
    for(int i = 1;i<P+1;i++) cin >> can[i];
    
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] != '#' && m[i][j] != '.'){
                cas[m[i][j] - 48].push_back({j,i});
                visited[i][j] = m[i][j] - 48;
            }
        }
    }

    while(1){
        bool chk = false;
        for(int i = 1;i<P+1;i++) if(!cas[i].empty()) { bfs(i); chk = true;}
        if(!chk) break;
    }

    for(int i = 1;i<N+1;i++) for(int j = 1;j<M+1;j++) res[visited[i][j]]++;
        
    for(int i = 1;i<P+1;i++) cout << res[i] << ' ';
}
/*
구현을 좀 해야 하는 것 외에는 큰 아이디어가 필요하진 않음.
*/