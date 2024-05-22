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
#define mod 1'000'000'007
//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0 ,1};

int N, M, input, cnt = 1, grnum = 1;
int map[1001][1001], visited[1001][1001][2], grs[1001];
//visited 배열: 해당 좌표의 그룹 넘버, 방문 유무
void dfs(int x, int y){//같은 그룹의 모든 연결된 개수를 확인
    visited[y][x][0] = grnum;//그룹 넘버 설정
    visited[y][x][1] = true;

    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

        if(!visited[ny][nx][1] && map[ny][nx] == 1){
            dfs(nx,ny);
            cnt++;
        }
    }
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    //방문하지 않은 곳(그룹 설정을 하지 않은 곳)은 그룹을 설정하여 이 그룹의 최대 연결된 개수 확인
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(map[i][j] == 1 && !visited[i][j][1]){
                dfs(j, i);
                grs[grnum++] = cnt;//dfs완료 후 해당 그룹의 연결된 요소 개수 저장
                cnt = 1;
            }
        }
    }

    //이후 0의 지점을 확인하여 4방향 개수 탐색 및 합 중 가장 큰 값
    int mx = 0;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(map[i][j] == 0){
                vector <int> vt;
                for(int k = 0;k<4;k++){
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
                    
                    //4방향 탐색 1을 발견 시 기존 탐색한 다른 방향과 같은 그룹이 존재하는지 확인
                    if(map[ny][nx] == 1){ bool chk = true;
                        for(int h = 0;h<vt.size();h++){
                            if(vt[h] == visited[ny][nx][0]) chk = false;
                        }
                        if(chk){//중복되지 않는 경우 개수 추가
                            cnt += grs[visited[ny][nx][0]];
                            vt.push_back(visited[ny][nx][0]);
                        }
                    }
                }
                mx = max(mx, cnt); cnt = 1;
            }
        }
    }
    //모든 요소가 1인 경우는 위의 과정을 무시하게되므로 1 >> 0만 고려
    if(mx == 0) cout << M*N - 1;
    else cout << mx;
}
/*for(int i = 1;i<N+1;i++){
    for(int j = 1;j<M+1;j++){
        cout << visited[i][j][0] << ' ';
    }cout << '\n';
}
cout << '\n';

for(int i = 1;i<N+1;i++){
    for(int j = 1;j<M+1;j++){
        cout << visited[i][j][1] << ' ';
    }cout << '\n';
}*/