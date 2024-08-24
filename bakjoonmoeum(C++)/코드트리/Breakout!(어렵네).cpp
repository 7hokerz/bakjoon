#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int N, M, ret = 0, arr[101], mx = 0, mn = 0;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> arr[i];
        if(arr[i] != -1 && arr[i] && arr[i-1] == -1){//arr[i]가 0이나 -1이 아니고, arr[i-1]가 -1일 때
            for(int j = i-1;j >= 1 && arr[j] == -1;j--){//앞의 수를 채워준다. 1씩 빼주면서
                arr[j] = arr[j + 1] - 1;
                if(!arr[j]) break;//현재 수가 0이면 중지
            }
        }
    }

    for(int i = 1;i<N+1;i++){
        if(arr[i] == -1 || !arr[i]) mx++;//최댓값 구하기(-1을 항상 0으로만 생각하면 된다.)

        if(i == 1 && arr[i] == -1) arr[i] = 0;//첫 번째 수는 항상 0으로 시작해야 한다.
        else if(arr[i] == -1 && arr[i-1] != -1) arr[i] = arr[i-1] + 1;//-1을 순서대로 채워준다.
    }

    if(arr[1]) {cout << -1; return 0;}//첫 번째 수는 항상 0으로 시작해야 한다.

    for(int i = 1;i<N;i++) {
        if(!(!arr[i+1] || arr[i+1] == arr[i] + 1)) {cout << -1; return 0;}
        //현재 수 + 1 == 다음 수 또는 다음 수 == 0 두 조건을 만족하지 않으면 수열을 만들 수 없음.
        if(!arr[i]) mn++;//0일 때 
    }
    if(!arr[N]) mn++;//마지막 수가 0일 때
    cout << mn << ' ' << mx;
}
/*
이런 유형은 뭔가 어색한 느낌이다. 그리디인데...

틀리는 테스트 케이스 안보여줬으면 못풀었을 듯 하다.

코드도 드럽네 썅
*/