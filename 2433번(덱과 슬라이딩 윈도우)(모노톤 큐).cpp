#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,c,input;
    deque <int> dq[2];//값이 아닌 인덱스를 저장
    vector <int> vt, max, min, ans;//값을 저장, 범위 내의 최댓값의 인덱스를 저장
    cin >> n >> m >> c;
    for(int i = 0;i<n;i++){
        cin >> input;
        vt.push_back(input);
    }
    for(int i = 0;i<vt.size();i++){
        while(!dq[0].empty() && vt[dq[0].back()] <= vt[i]) dq[0].pop_back();

        while(!dq[1].empty() && vt[dq[1].back()] >= vt[i]) dq[1].pop_back();
        
        dq[0].push_back(i); dq[1].push_back(i);

        if(dq[0].front() == i-m) dq[0].pop_front();
        if(dq[1].front() == i-m) dq[1].pop_front();
        
        if(i >= m-1){
            max.push_back(dq[0].front());
            min.push_back(dq[1].front());
        }
    }
    for(int i = 0;i<max.size();i++){
        if(vt[max[i]] - vt[min[i]] <= c){
            ans.push_back(i+1);
        }
    }
    if(ans.empty()) cout << "NONE";
    else{
        for(int i = 0;i<ans.size();i++){
            cout << ans[i] << '\n';
        }
    }
}
/*문제 코드 답을 본 건 아니지만 사실상 본 거나 다름 없음.

이번 문제 풀이로 안 알고리즘: 
슬라이딩 윈도우를 통한 덱을 이용한 최대 최소 값 구하기 알고리즘
슬라이딩 윈도우란 배열의 어느 범위 안에서 한 칸씩 이동하면서 부분의 값을 이용하는 것

보통 배열 내에서 최대 최소 값을 구할 땐 단순하게 떠오르는 건 (브루트포스) 이중 반복문이다. 시간 복잡도는 O(N^2)
구현은 간단하지만 많은 값을 연산할 경우 시간초과되기 딱 좋다.

자세한 건 알고리즘 폴더에서 참고

문제 과정은 간단하다.
1. 입력값을 벡터에 담는다.
2. 이제부터 덱을 이용한다. 이때 덱에는 요소 자체를 담지 않고 인덱스를 담는다.**
최대와 최소를 구해야하므로 2개의 덱을 이용했다.
2-1. 인덱스를 차근 차근 담는데, 이때 중요한 건 front에 최댓값이 항상 존재해야 한다.
덱의 back()과 vt[i]를 비교하여 새로 최댓값이 발견되면 pop한다.
2-2. 그리고 윈도우 범위 밖의 최댓값은 버려야 하므로 i-m과 front가 같아지는, 즉 범위를 벗어난 즉시 삭제한다.
2-3. i >= m-1의 조건은 처음 시작 시 윈도우가 m만큼 범위를 가질 때부터 값을 반환시킨다.
*/