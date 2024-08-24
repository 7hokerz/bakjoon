#include <iostream>
#include <vector>
using namespace std;

/*
vector<자료형> 변수명: 백터 생성 
vector<자료형> 변수명(숫자): 숫자만큼 백터 생성 후 0으로 초기화 
vector<자료형> 변수명 = { 변수1, 변수2, 변수3...}	
백터 생성 후 오른쪽 변수 값으로 초기화 

vector<자료형> 변수명[] = {, } 	:
백터 배열(2차원 백터)선언 및 초기화(열은 고정, 행은 가변)

vector<vector<자료형>> 변수명: 2차원 백터 생성(열과 행 모두 가변)

vector<자료형>변수명
변수명.assign(범위, 초기화할 값):
백터의 범위 내에서 해당 값으로 초기화

반복자
v.begin(): 벡터 시작점의 주소값 반환
v.end(): 벡터 끝부분+1의 주소값 반환
v.rbegin(): 벡터의 끝 지점을 시작점으로 변환
v.rend(): 벡터의 시작 지점을 끝 부분으로 변환

요소 접근 함수
v.at(i) 벡터의 i번째 요소 접근(범위 검사함)
v[i] 벡터의 i번째 요소 접근(범위 검사 X)(at보다 []사용 권장)
v.front() 벡터의 첫번째 요소 접근
v.back() 벡터의 마지막 요소 접근

요소 삽입 함수
v.push_back(): 백터의 마지막 부분에 새로운 요소 추가 
v.pop_back(): 백터의 마지막 부분 제거 
v.insert(삽입할 위치의 주소 값, 변수 값): 사용자가 원하는 위치에 요소 삽입 
v.emplace(삽입할 위치의 주소 값, 변수 값): 사용자가 원하는 위치에 요소 삽입(move로 인해 복사생성자 X) 
v.emplace_back(): 백터의 마지막 부분에 새로운 요소 추가(move로 인해 복사생성자 X) 
v.erase(삭제할 위치) or v.erase(시작위치, 끝위치): 사용자가 원하는 index값의 요소를 지운다. v.begin 등 필수
v.clear(): 백터의 모든 요소를 지운다.(return size = 0)
v.resize(수정 값): 백터의 사이즈를 조정한다.(범위 초과시 0으로 초기화) 
v.swap(백터 변수): 백터와 백터를 스왑한다. 

벡터 크기 관련 함수
v.empty(): 백터가 빈공간이면 true, 값이 있다면 false 
v.size(): 백터의 크기 반환 
v.capacity(): heap에 할당된 백터의 실제크기(최대크기) 반환 
v.max_size(): 백터가 system에서 만들어 질 수 있는 최대 크기 반환 
v.reserve(숫자): 백터의 크기 설정 
v.shrink_to_fit(): capacity의 크기를 백터의 실제 크기에 맞춤 
*/

int main(){
    
    
}