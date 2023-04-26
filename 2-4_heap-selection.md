## divide & conquer

>## selection problem (k<sup>th</sup> order statistic)
>
>정렬의 low bound인 O(nlgn)보다 빠르게 할 수 있다; linear time 알고리즘 존재 by divide & conquer

# heap-selection: O(n + klgn)

1. linear time으로 min-heap을 만들고; `O(n)`

> C * 2<sup>h-1</sup> + 2C * 2<sup>h-2</sup> + 3C * 2<sup>h-3</sup> + ... + hC * 2<sup>0</sup> 
>
> = C(sigma k=1, k=h) k * 2<sup>h-k</sup> ≤ C * 2<sup>h + 1</sup> ≤ C * k * n
>
> = O(n)

2. pop을 k번 한다; `O(klgn)`

