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

int m[101][101], visited[4][14][101][101];//방향, 가속도, y, x
int N, res = -1;
queue <t5> q;

void bfs(){
    q.push(make_tuple(1,1,0,-1,0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int rot = get<3>(q.front());
        int rotcnt = get<4>(q.front());//같은 방향에 대한 카운트
        
        q.pop(); //cout << y << ' ' << x << ' ' << cnt << ' ' << rot << ' ' << rotcnt << '\n';

        if(x == N && y == N){
            res = cnt;
            return;
        }
        
        for(int i = 0;i<4;i++){
            int nx = x; int ny = y;
            
            //방향이 같으면 카운트를 확인하고 해당 카운트 동안 전진하면서 목표지점까지 가는데 문제가 없는 지 확인
            if(i == rot){
                bool can = true;
                for(int k = 0;k<rotcnt;k++){
                    nx += dx[i]; ny += dy[i];
                    if(nx < 1 || ny < 1 || nx > N || ny > N) {can = false; break;}//지도를 벗어나는 경우
                    if(m[ny][nx] != 0 && m[ny][nx] <= cnt){can = false; break;}//중간에 통제 구역에 들어선 경우
                }
                if(!can) continue;
            }
            nx += dx[i]; ny += dy[i];
            
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(m[ny][nx] != 0 && m[ny][nx] <= cnt + 1) continue;
            
            if(i == rot){//이전과 같은 방향인 경우
                if(!visited[i][rotcnt + 1][ny][nx]){
                    visited[i][rotcnt + 1][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1, i, rotcnt + 1));
                }
            }
            else{
                if(!visited[i][1][ny][nx]){
                    visited[i][1][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1, i, 1));
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> m[i][j];
        }
    }
    bfs();
    if(res == -1) cout << "Fired";
    else cout << res;
}
/*
4차원 visit 방문 배열을 만들어야 하는 문제.
방향전환을 고려하는 것은 많이 봐왔기 때문에 당연하지만, 
가속도도 고려해야 했던 것이 중요했다. 어느 정도 후에 떠올리긴 했다.
*/