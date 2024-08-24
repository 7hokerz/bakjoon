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
int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0 ,-1, 1, -1, 1, -1};

int visited[9][9], map[9][9];
string input;

queue <pair<pair<int,int>,int>> q;//y,x

void update(){
    for(int i = 8;i>=1;i--){
        for(int j = 1;j<9;j++){
            map[i][j] = map[i-1][j];
        }
    } 
}

bool can = false;

void bfs(){
    int time = 0;
    q.push({{1,8},time});//x,y

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int curtime = q.front().second;

        if(x == 8 && y == 1){
            can = true; return;
        }

        if(curtime != time){
            time = curtime; update();
        }

        q.pop();

        for(int i = 0;i<8;i++){//갈 수 있는 곳 탐색하여 가기
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > 8 || ny > 8) continue;

            if(!visited[ny][nx] && map[ny][nx] == 0){
                visited[ny][nx] = true;
                q.push({{nx,ny},curtime + 1});
            }
        }
        if(map[y][x] == 0) q.push({{x,y},curtime + 1});//가만히 있는 경우
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 1;i<9;i++){
        cin >> input;
        for(int j = 1;j<9;j++){
            if(input[j-1] == '.'){
                if(map[i-1][j] == 1){
                    map[i][j] = map[i-1][j]+1;
                }
                else{
                    map[i][j] = 0;
                }
            }
            else{
                map[i][j] = 1;
            }
        }
    }
    bfs();
    cout << can;
}
/*
처음 벽의 위치와, 바로 아래에 또 벽 1을 두기(2)
결과적으로 1과 2의 칸은 모두 움직일 수 없는 칸

cnt는 결국 순차적으로 증가하므로
cnt가 바뀌면 맵의 아래서부터 시작해
현재의 칸은 바로 위의 칸의 요소로 변경시킨다.

for(int i = 1;i<9;i++){
        for(int j = 1;j<9;j++){
            cout << map[i][j] << ' ';
        }cout << '\n';
    }

*/