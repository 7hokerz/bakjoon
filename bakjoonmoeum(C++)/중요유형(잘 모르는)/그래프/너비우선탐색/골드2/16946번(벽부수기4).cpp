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
            cout << (map)[i][j];  \
        }cout << '\n';                 \
    }cout << '\n'; \
//3차원 map 출력
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, visited[1001][1001], m[1001][1001], grnum = 1, ans[1001][1001];
map <int, int> grcnt;
string input;
queue <pii> q;//큐

void bfs(){
    int count = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] == 0 && visited[ny][nx] == 0){
                visited[ny][nx] = grnum;
                q.push({nx,ny}); count++;
            }
        }
    }
    grcnt[grnum] = count;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1] - 48;
        }
    }

    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(m[i][j] == 0 && !visited[i][j]){
                visited[i][j] = grnum;
                q.push({j,i});//x=j, y=i....
                bfs();
                grnum++;
            }
        }
    }
    //printmap(N,M,m);
    //printmap(N,M,visited);
    //for(auto &[k,v] : grcnt){
    //    cout << v << ' ';
    //}

    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(m[i][j] == 1){
                set <int> check;
                for(int k = 0;k<4;k++){
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

                    if(m[ny][nx] == 0){
                        
                        if(check.find(visited[ny][nx]) == check.end()){
                            check.insert(visited[ny][nx]);
                            ans[i][j] += grcnt[visited[ny][nx]] % 10;
                            ans[i][j] %= 10;
                        }
                    }
                }
                ans[i][j]++; ans[i][j] %= 10;
            }
        }
    }

    printmap(N,M,ans);
}
/*

*/
