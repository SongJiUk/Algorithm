# 위상정렬!
줄세우기같은건 위상정렬로 하면 된다. </br>
위상정렬은 indegree만 생각하면된다! </br>
처음에 값을 받아줄때 indegree값도 함께 받아주면서 indegree가 0인 정점들을 큐에 넣어 먼저 돌려준다. </br>
그리고 난 후 차근차근 indegree값을 빼주면서 하나씩 계산해주면 된다. </br>
아무래도 값이 여러개가 나올 확률이 높은데, 그런 경우에는 문제에 답이 여러개인경우 아무거나 출력하라고 할것이다. </br>

위상정렬 (순서가 정해져있는 작업을 차례대로 수행해야 할 때, 그 순서를 정렬하기 위해 사용) </br>
싸이클이 존재하지않는 양방향 그래프에서 사용할 수 있다. </br>
만약 사이클이 존재하면 위상정렬을 사용할 수 없다. </br>

# [Gold III] 줄 세우기 - 2252 

[문제 링크](https://www.acmicpc.net/problem/2252) 

### 성능 요약

메모리: 3968 KB, 시간: 28 ms

### 분류

방향 비순환 그래프, 그래프 이론, 위상 정렬

### 제출 일자

2024년 4월 25일 13:15:08

### 문제 설명

<p>N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.</p>

<p>일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N(1 ≤ N ≤ 32,000), M(1 ≤ M ≤ 100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.</p>

<p>학생들의 번호는 1번부터 N번이다.</p>

### 출력 

 <p>첫째 줄에 학생들을 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.</p>

