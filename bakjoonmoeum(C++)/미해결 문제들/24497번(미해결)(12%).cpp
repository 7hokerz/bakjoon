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
#define INF 0x7f7f7f7f7f7f7
#define printmap(row, col, map)      \
    for (int i = 0; i < (row); i++){   \
        for (int j = 0; j < (col); j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

ll num[500001];
int N, M, I, J, K, cnt;
bool visited[500001];
vector <pii> gr[500001];

void findCycle(int x, int pre, ll val, int cnt){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        int ncost = gr[x][i].second;

        if(!visited[nx]){
            visited[nx] = 1;
            ll nxt;
            if(cnt == 0) nxt = ncost;
            if(cnt % 2 == 0){
                nxt = val + ncost;
            }   
            else{
                nxt = val - ncost;
            }

            findCycle(nx, x, nxt, cnt + 1);

            if(num[x] == INF) num[x] = ncost - num[nx];
            else{
                if(num[x] != ncost - num[nx]){
                    cout << "ERROR"; exit(0);
                }
            }
            //cout << x << ' ' << nx << ' '  << num[x] << ' ' << num[nx] << '\n';
            visited[nx] = 0;
        }
        else{
            if(nx != pre){ 
                if(cnt % 2 == 0){
                    if(num[nx] == INF){
                        num[nx] = (val + ncost) / 2;

                        if(num[x] == INF) num[x] = ncost - num[nx]; 
                        else{
                            if(num[x] != ncost - num[nx]){
                                cout << "ERROR"; exit(0);
                            }
                        }
                    }
                    else{
                        if(num[nx] != (val + ncost) / 2){
                            cout << "ERROR"; exit(0);
                        }
                    }
                }
                else {cout << "ERROR"; exit(0);}
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    fill(num, num + 200001, INF);
    for(int i = 0;i<M;i++){
        cin >> I >> J >> K;
        gr[I].push_back({J,K});
        gr[J].push_back({I,K});
    }
    visited[1] = 1;
    findCycle(1, -1, 0, 0);
        
    for(int i = 1;i<N+1;i++) {//7%출력 초과는 해결했으나 12%틀림 발생
        if(num[i] >= INF || num[i] <= -INF) {cout << "ERROR"; exit(0);}
    }

    for(int i = 1;i<N+1;i++) cout << num[i] << ' ';
}
/*
12% 과연 뭘까...허허

첫 출발 지점에서 수를 정하면 다른 수는 정할 필요가 없다.

우선 사이클이 존재하는 건 확실하다. 따라서 사이클을 찾아보자.

2
a1 + a2 - (a2 + a3) = 3 - 5 = -2 cnt = 2
a1 - a3 + (a3 + a4) = -2 + 7 = 5 cnt = 3
a1 + a4 = 5

1
a1 + a2 - (a2 + a3) = 3 - 5 = -2
a1 - a3 + (a1 + a3) = 2a1 = -2 + 4 = 2
a1 = 1;

4 - 5 = -1
-1 + 3
*/