# README

[TOC]

## Permutation ( 순열 )



##### 순열

> nPm
>
> > m개의 숫자에서 n개 (중복 허용)
> >
> > (m) x (m-1) x (m-2) ... 총 n개를 곱함
>
> nCm
>
> > m개의 숫자에서 n개 (중복 불가)
> >
> > (m) x (m-1) x (m-2)... 총 n개 / (n) x (n-1) x (n-2) ... 1 까지 곱



[순열 문제 주소](https://www.acmicpc.net/problem/tag/순열)



### 10974 모든 순열

> <Algorithm> 안의 next_permutation 사용
>
> ```cpp
> next_permutation(arr, arr + n)
> ```
>
> 다음 순서에 해당하는 arr로 변경해줌
>
> return 값은 true
>
> 다음 순열이 없을 경우 false를 리턴

