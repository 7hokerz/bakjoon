#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, inp;
vector <int> vt1, vt2;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> inp;
        vt1.push_back(inp);
    }sort(vt1.begin(), vt1.end());
    for(int i = 0;i<N;i++){
        cin >> inp;
        vt2.push_back(inp);
    }sort(vt2.begin(), vt2.end());

    int ret = 0, l = 0;

    for(int i = 0;i<vt1.size();i++){
        while(vt1[i] >= vt2[l] && l < N) l++;
        if(l == N) break;
        ret++; l++;
    }//cout << ret << '\n';

    if(ret >= (N + 1) / 2) cout << "YES";
    else cout << "NO";
}
/*
이상하게 안 풀린 문제.
처음에 뒤부터 조사해서 upperbound 써서 투 포인터로 풀려 했는데 자꾸 틀려서 뭐지 싶어서 봄.

그렇게 까지 할 필요 없이 위와 같이 간단하게 하면 풀렸다...허허 아직 부족하다.
*/