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
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0 ,-1};

int N, M, res = 0, input, walla = 0, visited[9][9], map[9][9];

vector <pair<int,int>> vt;//x,y
queue <pair<int,int>> q;//x,y

void bfs(){
    int vicnt = 0;
    for(int i = 0;i<vt.size();i++){
        q.push(vt[i]);
        visited[vt[i].first][vt[i].second] = true;
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

            if(!visited[nx][ny] && map[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(walla == 3){//총 세워진 벽의 개수 3개 확인
        int sum = 0;
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){//방문하지 않고 0인 구역을 체크
                if(!visited[i][j] && map[i][j] == 0) sum++; //cout << visited[i][j] << ' ' ;
            }//cout << '\n';
        } 
        res = max(res, sum);
    }
    
    fill(visited[0], visited[9], 0);//초기화
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            if(input == 2) {//2인 좌표에 대해 벡터에 삽입(매 반복마다 큐에 삽입하기 위해)
                vt.push_back({i,j});
            }
            map[i][j] = input;
        }
    }

    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(map[i][j] == 0){
                map[i][j] = 1; walla++;

                for(int k = i;k<N+1;k++){
                    int l;//중복 연산을 줄이기 위해 아래와 같이 작성(같은 줄이면 옆 칸, 다른 줄이면 1부터 시작)
                    if(k != i) l = 1;
                    else l = j + 1;

                    for(l;l<M+1;l++){
                        
                        if(map[k][l] == 0){
                            map[k][l] = 1; walla++;

                            for(int a = k;a<N+1;a++){
                                int b;
                                if(a != k) b = 1;
                                else b = l + 1;

                                for(b;b<M+1;b++){
                                    if(map[a][b] == 0){
                                        map[a][b] = 1; walla++;
                                        bfs();
                                        map[a][b] = 0; walla--;
                                    }
                                }
                            }
                            map[k][l] = 0; walla--;
                        }
                    }
                }
                map[i][j] = 0; walla--;
            } 
        }
    }
    cout << res;
}
/*

*/