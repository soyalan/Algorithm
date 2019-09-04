# README

[TOC]

## DFS (Depth First Search)



`DFS` 

> 깊이 우선 탐색



[DFS 문제 주소](https://www.acmicpc.net/problem/tag/DFS)





### 1260 DFS와 BFS

> DFS와 BFS 기초
>
> scanf를 사용 시 문제가 발생해 cin 사용



### 2667 단지번호붙이기

> DFS를 이용하여 근접한 칸의 값을 확인
>
> scanf에서 %1d를 활용



### 1012 유기농 배추

> 기본 DFS
>
> 근접한 칸의 값을 확인



### 11403 경로 찾기

> 조금 어려웠음
>
> 방문한 칸의 처리를 해주는 부분이 중요 (무한루프 주의)



### 6603 로또

> DFS로 풀지 않음
>
> 순열을 생성하는 permutation 사용
>
> 그냥 permutation을 사용했더니 중복 제거가 불가능
>
> 따라서 1이 6개, 나머지는 0으로 채워진 배열을 만들어 필터로 사용
>
> next_permutation을 사용했더니 큰 수부터 나와서 prev_permutation 사용