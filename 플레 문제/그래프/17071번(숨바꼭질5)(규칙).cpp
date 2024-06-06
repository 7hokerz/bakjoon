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
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \
//3차원 map 출력
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \


int N, M, visited[500001][2], res = -1;//짝수와 홀수
queue <pii> q;//큐

void check(int time){
    if((time % 2 == 0 && visited[M][0]) || (time % 2 == 1 && visited[M][1])){
        res = time;
    }
    M += (time + 1);
}

void bfs(){
    int pre = -1;
    visited[N][0] = 1;//첫 번째는 0초이므로 짝수
    q.push({N, 0});

    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        
        q.pop();

        if(pre != cnt){ pre = cnt; check(cnt); }

        if(res != -1 || M > 500000) return;

        int nxt[3] = {x * 2, x + 1, x - 1};

        for(int i = 0;i<3;i++){
            int nx = nxt[i];//cnt+1인 이유는 nx는 현재시간+1의 시간값이기 때문
            if(nx >= 0 && nx < 500001 && !visited[nx][(cnt + 1) % 2]){
                visited[nx][(cnt + 1) % 2] = 1; q.push({nx, cnt + 1});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    bfs();
    
    cout << res;
}
/*
첫 시도
방문 배열에 카운트(시간)을 기록하고, 매 시간이 갱신될 때 마다 현재 시간과 M에 기록된 cnt를 비교하여
같으면 값을 리턴하고, 그렇지 않으면 -1을 리턴하는 알고리즘.

메모리 초과로 실패

2번째 시도
같은 카운트 값이 여러 번 같은 곳에 누적되어 큐에 삽입 가능하다는 점을 알게 되어 이 부분을 예외 처리

71% 시간 초과로 실패

**3번째(질게 방법 참고)(홀수, 짝수 규칙)
한 번 방문한 곳의 시간에 따라(홀수, 짝수) 해당 시간+2, +4, +6...에도 같은 곳에 방문 가능하다는 규칙
즉 홀수(짝수) 시간에 따라 처음 방문한 지점은 다음 홀수(짝수)에도 항상 다시 방문 가능(n에 방문 시, n+2, n+4...에도 방문 가능)
왜냐하면 -1, +1로 움직일 수 있기 때문이다.

방문 배열을 [500001][2]로 재설정하여 0은 짝수, 1은 홀수로 둔다. cnt % 2 연산으로 구분 가능

위와 같이 설정 후 성공
*/

/*
5: 4,6,10

4:3,5,8
6:(5),7,12
10:9,11,20
>>9-1=8

3:2,4,6
5:(4),(6),10
8:7,9,16
7:(6),8,14
12:11,13,24
9:(8),(10),18
11:(10),12,22
20:19,21,40
>>24-6=18

1:3
2:8
3:18
4:
5:
*/