# 2022/1/17

两数之和

注意：重复元素

# 2022/1/18

## 代码随想录——数组

- 地址：https://programmercarl.com/%E6%95%B0%E7%BB%84%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#%E6%95%B0%E7%BB%84%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80
- 内存的地址空间是按照**字节**编址。所以说1代表的是1个字节（8位）。
- C++的二组在地址空间上是连续的，Java呢？

关于数组，只需要注意一下几点

1. 一般上，我们认为数组在地址空间上连续的。
2. 可以通过**下标**访问数组的元素，也可以使用for-each循环。
3. 特别的，下标是从0开始的。不想使用0的话，多开点空间就好了。

### 二分查找

​	出身在中国和美国都很重要。

- 链接：https://leetcode-cn.com/problems/binary-search/
- 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
- 关键点：有序，无重复元素
- 集合在算法中的使用
- 二分查找跟实数的基本定理有关，是一个特别的技巧。

关键点：

1. 区间就是不变量。根据区间的定义来写算法。
2. 循环不变量规则，在每一次的循环中都根据定义的区间来查找target。

实现代码：

​		定义区间为左闭右开$[left, right)$。

​		特别的处理是$m = l + ((r - l) >> 1)$，具体是下位中位数还是上位中位数以后再讨论。

```java
class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] > target)
                r = m;
            else if (nums[m] < target)
                l = m + 1;
            else 
                return m;
        }
        return -1;
    }
}	
```

#### [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)

> 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
>
> 请必须使用时间复杂度为 O(log n) 的算法。
>

前提：数组有序且无重复元素。

例子：
$$
nums = [1,3,5,6]\\
taget = 2\\
$$
​		定义的区间是$[l, r)$，当数组中不存在target值时，区间会收缩到两个元素的范围内$[l, l+1)$，其中$l+1$一定取不到，只能取到$l$，所以最后$l$会前进成为$l+1$。

​		或者说算法取到应当插入位置的值。

二分法——实现代码：

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] > target)
                r = m;
            else if (nums[m] < target)
                l = m + 1;
            else
                return m;
        }
        return l; 
    }
}
```

