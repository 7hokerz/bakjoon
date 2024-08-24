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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define mod 1'000'000'007
//int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int N, M, input, cnt = 0; bool chk = false;

vector <int> gr[51], inp;

void dfs(int x){
    if(gr[x].size() == 0) {//연결된 노드가 없으면 리프 노드이므로
        cnt++;
        return;
    }
    for(int i = 0;i<gr[x].size();i++){
        dfs(gr[x][i]);
    }
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int root;
    for(int i = 0;i<N;i++){
        cin >> input;
        inp.push_back(input);
    }
    cin >> input;//지울 노드

    for(int i = 0;i<N;i++){
        if(inp[i] == -1){root = i; continue;}//루트 노드 기록
        if(i == input) continue;//지울 노드는 따로 채우지 않음.

        gr[inp[i]].push_back(i);
    }
    if(root != input)//지울 노드가 루트 노드면 cnt = 0
        dfs(root);
    
    cout << cnt;
}
/*


*/ 