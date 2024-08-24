#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 31) - 1

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, M, res = -1, vismnum = 1, vism[5][6];
char m[5][6];
bool visited[5][6][(1 << 21)];

struct info{
    int vis, x, y, cnt, steal;
};

queue <info> q;

bool check(int x, int y, int steal, int vis){//중요한 최적화 코드
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > 5 || ny > 4 || m[ny][nx] == '.' ||
        (m[ny][nx] < 58 && steal + 2 <= (m[ny][nx] - 48)) || steal - 10 + 2 <= (m[ny][nx] - 65)) continue;

        int nvis = vis | (1 << vism[ny][nx]);

        if(m[y][x] == '#' && nvis != vis) return true;
        //이유는 모르겠으나 m[y][x] == '#'를 추가 삽입하니 통과하였음.
    }
    return false;
}//요약: 방문하지 않은 노드가 없는 경우에만 노드를 재방문하도록 허용(단, 현 위치가 '#'일 때만)

void bfs(){
    while(!q.empty()){
        auto [vis, x, y, cnt, steal] = q.front();

        q.pop(); //cout << y << ' ' << x << ' ' << cnt << ' ' << vis << ' ' << steal << '\n';

        if(!(vis ^ ((1 << vismnum) - 2))){//모든 점을 방문한 경우
            res = cnt;
            return;
        }

        bool mod = check(x,y,steal,vis);//한 번도 방문하지 않은 노드가 있는지 체크

        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > 5 || ny > 4 || m[ny][nx] == '.' ||
            (m[ny][nx] < 58 && steal + 2 <= (m[ny][nx] - 48)) || steal - 10 + 2 <= (m[ny][nx] - 65)) continue;

            int nvis = vis | (1 << vism[ny][nx]);
            int nsteal = steal;

            if(m[ny][nx] == '#'){
                if(mod && nvis == vis) continue;
                if(!visited[ny][nx][nvis]){
                    visited[ny][nx][nvis] = 1;
                    q.push({nvis,nx,ny,cnt + 1,nsteal});
                }
            }
            else{//#가 아닌 노드를 방문할 때
                if((m[ny][nx] < 58 && steal + 1 == (m[ny][nx] - 48)) || steal - 10 + 1 == (m[ny][nx] - 65)) nsteal++;

                if(!visited[ny][nx][nvis]){
                    visited[ny][nx][nvis] = 1;
                    q.push({nvis,nx,ny,cnt + 1,nsteal});
                }
            }
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int j = 0;j < N;j++){
        for(int i = 1;i < 5;i++){
            for(int j = 1;j < 6;j++){
                cin >> m[i][j];
                if(m[i][j] != '.') vism[i][j] = vismnum++;
                if(m[i][j] == '0'){
                    int svis = (1 << vism[i][j]);
                    visited[i][j][svis] = 1;
                    q.push({svis,j,i,0,0});
                }
            }
        }
        bfs(); cout << res << '\n';
        while(!q.empty()) q.pop();
        fill_n(&visited[0][0][0], 5*6*(1 << 21), 0); fill_n(&vism[0][0], 5*6, 0);
        vismnum = 1; res = -1;
    }
}
/*
이걸 풀 줄은 몰랐네...
*/