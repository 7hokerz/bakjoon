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

int N, M, inp;
vector <int> crane, box;
queue <int> q[10002];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> inp;
        crane.push_back(inp);
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> inp;
        box.push_back(inp);
    }
    sort(crane.rbegin(), crane.rend()); sort(box.begin(), box.end());

    for(int i = 0;i<N;i++) q[0].push(crane[i]);
    
    int res = 0;
    
    while(!box.empty()){
        int cnt = 0;
        
        while(cnt <= 10000){
            if(q[cnt].empty() || box.back() > q[cnt].front()) cnt++;
            else if(box.back() <= q[cnt].front()) break;
        }
        if(cnt == 10001) {cout << -1; return 0;}
        box.pop_back(); //cout << cnt << ' ' << q[cnt].size() << ' ' << q[cnt].empty() << '\n';

        q[cnt + 1].push(q[cnt].front()); q[cnt].pop();

        res = max(res, cnt + 1);
    }
    cout << res;
}
/*
cout << cnt << '\n';
        for(int i = 0;i<box.size();i++){
            cout << box[i] << ' ';
        }cout << q[cnt].front() << '\n';
0 0 0 0 0 0 0 0 0 0
2 5 5 5 7 7 11 17 20 20

15 15 17 18 18

각각의 크레인에 카운트를 매겨준다.

18 (20,1)
18 (20,1)
17 (17,1)
15
*/