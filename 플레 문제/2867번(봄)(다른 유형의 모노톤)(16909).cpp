#include <iostream>
#include <stack>
using namespace std;

//히스토그램과 같은 모노톤 스택을 이용하는 문제다.
//하지만 문제의 느낌이 달라서 풀지 못했다. 어떤 방법으로 하는 지 참고했다.
//요약: 최댓값과 최솟값을 뺀 값의 모든 합을 구하는 문제는 모노톤 스택을 이용하자. 단 최댓값 최솟값 따로 구하기
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    long long sum = 0LL, input = 0LL;
    cin >> n;
    stack <pair<long long, pair<int,int>>> maxnum, minnum;//(합, (값,인덱스))
    for(int i = 0;i<n;i++){
        cin >> input;
        if(!maxnum.empty()){
            //현재 최댓값보다 작은 값이 들어오면 합 = top의 합을 더한 값으로 넣어준다.
            if(maxnum.top().second.first > input){
                maxnum.push({(maxnum.top().first + input)*1LL,{input,i}});
            }//그렇지 않은 경우는 큰 최댓값이 들어와서 제거해야 하는 경우로 취급하고,
            //스택에서 input보다 큰 최댓값이 나올 때까지 top을 제거한다. 이때 스택에 저장되어있던 top의 합 값을 sum에 합한다.
            else{
                while(!maxnum.empty() && maxnum.top().second.first <= input){
                    sum += maxnum.top().first;
                    maxnum.pop();
                }
                //두 경우의 차이는 최댓값이 적용되는 값의 개수 차이이다.
                //스택이 빈 경우는 index+1이 개수가 되고, 아닌 경우는 i-top의 인덱스+1인데,
                //+1을 한 이유는 top의 값이 더 큰 경우기 때문에 개수에 포함시키지 않는다는 뜻으로 해석하자.
                if(maxnum.empty()) maxnum.push({input*(i+1)*1LL,{input,i}});
                else maxnum.push({input*(i-maxnum.top().second.second)*1LL + maxnum.top().first,{input,i}});
            }
        }
        else maxnum.push({input*1LL,{input,i}});//사실상 i=0일때라고 봐도 무방
        //최솟값의 경우도 과정은 같다. 다만 최솟값이 유지되어야 하므로 큰 값이 들어오면 단순 삽입.
        //더 작은 값이 들어오면 더 작은 값을 찾을때까지 제거시킨다는 것이다.
        //또한 최솟값은 sum에서 빼줘야 하는 값이므로 sum -=을 써준다.
        if(!minnum.empty()){
            if(minnum.top().second.first < input){
                minnum.push({(minnum.top().first + input)*1LL,{input,i}});
            }
            else{
                while(!minnum.empty() && minnum.top().second.first >= input){
                    sum -= minnum.top().first;
                    minnum.pop();
                }
                if(minnum.empty()) minnum.push({input*(i+1)*1LL,{input,i}});
                else minnum.push({input*(i-minnum.top().second.second)*1LL + minnum.top().first,{input,i}});
            }
        }
        else minnum.push({input*1LL,{input,i}});
    }
    //남아있는 원소의 합들을 모두 sum에 더해준다.
    while(!maxnum.empty()){
        sum += maxnum.top().first;
        maxnum.pop();
    }
    while(!minnum.empty()){
        sum -= minnum.top().first;
        minnum.pop();
    }
    
    cout << sum;
}
/* 
아래는 풀면서 해본 풀이들

부분 수열 ai가 있다.(ai는 ai로만 끝나는 부분수열을 뜻함.)
이때 ai가 부분 수열의 최댓값이면, ai로 끝나는 부분수열이 항상 ai를 최댓값으로 갖는다는 뜻이다.

a{i-2}가 1∼i번째 항까지의 최댓값이고, ai가 그 이후의 최댓값이라고 해보자. 
그렇다면 ai로 끝나는 부분수열 중 i−2개는 a{i-2}가 최댓값이고 2개는 ai가 최댓값이다.

**최댓값 스택은 내림차순 스택으로 관리(즉, top보다 큰 요소가 들어오면 top을 지우겠다는 의미)

최솟값은 반대로 오름차순 스택으로 관리하면서 원소를 넣으면서, 해당 원소가 최댓값인 경우가 몇 번인지를 계산해주어야 한다.

어떤 공식으로?
합,(값,인덱스)
(최댓값 기준)
1. top보다 작은 요소가 들어오면 인풋의 합부분에 top.first를 더한 후 삽입
2. top보다 큰 요소가 들어오면 더 큰 요소를 찾을 때까지 pop

4
0 1 2 3
3 1 7 2
일일이 계산했을 때 최댓값의 합:3+/3+1+/7+7+7/+7+7+7+2 = 3+/4+/21+/23 = 51
일일이 계산했을 때 최솟값의 합:3+/1+1+/1+1+7/1+1+2+2 = 3+/2+/9+/6= 20

3,(3,0)
3,(3,0) , 4,(1,1)
>> sum = 3+4 = 7
21,(7,2)
21,(7,2), 23,(2,3)
>>sum = 7+ 21+ 23 = 51

이때 제거가 완료된 후 새로운 요소가 삽입될 시에는 인덱스+1을 가지고 합을 구하면 된다. 
(앞에 요소가 있으면 i-top인덱스)(없으면 인덱스+1)
7,21 sum = 3+4 = 7
7,21 2,23 
새로운 값이 더 없으므로 
sum = 7+44 = 51

3,(3,0)
>>sum = 3
2,(1,1)
2,(1,1), 9,(7,2)
>>sum = 3+9 = 12
2(1,1), 6(2,3)
**7을 제거한 후 (i-top인덱스)*값에다가 앞의 합 2를 더해야된다. 그러면 6(2,3)이다.
>>sum = 12+8=20

3
1 2 3
1+2+2+3+3+3=14
*/
