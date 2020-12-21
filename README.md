# 텍스트 파일에서 빈도수 높은 특정 길이의 문자열 추출하기

## 사용한 것들

- Hash Map(unordered_map)
- stringstream, string
- vector, pair, sort

길이 n으로 텍스트 파일에서 문자열을 잘라서 Hash Map에 담고,
vector<pair<string, int>>에 해당 Hash Map을 저장 및 정렬(빈도수 int 기준)하여
첫 번째 index의 요소 문자열을 출력

---

## 프로그램 실행 방법

- 명령 프롬프트(CMD)에서 redirection 이용
- HW3.exe < testcase0.txt
