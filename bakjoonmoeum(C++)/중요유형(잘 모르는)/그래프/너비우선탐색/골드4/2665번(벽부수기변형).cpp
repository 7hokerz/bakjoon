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

int N, res = 2501;
string input;
char map[51][51];
int visited[2501][51][51];

queue <pair<pair<int,int>,int>> q;//x,y,wall

void bfs(){
    q.push({{1,1},0});
    visited[0][1][1] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;

        q.pop();
        if(x == N && y == N) res = min(res, wall);
        
        if(wall >= res) continue;

        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

            if(map[ny][nx] == '1' && !visited[wall][ny][nx]){
                visited[wall][ny][nx] = 1;
                q.push({{nx,ny},wall});
            }
            if(wall < res && map[ny][nx] == '0' && !visited[wall+1][ny][nx]){
                visited[wall + 1][ny][nx] = 1;
                q.push({{nx,ny},wall + 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int val = 0;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<N+1;j++){
            map[i][j] = input[j-1]; 
        }
    }
    bfs();
    
    cout << res;
}