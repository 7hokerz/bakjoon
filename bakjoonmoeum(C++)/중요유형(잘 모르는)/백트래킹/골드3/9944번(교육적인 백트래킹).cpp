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

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, total = 0, res = -1;
int visited[31][31];
char m[31][31];

void dfs(int x, int y, int cnt, int fill){ //cout << y << ' ' << x << ' ' << cnt << ' ' << fill << '\n';
    if(fill == total){
        if(res == -1) res = cnt;
        else res = min(res, cnt);
        return;
    }
    if(res != -1 && cnt >= res) return;//있나 없나...큰 차이가?

    vector <pii> loc;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == '*' || visited[ny][nx]) continue;

        while(1){
            visited[ny][nx] = 1;
            loc.push_back({nx,ny});
            nx += dx[i]; ny += dy[i];
            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == '*' || visited[ny][nx]) {
                nx -= dx[i]; ny -= dy[i];  break;
            }
        }
        dfs(nx,ny,cnt+1,fill+loc.size());
        while(!loc.empty()){
            visited[loc.back().second][loc.back().first] = 0;
            loc.pop_back();
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 1;
    while(cin >> N >> M){
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                cin >> m[i][j];
                if(m[i][j] == '.') total++;
            }
        }
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                if(m[i][j] == '.'){
                    visited[i][j] = 1;
                    dfs(j,i,0,1);
                    visited[i][j] = 0;
                }
            }
        }
        cout << "Case " << cnt << ": " << res << '\n';
        cnt++; res = -1; total = 0; fill(m[0], m[31], 48);
    }
}
/*
for(int k = 0;k<4;k++){
                        int nx = j + dx[k];
                        int ny = i + dx[k];

                        if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == '*'){
                            
                            break;
                        }
                    }
*/