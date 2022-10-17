# Data Structure Homework 1 - N 皇后問題變化版

### 題目

#### Input

輸入 M N K 三個數字，M N 表示棋盤大小，K 表示上面已經有的棋子數，接著輸入 K 列位置 X Y，表示在 (X,Y) 位置上預先放置了皇后，預先放置的皇后位置不重複，也不受路徑限制。  

3 <= M, N <= 10  
0 <= K <= M\*N  
0 <= X < M  
0 <= Y < N  

#### Output

輸出 P 表示最多還能再放 P 個皇后，接著輸出 P 列表示一組解中的每個皇后位置，可能不只一組解，但輸出一組解就好。

### 範例測資

#### Input

```
5 3 2
3 2
4 2
```

#### Output

```
1
0 0
```
