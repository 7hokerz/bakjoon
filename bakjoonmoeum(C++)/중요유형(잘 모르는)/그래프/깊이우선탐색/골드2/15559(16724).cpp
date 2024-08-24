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

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0 ,-1};//WSEN
int N, M, visited[1001][1001][2], grnum = 0;
char map[1001][1001];
string input;

int dfs(int x, int y){//cout << y << ' ' << x << '\n';
    int nx, ny;
    if(map[y][x] == 'W'){nx = x+dx[0]; ny = y+dy[0];}
    else if(map[y][x] == 'S'){nx = x+dx[1]; ny = y+dy[1];}
    else if(map[y][x] == 'E'){nx = x+dx[2]; ny = y+dy[2];}
    else{nx = x+dx[3]; ny = y+dy[3];}

    if(!visited[ny][nx][0]){//방문한 적 없는 경우
        visited[ny][nx][0] = 1;//방문 처리 및 dfs
        visited[y][x][1] = dfs(nx,ny);
    }
    else{//방문한 적 있는 경우 그룹 번호 확인 후 결정
        if(visited[ny][nx][1] == 0) visited[y][x][1] = ++grnum;
        else visited[y][x][1] = visited[ny][nx][1];
    }
    return visited[y][x][1];//그룹번호 반환
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++) map[i][j] = input[j-1];
    }
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(!visited[i][j][0]){
                visited[i][j][0] = 1;
                visited[i][j][1] = dfs(j,i);
            }
        }
    }
    cout << grnum;
}   
/*
문자만 바뀐 똑같은 풀이

*/ 