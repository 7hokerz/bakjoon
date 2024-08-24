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
typedef tuple<int,int,int,int,int,int> t6;
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int n, m, k, a, b, c, res = 0, jew[101];//맵이 생각보다 시간복잡도가 상당하구나...
bool visited[101][(1<<15)];
vector <pii> gr[101];
queue <t3> q;

void bfs(){
    visited[1][0] = 1;
    q.push(make_tuple(1, 0, 0));

    while(!q.empty()){
        int x = get<0>(q.front());
        int asset = get<1>(q.front());//가진 보석의 종류
        int cnt = get<2>(q.front());//보석의 개수

        q.pop();

        if(x == 1) res = max(res, cnt);

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i].first;
            int cost = gr[x][i].second;

            //현재 자리의 보석 유무와 관계없이 줍지 않는 경우
            if(cnt <= cost && !visited[nx][asset]){
                visited[nx][asset] = 1;
                q.push(make_tuple(nx, asset, cnt));
            }
            
            //현재 자리에 보석이 있고 줍는 경우(이전에 줍지 않은 경우)
            if(jew[x] && !(asset & (1 << jew[x]))){
                int nasset = asset;
                int ncnt = cnt;

                nasset |= (1 << jew[x]); ncnt++;
                if(x == 1) res = max(res, ncnt);//위와 같이 확인하는 이유? 1번 섬에서 줍지 않았을 경우도 존재하기 때문
                //위 조건문 만으로는 마지막에 1번 섬에 도착하고 보석을 가지는 경우를 계산하지 못함.
                
                if(ncnt <= cost && !visited[nx][nasset]){
                    visited[nx][nasset] = 1;
                    q.push(make_tuple(nx, nasset, ncnt));
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1;i<k+1;i++){
        cin >> a;
        jew[a] = i;
    }
    for(int i = 1;i<m+1;i++){
        cin >> a >> b >> c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    bfs();
    cout << res;
}
/*
1194 < 2001 < 1473 난이도로 생각 중.

+ 맵은 꼭 필요한 거 아니면 굳이 쓰지 말자.
*/