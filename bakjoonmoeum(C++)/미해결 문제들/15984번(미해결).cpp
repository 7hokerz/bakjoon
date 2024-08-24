#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1
#define printmap(row, col, map)      \
    for (int k = 1; k < (row) + 1; k++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[k][j] << ' ';  \
        }cout << '\n';      \
    }cout << '\n'; \
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, M, Q, K, res1 = -1, res2 = 0, a, b;
int trea[10001], visited[2][10001], cantvisited[301][10001];
int treacnt[10001];
vector <int> gr[10001], cant[10001];

struct info{
    int x, cnt;
};

queue <info> q;

void bfs(){
    q.push({1,0}); visited[0][1] = 0;
    while(!q.empty()){
        auto[x, cnt] = q.front();

        q.pop();  //cout << x << ' ' << cnt << ' ' << trea[x] << '\n';

        if(cnt > K) continue;
        
        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];  

            if(visited[(cnt + 1) % 2][nx] == -1){
                visited[(cnt + 1) % 2][nx] = cnt + 1;
                q.push({nx, cnt + 1});
            }
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill_n(&visited[0][0], 2*10001, -1); fill_n(&cantvisited[0][0], 301*10001, -1);
    cin >> N >> M >> Q >> K;
    for(int i = 1;i<N+1;i++) cin >> trea[i];
    
    for(int i = 1;i<M+1;i++){//간선
        cin >> a >> b; 
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    
    for(int i = 1;i<Q+1;i++){//감시
        cin >> a >> b;
        cantvisited[i][b] = a;
    }

    bfs(); //printmap(Q, N, cantvisited);//감시 시간 확인

    for(int i = 1;i<N+1;i++){
        if(visited[K % 2][i] != -1) {
            res1 = max(res1, trea[i]);
            treacnt[i]++;
        }
    }

    for(int i = 1;i<N+1;i++){
        if(res1 == trea[i] && treacnt[i]) res2++;
    }

    if(res1 == -1) cout << -1;
    else cout << res1 << ' ' << res2;
}
/*
홀짝 느낌이 강하게 난다.
근데 이제 홀짝인데 특정 시간대에는 갈 수 없는 경우가 존재하니까 그걸 제외시키는 작업이 필요하다...



*/