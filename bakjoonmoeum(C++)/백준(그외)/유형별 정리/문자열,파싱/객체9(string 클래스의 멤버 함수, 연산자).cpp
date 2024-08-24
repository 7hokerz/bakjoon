#include <iostream>
#include <string>
#include <locale>
using namespace std;
//string 클래스의 멤버 함수와 연산자

int main(){
    //치환(=)
    string a = "java", b = "C++";
    a = b;//a는 b를 복사한 문자열을 가짐.
    //cout << a << endl;

    //비교(compare())
    string name = "Kitae";
    string alias = "Kito";
    int res = name.compare(alias);//두 문자열이 같으면 0, 사전 순으로 앞이면 음수, 뒤면 양수 출력
    //cout << res << endl;
    //또는 비교 연산자를 이용
    //cout << (name < alias) << endl;//(name이 alias보다 사전순으로 앞이면 양수)

    //문자열 연결(append())
    string em;
    //em = name.append(alias); //cout << em << endl;
    //또는 +, += 연산자 이용
    em += name; //cout << em << endl;

    //문자열 삽입(insert())
    em.insert(2,"how"); //cout << em;//인덱스 위치에 문자열을 삽입. 결과:Kihowtae
    //또는 문자열 대치 replace()
    em.replace(5, 7, "eat"); //cout << em;

    //문자열 길이(length, size, capacity)
    /*cout << em.length() << endl;//
    cout << em.size() << endl;//length와 동일
    cout << em.capacity() << endl;//현재 용량(변할 수 있다.)
    */

    //문자열 삭제(erase, clear)
    //em.erase(5,7);//일부분 삭제
    //em.clear();//em = ""
    //cout << em << endl;

    //서브스트링(substr)(원본 문자열은 변화 없음)
    //cout << em.substr(2,3) << endl;//인덱스 2에서 문자 3개 리턴
    //cout << em.substr(2);//인덱스 2에서 끝까지 문자열 리턴

    //문자열 검색(find())
    /*int index;
    cout << em.find("how") << endl;//특정 문자나 문자열을 발견하면 첫 번째 인덱스 리턴
    index = em.find('0');
    cout << index << endl;//발견하지 못하면 npos 리턴
    index = em.find("how", 5);//인덱스 5부터 검색
    cout << index << endl;*/
    //이유를 알 순 없으나 cout << em.find("0") 형식으로 하여 발견하지 못하면 -1이 아닌 이상한 값을 반환하므로 유의

    //문자열의 각 문자 다루기(at(), [])
    /*cout << em.at(5) << endl;//인덱스에 있는 문자 리턴
    cout << em[5] << endl;//동일한 표현
    em[5] = 'D';//[]연산자는 특정 문자를 다른 문자로 수정 가능
    cout << em << endl;
    cout << em.at(em.length()-1) << endl;//마지막 문자 얻기 */

    //문자열의 숫자 변환(stoi)
    string year = "2014";
    int n = stoi(year);
    cout << n << endl;

    //문자 다루기<locale>헤더(toupper(), isdigit(), isalpha())
    for(int i = 0;i<em.length(); i++){ em[i] = toupper(em[i]); };
    cout << em << endl;
    cout << isdigit(year[0]) << endl;//문자가 숫자인지 판별
    cout << isalpha(em.at(5)) << endl;//문자가 알파벳인지 판별
}   