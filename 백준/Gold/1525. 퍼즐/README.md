# BFS를 문자열로!
와 진짜 감탄했다. </br>
2차원 배열로 풀다가 방문처리가 안될것같아서 검색해봤는데 string을 이용하라더라.. </br>
string으로 풀어봤다. 방문처리는 set에다가 넣어주면 된다. ( set의 find함수는 시간복잡도가 O(logN)임)
이대로 풀다가 제일 막혔던건, 상하좌우 체크해주는 부분이었는데, 2차원배열로하면 i,j값을 적절히 바꾸면 상하좌우가 됐는데 </br>
문자열은 1차원배열이나 마찬가지니까 많이 헷갈렸다. </br>
내가 푼 방법은 어차피 상,하는 똑같이 줄어드니까 그대로 쓰고, 좌우가 0,1,2에서만 돌아가니까 MOD를 해줬다. </br>

BFS문제인거같아서 2차원배열로만 고민을 계속했는데, 문자열로도 풀 수있다니 진짜 감탄이 나온다. </br>
이제 이런문제 나오면 2차원배열에 국한되지않고, 새로운 방법도 터득했으니 기분이 좋다. </br>


# [Gold II] 퍼즐 - 1525 

[문제 링크](https://www.acmicpc.net/problem/1525) 

### 성능 요약

메모리: 16684 KB, 시간: 268 ms

### 분류

너비 우선 탐색, 자료 구조, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵

### 제출 일자

2024년 4월 12일 16:49:52

### 문제 설명

<p>3×3 표에 다음과 같이 수가 채워져 있다. 오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.</p>

<table class="table table-bordered" style="width:15%">
	<tbody>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">3</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">5</td>
			<td style="text-align: center;">6</td>
		</tr>
		<tr>
			<td style="text-align: center;">7</td>
			<td style="text-align: center;">8</td>
			<td style="text-align: center;"> </td>
		</tr>
	</tbody>
</table>

<p>어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다. 물론 표 바깥으로 나가는 경우는 불가능하다. 우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다. 다음의 예를 보자.</p>

<table class="table table-bordered" style="width:15%">
	<tbody>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;"> </td>
			<td style="text-align: center;">3</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">5</td>
		</tr>
		<tr>
			<td style="text-align: center;">7</td>
			<td style="text-align: center;">8</td>
			<td style="text-align: center;">6</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered" style="width:15%">
	<tbody>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">3</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;"> </td>
			<td style="text-align: center;">5</td>
		</tr>
		<tr>
			<td style="text-align: center;">7</td>
			<td style="text-align: center;">8</td>
			<td style="text-align: center;">6</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered" style="width:15%">
	<tbody>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">3</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">5</td>
			<td style="text-align: center;"> </td>
		</tr>
		<tr>
			<td style="text-align: center;">7</td>
			<td style="text-align: center;">8</td>
			<td style="text-align: center;">6</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered" style="width:15%">
	<tbody>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">3</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">5</td>
			<td style="text-align: center;">6</td>
		</tr>
		<tr>
			<td style="text-align: center;">7</td>
			<td style="text-align: center;">8</td>
			<td> </td>
		</tr>
	</tbody>
</table>

<p>가장 윗 상태에서 세 번의 이동을 통해 정리된 상태를 만들 수 있다. 이와 같이 최소 이동 횟수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 수가 주어진다. 한 줄에 세 개의 수가 주어지며, 빈 칸은 0으로 나타낸다.</p>

### 출력 

 <p>첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력한다.</p>

