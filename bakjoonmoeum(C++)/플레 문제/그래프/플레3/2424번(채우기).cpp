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

int m[701][701], visitedV[701][701][2], visitedY[701][701];//
int N, M, Ysx, Ysy, Vsx, Vsy; string input;
queue <t3> qV, qY;

void bfsV(){//fill
    visitedV[Vsy][Vsx][0] = 0;
    qV.push(make_tuple(Vsx, Vsy, 0));
    while(!qV.empty()){
        int x = get<0>(qV.front());
        int y = get<1>(qV.front());
        int cnt = get<2>(qV.front());
        
        qV.pop();

        if(visitedV[y][x][(cnt + 1) % 2] == -1) visitedV[y][x][(cnt + 1) % 2] = cnt + 1;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] != 'I' && visitedV[ny][nx][(cnt + 1) % 2] == -1){
                visitedV[ny][nx][(cnt + 1) % 2] = cnt + 1;
                qV.push(make_tuple(nx, ny, cnt + 1));
            }
        }
    }
}

bool chk(int x, int y, int cnt){
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        while(1){
            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == 'I') break;
            if(visitedV[ny][nx][(cnt + 1) % 2] != -1 && visitedV[ny][nx][(cnt + 1) % 2] <= cnt + 1) return false;
            nx += dx[i];
            ny += dy[i];
        }
    }
    return true;
}

void bfsY(){
    visitedY[Ysy][Ysx] = 0;
    qY.push(make_tuple(Ysx, Ysy, 0));
    while(!qY.empty()){
        int x = get<0>(qY.front());
        int y = get<1>(qY.front());
        int cnt = get<2>(qY.front());
        
        qY.pop(); //cout << y << ' ' << x << ' ' << cnt << '\n';

        if(m[y][x] == 'T'){
            cout << "YES";
            exit(0);
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] != 'I' && !visitedY[ny][nx]){
                if(chk(nx,ny,cnt)){
                    visitedY[ny][nx] = 1;
                    qY.push(make_tuple(nx, ny, cnt + 1));
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill_n(&visitedV[0][0][0], 701*701*2, -1);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == 'Y'){//수아
                Ysx = j; Ysy = i; m[i][j] = '.';
            }
            if(m[i][j] == 'V'){//해적
                Vsx = j; Vsy = i; m[i][j] = '.';
            }
        }
    }
    bfsV(); bfsY();
    cout << "NO";
}
/*
홀수나 짝수에 처음 도달한 지점은 n+2에도 도달 가능하다는 사실을 잊지 말자

해적에 대해 방문 표시하여 다 채워버리는데 홀수와 짝수를 나눠서 표시한다. 방문 표시에 넣을 값은 해적에 대한 카운트다.
다 채운 후, Y가 시작 위치에서 탐색을 시작한다.
움직일 수 있는 칸에서 4방향 탐색하여 홀수와 짝수를 나눠서 만약 Y의 카운트와 같거나 작은 값을 발견하면 NO

+ 둘이 같이 동시에 진행하면서도 가능할 것 같다는 생각도 든다. 이따가 시도해보자.
*/