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

int N, M, res = 0; pii st;
char m[51][51];

bool visited[51][51], vis[251][251];
int node[51][51], parent[251];

vector <t3> spg, mst;

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

        if(mst.size() == M) return;
    }
}

void bfs(int sx, int sy){
    queue <t3> q;
    visited[sy][sx] = 1;
    q.push({sx,sy,0});

    while(!q.empty()){
        auto [x,y,cnt] = q.front();

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N || m[ny][nx] == '1') continue;

            if((m[ny][nx] == '0' || m[ny][nx] == 'K') && !visited[ny][nx]){
                if(m[ny][nx] == 'K'){
                    vis[node[sy][sx]][node[ny][nx]] = 1;
                    vis[node[ny][nx]][node[sy][sx]] = 1;
                    spg.push_back({cnt + 1, node[sy][sx], node[ny][nx]});
                }
                visited[ny][nx] = 1;
                q.push({nx,ny,cnt + 1});
            }
        }
    }
}

int nodenum = 1;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++) parent[i] = i;

    for(int i = 1;i<N+1;i++) {
        for(int j = 1;j<N+1;j++){
            cin >> m[i][j];
            if(m[i][j] == 'S'){ st.first = j; st.second = i;}
            else if(m[i][j] == 'K') node[i][j] = nodenum++;
        }
    }
    bfs(st.first, st.second);//S >> 모든 K

    for(int i = 1;i<N+1;i++) {//K >> 모든 K
        for(int j = 1;j<N+1;j++){
            if(m[i][j] == 'K'){
                fill_n(&visited[0][0], 51*51, 0);//위에 놓는 게 맞다...밑에 놓으면 첫 K에 대해 못 구하니까...
                bfs(j,i); //fill_n(&visited[0][0], 51*51, 0);//근데 왜 통과...?반례는 그렇다고 딱히 못찾겠는데 
            }
        }
    }
    //for(t3 val: spg) cout << get<0>(val) << ' ' << get<1>(val) << ' ' << get<2>(val) << '\n';
    sort(spg.begin(), spg.end());
    kruskal();

    for(t3 val: mst){
        res += get<0>(val); //cout << get<0>(val) << ' ' << get<1>(val) << ' ' << get<2>(val) << '\n';
    }

    if(res == 0 || mst.size() < M) cout << -1;
    else cout << res;
}
/*

*/