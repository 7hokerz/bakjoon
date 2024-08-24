#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;

vector <int> vt;
int N, M, input, num[20000001];

int bisearch(int target, int size){
    int low = 0;
    int high = size - 1;
    int mid = 0;

    while(low <= high){
        mid = (low + high) / 2;

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
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        if(num[input + 10000000] == 0) vt.push_back(input);
        num[input + 10000000]++;
    }
    sort(vt.begin(),vt.end());
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> input;
        if(num[input + 10000000] == 0){
            cout << 0 << ' ';
            continue;
        } 
        //int idx = bisearch(input, vt.size());

        cout << num[input + 10000000] << ' ';
    }
}
/*

*/