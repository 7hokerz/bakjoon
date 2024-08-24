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

int N, visited[51][51];//벽을 부순 개수 저장
string input;char map[51][51];

queue <pair<int,int>> q;//x,y,wall

void bfs(){
    q.push({1,1});
    visited[1][1] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

            if(map[ny][nx] == '1'){//단순히 갈 수 있는 공간
                if(visited[ny][nx] > visited[y][x]){
                    visited[ny][nx] = visited[y][x];
                    q.push({nx,ny});
                }
            }
            else{//벽 공간
                if(visited[ny][nx] > visited[y][x] + 1){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    fill(visited[0], visited[51], 9876543);
    int val = 0;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<N+1;j++){
            map[i][j] = input[j-1]; 
        }
    }
    bfs();
    
    cout << visited[N][N];
}
