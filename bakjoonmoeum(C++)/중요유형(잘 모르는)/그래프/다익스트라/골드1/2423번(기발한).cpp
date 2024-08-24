#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int,int> t4;
#define INF 1e9

int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1}; int dy[] = {0, 1, 0, -1, -1, -1, 1, 1};
//WSEN NW NE SW SE

int N, M, res = 0;

int dist[2][502][502];
char m[502][502];

void dij(){
    priority_queue<t4, vector<t4>, greater<t4>> pq;
    if(m[1][1] == '1'){
        pq.push({1,1,1,0});
        dist[0][1][1] = 1;
    }
    else{
        pq.push({0,1,1,0});
        dist[0][1][1] = 0;
    }
    
    while(!pq.empty()){
        auto [cost, x, y, curstat] = pq.top();

        pq.pop(); //cout << curstat << ' ' << y << ' ' << x << ' ' << cost << '\n';

        if(dist[curstat][y][x] < cost) continue;

        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            int ncost = cost;   
            int nstat = m[ny][nx] - 48;

            if(!curstat){
                if(i == 5 || i == 6) continue;
                if(i < 4 && !(m[ny][nx] - 48)){
                    ncost++;
                }
                else if(i >= 4 && (m[ny][nx] - 48)){//>가 아니라 >= 다...아오 ㅅㅂ
                    ncost++;
                }
            }
            else{
                if(i == 4 || i == 7) continue;
                if(i < 4 && (m[ny][nx] - 48)){
                    ncost++;
                }
                else if(i > 4 && !(m[ny][nx] - 48)){
                    ncost++;
                }
            }

            if(ncost != cost) nstat = !nstat;

            if(dist[nstat][ny][nx] > ncost){
                dist[nstat][ny][nx] = ncost;
                pq.push({ncost,nx,ny,nstat});
            }
        }
    }
}


int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill_n(&dist[0][0][0], 2*502*502, INF);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] == '\\') m[i][j] = '0';
            else m[i][j] = '1';   
        }
    }

    dij();
    
    if(dist[0][N][M] == INF) cout << "NO SOLUTION";
    else cout << dist[0][N][M];
}
/*
    왼쪽 위 >> 오른쪽 아래 : 0 
    왼쪽 아래 >> 오른쪽 위 : 1

    현 좌표: 0
    0 >> 1 1 >> 1 2 >> 1 3 >> 1 : 0일 때 비용+1
    4 >> 0 5 >> X 6 >> X 7 >> 0 : 1일 때 비용+1

    현 좌표: 1
    0 >> 0 1 >> 0 2 >> 0 3 >> 0 : 1일 때 비용+1
    4 >> X 5 >> 1 6 >> 1 7 >> X : 0일 때 비용+1

*/