#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
/*
**오름차순 정렬 필수
lower_bound: 찾으려는 값보다 "같거나 큰 숫자"가 처음 등장하는 곳을 찾음. 

upper_bound: 찾으려는 값보다 "큰 숫자"가 처음 등장하는 곳을 찾음.

두 함수 모두 iterator를 반환하므로 arr.begin()을 빼줘야 함.
*/
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    vector <int> arr = { 1,2,3,4,5,6,6,6 };
    //6보다 같거나 큰 숫자가 발견되는 처음 위치 반환
    cout << "lower_bound(6) : " << lower_bound(arr.begin(), arr.end(), 6) - arr.begin();//5
    
    //3보다 큰 숫자가 발견되는 처음 위치 반환
    cout << "upper_bound(3) : " << upper_bound(arr.begin(), arr.end(), 3) - arr.begin();//3
}