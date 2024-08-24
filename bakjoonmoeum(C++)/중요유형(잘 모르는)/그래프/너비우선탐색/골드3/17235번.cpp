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
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 2'000'000'001
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

ll calc(ll a, ll n){
    if(n == 0) return 1;
    if(n == 1) return a;

    ll tmp = calc(a, n/2);

    if(n % 2 == 0) return (tmp * tmp);
    
    else return (tmp * tmp) * a;
}

int n, a, b, visited[2][20][500001], res = -1;//오리1, 오리2

queue <rpii> q;

void bfs(){
    visited[0][0][a] = 1; visited[1][0][b] = 1;
    q.push({a,{0,0}}); q.push({b,{1,0}});//1,2

    while(!q.empty()){
        int x = q.front().first;
        int ori = q.front().second.first;
        int day = q.front().second.second;

        if(visited[0][day][x] && visited[1][day][x] &&
        visited[0][day][x] == visited[1][day][x]){
            res = day; return;
        }
        q.pop();

        int nx = calc(2, day);

        if(x + nx < n + 1 && !visited[ori][day + 1][x + nx]){
            visited[ori][day + 1][x + nx] = 1;
            q.push({x + nx,{ori, day + 1}});
        }

        if(x - nx > 0 && !visited[ori][day + 1][x - nx]){
            visited[ori][day + 1][x - nx]= 1;
            q.push({x - nx,{ori, day + 1}});
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;//오리, 육리
    bfs();
    cout << res;
}
/*


*/