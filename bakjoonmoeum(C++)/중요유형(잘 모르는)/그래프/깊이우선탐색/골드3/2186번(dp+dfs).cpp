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
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int N, M, K, res = 0, can[101][101][81], accu[101][101][81];
char map[101][101]; string input;

void dfs(int x, int y, int cnt){//cout << y << ' ' << x << '\n';
    if(cnt == input.length()){
        accu[y][x][cnt] = 1;
        res++; return;
    }

    int cancnt = 0;
    bool chk = false;
    for(int i = 1;i<K+1;i++){
        for(int k = 0;k<4;k++){
            int nx = x + dx[k] * i;
            int ny = y + dy[k] * i;

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
            
            if(can[ny][nx][cnt+1]){
                if(accu[ny][nx][cnt+1] == 0) dfs(nx,ny,cnt+1);

                if(accu[ny][nx][cnt+1] == -1) continue;

                cancnt += accu[ny][nx][cnt+1];
                
                chk = true;
            }
        }
    }

    if(!chk) accu[y][x][cnt] = -1;
    else accu[y][x][cnt] = cancnt;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++) map[i][j] = input[j-1];
    }

    cin >> input;
    for(int i = 1;i<N+1;i++)//글자 위치에 대한 곳에 가능 표시 나중에 can[i][j][cnt]만 확인하면 됨
        for(int j = 1;j<M+1;j++)
            for(int k = 0;k<input.length();k++)
                if(input[k] == map[i][j]) can[i][j][k + 1] = 1;

    int ret = 0;     
    for(int i = 1;i<N+1;i++)
        for(int j = 1;j<M+1;j++)
            if(can[i][j][1]) {
                dfs(j,i,1);
                if(accu[i][j][1] != -1){
                    ret += accu[i][j][1];
                }
            }
    cout << ret;
}   
/*
단순 dfs로는 시간초과. dp를 이옹해야 한다.
dp 쓰는 것만 따지면 1920 내리막길과 비슷한 흐름으로 푼 것 같다.?

can 배열: 
처음 배열을 입력받고, 문자열의 위치를 배열에 기록한다.
즉 map 배열의 문자에 대해 지점으로 갈 수 있는 카운트를 표시함. 카운트는 여러 개 들어갈 수 있음.
예: BREAK >> 12345
can[][][idx] >> 문자열 인덱스에 따라 가능 유무를 표시

accu 배열:
메모이제이션을 통한 결과 누적.
accu를 처음에 2차원을 사용했다가 문제가 생겼었는데 이유는
연속된 같은 문자열, 위치 등의 복합적인 문제로 결과가 잘못 누적됨.

[cnt]를 추가하여 카운트에 따라 구분하여 추가로 저장해 오류 방지.


1. 시간초과(30%?)
단순 dfs 사용으로 인한 문제
2. 틀림 
accu를 2차원으로 사용하여 잘못된 값 누적
3. 시간초과(45%?)
메모이제이션을 통해 획기적인 개선을 이뤘지만 도달하지 못하는 가능한 길에 대한 처리를 하지 않음.
(내리막길과 비슷한 흐름)
4. 해결
도달하지 못하는 가능한 길에 대해 -1로 처리하여 다음 번에 다시 가지 않도록 처리
*/