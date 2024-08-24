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
#define mod 998'244'353
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int dic[] = {(1<<0), (1<<1), (1<<2), (1<<3)};
int M, N, m[51][51], visited[51][51], ans1, ans2 = 0, ans3 = 0, grnum = 1;
vector <int> grcnt;
queue <pii> q;

int bfs(){
    int room = 0;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        room++;

        q.pop(); //cout << y << ' ' << x << '\n';
 
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

            if(m[y][x] & dic[i]) continue;
            
            if(!visited[ny][nx]){
                visited[ny][nx] = grnum;
                q.push({nx,ny});
            }
        }
    }
    return room;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> m[i][j];
        }
    }
    for(int i = 1;i<M+1;i++){
        for(int j = 1;j<N+1;j++){
            if(!visited[i][j]){
                visited[i][j] = grnum;
                q.push({j,i});
                int room = bfs();
                grcnt.push_back(room); grnum++;
                ans2 = max(ans2, room);
            }
        }
    }
    ans1 = grnum - 1;
    //printmap(M, N, visited);

    for(int i = 1;i<M+1;i++){
        for(int j = 1;j<N+1;j++){
            for(int k = 0;k<4;k++){
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

                if(visited[ny][nx] != visited[i][j]){
                    ans3 = max(ans3, grcnt[visited[ny][nx] - 1] + grcnt[visited[i][j] - 1]);
                }
            }
        }
    }
    if(ans1 == 1) ans3 = grcnt[0];
    cout << ans1 << '\n' << ans2 << '\n' << ans3;
}
/*


*/