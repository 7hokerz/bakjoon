#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int N, maxsum = -10000, minsum = 10000;
char input, map[6][6];

int calc(int x, int y, int &sum, char op){
    if(op == '+') return sum + (map[x][y] - '0');
    else if(op == '-') return sum - (map[x][y] - '0');
    else return sum * (map[x][y] - '0');
}

void dfs(int x, int y, int sum){
    if(x > N || y > N) return;
    if(x == N && y == N){
        maxsum = max(maxsum, sum);
        minsum = min(minsum, sum);
        return;
    }
    dfs(x+2,y,calc(x+2, y, sum, map[x+1][y]));

    dfs(x+1,y+1,calc(x+1, y+1, sum, map[x+1][y]));

    dfs(x+1,y+1,calc(x+1, y+1, sum, map[x][y+1]));

    dfs(x,y+2,calc(x, y+2, sum, map[x][y+1]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    dfs(1,1,map[1][1] - '0');
    cout << maxsum << ' ' << minsum;
}
/*
연산자는 두 방향에 존재하고, 한 방향에 두 개의 값으로 갈 수 있다.
즉 한 번의 dfs가 호출되면 총 4개의 dfs가 재귀호출됨.
*/