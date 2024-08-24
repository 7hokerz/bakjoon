#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, L, inp;
vector <int> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> L;
    for(int i = 0;i<N;i++){
        cin >> inp;
        vt.push_back(inp);
    }
    sort(vt.begin(),vt.end());

    int l = 0, ret = 0;

    while(l < vt.size()){
        double loc = vt[l] - 0.5;
        while(loc + L > vt[l]){
            if(l >= vt.size()) break;
            l++;
        }
        ret++;
    }
    cout << ret;
}
/*
포인터 l을 두고, 시작점을 vt[l] - 0.5로 잡는다. 
시작점 + L만큼이 테이프로 막을 수 있는 부분이므로
시작점 + L을 넘지 않을 동안 포인터 l을 증가한다.
그 후 ret++하여 테이프의 개수를 추가시킨다.

위의 과정을 반복하다 모든 위치를 스캔하면 종료
*/