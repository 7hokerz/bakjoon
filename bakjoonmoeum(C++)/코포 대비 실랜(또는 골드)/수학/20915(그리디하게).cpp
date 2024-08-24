#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9
 
int T, inp;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        vector <ll> vt;

        for(int i = 0;i<str.length();i++){
            if(str[i] - 48 == 6) vt.push_back(9);
            else vt.push_back(str[i] - 48);
        }sort(vt.begin(), vt.end());
 
        ll one = vt.back(); vt.pop_back();
        ll two = vt.back(); vt.pop_back();

        while(!vt.empty()){
            ll none = one * 10 + vt.back();
            ll ntwo = two * 10 + vt.back();

            if(abs(none - two) > abs(ntwo - one)) two = ntwo;
            else one = none;

            vt.pop_back();
        }

        cout << one * two << '\n';
    }
}
/*
최대한 큰 수를 앞에 세우되, 두 수의 차이가 많이 나지 않아야 함.
두 수를 항상 크게 만들면서, 두 수의 차이가 적은 경우가 곱이 크다는 점을 이용하면 된다.
*/