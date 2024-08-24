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

int N, M, K, rescnt = -1, restat = -1;
bool visited[2][10][501][501];//(1)밤,(0)낮//카운트 나머지 값(M<=10)(나머지<=9)
char m[501][501];

queue <t4> q;

void bfs(){
    q.push(make_tuple(1,1,0,0));
    visited[0][0][1][1] = 1;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        bool daynight = get<2>(q.front());
        int cnt = get<3>(q.front());
        
        q.pop(); //cout << y << ' ' << x << ' ' << daynight << ' ' << cnt << '\n';

        if(x == N && y == N){
            rescnt = cnt;
            restat = daynight; //cout << cnt << ' ' << daynight << '\n';
            return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            
            if((cnt + 1) % M != 0){//밤낮이 바뀌지 않는 경우
                if(m[ny][nx] == '0' && !visited[daynight][(cnt + 1) % M][ny][nx]){//갈 수 있는 곳
                    visited[daynight][(cnt + 1) % M][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,daynight,cnt+1));
                }
                else if(m[ny][nx] == '1' && daynight == 1){//밤일 때 벽을 타고 가는 경우
                    int nnx = nx; int nny = ny; 
                    while(1){   
                        nnx += dx[i]; nny += dy[i];
                        if(m[nny][nnx] == '0') break;
                        if(nnx < 1 || nny < 1 || nnx > N || nny > N) break;
                    }
                    if(nnx < 1 || nny < 1 || nnx > N || nny > N) continue;

                    if(!visited[daynight][(cnt + 1) % M][nny][nnx]){
                        visited[daynight][(cnt + 1) % M][nny][nnx] = 1;
                        q.push(make_tuple(nnx,nny,daynight,cnt+1));
                    }
                }
            }
            else{//밤낮이 바뀌는 경우
                if(m[ny][nx] == '0' && !visited[!daynight][(cnt + 1) % M][ny][nx]){//갈 수 있는 곳
                    visited[!daynight][(cnt + 1) % M][ny][nx] = 1;
                    q.push(make_tuple(nx,ny,!daynight,cnt+1));
                }
                else if(m[ny][nx] == '1' && daynight == 1){//밤일 때 벽을 타고 가는 경우
                    int nnx = nx; int nny = ny; 
                    while(1){   
                        nnx += dx[i]; nny += dy[i];
                        if(m[nny][nnx] == '0') break;
                        if(nnx < 1 || nny < 1 || nnx > N || nny > N) break;
                    }
                    if(nnx < 1 || nny < 1 || nnx > N || nny > N) continue;

                    if(!visited[!daynight][(cnt + 1) % M][nny][nnx]){
                        visited[!daynight][(cnt + 1) % M][nny][nnx] = 1;
                        q.push(make_tuple(nnx,nny,!daynight,cnt+1));
                    }
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> m[i][j];
        }
    }
    bfs();//printmap(N,N,m);

    if(rescnt == -1){
        cout << -1;
    }
    else{//카운트는 (밤+낮) 모두 증가하므로 M*2를 해주어야 함.
        if(rescnt / (M*2) == 0) cout << 1 << ' ';
        else cout << rescnt / (M*2) + 1 << ' ';
        //나머지에 상관 없이 몫이 며칠이 됨.
        if(restat == 0){
            cout << "sun";
        }
        else{
            cout << "moon";
        }
    }
}
/*
구현은 쉽게 할 수 있었으나 왜틀? 
반례글 보니까 마지막에 결과 도출할 때 나머지 연산, M에 2 곱하는거, 배열 범위 M으로 안하고...
등등으로 많이 실수한 문제.
반례글 없었으면 구현은 잘해놓고 쓸데없는 실수 못찾을 뻔...
*/