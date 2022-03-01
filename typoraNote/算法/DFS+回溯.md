深搜和宽搜的区别

深搜：当状态数量比较庞大，但解的方案数很少的时候。例：数独的某一种解。

宽搜：最小的步数，最短的距离。搜索方案有限。

搜索 != 递归

![image-20211212000255766](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20211212000255766.png)

![image-20211212000330143](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20211212000330143.png)

数据范围小，用搜索

数据范围大，用动态规划

![image-20211212001905167](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20211212001905167.png)





数独问题

![image-20211212122741141](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20211212122741141.png)

TLE！！！



优化方式：

1. 优化搜索顺序 优先选择策略少的
2. 排除冗余信息
3. 可行性剪枝
4. 最优化剪枝

![image-20211212124138762](C:\Users\app\AppData\Roaming\Typora\typora-user-images\image-20211212124138762.png)













正确的：

1. 
