#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
//이분 탐색 알고리즘
/*
어떤 배열에서 특정한 값을 찾는 데 사용한다.
순차 탐색은 복잡도가 O(N)인데 반해 이분 탐색은 O(lgN)으로 더 효율적이다.

**단, 배열은 항상 정렬되어 있어야 한다.

과정:
1. 배열 중앙값과 찾는 값을 비교하여, 
찾는 값이 더 크면 low = mid + 1
찾는 값이 더 작으면 high = mid - 1
찾는 값이면 return mid

즉 매번 탐색할 때마다 반 씩 줄여나간다.
*/
vector <int> vt;

int bisearch(int target, int size){
    int low = 0;
    int high = size - 1;
    int mid = 0;

    while(low <= high){
        mid = (low + high) / 2;
        cout << mid << ' ';

        if(target < vt[mid]){
            high = mid - 1;
        }
        else if(target > vt[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    for(int i = 10;i>0;i--){
        vt.push_back(i);
    }
    sort(vt.begin(),vt.end());

    cout << vt[bisearch(7, vt.size())];
}
/*

*/