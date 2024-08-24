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

int dx[] = {1,1,1,0,-1,-1,-1,0}; int dy[] = {1,0,-1,-1,1,0,-1,1};
int dx2[] = {1,-1,0}; int dy2[] = {1,1,1};

int N, inp;
int visited[21][21];
vector <pii> vt[21][21];
int res[21];

void cal(int x, int y, int calc){
    for(int i = 0;i<vt[y][x].size();i++){
        int nx = vt[y][x][i].first; int ny = vt[y][x][i].second;
        if(calc) visited[ny][nx]++;
        else visited[ny][nx]--;
    }
}

bool dfs(int x, int y){ 
    while(res[y] && y <= N+1) y++;
    if(y == N + 1) return true;

    bool chk = false;
    //cout << y << ' ' << x << '\n';
    for(int j = 1;j<N+1;j++){
        if(!visited[y][j]){
            visited[y][j]++;
            cal(j,y,1);

            if(dfs(j,y+1)){
                res[y] = j;
                chk = true;
                break;
            }

            visited[y][j]--;
            cal(j,y,0);
        }
    }
    return chk;
}

void fillcan(int x, int y){
    for(int i = 0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
            vt[y][x].push_back({nx,ny});
            nx += dx[i]; ny += dy[i];
        }
    }
}

void fillcan2(int x, int y){
    for(int i = 0;i<3;i++){
        int nx = x + dx2[i];
        int ny = y + dy2[i];

        while(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
            vt[y][x].push_back({nx,ny});
            nx += dx2[i]; ny += dy2[i];
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> inp; if(inp == 0) continue;
        res[i] = inp;
    }
    for(int i = 1;i<N+1;i++) {
        for(int j = 1;j<N+1;j++) {
            if(res[i] && j == res[i]){
                fillcan(j,i); cal(j,i,1);
            }
            else fillcan2(j,i); 
        }
    }

    int i = 1;
    while(res[i]) i++;

    for(int j = 1;j<N+1;j++){
        if(!visited[i][j]){
            visited[i][j]++;
            cal(j,i,1);

            if(dfs(j,i+1)){
                res[i] = j;
                break;
            }

            visited[i][j]--;
            cal(j,i,0);
        }
    }
    
    for(int i = 1;i<N+1;i++){
        if(res[i] == 0) {cout << -1; return 0;}
        
    }
    for(int i = 1;i<N+1;i++) cout << res[i] << ' ';
}
/*

*/