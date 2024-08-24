#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, X;

vector <char> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> X;
    int sum = 0;
    bool chk = false;

    if(26 * N < X || N > X) {cout << '!'; return 0;}

    for(int i = 1;i<N+1;i++){
        if(!chk){
            int val = 1;
            while(val <= 26){
                if(26*(N-i) + val >= X - sum) break;
                else{chk = true; val++;}
            }
            sum += val;
            vt.push_back(64 + val);
        }
        else vt.push_back('Z');
    }
    for(char val: vt) cout << val;
}
/*

*/