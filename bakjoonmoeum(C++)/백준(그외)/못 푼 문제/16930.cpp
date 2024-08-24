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

int N, M, K, xs, xe, ys, ye, res = -1, visited[1001][1001];
char m[1001][1001];
string input;
queue <t3> q;

void bfs(){
    visited[ys][xs] = 1;
    q.push(make_tuple(xs,ys,0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());

        q.pop(); cout << y << ' ' << x << ' ' << cnt << '\n';

        bool chk[4] = {0,0,0,0};

        for(int k = 1;k<K+1;k++){
            for(int i = 0;i<4;i++){
                int nx = x + dx[i] * k;
                int ny = y + dy[i] * k;
                
                if(nx < 1 || ny < 1 || nx > M || ny > N || chk[i]) continue;
                if(m[ny][nx] == '#') {
                    chk[i] = 1; continue;
                }
                
                if(m[ny][nx] == '.' && !visited[ny][nx]){
                    if(nx == xe && ny == ye){
                        res = cnt + 1;
                        return;
                    }
                    bool check = false;
                    if(k != K){
                        for(int j = 0;j<4;j++){
                            if((i == 0 || i == 2) && (j == 0 || j == 2)) continue;
                            if((i == 1 || i == 3) && (j == 1 || j == 3)) continue;
                            int nnx = nx + dx[j];
                            int nny = ny + dy[j];
                            
                            if(nnx < 1 || nny < 1 || nnx > M || nny > N) continue;
                            //cout << ny << ' ' << nx << ' ' << cnt << '\n';

                            if(m[nny][nnx] == '.'){
                                check = true;
                                break;
                            }
                        }
                        if(check){
                            visited[ny][nx] = cnt + 1;
                            q.push(make_tuple(nx,ny,cnt + 1));
                        }  
                    }else{
                        visited[ny][nx] = cnt + 1;
                        q.push(make_tuple(nx,ny,cnt + 1));
                    }
                }
            }
        }
        
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
        }
    }
    cin >> ys >> xs >> ye >> xe;
    bfs();
    cout << res;
}
/*


*/