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
#define mod 1'000'000'007
//int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1}; int dy[] = {0, 1, 0 ,-1, 1, -1, 1, -1};
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0 ,-1};

int N, M, input, map[51][51], visited[51][51], visit[2501], wall = 0, res = -1;

vector <pair<int,int>> vt, selected;//바이러스 좌표(x,y)
queue <pair<pair<int,int>,int>> q;//x,y,time

void bfs(){
    for(int i = 0;i<selected.size();i++){
        q.push({{selected[i]},0});
        visited[selected[i].second][selected[i].first] = true;
    }
    int restime = 0, count = M;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

            if(!visited[ny][nx] && map[ny][nx] == 0){
                visited[ny][nx] = true; 
                restime = max(restime, time + 1);//가능한 0을 2로 채울 때까지의 걸리는 시간
                count++;
                q.push({{nx,ny}, time + 1});
            }
        }
    } 
    if(N*N - wall == count){//모든 0을 채웠는지 확인
        if(res == -1) res = restime;
        else res = min(res, restime);
    }

    fill(visited[0],visited[51],0);
}

void push(int idx, int cnt){//조합
    if(cnt == M){//M개를 뽑은 경우 bfs 탐색
        bfs();
        return;
    }

    for(int i = idx;i<vt.size();i++){//원소를 M개 만큼 뽑아준다.
        if(!visit[i]){
            visit[i] = true;
            selected.push_back({vt[i]});
            push(i + 1,cnt + 1);  
            selected.pop_back();
            visit[i] = false;
        }
    }
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> input;
            if(input == 2){
                vt.push_back({j,i});//x,y
                map[i][j] = 0;
            }
            else map[i][j] = input;
            if(map[i][j] == 1) wall++;
        }
    }
    push(0,0);
    cout << res;
}//95퍼?
