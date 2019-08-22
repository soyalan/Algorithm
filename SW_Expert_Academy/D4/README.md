# README

[TOC]

## D4

[D4 문제 주소](https://swexpertacademy.com/main/code/problem/problemList.do?problemLevel=4&problemTitle=&orderBy=FIRST_REG_DATETIME&select-1=3&pageSize=10&pageIndex=1)



### 1210 Ladder1

> direction을 통해 아래, 왼쪽, 오른쪽 구분



### 1211 Ladder2

> ladder1과 동일함
>
> count 값을 정하여 최단거리를 구하는 문제



### 1218 괄호 짝짓기

> 짝이 맞는지만 판단하면 됨 (순서 상관 없음)
>
> 순서가 필요하다면 stack을 사용해야 할 듯



### 1219 길찾기

> DFS를 이용해 문제 해결
>
> 함수에 참조형으로 넘기려하였으나 되지 않아서 전역변수 사용
>
> 전역변수를 사용했더니 초기화 문제가 발생 -> 매번 초기화 따로 해줌



### 1222 계산기1

> +만 존재
>
> 후위 표기식으로 변환하지 않고 그냥 처리...
>
> 추후에 후위 표기식으로 변환하는 것으로



### 1223 계산기2

> +와 *의 우선 순위 계산
>
> String을 이용하여 후위 표기식으로 변환
>
> 후위 표기식을 stack을 이용하여 계산



### 1224 계산기3

> ()+-*/ 우선 순위 계산
>
> String을 이용하여 후위 표기식으로 변환
>
> 후위 표기식을 stack을 이용하여 계산



### 1226 미로1

> DFS나 BFS를 사용하면 됨
>
> BFS 사용



### 1227 미로2

> 미로1과 동일
>
> 행렬의 크기가 늘어남
>
> 코드는 동일