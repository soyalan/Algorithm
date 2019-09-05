# README

[TOC]

## 1st



> 09.04 ~ 09.11



### 1.1 탐색과 정렬 (1)



#### 1920 수 찾기

> 탐색 개수가 10만 x 10만이므로 완전 탐색 불가능
>
> 이진 탐색 (Binary Search) 사용
>
> <algorithm> 안에 있는 binary_serach 사용
>
> ```cpp
> bool x = binary_search(v.begin(), v.end(), number);
> ```