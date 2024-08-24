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
#define mod 1'000'000'009
#define INF 2'000'000'001

int N, visited[123457];
ll b, c;
char a;
vector <pll> gr[123457];

ll dfs(int x){
    ll sum = 0;
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        ll ncost = gr[x][i].second;

        if(!visited[nx]){
            visited[nx] = 1;
            ll val = dfs(nx) + ncost;
            if(val < 0) val = 0;
            sum += val;
        }
    } //cout << x << ' ' << sum << '\n';
    return sum;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 2;i<N+1;i++){
        cin >> a >> b >> c;
        if(a == 'W') b = -b;
        gr[i].push_back({c, b});
        gr[c].push_back({i, b});
    }
    visited[1] = 1;
    cout << dfs(1);
}
/*






*/