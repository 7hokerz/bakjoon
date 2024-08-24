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
#define INF 0x7f7f7f7f7f7f7
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {0, -1, 0, 1}; int dy[] = {1, 0, -1 ,0};

int N, S, res = -1, stx, sty, high = 0;
int bees[801][801], visited[801][801];
char m[801][801];

queue <pii> q;

void fillbees(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        
        q.pop(); //cout << y << ' ' << x << ' ' << cnt << '\n';

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            
            if(m[ny][nx] != 'T' && m[ny][nx] != 'D' && bees[ny][nx] == -1){
                bees[ny][nx] = bees[y][x] + 1;
                high = max(high, bees[ny][nx]);
                q.push({nx,ny});
            }
        }
    }
}

queue <t4> q2;

bool bfs(int minute){
    if(bees[sty][stx] != -1 && minute >= bees[sty][stx]) return false;
    q2.push(make_tuple(stx,sty,0,minute));
    visited[sty][stx] = minute;

    while(!q2.empty()){
        int x = get<0>(q2.front());
        int y = get<1>(q2.front());
        int cnt = get<2>(q2.front());
        int min = get<3>(q2.front());
        
        q2.pop(); //cout << y << ' ' << x << ' ' << cnt << ' ' << min << '\n';

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > N || ny > N || m[ny][nx] == 'T' || m[ny][nx] == 'H') continue;

            if(visited[ny][nx] == -1){
                if(m[ny][nx] == 'D'){
                    res = max(res, minute);
                    return true;
                }
                else if(cnt == S && (bees[ny][nx] == -1 || bees[ny][nx] > min + 1)){
                    visited[ny][nx] = min + 1;
                    q2.push(make_tuple(nx,ny,0, min + 1));
                }
                else if(cnt < S && (bees[ny][nx] == -1 || bees[ny][nx] > min)){
                    visited[ny][nx] = min;
                    q2.push(make_tuple(nx,ny,cnt + 1, min));
                }
            }
        }
    }//cout << -1 << '\n';
    return false;
}

void bisearch(){
    int low = 0, mid = 0;

    while(low <= high){
        fill(visited[0], visited[801], -1);
        mid = (low + high) / 2;
        //cout << mid << ' ';
        if(bfs(mid)){
            low = mid + 1;
        }   
        else{
            high = mid - 1;
        }
        //cout << res <<'\n'; printmap(N,N,visited);
        while(!q2.empty()) q2.pop();
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(bees[0], bees[801], -1); 
    cin >> N >> S;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> m[i][j];
            if(m[i][j] == 'H'){
                bees[i][j] = 0;
                q.push({j,i});
            }
            else if(m[i][j] == 'M'){
                stx = j; sty = i;
            }
        }
    }
    fillbees(); //printmap(N,N,bees);
    
    bisearch();

    cout << res;
}
/*
도달 가능 코드는 현재 짜놨고, 왜 틀리는 걸까? 1%

*/