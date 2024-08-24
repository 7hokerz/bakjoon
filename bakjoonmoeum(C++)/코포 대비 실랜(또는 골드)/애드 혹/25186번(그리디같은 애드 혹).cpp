#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, inp;
vector <int> val;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++) {cin >> inp; val.push_back(inp);}

    sort(val.begin(), val.end());

    int m = val.back(); val.pop_back();

    int sum = 0;

    bool chk = false;

    for(int i = 0;i<val.size();i++){
        sum += val[i];
        if(m <= sum){
            chk = true; break;
        }
    }

    if(chk || (N == 1 && val[0] == 1)) cout << "Happy";
    else cout << "Unhappy";
}
/*


4 4
1 2 1 2 1 2 1 2


*/