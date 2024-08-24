#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
 
int T, N, M, Q, P, L, inp, mx = 0;
string str;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        multiset<int> s;
        for(int i = 1;i<N+1;i++){
            char c; int num;
            cin >> c >> num;
            if(c == 'I'){
                s.insert(num);
            }
            else{
                if(s.empty()) continue;
                if(num == 1){
                    s.erase(prev(s.end()));
                }
                else{
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
}
/*



*/