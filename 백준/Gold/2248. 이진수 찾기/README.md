# DP진짜 너무빡세다..
전제조건자체가 0부터 시작할수 있으니까 </br>
0~N이 시작이란소린데.. </br>
암튼 이번에도 문제를 잘못 이해했다. 3개 이하라고하면 00000부터 시작되는건데 그냥 그 지점부터 생각해버렸다.</br>
일단 DP문제를 풀다보면 점화식을 먼저 찾고싶은데 점화식 찾는것도 생각보다 쉽지가 않다. </br>
검색해본결과 DP[i][j] = DP[i-1][j] + DP[i-1][j-1] 라는것만 봤고 문제가 풀렸다.</br>
여기서 i는 i번째를 뜻하는것이고, j는 1의 개수를 뜻하는것이다.(DP[1][1] -> 1번째자리까지 1의 개수)</br>
이렇게 찾아서 다 풀어놓고 N번째 까지 DP를 확인해보는데 여기서 애초에 N이라는 값은 정해져있다. </br>
정해져 있으니 0의 개수는 정해져있고. N이 5라고할때 DP[4][] 의 값을 모두 더해서 I값보다 작게되면 무조건 DP[5] 안에 답이 있는것. </br>
그렇게 해서 I를 빼가주면서 1과 0을 입력해주면 된다. </br>



# [Gold III] 이진수 찾기 - 2248 

[문제 링크](https://www.acmicpc.net/problem/2248) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 3월 8일 15:46:30

### 문제 설명

<p>N(1 ≤ N ≤ 31)자리의 이진수가 있다. 이러한 이진수 중에서, L(1 ≤ L ≤ N)개 이하의 비트만 1인 것을 크기 순으로 나열했을 때, I번째로 나오는 이진수를 구해내는 프로그램을 작성하시오. 이진수는 0으로 시작할 수도 있다.</p>

### 입력 

 <p>첫째 줄에 세 정수 N, L, I가 주어진다. I번째 이진수가 있는 입력만 주어진다.</p>

### 출력 

 <p>첫째 줄에 답을 출력한다.</p>

