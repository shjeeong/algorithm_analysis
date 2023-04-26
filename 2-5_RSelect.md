## Divide & Conquer: k<sup>th</sup> order statistic

# RSelect: ≅O(n)

```
RSelect(A[1...n], k)
{
  1. Choose a random pivot
  2. Partition: [less than pivot]pivot[greater than pivot]
  3. if k == j
       return pivot
     if k < j
       RSelect(A[1...j-1], k)
     if k > j
       RSelect(A[j+1...n], k-j)
}
```

평균적으로 linear time에 동작 (Partition 하는데 걸리는 시간)



