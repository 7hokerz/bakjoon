#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int N, M, ret = 0;
string str;
set<string> s;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> str;
        s.insert(str);
    }
    for(int i = 0;i<M;i++){
        cin >> str;
        if(s.find(str) != s.end()){
            ret++;
        }
    }
    cout << ret;
}

/*

*/