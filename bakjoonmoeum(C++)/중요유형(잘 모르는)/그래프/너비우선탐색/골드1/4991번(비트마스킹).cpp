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
typedef tuple<int,int,int,int,int,int> t6;
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int w, h, res = -1, trash = 48;
bool visited[21][21][(1<<11)];

void bfs(char m[21][21], queue <t5> q){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int clean = get<3>(q.front());
        int cleancnt = get<4>(q.front());

        q.pop();

        if(cleancnt == trash - 48){
            res = cnt; return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > w || ny > h || m[ny][nx] == 'x') continue;

            if(m[ny][nx] == '.' && !visited[ny][nx][clean]){
                visited[ny][nx][clean] = 1;
                q.push(make_tuple(nx,ny,cnt + 1,clean,cleancnt));
            }
            
            if(m[ny][nx] != '.'){//*가 아닌 번호를 부여하였기 때문에 위와 같이 표시
                if(!(clean & (1 << (m[ny][nx] - 48)))){
                    int nclean = clean;
                    int ncleancnt = cleancnt;

                    nclean |= (1 << (m[ny][nx] - 48));
                    ncleancnt++;

                    if(!visited[ny][nx][nclean]){
                        visited[ny][nx][nclean] = 1;
                        q.push(make_tuple(nx,ny,cnt + 1, nclean, ncleancnt));
                    }
                }
                else{//중요한 예외 케이스. *을 만난 경우에 대해 처리하지 않았기 때문에 이와 같은 문이 필요함. 
                    if(!visited[ny][nx][clean]){
                        visited[ny][nx][clean] = 1;
                        q.push(make_tuple(nx,ny,cnt + 1, clean, cleancnt));
                    }
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        char m[21][21]; 
        queue <t5> q;

        for(int i = 1;i<h+1;i++){
            for(int j = 1;j<w+1;j++){
                cin >> m[i][j];
                if(m[i][j] == 'o'){
                    visited[i][j][0] = 1;
                    q.push(make_tuple(j,i,0,0,0));
                    m[i][j] = '.';
                }
                else if(m[i][j] == '*'){
                    m[i][j] = trash++;
                }
            }
        }

        bfs(m, q); //printmap(h, w, m);
        cout << res << '\n';
        trash = 48; res = -1;
        fill_n(&visited[0][0][0], 21 * 21 * (1<<11), 0);
    }
}
/*


*/