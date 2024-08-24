#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp;
ll ret = 0;
string str;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    vector <int> vt(N);
    for(int i = 0;i<N;i++){
        cin >> vt[i];
    }sort(vt.begin(),vt.end());
    
    for(int i = 0;i<N;i++){
        if(vt[i] > 0) break;//처음부터 양수면 0을 만들 수 없다.
        int cur = vt[i];
        int l = i + 1, r = N - 1;//양쪽에 투 포인터

        while(l < r){
            while(l < r && cur + vt[l] + vt[r] < 0) l++;//합이 0보다 작으면 -를 줄이고
            while(l < r && cur + vt[l] + vt[r] > 0) r--;//합이 0보다 크면 +를 줄이고

            if(!(l < r)) break;

            if(!(cur + vt[l] + vt[r])) {//합이 0인 경우
                if(vt[l] == vt[r]){//두 수가 같으면 조합으로 나올 수 있는 경우의 수를 공식으로 구한다.
                    ll n = r - l + 1;//개수
                    ret += n * (n - 1) / 2;
                    break;
                }
                
                //수가 같을 동안 개수 증가
                ll s = 1, e = 1;
                while(l < r && vt[l] == vt[l+1]){
                    l++;
                    s++;
                }
                
                while(l < r && vt[r] == vt[r-1]){
                    r--;
                    e++;
                }

                ret += s * e;//총 경우의 수를 더한다.
            }

            if(cur + vt[l] + vt[r] > 0) r--;
            else l++;
            //0일 땐 어차피 수 경계에 포인터가 존재하게 되므로 어떤 포인터를 움직여도 상관은 없다.
        }
    }
    cout << ret;
}
/*
같은 수가 여러 개 존재할 경우 어떻게 처리할 지 알 수 있는 문제.

같은 수일 동안 포인터를 이동하면서 개수를 구해준다.

그 후 s * e를 ret에 더한다.

*/