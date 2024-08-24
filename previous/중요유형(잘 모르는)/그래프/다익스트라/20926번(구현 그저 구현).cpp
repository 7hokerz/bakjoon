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
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int W, H, res = -1, dist[501][501];
string input;
char m[501][501];
priority_queue<rpii, vector<rpii>, greater<rpii>> pq;

void dij(){
    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(dist[y][x] < cost) continue;
        if(m[y][x] == 'E') {
            if(res == -1) res = dist[y][x];
            else res = min(res,dist[y][x]);
            continue;
        }

        for(int k = 0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            int ncost = cost;

            while(1){
                if(nx < 1 || ny < 1 || nx > W || ny > H || m[ny][nx] == 'H' || m[ny][nx] == 'R' || m[ny][nx] == 'E') break;

                ncost += (m[ny][nx] - 48);
                nx = nx + dx[k]; ny = ny + dy[k];
            }
            
            if(m[ny][nx] == 'R') {nx -= dx[k]; ny -= dy[k];}
            if(nx < 1 || ny < 1 || nx > W || ny > H || m[ny][nx] == 'H') continue;

            if(dist[ny][nx] > ncost){
                dist[ny][nx] = ncost;
                pq.push({ncost, {nx,ny}});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(dist[0], dist[501], INF);
    cin >> W >> H;
    for(int i = 1;i<H+1;i++){cin >> input;
        for(int j = 1;j<W+1;j++){   
            m[i][j] = input[j-1];
            if(m[i][j] == 'T'){
                pq.push({0,{j,i}}); dist[i][j] = 0;
                m[i][j] = '0';
            }
        }
    }
    dij();
    //printmap(H, W, m); printmap(H, W, dist);
    cout << res;
}
/*                         
구현...힘들어.

아직 2차원 맵에서 다익스트라를 적용하는 게 익숙하지 않기도 하고, 
이 문제는 꽤나 구현을 해야하서 더욱 귀찮았던 문제.

과정:
1. 맵을 입력받아 시작점을 표시 및 pq에 삽입
2. 한 칸씩 전진하는 방식이 아닌 처음 위치에서 방향을 정하면 해당 방향으로 쭉 가야 함.
그래서 맵 밖이나 구멍이나 출구나 바위 등...을 만날 때까지 무한 전진 및 비용 합산
3. 비용 합산을 완료했으면 기존 비용과 비교하고 삽입 및 pq에 삽입
4. 출구에 도착하면 값을 res에 저장 및 continue.(너비 우선 탐색 처럼 먼저 도착한 게 최단 거리는 아니니까)
5. 위의 과정을 반복하여 최솟값 출력
*/ 

