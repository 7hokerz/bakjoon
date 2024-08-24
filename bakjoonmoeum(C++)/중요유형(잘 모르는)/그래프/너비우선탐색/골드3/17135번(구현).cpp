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

int dx[] = {-1, 0, 1}; int dy[] = {0, -1, 0};//세 방향 탐색(왼, 위, 오)

int N, M, D, input, res = 0;
int map[17][16], visited[17][16], tmp[17][16];

queue <pair<pair<int,int>,int>> q;//x,y

void update(){//턴이 끝난 후 새로운 턴으로 맵을 갱신하는 함수
    for(int i = N;i>=1;i--){
        for(int j = 1;j<M+1;j++){
            if(tmp[i-1][j] == 2) tmp[i-1][j] = 0;
            tmp[i][j] = tmp[i-1][j];
        }
    }
}

void init(){//상태를 초기화해주는 함수
    while(!q.empty()) q.pop();
    fill(visited[0], visited[N+1],0);
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();
        
        if(tmp[y][x] == 1 || tmp[y][x] == 2){//처음 위치(현재 자리)에 적이 존재하면 수행
            if(tmp[y][x] == 1){
                res++; tmp[y][x] = 2;
            }
            return;
        }
        if(cnt == D){continue;}//거리 제한에 도달하면 이 이상의 탐색은 의미없으므로 중지
        for(int i = 0;i<3;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx]){
                if(tmp[ny][nx] == 1 || tmp[ny][nx] == 2){//적을 공격하면 적을 제거 후 중지
                    if(tmp[ny][nx] == 1){res++; tmp[ny][nx] = 2;}//처음 공격받은 적은 2로 변경 및 카운트
                    return;
                }
                else{//적이 해당 지역에 없으면 bfs
                    visited[ny][nx] = true;
                    q.push({{nx,ny}, cnt+1});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> D;
    int val = 0;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    for(int i = 1;i<M+1;i++){//1
        for(int j = i+1;j<M+1;j++){//2
            for(int h = j+1;h<M+1;h++){//3
                memcpy(tmp, map, sizeof(map));
                for(int k = N;k>=1;k--){//턴 1개마다 3명의 궁수를 따로따로 수행하여 결과 확인
                    q.push({{i,N},1}); bfs(); init();
                    q.push({{j,N},1}); bfs(); init();
                    q.push({{h,N},1}); bfs(); init();
                    update();
                }
                val = max(val, res); res = 0;
            }
        }
    }
    cout << val;
}
/*
BFS+구현 문제입니다.

격자의 범위 및 여러가지 등등이 전체적으로 작으므로 모든 경우를 탐색해도 큰 문제가 없습니다.

처음 및 두 번째로 풀었을 때, 26% 틀렸습니다를 받았습니다.
​
두 번째 제출 코드(처음과 거의? 다를 것 없음)

틀린 원인은 복합적이었다고 보는데, 

1. 결과적으로 한 턴에 3명의 궁수가 같은 적을 공격할 수도 있다는 사실을 간과했었습니다.

2. 그리고 현재 코드는 처음 탐색 시작점이 궁수 바로 앞 1칸인데, (cnt = 1 상태)

이 때 현재 위치 적이 있는 경우를 고려하지 않은 문제도 매우 컸습니다.

1의 문제를 수정하려면 우선 어떤 한 적이 공격을 받았을 때 바로 처리하는 게 아닌 1턴이 끝난 후에 몰아서 처리해야합니다.(tmp[ny][nx]=0으로 처리 X)

2의 문제를 수정하려면 3방향 탐색 전 현재 좌표에 적이 존재하는지 확인하여야 합니다.

해당 부분을 수정한 최종 코드입니다.

최종 제출 코드(2028KB, 4ms)

세 방향을 탐색하기 전에 현재 좌표에 적이 존재하는지 확인하고 존재하면 적을 제거 처리 후 추가 과정 없이 바로 리턴합니다. 궁수는 1턴에 최대 1명의 적만 죽일 수 있기 때문입니다.

또한 적을 처음 확인하고 죽인 경우 적의 위치를 2로 처리하여 위의 1번 문제를 해결하였습니다.

여기서 3명의 궁수를 한꺼번에 같이 처리하지 않은 이유는 여러 복합적인 이유가 존재하나, 딱 요약해서 말하면

"3명의 궁수에 대한 중복 처리"를 어떻게 할 지 모르겠어서 어려워서 저는 위와 같이 처리했습니다.

코드의 전체적인 틀만 보면 bfs의 기본 문제와 비슷하지만 여러 업데이트, 조건 등을 고려해야하는 문제였습니다.
*/