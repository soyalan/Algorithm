# README

[TOC]

## Greedy Algorithm



`Greedy Algorithm` 

> 하나를 결정해야 할 때마다 그 순간에 최적이라고 생각되는 것을 선택해 나가는 방식
>
> 당시엔 최적이나 최종적으로 봤을 때 최적의 선택이라고 할 수는 없음







### 11399 ATM

[문제 주소](https://www.acmicpc.net/problem/11399)

> 정렬을 이용해 해결



### 11047 동전 0

[문제 주소](https://www.acmicpc.net/problem/11047)

> 큰 동전부터 차례차례 계산



### 1931 회의실배정

[문제 주소](https://www.acmicpc.net/problem/1931)

> 끝나는 시간 순서대로 정렬 후, 계속해서 가장 먼저 끝나는 것을 선택
>
> 초기엔 vector에서 종료시간보다 시작시간이 빠른 (시작할 수 없는 시간) 시간들을 하나하나 제거해줬는데 시간초과 발생
>
> 따라서 제거할 필요 없이 그냥 바로 continue를 이용해 넘기는 방식으로 변경



### 5585 거스름돈

[문제 주소](https://www.acmicpc.net/problem/5585)

> 동전 문제와 마찬가지로 큰 동전부터 계산



### 2217 로프

[문제 주소](https://www.acmicpc.net/problem/2217)

>정렬을 이용해서 계산
>
>하중이 큰 로프부터 계산하여 최대값을 찾음