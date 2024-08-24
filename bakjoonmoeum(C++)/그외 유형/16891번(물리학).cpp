#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int m1 = 1, m2, cnt = 0;
double v1 = 0, v2 = -1, tmp1, tmp2, tmp3;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> m2;
    m2 *= m2;

    while(!(v2 > 0 && v2 > v1)){
        //v1
        tmp1 = m1 - m2;
        tmp2 = 2 * m1;

        //v2
        tmp3 = 2 * m2;
        
        double nv1 = tmp1 * v1 / (m1 + m2) + tmp3 * v2 / (m1 + m2);
        double nv2 = tmp2 * v1 / (m1 + m2) - tmp1 * v2 / (m1 + m2);

        v1 = nv1; v2 = nv2;
        //cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << ' ' << cout << v1 << ' ' << v2 << '\n';
        cnt++;

        if(v1 < 0) {v1 = -v1; cnt++;}//A가 벽과 충돌하는 경우 카운팅 및 속도 반대
    }
    cout << cnt;
} 
/*
A <= B
*/