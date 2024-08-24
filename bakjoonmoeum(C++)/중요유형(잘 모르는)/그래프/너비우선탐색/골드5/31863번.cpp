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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int N, M, stx, sty, all = 0, cnt = 0; string input;
int visited[1001][1001], map[1001][1001];

queue <pair<int,int>> q;

void bfspre(int stx, int sty){
    for(int k = 0;k<4;k++){
        int nx = stx+dx[k];
        int ny = sty+dy[k];

        for(int h = 0;h<2;h++){
            if(nx < 1 || ny < 1 || nx > M || ny > N) break;

            if(map[ny][nx] == -1) break;

            else if(map[ny][nx] == 2) map[ny][nx]--;

            else if(map[ny][nx] == 1){
                map[ny][nx]--; 
                q.push({nx,ny});
                cnt++;
            }

            if(dx[k] == -1) nx--;
            else if(dx[k] == 1) nx++;
            else if(dy[k] == -1) ny--;
            else if(dy[k] == 1) ny++;
        }
    }
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
            if(map[ny][nx] == -1) continue;
            
            if(map[ny][nx] == 1){//1인 경우 무너지므로 거기서부터 다시 지진이 퍼짐
                map[ny][nx]--; cnt++;
                q.push({nx,ny});
            }
            if(map[ny][nx] == 2) map[ny][nx]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++){
            if(input[j-1] == '|'){
                map[i][j] = -1;
            }
            else if(input[j-1] == '.'){
                map[i][j] = 0;
            }
            else if(input[j-1] == '@'){
                map[i][j] = 0; stx = j; sty = i;
            }
            else if(input[j-1] == '*'){ all++;
                map[i][j] = 1;
            }
            else if(input[j-1] == '#'){ all++;
                map[i][j] = 2;  
            }
        }
    }
    bfspre(stx,sty);
    bfs();
    cout << cnt << ' ' << all - cnt;
}
/*
본진 진원지를 기준으로 2칸
여진 건물이 무너지는 경우 발생함. 1칸

*/