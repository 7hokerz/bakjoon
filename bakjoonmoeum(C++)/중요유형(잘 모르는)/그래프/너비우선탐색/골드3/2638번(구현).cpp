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
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int N, M, input, map[101][101], visitedair[101][101], visitedcheese[101][101];
int cheese = 0, time = 0;

queue <pair<int,int>> q;//x,y

void bfs0(){//연결된 0을 방문 처리
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visitedair[ny][nx] && map[ny][nx] == 0){
                visitedair[ny][nx] = true;
                q.push({nx,ny});
            }
        }
    }
}

void bfs1(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        int aircnt = 0;
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visitedcheese[ny][nx] && map[ny][nx] == 1){
                visitedcheese[ny][nx] = true;
                q.push({nx,ny});
            }
            if(map[ny][nx] == 0 && visitedair[ny][nx]){
                aircnt++;
            }
        }
        if(aircnt > 1) {
            map[y][x] = 2;
            cheese--;
        }//사라질 치즈 표시
    }
}

void update(){
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(map[i][j] == 2) map[i][j] = 0;
        }
    }
    time++;
    fill(visitedair[0],visitedair[101],0);
    fill(visitedcheese[0],visitedcheese[101],0);
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            if(input == 1) cheese++;
            map[i][j] = input;
        }
    }
    
    while(1){
        q.push({1,1});
        bfs0();//이 때 방문표시되지 않은 0은 제외하는걸로 가정
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                if(map[i][j] == 1 && !visitedcheese[i][j]){
                    visitedcheese[i][j] = true;
                    q.push({j,i});
                    bfs1();
                }
            }
        }
        if(cheese == 0) break;
        update();
    }  
    cout << time + 1; 
}   
/*
시간초과를 예상했으나 시간초과가 나지 않았네?

bfs0: 가장자리에는 1이 없으므로 1,1에서 시작해 모든 0을 방문처리시킨다.
이 때 방문처리되지 않은 1은 치즈에 둘러싸여있는 공기다.

bfs1: 모든 치즈에 대해서 탐색하는데 이 때 방문처리되지 않은 공기는 aircnt++을 하지 않음.
여기서 사라져야하는 치즈에 대해 추가로 표시한다.

update: 시간을 증가시키고 맵에 있는 2를 모두 0으로 바꾼 후 방문 배열들을 초기화함.



*/