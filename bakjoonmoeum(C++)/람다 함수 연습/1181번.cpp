#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, inp, ret = 0;
string str;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    vector<string> vt(N);
    
    for(auto & s: vt) cin >> s;//참조 변수를 사용하여 벡터에 저장
    
    sort(vt.begin(), vt.end(), [](const auto & a, const auto & b) {
        return a.length() < b.length() || (a.length() == b.length() && a < b);
    });//1. 길이 비교, 2. 길이가 같으면 사전순

    vt.erase(unique(vt.begin(), vt.end()), vt.end());//중복 제거
    
    for(const auto & s : vt) cout << s << '\n';
}
/*

*/