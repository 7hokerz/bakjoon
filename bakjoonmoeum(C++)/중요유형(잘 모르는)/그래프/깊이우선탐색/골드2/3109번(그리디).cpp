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

int dx[] = {1,1,1}; int dy[] = {-1,0,1};
int R, C, visited[10001][501], res = 0;
char map[10001][501];
string input;

bool dfs(int x, int y){ //cout << y << ' ' << x << '\n';
    if(x == C){
        res++;
        return true;
    }
    for(int i = 0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > C || ny > R) continue;

        if(!visited[ny][nx] && map[ny][nx] == '.'){
            visited[ny][nx] = 1;
            if(dfs(nx,ny)){
                return true;
            }
        }
    }
    return false;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 1;i<R+1;i++){
        cin >> input;
        for(int j = 1;j<C+1;j++){
            map[i][j] = input[j-1];
        }
    }
    for(int i = 1;i<R+1;i++){
        visited[i][1] = true;
        dfs(1,i);
    }
    cout << res;
}   
/*
최대한 북동으로 이동하도록 설정하면 풀린다.

그리고 방문 배열을 초기화할 필요도 없다.
어차피 해당 지역은 
1. 파이프가 설치된 지점이거나
2. 끝까지 도달하지 못한 경우
로 분류 가능하기 때문이다.

과정:
처음으로 북동을 우선으로 탐색한다.
목표 지점에 도달하면 true를 리턴하고, 이 때
어느 중간 지점에서 다른 지역을 볼 필요가 없으므로 dfs반환값을 확인해
true면 바로 return true를 실시한다.


for(int k = 1;k<R+1;k++){
            for(int j = 1;j<C+1;j++){
                cout << visited[k][j] << ' ';
            }cout << '\n';
        }cout << '\n';
11x1111111
22122x2222
3x2332x333
433x433xx4
5444544445
.555x5555.
*/ 