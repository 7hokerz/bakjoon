#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,pii> t6;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

char m[1001][1001];
int N, M, K, res = -1;
bool visited[1001][1001], visitedPower[2][2][1001][1001];
//해당 부분이 힘을 쓴 곳의 영역에 포함되는지 여부, 방향(오른쪽, 아래), 좌표

queue <t6> q;

void bfs(){
    visited[1][1] = 1; pii cur = {0,0};
    q.push(make_tuple(1,1,0,0,0,cur));

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int power = get<3>(q.front());
        int dic; pii loc;
        if(power){
            dic = get<4>(q.front());//힘을 쓴 방향(power가 0이면 상관 X)
            loc = get<5>(q.front());//힘을 쓴 위치(power가 0이면 상관 X)
        }

        q.pop(); //cout << y << ' ' << x << ' ' << cnt << ' ' << power << ' ' << dic << ' ' << loc.second << ' ' << loc.first << '\n';

        if(x == M && y == N){
            res = cnt; //cout << cnt << '\n';
            return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            //힘을 쓴 적 없고 벽이 아닌 경우
            if(m[ny][nx] == '0' && !power && !visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push(make_tuple(nx,ny,cnt + 1, 0, 0, loc));
            }

            int npower = power; int ndic = dic; pii nloc = loc;

            //힘을 쓰지 않았고 쓸 경우
            if(!npower && i > 1){
                npower = 1; ndic = i - 2; nloc = {x, y};
                visitedPower[1][ndic][y][x] = 1;
            }

            if(npower){//힘을 이미 쓴 경우
                if(((ny == nloc.second && (ndic == 0 && nx >= nloc.first)) ||
                (nx == nloc.first && (ndic == 1 && ny >= nloc.second)))){
                    if(!visitedPower[1][ndic][ny][nx]){
                        visitedPower[1][ndic][ny][nx] = 1;
                        q.push(make_tuple(nx,ny,cnt + 1, 1, ndic, nloc));
                    }
                }
                else if(m[ny][nx] == '0' && !visitedPower[0][ndic][ny][nx]){
                    visitedPower[0][ndic][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1, 1, ndic, nloc));
                }
            }
        }
    }
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++) for(int j = 1;j<M+1;j++) cin >> m[i][j];
        
    bfs();
    cout << res << '\n';
}
/*

*/