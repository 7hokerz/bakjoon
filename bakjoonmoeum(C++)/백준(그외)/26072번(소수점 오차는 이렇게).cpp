#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, L, x, w;
double ret;
vector <int> loc, wg;

void bisearch(){
    double low = 0.0, mid = 0.0, high = L * 1.0;

    while(low <= high){
        mid = (low + high) / 2.0;
        mid = round(mid * 100000000) / 100000000;

        double left = 0, right = 0;

        for(int i = 0;i<N;i++){
            if(loc[i] < mid){
                left += wg[i] * (mid - loc[i]);
            }
            else if(loc[i] > mid){
                right += wg[i] * (loc[i] - mid);
            }
        }
        left = round(left * 10000000) / 10000000; right = round(right * 1000000) / 1000000; 

        //cout << left << ' ' << right << ' ' << mid << '\n';
        if(left < right){
            low = mid + 0.00000001;
        }
        else if(left > right){
            high = mid - 0.00000001;
        }
        else{
            ret = round(mid * 100000000) / 100000000;
            return;
        }
    }
    ret = round(mid * 100000000) / 100000000;
    return;
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> L;
    for(int i = 0;i<N;i++){
        cin >> x; loc.push_back(x);
    }
    for(int i = 0;i<N;i++){
        cin >> w; wg.push_back(w);
    }
    cout << setprecision(16);
    bisearch();
    cout << ret;
} 
/*

위치 

*/