#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue <long long, vector<long long>, greater<long long>> pq;
    int n, m; cin >> n >> m;
    long long input = 0LL; 
    
    for(int i = 0;i<n;i++){
        cin >> input;
        pq.push(input);
    }
    for(int i = 0;i<m;i++){
        long long x, y;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        pq.push(x+y); pq.push(x+y);
    }
    long long sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}
/*
처음엔 몰랐는데 연산 값이 int를 쉽게 넘어가므로 long long으로 잡아주자

3 1
3 2 6(2 3 6)
>>
5 5 6 >> 16

4 2
4 2 3 1(1 2 3 4)
>>
3 3 3 4
>>
3 4 6 6
>> 19
*/