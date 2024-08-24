#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, M, m[11][11], res = 0;
int parent[7], grnum = 1;
int vis[11][11];
vector <t3> spg, mst;

queue <pii> q;

void bfs(){
    while(!q.empty()){
        auto [x,y] = q.front();

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] == 1 && !vis[ny][nx]){
                vis[ny][nx] = grnum;
                q.push({nx,ny});
            }
        }
    }
}

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y) parent[y] = x;
}

void kruskal(){
    for(int i = 0;i<spg.size();i++){
        int w = get<0>(spg[i]);//가중치
        int f = get<1>(spg[i]);//정점1
        int s = get<2>(spg[i]);//정점2

        if(find(f) == find(s)) continue;//사이클 발생 시 제외
        //cout << f << ' ' << s << ' ' << w << '\n';
        mst.push_back({w,f,s});

        uni(f,s);

        if(mst.size() == grnum - 1) return;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<7;i++) parent[i] = i;

    for(int i = 1;i<N+1;i++) for(int j = 1;j<M+1;j++) cin >> m[i][j];
        
    for(int i = 1;i<N+1;i++){//그룹화
        for(int j = 1;j<M+1;j++){
            if(m[i][j] == 1 && !vis[i][j]){
                vis[i][j] = grnum; q.push({j,i});
                bfs();
                grnum++;
            }
        }
    }grnum--;

    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(m[i][j] == 1){
                for(int k = 0;k<4;k++){
                    int nx = j;
                    int ny = i;
                    int dist = 0;

                    while(1){
                        nx += dx[k];
                        ny += dy[k];

                        if(nx < 1 || ny < 1 || nx > M || ny > N) break;

                        if(m[ny][nx] == 1){
                            if(dist != 1 && vis[i][j] != vis[ny][nx]) {
                                spg.push_back({dist, vis[i][j], vis[ny][nx]});
                                //cout << i << ' ' << j << '\n' << vis[i][j] << ' ' << vis[ny][nx] << ' ' << dist << '\n';
                            }
                            break;
                        }
                        dist++;
                    }
                }
            }
        }
    }
    sort(spg.begin(), spg.end());

    kruskal();

    for(t3 val: mst) res += get<0>(val);

    //모든 섬을 연결하지 못한 경우를 처리해야 함.
    if(res == 0 || mst.size() < grnum - 1) cout << -1;
    else cout << res << '\n'; 
    //printmap(N,M,vis);
}
/*
**모든 섬을 연결하지 못한 경우에도 MST 함수는 특별한 오류를 나타내지 않고 리턴된다.
따라서 간선의 개수가 정확히 일치하는지 확인하는 작업이 필요하다.
*/