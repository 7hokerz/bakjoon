#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int N, M;
string one, two, thr;
map<tuple<string,string,string>, int> m;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> one >> two >> thr;
        m[make_tuple(one,two,thr)]++;
    }

    for(int i = 0;i<M;i++){
        int ret = 0;
        cin >> one >> two >> thr;

        for(auto& v: m){//map 순회
            auto& k = v.first;//tup(string...)에 해당
            if((one == "-" || one == get<0>(k)) &&
                (two == "-" || two == get<1>(k)) &&
                (thr == "-" || thr == get<2>(k))){
                ret += v.second;//조건을 만족하는 경우에 대해 합산
            }
        }
        cout << ret << '\n';
    }
}

/*

*/