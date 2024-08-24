#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector <int> vt, val;
    deque <int> dq;
    int N, D, input;
    cin >> N >> D;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
    }

    for(int i = 0;i<N;i++){
        
    }
}
/* 
시작점은 최초로 양의 정수가 시작되는 곳으로 정하고, 양수 또는 0은 모두 밟으려 하되 음수는 가장 양수에 가까운 수만 밟도록 해야 한다.
그리고 나오고 싶을 때 나올 수도 있으므로 꼭 끝까지 갈 필요는 없다.
*/