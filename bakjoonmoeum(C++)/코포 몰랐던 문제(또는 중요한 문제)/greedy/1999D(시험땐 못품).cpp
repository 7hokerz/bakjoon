#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
 
int T;
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        string one, two;
        vector <char> vt;
        cin >> one >> two;

        int idx = 0;

        for(char val: one){
            if(idx != two.length() && (val == '?' || val == two[idx])){
                vt.push_back(two[idx++]);//?이거나 일치하는 문자가 나오면 삽입 및 인덱스 증가
            }
            else{//이미 idx가 만족된 경우(또는 문자가 일치하지 않은 경우)
                if(val == '?') vt.push_back('a');
                else vt.push_back(val);
            }
        }
        if(idx == two.length()){
            cout << "YES" << '\n';
            for(char val: vt) cout << val;
            cout << '\n';
        }
        else{
            cout << "NO" << '\n';
        } 
    }
}
/*
그냥 매우 쉬운 그리디...시험 땐 정신 없어서 못 찾고 못 품 ㅋㅋ;;
*/