#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T, N;
long long input = 0LL;
struct cmp{
    bool operator()(long long a, long long b){
        return a > b;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int j = 0;j<T;j++){
        priority_queue <long long, vector<long long>, cmp> pq;
        cin >> N;

        for(int i = 0;i<N;i++){
            cin >> input;
            pq.push(input);
        }
        long long sum = 0LL;
        while(pq.size() > 1){
            long long first, second;
            first = pq.top();pq.pop();
            second = pq.top();pq.pop();
            sum += (first+second);
            pq.push(first+second);
        }
        cout << sum << '\n';
    }
}
/*
우선순위 큐로 작은 수부터 정렬시키고
앞의 두 수를 더한 후 그 합을 pq에 삽입한다.

4
40 30 30 50
>>30 30 40 50
>>40 50 60 >> 60
>>60 90>> 150
>>150>> 300

15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
>>1 3 3 4 4 5 5 5 14 17 21 21 32 35 98
>>3 4 4 4 5 5 5 14 17 21 21 32 35 98>> 4
>>4 4 5 5 5 7 14 17 21 21 32 35 98>> 11
>>5 5 5 7 8 14 17 21 21 32 35 98>> 19
>>5 7 8 10 14 17 21 21 32 35 98>> 29
>>8 10 12 14 17 21 21 32 35 98>> 41
>>12 14 17 18 21 21 32 35 98>> 59
>>17 18 21 21 26 32 35 98>> 85
>>21 21 26 32 35 35 98>> 120
>>26 32 35 35 42 98>> 162
>>35 35 42 58 98>> 220
>>42 58 70 98>> 290
>>70 98 100>> 390
>>100 168>> 558
>>268>> 826
*/