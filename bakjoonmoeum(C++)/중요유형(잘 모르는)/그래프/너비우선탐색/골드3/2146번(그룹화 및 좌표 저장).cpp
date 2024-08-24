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
//int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1}; int dy[] = {0, 1, 0 ,-1, 1, -1, 1, -1};
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0 ,-1};

int N, input, grnum = 1, map[101][101], visited[101][101][2], res = 100000001;

queue <pair<int,int>> q;//x,y 
queue <pair<pair<int,int>,int>> q2, list;//x,y,cnt/ x,y,grnum

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visited[y][x][0] = grnum;
        list.push({{x,y}, grnum});//조건을 만족하는 모든 좌표 저장
        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

            if(!visited[ny][nx][1] && map[ny][nx] == 1){
                q.push({nx,ny}); visited[ny][nx][1] = true;
            }
        }
    }
}

void bfs2(int num){
    while(!q2.empty()){
        int x = q2.front().first.first;
        int y = q2.front().first.second;
        int cnt = q2.front().second;

        q2.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            
            if(map[ny][nx] == 0 && (visited[ny][nx][1] > cnt + 1 || !visited[ny][nx][1])){
                visited[ny][nx][1] = cnt + 1;
                q2.push({{nx,ny},cnt + 1});
            }
            if(map[ny][nx] == 1 && visited[ny][nx][0] != num){//그룹이 다른 1이 존재하는 좌표 발견
                res = min(res, visited[y][x][1]); 
                while(!q2.empty()) q2.pop();
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    for(int i = 1;i<N+1;i++){//그룹 설정
        for(int j = 1;j<N+1;j++){
            if(map[i][j] == 1 && !visited[i][j][1]){
                q.push({j,i});
                visited[i][j][1] = true; bfs(); grnum++;
            }
        }
    } 
    for(int i = 1;i<N+1;i++) for(int j = 1;j<N+1;j++) visited[i][j][1] = 0;

    while(!list.empty()){//모든 1에 대해서 다른 모든 그룹 1에 대한 최단 거리 조사
        q2.push({{list.front().first.first, list.front().first.second}, 0});
        bfs2(list.front().second);
        list.pop();
    }
    cout << res;
}
/*
for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cout << visited[i][j][1] << ' ';
        }cout << '\n';
    }
*/



