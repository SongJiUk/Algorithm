# 예전에 풀어봤던 DP문제
근데 그 문제는 난이도가 이것보다 높았다. 애초에 이진수의 자리수를 기준으로 주지않고 자연수 K를 줬었지..</br>
이 문제의 점화식은 DP[i] = DP[i - 2] + DP[i -1]!! </br>
한번 유사한 문제를 풀어봐서 그런지 바로바로 떠올려서 쉽게 풀 수 있었던것 같다.</br>


# [Silver III] 이친수 - 2193 

[문제 링크](https://www.acmicpc.net/problem/2193) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 3월 12일 19:59:10

### 문제 설명

<p>0과 1로만 이루어진 수를 이진수라 한다. 이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 이들을 이친수(pinary number)라 한다. 이친수는 다음의 성질을 만족한다.</p>

<ol>
	<li>이친수는 0으로 시작하지 않는다.</li>
	<li>이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.</li>
</ol>

<p>예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.</p>

<p>N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N이 주어진다.</p>

### 출력 

 <p>첫째 줄에 N자리 이친수의 개수를 출력한다.</p>

