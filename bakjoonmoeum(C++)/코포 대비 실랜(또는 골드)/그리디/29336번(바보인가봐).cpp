#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M;
int T, A, Q;
vector <int> vt;
vector <pii> vt2;
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> A;
        vt.push_back(A);
    }sort(vt.begin(), vt.end());

    for(int i = 1;i<M+1;i++){
        cin >> T >> Q;
        vt2.push_back({T, Q});
    }sort(vt2.begin(), vt2.end());
    
    ll ret = 0;

    for(int i = 0;i<vt2.size();i++){
        while(!vt.empty() && vt2[i].second > ret){//조건에 맞을 때까지
            ret += vt.back() + vt2[i].first;//사람의 역량 + 경과 일수
            vt.pop_back();
        }
        //모든 수를 제거했음에도 조건에 부합하지 못하면 -1
        if(vt.empty() && vt2[i].second > ret) { cout << -1; return 0; }
    }
    
    //남은 수들을 ret에 포함
    while(!vt.empty()){
        ret += vt.back() + vt2[M-1].first;
        vt.pop_back();
    }
    if(vt.empty() && vt2[M - 1].second > ret) { cout << -1; return 0; }
    cout << ret;
}
/*
음..이거 처음에 문제 읽고 뭔 소린가 싶었는데, 문제 예제 설명이 좀 포함됐으면 좋겠고 세부적인 설명이 부족한 듯 하다. ㅆㅍ
(그 후로 계속 틀림)(알고 보니 전 풀이에서는 포문 범위 이상하게 N으로 잡아서 병신됐음 시팔...잠 다 깼네)

아무 것도 하지 않은 사람의 역량은 항상 1씩 증가.

1 3 4 6
0일차

2 4 5 7
1일차: ret = 7

3 5 6
2일차: ret = 7

4 6 7
3일차: ret = 14

5 7
4일차: ret = 26
*/