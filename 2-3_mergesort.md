## Divide & Conquer

# Merge Sort



## Pseudo Code

```
⌞(l + u) / m⌟

mergesort (A(l...r))
{
	if (l < r)
		m = ⌞(l + u) / m⌟	O(1)
		mergesort(A(l, m))	// O(n/2)
		mergesort(A(m + 1, r))	// O(n/2)
		merge(A(l, m), A(m + 1, r))	// O(n)
}
```



## 시간복잡도:



