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

int dx[] = {1,-1,0}; int dy[] = {1,1,1};

int N, res = 0;
int visited[16][16];
vector <pii> vt[16][16];

void cal(int x, int y, int calc){
    for(int i = 0;i<vt[y][x].size();i++){
        int nx = vt[y][x][i].first; int ny = vt[y][x][i].second;
        if(calc) visited[ny][nx]++;
        else visited[ny][nx]--;
    }
}

void dfs(int x, int y, int cnt){ 
    if(cnt == N){
        res++; 
        return;
    }
    cal(x,y,1);//cout << y << ' ' << x << ' ' << can << ' ' << cnt << '\n';

    for(int j = 1;j<N+1;j++){
        if(!visited[y + 1][j]){//놓을 수 있는 경우
            visited[y+1][j]++;
            dfs(j,y+1, cnt + 1); 
            visited[y+1][j]--;
        }
    }
    cal(x,y,0);
}

void fillcan(int x, int y){
    for(int i = 0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
            vt[y][x].push_back({nx,ny});
            nx += dx[i]; ny += dy[i];
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++) for(int j = 1;j<N+1;j++) fillcan(j,i);
    
    for(int j = 1;j<N+1;j++){
        visited[1][j]++;
        dfs(j,1,1);
        visited[1][j]--;
    }
    cout << res;
}
/*

*/