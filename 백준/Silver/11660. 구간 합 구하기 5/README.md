![image](https://github.com/SongJiUk/Algorithm/assets/67099323/46c9f700-d58d-41b1-b2e3-48026bdc2667)# 부분 합문제! 규칙을 기억하자!


![image](https://github.com/SongJiUk/Algorithm/assets/67099323/da0b7ac2-ed6c-49c5-b6c1-ab5a2ab2da27)
이렇게 있다고 치면, 부분합을 이런 식으로 구해주면 된다. </br>
DP[i][j] = MAP[i-1][j-1] + DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1]; (여기서 MAP은 0부터 값이 입력되고, DP는 1부터 입력이됨(x =0,  y= 0인값들은 다 0임) </br>
이게 부분합의 기본 식이다. 외워두도록 하자 외워놓으면 다른 문제에도 응용할 수 있음. </br>

부분합을 구한 다음 (2,2) ~ (3,4)의 합을 구해야되는데 이 문제는 이렇게 풀면 된다. </br>
2,2 를 x1,y1으로, 3,4 를 x2,y2로 표현한다고 하자.</br>

그럼 (x2,y2)는 처음부터 x2,y2의 값들을 모두 더한 값이다. 여기서 (x1-1,y2)와 (x2, y1-1)을 빼준다. 그 후에 겹치는 부분인 (x1-1, y1-1)을 한번 더해준다. </br>

![image](https://github.com/SongJiUk/Algorithm/assets/67099323/b277177f-33c8-4d4b-8348-6de6dd438aa8)
그림으로 설명하면 빨간색 - 노란색 - 파란색 + 초록색 이라고 생각하면 된다. </br>

처음 부분합을 접했을땐 많이 헷갈렸는데 그림으로 그려서 하다보니까 이제 이해가됐다. </br>



# [Silver I] 구간 합 구하기 5 - 11660 

[문제 링크](https://www.acmicpc.net/problem/11660) 

### 성능 요약

메모리: 10228 KB, 시간: 132 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2024년 5월 2일 21:30:15

### 문제 설명

<p>N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.</p>

<p>예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.</p>

<table class="table table-bordered" style="line-height:20.8px; width:158px">
	<tbody>
		<tr>
			<td style="text-align:center">1</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
		</tr>
		<tr>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
		</tr>
		<tr>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
			<td style="text-align:center">6</td>
		</tr>
		<tr>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
			<td style="text-align:center">6</td>
			<td style="text-align:center">7</td>
		</tr>
	</tbody>
</table>

<p>여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.</p>

<p>표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)</p>

### 출력 

 <p>총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.</p>

