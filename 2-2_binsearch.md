## Divide & Conquer

# Binary Search



## Pseudo Code

```
binsearch(k, l, u, x)
{
	if l > u
		return -1
	else
		m = ⌞(l + u) / m⌟
		if k[m] == x
			return m
		else if k[m] > x
			return binsearch(k, l, m - 1, x)
		else
			return binsearch(k, m + 1, u, x)
}
```



## 시간 복잡도: O(lgn)

```
T(n) ≤ T(n/2) + C
	 ≤ T(n/4)  + 2C
	 ≤ T(n/8) + 3C
    	...
	 ≤ T(1) + Clgn
	 ≤ T(0) + C(lgn + 1)
```

