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
typedef long long ll; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef pair<int,int> pii; typedef pair<pii,int> lpii; typedef pair<int,pii> rpii;
typedef pair<pii,pii> piiii;//더블 pii
#define mod 1'000'000'009
#define INF 2'000'000'001
#define printdist2(N, dist, num)   \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k][num] << ' ';     \
    }cout << '\n';  \

int N, R, Q, u, v, visited[100001][2], col = 0, mx = 0;//여기서 [0]은 방문처리, [1]이 DP배열과 동일하다고 볼 수 있음.
vector <int> gr[100001];

int dfs(int x){
    if(x != R && gr[x].size() == 1){
        return 1;
    }

    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];

        if(!visited[nx][0]){
            visited[nx][0] = 1;
            visited[x][1] += dfs(nx);
        }
    }
    return visited[x][1] + 1;//서브 트리의 루트 노드도 포함해야 하므로 +1한다.
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R >> Q;
    for(int i = 0;i<N-1;i++){
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    visited[R][0] = 1;
    dfs(R); 
    for(int i = 0;i<Q;i++){
        cin >> u;
        cout << visited[u][1] + 1 << '\n';//최상단 루트 노드 개수 포함
    }
}
/*                         
트리 DP 기본 문제.
리프 노드에서부터 점점 올라오면서 값을 누적시키는 형태로 코드를 구현하였다.
아직 트리 DP에 대해 잘은 모르겠지만 이런게 트리 DP라는거구나에 대해 조금은 안 것 같기도?
*/