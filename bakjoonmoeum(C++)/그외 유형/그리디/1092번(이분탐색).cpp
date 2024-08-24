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
    
    if(*crane.begin() < *box.rbegin()){cout << -1 << '\n'; return 0;}
    //가장 큰 크레인이 박스보다 작은 경우(옮길 수 없음)
    int res = 0;
    
    while(!box.empty()){//모든 크레인을 순회
        for(int i = 0;i<N;i++){//크레인 크기보다 더 큰 박스가 나오는 위치 확인
            auto iter = upper_bound(box.begin(), box.end(), crane[i]);
            if(iter == box.begin()) continue;//처음부터 박스가 큰 경우는 현재 크레인으로 옮길 수 없음.
            box.erase(--iter);//iter 바로 전 위치의 박스 지우기
        }
        res++;
    }
    cout << res;
}
/*

*/