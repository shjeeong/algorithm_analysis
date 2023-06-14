## MST를 greedy하게 만들기 2

# Kruskal's algorithm





# Basic Implementation: O(mn)

```
Processing:
  S <- {}  // chosen edges
  Sort edges by weights

Main Loop:
  for each edge e, in increasing order of weights:
    if S and e does not make cycle:
      Add e into S
  return S
```

