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
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0 ,-1};

int N, x, a, res = 1e9;
vector <pii> m;
vector <ll> psum;

void bisearch(){
    int left = 0, right = N - 1;//인덱스
    while(left <= right){
        int mid = (left + right) / 2; 
        
        ll leftp = psum[mid];//왼쪽의 사람 수
        ll rightp = psum[N-1] - psum[mid];//오른쪽의 사람 수
        cout << left << ' ' << mid << ' ' << right << '\n';

        if(leftp < rightp){
            left = mid + 1;
        }
        else{
            right = mid - 1;
            res = min(res, m[mid].first);
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> x >> a;
        m.push_back({x,a});
    }
    sort(m.begin(), m.end());

    psum.push_back(m[0].second);
    for(int i = 1;i<m.size();i++){//누적 합
        psum.push_back(psum[i-1] + m[i].second);
    }
    bisearch();

    cout << res; 
}
/*
이분탐색까진 생각했는데, 못 풀고 봄.
실제 풀이로는 단순 그리디 / 누적합, 이분탐색을 이용한 풀이가 존재했다.

0 1 2
8 3

0 0 0
3 8




*/