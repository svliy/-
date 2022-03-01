#### [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

> 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
>
> 算法的时间复杂度应该为 O(log (m+n)) 。
>

基础知识：

1.中位数：有序数组的中位数，奇数个元素时位于中间，偶数个元素时位中间的两个数的平均值。

举例： 
$$
if nums = [1,2,3] \\

  n = 3 2 2     2

[1,2,3,4]

n=4 2 3 2
$$


2.技巧：

设一个含n个元素的数组，如何让求其中位数？

答：中位数的值一定为 下标$(n+1)/2 和 (n+2)/2$的值的均值。

#### [506. 相对名次](https://leetcode-cn.com/problems/relative-ranks/)

> 给你一个长度为 `n` 的整数数组 `score` ，其中 `score[i]` 是第 `i` 位运动员在比赛中的得分。所有得分都 **互不相同** 。
>
> 运动员将根据得分 **决定名次** ，其中名次第 `1` 的运动员得分最高，名次第 `2` 的运动员得分第 `2` 高，依此类推。运动员的名次决定了他们的获奖情况：
>
> - 名次第 `1` 的运动员获金牌 `"Gold Medal"` 。
> - 名次第 `2` 的运动员获银牌 `"Silver Medal"` 。
> - 名次第 `3` 的运动员获铜牌 `"Bronze Medal"` 。
> - 从名次第 `4` 到第 `n` 的运动员，只能获得他们的名次编号（即，名次第 `x` 的运动员获得编号 `"x"`）。
>
> 使用长度为 `n` 的数组 `answer` 返回获奖，其中 `answer[i]` 是第 `i` 位运动员的获奖情况。

模拟：关键是建立排名和分数的映射。克隆score数组，并用sort()降序排序。将排序结果放在map中。遍历score数组，在map中找到其排名，按规则将字符串加入ans。

```c++
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        string ss[3] = {"Gold Medal","Silver Medal","Bronze Medal"};
        vector<int> clone(score);
        sort(clone.rbegin(),clone.rend());

        map<int,int> map;
        for(int i = 0; i < score.size(); i++){
            map[clone[i]] = i;
        }
        
        vector<string> ans;
        for(int i = 0; i < score.size(); i++){
            int tmp = map[score[i]];
            string tmp_s = tmp < 3 ? ss[tmp] : to_string(tmp+1);
            ans.push_back(tmp_s);
        }
        return ans;
    }
};
```

