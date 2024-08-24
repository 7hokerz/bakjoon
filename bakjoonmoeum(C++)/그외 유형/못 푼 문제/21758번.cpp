#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input, sum = 0, res = 0;
    cin >> n;
    int arr[n], arr2[n];
    for(int i = 0;i<n;i++){
        cin >> input;
        arr[i] = input;
        arr2[i] = arr[i];
    }
    for(int i = n-1;i>0;i--) arr2[i-1] += arr2[i];
    
    for(int i = 0;i<n;i++){
        //cout << arr2[i] << ' ';
    }

        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                sum += arr2[j+1];
                sum += arr2[i+1] - arr[j];
                res = (res>sum)?res:sum;
                cout << sum << ' ';
                sum = 0;
            }
        }
    
    cout << res;
}
/*
왼쪽에 있는 벌은 가장 왼쪽에 있는 것이 좋고,
오른쪽에 있는 벌은 가장 낮은 숫자에 위치한 것이 좋다.

만약 오른쪽에 있는 벌이 자리 하나를 선택하면 그보다 왼쪽에 있는
모든 배열의 요소는 -arr[i]처리된다.

**벌통의 위치 또한 고려해야한다.
벌통의 위치를 매번 바꿀 때는 누적 합 또한 변경하고, 
기준을 바꿔야 한다.


*/