#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define mod 1'000'000'009
#define INF 2'000'000'001

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, stx, sty, gox, goy, res = -1, visited[2][1001][1001];
int m[1001][1001];
queue <t4> q;

void bfs(){
    visited[0][sty][stx] = 1;
    q.push(make_tuple(stx,sty,0,0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int jump = get<3>(q.front());

        q.pop(); //cout << y << ' ' << x << ' ' << cnt << ' ' << jump << '\n';

        if(x == gox && y == goy){
            res = cnt;
            return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i] * m[y][x];
            int ny = y + dy[i] * m[y][x];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(jump == 0){
                for(int k = 1;k<1001;k++){ 
                    int chk = 0; if(k == m[y][x]) continue;
                    for(int j = 0;j<4;j++){
                        int nnx = x + dx[j] * k;
                        int nny = y + dy[j] * k;

                        if(nnx < 1 || nny < 1 || nnx > M || nny > N) {
                            chk++; continue;
                        }
                        if(!visited[jump + 1][nny][nnx]){
                            visited[jump + 1][nny][nnx] = 1;
                            q.push(make_tuple(nnx,nny,cnt + 1,jump + 1));
                        }
                    } 
                    if(chk == 4) break; 
                }
            }

            if(!visited[jump][ny][nx]){
                visited[jump][ny][nx] = 1;
                q.push(make_tuple(nx,ny,cnt + 1,jump));
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> sty >> stx >> goy >> gox;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
        }
    }
    bfs();
    cout << res;
}
/*


*/