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
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 0; i < (row); i++){   \
        for (int j = 0; j < (col); j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1}; int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int N, M, T, Xc, Yc, Xi, Yi, K, visited[101][101], vis[101][101][101];
queue <t3> q;//x,y,cnt

void fillBullet(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        //cout << y << ' ' << x << ' ' << cnt << '\n';
        q.pop();

        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

           if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(visited[ny][nx] == -1 || visited[ny][nx] > cnt + 1){
                visited[ny][nx] = cnt + 1;
                q.push(make_tuple(nx,ny,cnt + 1));
            }
        }
    }
}

bool bfs(){
    q.push(make_tuple(Xc,Yc,0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop();//cout << y << ' ' << x << ' ' << cnt << '\n';

        if(cnt == T) return true;

        if(!vis[y][x][cnt + 1] && (visited[y][x] == -1 || visited[y][x] > cnt + 1)){
            vis[y][x][cnt + 1] = 1;
            q.push(make_tuple(x,y,cnt + 1));
        }

        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(!vis[ny][nx][cnt + 1] && (visited[ny][nx] == -1 || visited[ny][nx] > cnt + 1)){
                vis[ny][nx][cnt + 1] = 1;
                q.push(make_tuple(nx,ny,cnt + 1));
            }
        }
    }
    return false;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> T >> Yc >> Xc >> K;
    fill_n(&visited[0][0], 101*101, -1);

    for(int i = 1;i<K+1;i++){
        cin >> Yi >> Xi;
        visited[Yi][Xi] = 0;
        q.push(make_tuple(Xi, Yi, 0));
    }
    fillBullet();//printmap(M,N,visited);

    if(bfs()) cout << "YES";
    else cout << "NO";
}
/*
2424와 비슷한 아이디어지만 조금은 더 쉬운 문제.
처음엔 그냥 느슨하게 막 했다가 메모리 초과 맞고 곰곰이 생각했다.





*/