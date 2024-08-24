#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {0, 1, 0, -1}; int dy[] = {-1, 0, 1, 0};
//NESW
int N, M, K, a, b, res = 0;
char inp;
int m[101][101][2];
bool visited[101][101][(1<<9)];

void bfs(){
    queue <t5> q;
    visited[1][1][0] = 1;
    q.push(make_tuple(1,1,0,0,0));

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int trea = get<3>(q.front());//얻은 보물
        int treacnt = get<4>(q.front());//개수

        q.pop();

        if(x == M && y == N && treacnt == K){
            res = cnt;
            return;
        }

        bool chk = false;
        //현 위치에서 모든 4방향에 도달했는지 확인
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx][trea]) chk = true;
        }

        if(chk) q.push(make_tuple(x,y,cnt + 1,trea,treacnt));
        //시간에 따른 방향 구현
        int curdic = m[y][x][0]; 
        int nx = x + dx[(curdic + (cnt % 4)) % 4];
        int ny = y + dy[(curdic + (cnt % 4)) % 4];

        int istrea = m[ny][nx][1];
        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
        //보물이 없으면 단순 전진
        if(!istrea && !visited[ny][nx][trea]){
            visited[ny][nx][trea] = 1;
            q.push(make_tuple(nx,ny,cnt + 1,trea,treacnt));
        }//보물이 있으면 해당 보물을 얻었는지 확인 및 전진
        else if(istrea){
            int ntrea = trea;
            int ntreacnt = treacnt;
            if(!(ntrea & (1 << istrea))){
                ntrea |= (1 << istrea);
                ntreacnt++;
            }
            if(!visited[ny][nx][ntrea]){
                visited[ny][nx][ntrea] = 1;
                q.push(make_tuple(nx,ny,cnt + 1,ntrea,ntreacnt));
            }
        }
    }
}

void init(){//초기화
    fill_n(&m[0][0][0], 101*101*2, 0);
    fill_n(&visited[0][0][0], 101*101*(1<<9), 0);
    res = 0;
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    while(cin >> N >> M){
        if(N == 0 && M == 0) break;
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                cin >> inp;
                switch (inp)
                {
                case 'N':
                    m[i][j][0] = 0; break;
                case 'E':
                    m[i][j][0] = 1; break;
                case 'S':
                    m[i][j][0] = 2; break;
                case 'W':
                    m[i][j][0] = 3; break;
                }
            }
        }
        cin >> K;
        for(int i = 1;i<K+1;i++){
            cin >> b >> a;
            m[b][a][1] = i;
        }
        bfs();
        cout << res << '\n';
        init();
    }
}
/*
BFS + 비트마스킹.
다른 문제와 다르게 맵에 갈 수 있는 방향이 정해져있고 주기가 있다는 점.

그래서 처음 초기값을 받고 시계 방향으로 움직이는 것을 구현해줘야 한다.

보물의 경우 번호를 부여해 저장한다.

2가지 경우
1. 갈 수 있는 방향으로 움직인다.
2. 현 위치에서 대기한다.

1은 기존과 똑같이 구현하면 되고,
2는 4방향을 모두 확인해서 방문한 적 없는 곳이 존재하면 실행.

보물을 획득하는 것 등등...에 대해 모두 구현하고 나면 완료된다.
*/