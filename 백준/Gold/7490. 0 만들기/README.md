# 진짜 어지럽네 문제 ㅋㅋㅋ
일단 나는 이렇게 풀었다. </br>
1. 값을 받아서 +, -, ' ' 순으로 DFS해서 값을 모두 저장해줬다. </br>
2. 그리고 저장한 값들을 하나씩 순차시켜서 해당값의 번호를 저장해 큐로 돌려줬다. </br>
3. 큐를 돌리면서 받는 +, -, ''의 번호로 공백문자를 없애줬다. </br>
4. 없애준 문자열을 다시 백트래킹해서 값을 더해줬다. </br>
5. 더한 값중에 0이 있다면 새로운 벡터에 넣어줬다. </br>
6. 벡터를 아스키코드값에 맞도록 정렬해줬다. 공백 > + > - </br>

나도 6번을 안해서 틀렸다고 나오길래 아 또 언제하나 했다가 출력문구를 읽고 다시 정렬시켰다. cmp에서 for문은 처음써보는것같다. </br>

# [Gold V] 0 만들기 - 7490 

[문제 링크](https://www.acmicpc.net/problem/7490) 

### 성능 요약

메모리: 2548 KB, 시간: 4 ms

### 분류

백트래킹, 브루트포스 알고리즘, 구현, 문자열

### 제출 일자

2024년 4월 3일 13:03:24

### 문제 설명

<p>1부터 N까지의 수를 오름차순으로 쓴 수열 1 2 3 ... N을 생각하자.</p>

<p>그리고 '+'나 '-', 또는 ' '(공백)을 숫자 사이에 삽입하자(+는 더하기, -는 빼기, 공백은 숫자를 이어 붙이는 것을 뜻한다). 이렇게 만든 수식의 값을 계산하고 그 결과가 0이 될 수 있는지를 살피자.</p>

<p>N이 주어졌을 때 수식의 결과가 0이 되는 모든 수식을 찾는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수가 주어진다(<10).</p>

<p>각 테스트 케이스엔 자연수 N이 주어진다(3 <= N <= 9).</p>

### 출력 

 <p>각 테스트 케이스에 대해 ASCII 순서에 따라 결과가 0이 되는 모든 수식을 출력한다. 각 테스트 케이스의 결과는 한 줄을 띄워 구분한다.</p>

