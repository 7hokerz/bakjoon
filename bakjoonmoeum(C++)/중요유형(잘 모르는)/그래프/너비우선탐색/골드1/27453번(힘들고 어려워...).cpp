#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,pii> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {0, 1, 0, -1}; int dy[] = {-1, 0, 1, 0};

int N, M, K, res = -1;
pii st, en;
int visited[4][1001][1001];
char m[1001][1001];

queue <t4> q;

void bfs(){
    pii prev = {0,0};
    for(int i = 0;i<4;i++) visited[i][st.second][st.first] = 0;

    q.push(make_tuple(st.first, st.second, 0, prev));

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        pii pre = get<3>(q.front());
        
        q.pop(); 

        if(x == en.first && y == en.second){
            res = cnt;
            return;
        }
        
        int sum = m[pre.second][pre.first] - 48; sum += m[y][x] - 48;//이전 값 + 현재 값

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == 'X') continue;
            if(nx == pre.first && ny == pre.second) continue;//바로 이전 좌표로는 이동할 수 없음.

            int nxnum = m[ny][nx] - 48;//다음 값

            //총 불상사의 합이 K이하면서 방문하지 않은 경우(또는 이전 방문보다 합이 작은 경우)
            if(nxnum + sum <= K && (visited[i][ny][nx] == -1 || visited[i][ny][nx] > nxnum + sum)){
                visited[i][ny][nx] = nxnum + sum; pii pre = {x,y};
                q.push(make_tuple(nx,ny,cnt + 1, pre));
            }
        }
    }
}

int main(){ fill_n(&visited[0][0][0], 4*1001*1001, -1);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] == 'S'){
                st.first = j; st.second = i; m[i][j] = '0';
            }
            else if(m[i][j] == 'H'){
                en.first = j; en.second = i; m[i][j] = '0';
            }
        }   
    }
    bfs();
    cout << res;
}

/*




*/