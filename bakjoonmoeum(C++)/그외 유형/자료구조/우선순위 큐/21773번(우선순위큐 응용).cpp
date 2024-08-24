#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct cmp{
    bool operator()(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.first.first ==  b.first.first) return a.second > b.second;
        return a.first.first < b.first.first;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue <pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> pq;//우선순위, 남은 시간, id
    int n, T, a,b,c; cin >> T >> n;
    for(int i = 0;i<n;i++){
        cin >> a >> b >> c;
        pq.push({{c,b},a});
    }
    for(int i = 0;i<T;i++){
        a = pq.top().second; b = pq.top().first.second; c = pq.top().first.first;
        cout << a << '\n';
        pq.pop();
        b--;c--;
        pq.push({{c,b},a});
        while(!pq.empty() && pq.top().first.second == 0) pq.pop();//이거 추가하니 맞음
    }
}
/*
8 2
1 5 1
2 5 1



*/