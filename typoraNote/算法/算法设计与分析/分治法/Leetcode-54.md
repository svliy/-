# [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

## 暴力法：$O(n^2)$

```java
class Solution {
    
    public int maxSubArray(int[] nums) {
        int sum,r=nums[0];
        for(int i=0;i<nums.length;i++){
            sum = 0;
            for(int j=i;j<nums.length;j++){
                sum += nums[j];
                if(sum>r)   
                    r = sum;
            }
        }
        return r;
    }
}
```

## 分治法：

```java
as
```

