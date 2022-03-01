### 常用操作

```java
package com.asuka.Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Array {
    public static void main(String[] args) {
        //Four solutions to create an array in java
        //Take [1,2,3] as example
        //Solution1
        int[] a = {1, 2, 3};
        System.out.println("a: " + Arrays.toString(a));
        //Solution2
        int[] b = new int[]{1, 2, 3};
        System.out.println("b: " + Arrays.toString(b));
        //Solution3
        int[] c = new int[3];
        for (int i = 0; i < c.length; i++) {
            c[i] = i + 1;
        }
        System.out.println("c: " + Arrays.toString(c));
        //Solution4
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            arr.add('A' + i);
        }
        //arr: [65, 66, 67, 68]
        System.out.println("arr: " + arr.toString());


        //添加元素
        //Add element
        //Time Complexity:O(1) or O(N)
        arr.add(99);
        //arr: [65, 66, 67, 68, 99]
        System.out.println("arr: " + arr.toString());

        arr.add(0, 99);
        //arr: [99, 65, 66, 67, 68, 99]
        System.out.println("arr: " + arr.toString());

        //访问元素
        //通过下标或者索引访问
        //Access element
        //Time Complexity:O(1)
        int cl = c[1];
        int arrl = arr.get(1);
        //1
        System.out.println("cl: " + cl);
        System.out.println("arrl: " + arrl);


        //更新元素
        //Update element
        //Time Complexity:O(1)
        c[1] = 11;
        arr.set(1, 11);
        //
        System.out.println("cl: " + c[1]);
        System.out.println("arrl: " + arr.get(1));


        //删除元素
        //Remove element
        //Time Complexity:O(N)
        arr.remove(3);
        System.out.println("arrl: " + arr.toString());


        //数组长度
        //The length of an array
        //Time Complexity:O(1)
        int cSize = c.length;
        int arrSize = arr.size();
        System.out.println("cSize:" + cSize);
        System.out.println("arrSize:" + arrSize);


        //遍历数组
        //Iterate an array
        //Time Complexity:O(1)
        //Iterate c
        for (int i = 0; i < c.length; i++) {
            int current = c[i];
            System.out.println("c at index" + i + ": " + current);
        }
        //Iterate arr
        for (int j = 0; j < arr.size(); j++) {
            int current = arr.get(j);
            System.out.println("arr at index" + j + ": " + current);
        }


        //查找元素
        //Find an element
        //Find an element in c
        for (int i1 = 0; i1 < c.length; i1++) {
            if (c[i1] == 11) {
                System.out.println("We find 11 in c!");
            }
        }
        //Find an element in arr
        boolean is68 = arr.contains(68);
        System.out.println("Are we found 68 in arr?" + is68);

        //数组排序
        //Sort an array by built-in lib
        int[] d = new int[]{2, 3, 1};
        ArrayList<Integer> arr01 = new ArrayList<>();
        arr01.add(2);
        arr01.add(3);
        arr01.add(1);
        //[2,3,1]
        System.out.println("d: " + Arrays.toString(d));
        System.out.println("arr01: " + arr01.toString());
        //from small to big
        //Time Complexity:O(NlogN)
        Arrays.sort(d);
        System.out.println("d: " + Arrays.toString(d));

        Collections.sort(arr01);
        System.out.println("arr01: " + arr01.toString());
        Collections.sort(arr01,Collections.reverseOrder());
        System.out.println("arr01: " + arr01.toString());

        //read an array in reverse
        //Integer T[] = new Integer[3];
        //Arrays.sort(T[],Collections.reverseOrder());
        //System.out.println("arr01: " + arr01.toString());
    }
}

```



### 练习题

| 题目编号 | 题目            | 英文                  |
| -------- | --------------- | --------------------- |
| 283      | 移动零          | Remove Element        |
| 27       | 移除元素        | Move Zero             |
| 485      | 最大连续1的个数 | Max Consecatinue Ones |



