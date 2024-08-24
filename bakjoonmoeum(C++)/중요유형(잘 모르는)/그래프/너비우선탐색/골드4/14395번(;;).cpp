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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//북,동,남,서 총 4 방향 탐색
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0 ,-1};

int s, t, res = 0, input, visited[2];

queue <pair<int,string>> q;//val, cnt

void bfs(){
    q.push({s,""});
    while(!q.empty()){
        ll val = q.front().first;
        string cnt = q.front().second;

        if(val == t){ res = 1;
            cout << cnt; return;
        }

        q.pop();
        if(val != 0 && val != 1 && val * val <= t){
            q.push({val * val, cnt + '*'});
        }
        if(val != 0 && val + val <= t){ 
            q.push({val + val, cnt + '+'});
        }
        if(!visited[val - val]){ visited[0] = true;
            q.push({val - val, cnt + '-'});
        }
        if(val != 0 && !visited[val / val]){ visited[1] = true;
            q.push({val / val, cnt + '/'});
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t; if(s == t) {cout << 0; return 0;}
    bfs();
    if(res != 1) cout << -1;
}
/*
for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

            if(!visited[nx][ny] && map[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
*/