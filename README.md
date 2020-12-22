# 텍스트 파일에서 빈도수 높은 특정 길이의 문자열 추출하기

## 사용한 것들

- Hash Map(unordered_map)
- stringstream, string
- vector, pair, sort

길이 n으로 텍스트 파일에서 문자열을 잘라서 Hash Map에 담고,
vector<pair<string, int>>에 해당 Hash Map을 저장 및 정렬(빈도수 int 기준)하여
첫 번째 index의 요소 문자열을 출력

---

## 프로그램의 전체적인 흐름 및 알고리즘

① 입력 redirection으로 지정한 텍스트 파일에서 추출할 문자열의 길이(n),
텍스트 파일의 전체 텍스트를 읽어서 저장.

② stringstream에 전체 텍스트를 저장한 후, 추출할 문자열 길이 n으로 문자열을 자름.

③ 자른 문자열들을 해쉬 맵(unordered_map)에 저장.

④ ②~③의 과정을 string stream을 다 읽을 때까지 반복.

⑤ 자른 문자열들이 모두 담긴 Hash map을 벡터에 저장 후,
벡터를 해쉬 맵의 value 값(문자열 등장 횟수, 빈도수)을 기준으로 내림차순 정렬
=> value 값이 큰 요소가 앞에 위치하게 됨.

⑥ 정렬된 vector의 첫 번째 요소 출력
=> 전체 텍스트에서 가장 많이 등장한 문자열이 출력됨.

---

## 프로그램 실행 방법

- 명령 프롬프트(CMD)에서 redirection 이용
- HW3.exe < testcase0.txt
