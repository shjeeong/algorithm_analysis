## Divide & Conquer

# Merge Sort



## Pseudo Code

```
mergesort (A(l...r))
{
	if (l < r)
-		m = ⌞(l + u) / m⌟				// O(1)
		mergesort(A(l, m))			// O(n/2)
		mergesort(A(m + 1, r))	// O(n/2)
		merge(A(l, m), A(m + 1, r))	// O(n)
}
```



## 시간복잡도: O(nlgn)

```
T(n) ≤ 2T(n/2) + Cn
	≤ 4T(n/4) + 2Cn
	...
	≤	lgnT(1) + lgnCn
```





