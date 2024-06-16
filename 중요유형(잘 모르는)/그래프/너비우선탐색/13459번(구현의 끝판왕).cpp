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

char m[11][11];
int N, M, resR = -1, stxR, styR, visited[11][11][11][11];//Ry,Rx,By,Bx(4차원 중요)
queue <tuple<int,int,int,pii>> q;//Rx,Ry,cnt,(Bx,By)
string input; pii stxyB;//Bx,By

//B의 좌표를 업데이트
pii updateBlue(int loc, int Rx, int Ry, pii Bxy){
    int nx = Bxy.first + dx[loc];
    int ny = Bxy.second + dy[loc];
    pii nBxy;

    while(m[ny][nx] == '.' && !(Rx == nx && Ry == ny)) { nx += dx[loc]; ny += dy[loc];}

    if(m[ny][nx] == '#' || (Rx == nx && Ry == ny)) { nx -= dx[loc]; ny -= dy[loc];}
    
    nBxy.first = nx; nBxy.second = ny;
    return nBxy;
}

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());//Rx
        int y = get<1>(q.front());//Ry
        int cnt = get<2>(q.front());//조작 횟수
        pii Bxy = get<3>(q.front());//Bx, By 좌표
        
        q.pop(); 
        
        if(cnt == 10) continue;//최대 카운트 이상이면 생략
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            pii nBxy;

            //다음 칸이 바로 벽인 경우(1)(아래 설명 주목)
            if(m[ny][nx] == '#'){
                //구슬 B의 위치를 업데이트
                nBxy = updateBlue(i,nx - dx[i], ny - dy[i], Bxy);
                //B가 구멍에 들어가거나 위치 변화가 없으면 생략
                if(m[nBxy.second][nBxy.first] == 'O' || Bxy == nBxy) continue;
                q.push(make_tuple(nx - dx[i],ny - dy[i],cnt + 1,nBxy));
                continue;
            }

            //갈 수 있는 곳일 동안 반복해서 한 뱡향으로 전진
            while(m[ny][nx] == '.' && !(Bxy.first == nx && Bxy.second == ny)){
                nx += dx[i]; ny += dy[i];
            }

            if(m[ny][nx] == 'O'){//목표 지점인 경우
                nBxy = updateBlue(i, -1, -1, Bxy);//B 업데이트
                //B가 구멍에 들어가는 경우 생략
                if(m[nBxy.second][nBxy.first] == 'O') continue;
                resR = cnt + 1;//결과 저장
                return;
            }
            else if(m[ny][nx] == '#'){//벽인 경우
                nx -= dx[i]; ny -= dy[i];
                nBxy = updateBlue(i,nx,ny,Bxy);
                //B가 구멍에 들어가는 경우 생략
                if(m[nBxy.second][nBxy.first] == 'O') continue;

                //구슬 R과 B가 같이 각각의 해당 좌표에 동시에 방문했던 적이 없는 경우
                if(!visited[ny][nx][nBxy.second][nBxy.first]){
                    visited[ny][nx][nBxy.second][nBxy.first] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1,nBxy));
                }
            }   
            else{//R이 B구슬을 만난 경우
                nBxy = updateBlue(i,nx - dx[i], ny - dy[i],Bxy);//B 업데이트
                //cout << y << ' ' << x << ' ' << Bxy.second << ' ' << Bxy.first << ' ' << cnt << '\n';
                //cout << ny - dy[i] << ' ' << nx - dx[i] << ' ' << nBxy.second << ' ' << nBxy.first << '\n';
                if(m[nBxy.second][nBxy.first] == 'O'/* || Bxy == nBxy*/) continue;
                //B가 구멍에 들어가는 경우 생략
                /*Bxy == nBxy를 지워야 하는 이유는 일단 반례가 발견되었고,
                위의 경우(1)와 달리 B가 움직일 수도 있고, R또한 그 영향으로 움직일 수 있기 때문으로 추측
                위의 경우는 R은 벽이 진행방향에 있으므로 움직이지 않음이 보장되고,
                또한 B가 움직이지 않는다면 사실상 아무것도 움직이지 않은 것과 다름 없으므로 
                위 조건을 넣어 큐에 넣지 않아 중복 연산을 방지하는 효과를 발견했다.
                (실제로 메모리 및 시간 차이가 발견됨.(약 20000KB 및 48ms 차이 존재)) */

                //갈 수 있는 곳일 동안 반복해서 한 뱡향으로 전진
                while(m[ny][nx] == '.' && !(nBxy.first == nx && nBxy.second == ny)){
                    nx += dx[i]; ny += dy[i];
                }

                //현 R 좌표가 벽이거나 B구슬과 겹치면 한 칸 뒤로
                if(m[ny][nx] == '#' || (nBxy.first == nx && nBxy.second == ny)) {
                    nx -= dx[i]; ny -= dy[i];
                }

                //구슬 R과 B가 같이 각각의 해당 좌표에 동시에 방문했던 적이 없는 경우
                if(!visited[ny][nx][nBxy.second][nBxy.first]){
                    visited[ny][nx][nBxy.second][nBxy.first] = 1; 
                    q.push(make_tuple(nx,ny,cnt + 1,nBxy)); 
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int Kc = 0;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == 'R' || m[i][j] == 'B'){
                if(m[i][j] == 'R'){
                    stxR = j; styR = i;
                }
                else{
                    stxyB.first = j; stxyB.second = i;
                }
                m[i][j] = '.';
            }
        }
    } 
    visited[styR][stxR][stxyB.second][stxyB.first] = 1;

    q.push(make_tuple(stxR,styR,0,stxyB));
    bfs(); //cout << resR << '\n';

    if(resR == -1) cout << 0;
    else cout << 1;
}
/*
엄청나다...
진짜 아주 세세한 것 까지 잡지 않으면 하나라도 반례가 나와서 틀려버리는 문제. 까다롭다.

방문 배열 또한 R뿐만 아니라 B까지 고려해야 했고, 따로따로 2차원이 아니라
두 개를 합한 4차원 배열을 써줘야 했다.
이유는 R과 B의 위치가 항상 같지 않고 다를 수 있는데 이를 고려하지 않고 단순 2차원으로 만들면
잘못된 처리를 하게 된다. 즉, 두 구슬의 위치를 모두 고려하여야 한다.

과정 설명은...위에 적은 거 참고. 설명 적기도 빡세
*/