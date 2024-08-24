#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9
 
int N, T, S, ret = 0;
vector <pii> vt;//S(마감 시간), T(걸리는 시간)

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> T >> S;
        vt.push_back({S,T});
        ret = max(ret, S);
    }sort(vt.begin(),vt.end());

    while(!vt.empty()){
        int st = vt.back().first - vt.back().second;//현재 임무 기준 최적 시작점
        /*이전 시작점이 현재 임무 마감 시간보다 크면: st를 단순히 넣으면 됨.
        그렇지 않다?(이전 시작점이 현재 임무 기준 시간과 겹친다면): 이전 시작점 - 현재 임무 걸리는 시간
        이유: 이전 시작점 이전이 임무 수행이 가능한 시간대이기 때문이다.*/
        if(ret > vt.back().first) ret = st;
        else ret -= vt.back().second;

        vt.pop_back();
    }
    if(ret < 0) cout << -1;
    else cout << ret;
}
/*
과정: S 내에 일을 끝내야 한다.
따라서 그리디(?)하게 가면 S - T 시점에 시작하는 게 가장 좋다.
우선 S를 기준으로 정렬 후 가장 큰 S부터 S - T를 구해준다.

(이 문제는 풀어놓고 다시 복기하려니까 갑자기 헷갈리네...허허 이게 뭔)




*/