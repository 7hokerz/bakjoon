#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, -1, 1, 1}; int dy[] = {1, -1, 1, -1};

int w, h, p, q, t, cnt = 0;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> w >> h >> p >> q >> t;
    
    int x = w - abs(w - (p + t) % (2 * w));
    int y = h - abs(h - (q + t) % (2 * h));

    cout << x << ' ' << y << '\n';
}
/*
4 + 12 + 12..
1 + 8 + 8...

이동 주기: 2*w, 2*h

현 위치에서 w까지의 남은 거리: abs(w - (p + t) % (2 * w))
현 위치에서 h까지의 남은 거리: abs(h - (q + t) % (2 * h))

abs를 붙이지 않으면 방향이 포함된(부호가 포함된) 값이 나오기 때문.

실 좌표:
w - 현 위치 w 남은 거리, h - 현 위치 h 남은 거리

직접 시뮬레이션 돌려서 시간초과 나서 못참겠어서 봤더니 식 하나 덜렁~~

저런 식 찾기는 관찰력이 중요한 거 같은데, 쉽지 않다. 어케 찾음?

저런 건 직접 풀려고 하기 보다 어떤 규칙이 있는지 찾는 게 중요한 거 같다.

x가 항상 증가하다가 감소하고 또 증가하고 결국은 제자리로 돌아오게 되고...최소공배수라는 사실!

범위도 보면 2억...그냥 시뮬로는 안된다고 볼 수 있지 않을까?
*/