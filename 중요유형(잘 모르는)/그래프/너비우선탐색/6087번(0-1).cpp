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
#define mod 1'000'000'009
#define INF 2'000'000'001

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

char m[101][101];
int W, H, res = -1, stx = -1, sty, gox, goy, visited[4][101][101];
deque <t4> q; string input; 

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int rot = get<3>(q.front());
        
        q.pop_front(); //cout << y << ' ' << x << ' ' << cnt << '\n';
        if(gox == x && goy == y){res = cnt; return;}
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > W || ny > H) continue;
            
            if(m[ny][nx] == '.' && (!visited[i][ny][nx] || visited[i][ny][nx] > cnt)){
                if(i == rot) {
                    visited[i][ny][nx] = cnt;
                    q.push_front(make_tuple(nx,ny,cnt,i));
                }
                else {
                    visited[i][ny][nx] = cnt + 1;
                    q.push_back(make_tuple(nx,ny,cnt + 1,i));
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> W >> H;
    for(int i = 1;i<H+1;i++){ cin >> input;
        for(int j = 1;j<W+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == 'C'){
                if(stx == -1){stx = j; sty = i;}
                else{gox = j, goy = i;}
                m[i][j] = '.';
            }
        }
    }
    q.push_back(make_tuple(stx,sty,-1,-1));
    bfs();
    cout << res;
}
/*
처음엔 단순 너비 탐색으로 했지만 여러가지 이유로 0-1 너비 탐색으로 최종적으로 풀이했다.
8ms차이지만 0-1너비탐색이 0ms를 기록하긴 했다.

요약:
현재 방향과 이전 방향의 다름 유무에 따라 카운트가 그대로거나 +1된다. 즉 방향이 바뀌면 +1
0-1너비 탐색으로 카운트+1인 경우는 덱 뒤에, 카운트인 경우는 덱 앞에 삽입시킨다.
그러다 목표 좌표에 도착하면 값 저장 후 리턴 및 출력
왜냐하면 위의 원리에 따라 카운트가 낮은 경우가 먼저 소모되고 그 다음에 큰 카운트가 소모되기 때문에
항상 낮은 카운트 값이 먼저 도달한다.
*/