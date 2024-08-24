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

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0 ,-1};

int N, M, res = -1, objnum = 48;
char m[51][51];
bool visited[(1<<5)][51][51];
queue <t5> q;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int obj = get<3>(q.front());
        int objcnt = get<4>(q.front());
        
        q.pop(); //cout << y << ' ' << x << ' ' << cnt << '\n';

        if(m[y][x] == 'E' && objcnt == objnum - 48){
            cout << cnt << '\n';
            exit(0);
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == '#') continue;
            
            if(m[ny][nx] != 'E' && m[ny][nx] != '.' && !(obj & (1 << (m[ny][nx] - 48)))){
                int nobj = obj; nobj |= 1 << (m[ny][nx] - 48);
                int nobjcnt = objcnt + 1;
                if(!visited[nobj][ny][nx]){
                    visited[nobj][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1, nobj, nobjcnt));
                }
            }else{
                if(!visited[obj][ny][nx]){
                    visited[obj][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1, obj, objcnt));
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] == 'S'){
                visited[0][i][j] = 1;
                q.push(make_tuple(j,i,0,0,0));
                m[i][j] = '.';
            }
            else if(m[i][j] == 'X'){
                m[i][j] = objnum++;
            }
        }
    }
    bfs();
}
/*



*/