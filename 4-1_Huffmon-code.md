## Greedy

# Huffmon code (and data compression)

symbol --(encode)--> code

code --(decode)--> encode

각 symbol에는 특정 codeword가 배정되어 있음

## prefix-free code

: 어떤 codeword가 다른 codeword의 prefix가 아닌 경우 --> decode 가능함

binary tree로 표현 가능하면 prefix-free code임

- external node -> symbol
- path -> word



## 가장 짧게 encoding하는 code 찾기

각각의 symbol의 등장 횟수가 정해져 있을 때 가장 짧게 encoding 하려면

![image-20230426151736293](image/image-20230426151736293.png)

빈도의 합이 가장 작게 나오도록 묶는 것을 반복해서 binary tree 만들기

그 결과로 빈도가 낮은 것들은 아래쪽에 있을 가능성이 크고, 빈도가 높은 것들은 위쪽에 있을 가능성이 큼; 아래쪽에 있을 수록 codeword의 길이가 길어짐

이는 optimal한 결과임; 즉 그리디한 방식이라는 뜻