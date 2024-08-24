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

int dx[] = {1, 1, -1, -1}; int dy[] = {1, -1, 1 ,-1};

int N, res1 = 0, res2 = 0;
int m[11][11], visited[11][11];
vector <pii> vt[11][11];

void cal(int x, int y, int calc){
    for(int i = 0;i<vt[y][x].size();i++){
        int nx = vt[y][x][i].first; int ny = vt[y][x][i].second;
        if(calc) visited[ny][nx]++;
        else visited[ny][nx]--;
    }
}

void dfs(int x, int y, int cnt, int mod, int &res){
    cal(x,y,1);
    int can = 0;
    for(int i = y;i<N+1;i++){ int j;
        if(i == y) j = x;
        else if(i % 2 == mod) j = 1;
        else j = 2;
        for(;j<N+1;j += 2) if(m[i][j] == 1 && !visited[i][j]) can++;
    }//cout << y << ' ' << x << ' ' << can << ' ' << cnt << ' ' << res1 << '\n';
    
    if(res < can + cnt){ 
        for(int i = y;i<N+1;i++){ int j;
            if(i == y) j = x;
            else if(i % 2 == mod) j = 1;
            else j = 2;
            for(;j<N+1;j += 2){
                if(m[i][j] == 1 && !visited[i][j]){//놓을 수 있는 경우
                    visited[i][j]++;
                    res = max(res, cnt + 1);
                    if(res < can + cnt) {
                        dfs(j,i, cnt + 1, mod, res); can--;
                    }
                    visited[i][j]--;
                }
            }
        }
    }
    cal(x,y,0);
} 

void fillcan(int x, int y){
    for(int i = 0;i<4;i++){
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
    for(int i = 1;i<N+1;i++) for(int j = 1;j<N+1;j++) cin >> m[i][j];

    for(int i = 1;i<N+1;i++) for(int j = 1;j<N+1;j++) fillcan(j, i);
    
    for(int i = 1;i<N+1;i++){ int j;
        if(i % 2 == 1) j = 1; else j = 2;
        for(;j<N+1;j += 2){
            if(m[i][j] == 1 && !visited[i][j]){//놓을 수 있는 경우
                visited[i][j]++;
                res1 = max(res1, 1);
                dfs(j,i,1,1,res1);
                visited[i][j]--;
            }
        }
    }

    for(int i = 1;i<N+1;i++){ int j;
        if(i % 2 == 0) j = 1; else j = 2;
        for(;j<N+1;j += 2){
            if(m[i][j] == 1 && !visited[i][j]){//놓을 수 있는 경우
                visited[i][j]++;
                res2 = max(res2, 1);
                dfs(j,i,1,0,res2);
                visited[i][j]--;
            }
        }
    }//cout << res1 << ' ' << res2;
    cout << res1 + res2;
}
/*
핵심 원리: 짝수와 홀수 즉 흑과 백 부분을 나눠서 따로 해야 시간을 줄일 수 있다.
왜냐하면 흑과 백은 서로 관계를 가지지 않기 때문.
흑에 있는 말이 백에 있는 말을 건드릴 수 없고, 그 반대로 마찬가지다.

우선 어떤 좌표의 위치에 말을 놓는다고 가정했을 때의 놓을 수 없는 지점에 대한 좌표를 미리 
벡터에 각각 저장시키고, 흑과 백에 대해서 따로 백트래킹하였다.

흑백 나누기가 큰 영향이었다. ㅠㅠ
*/