## dynamic programming

# Optimal BST

검색만 하기 위한 BST 만들기 

키값 검색 횟수가 정해져있을 때 검색 확률이 높은 키를 위쪽(루트 쪽)으로 보내자

![image-20230426184324060](image/image-20230426184324060.png)

p(i, j) : i ... j 의 검색 확률의 합

행렬 곱할 때랑 식만 조금 다름 (똑같이 opt랑 k표 만들어서 계산)

