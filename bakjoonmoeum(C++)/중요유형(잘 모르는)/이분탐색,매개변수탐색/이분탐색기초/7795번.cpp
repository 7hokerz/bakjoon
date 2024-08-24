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

vector <int> vt, a;
int N, M, T, input;

int bisearch(int target, int size){//lowerbound, upperbound에 대해서 알아보도록 하자....
    int low = 0; int high = size - 1; int mid = 0;

    while(low <= high){
        mid = (low + high) / 2;

        if(target <= vt[mid]) high = mid - 1;
        
        else if(target > vt[mid]) low = mid + 1;
    }
    return low;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);

    cin >> T;
    for(int j = 0;j<T;j++){
        cin >> N >> M;
        for(int i = 0;i<N;i++){
            cin >> input;
            a.push_back(input);
        }
        for(int i = 0;i<M;i++){
            cin >> input;
            vt.push_back(input);
        }
        sort(vt.begin(),vt.end());
        int sum = 0;
        for(int i = 0;i<N;i++){
            sum += bisearch(a[i],M);
            //cout << bisearch(a[i],M) << ' ';
        }
        cout << sum << '\n';
        while(!vt.empty())vt.pop_back(); while(!a.empty())a.pop_back();
    }
}
/*
1 1 3 7 8

1 3 6

0 0 1 3 3

1 7 13

11 103 215 290

0 0 1
*/