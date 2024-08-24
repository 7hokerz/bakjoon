#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {0, 1, 0, -1}; int dy[] = {-1, 0, 1, 0};

int M, N, L, X, Y, res = 0;

vector <int> locs;

bool bisearch(int X, int Y){
    int low = 0, mid = 0, high = M;

    while(low <= high){
        mid = (low + high) / 2;
        int xret = locs[mid] - X;
        int ret = abs(xret) + Y;

        if(ret <= L) return true;
        else{
            if(xret < 0) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> M >> N >> L;
    for(int i = 1;i<M+1;i++){
        cin >> X;
        locs.push_back(X);
    } 
    sort(locs.begin(), locs.end());

    for(int i = 1;i<N+1;i++){
        cin >> X >> Y;
        if(bisearch(X,Y)) res++;
    }

    cout << res;
}
/*
사거리가 L보다 커지는 지점을 찾자. 즉 upperbound
결국은 Y좌표는 같으니까 
X좌표가 가까운 사대를 찾아야 함.
*/