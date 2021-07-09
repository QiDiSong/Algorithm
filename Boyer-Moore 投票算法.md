#### [面试题 17.10. 主要元素](https://leetcode-cn.com/problems/find-majority-element-lcci/)

数组中占比超过一半的元素称之为主要元素。给你一个 **整数** 数组，找出其中的主要元素。若没有，返回 `-1` 。请设计时间复杂度为 `O(N)` 、空间复杂度为 `O(1)` 的解决方案。

**示例 1：**

```
输入：[1,2,5,9,5,9,5,5,5]
输出：5
```

**示例 2：**

```
输入：[3,2]
输出：-1
```

**示例 3：**

```
输入：[2,2,1,1,1,2,2]
输出：2
```



### **方法1：**

​	可以使用list的count函数统计出现的次数，若count  > len / 2，则可以直接返回

​	count 的时间复杂度为O(lgn)

​	使用set可以避免重复统计

​	最终时间复杂度 < O(nlgn)

​			空间复杂度    O(1)

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        for i in set(nums):
            if nums.count(i) > len(nums) // 2:
                return i
        return -1
```

### 方法2：Boyer-Moore 投票算法

由于题目要求时间复杂度 O(n)*O*(*n*) 和空间复杂度 O(1)*O*(1)，因此符合要求的解法只有 \text{Boyer-Moore}Boyer-Moore 投票算法。

\text{Boyer-Moore}Boyer-Moore 投票算法的基本思想是：在每一轮投票过程中，从数组中删除两个不同的元素，直到投票过程无法继续，此时数组为空或者数组中剩下的元素都相等。

- 如果数组为空，则数组中不存在主要元素；
- 如果数组中剩下的元素都相等，则数组中剩下的元素可能为主要元素。

\text{Boyer-Moore}Boyer-Moore 投票算法的步骤如下：

1. 维护一个候选主要元素 \textit{candidate}*candidate* 和候选主要元素的出现次数 \textit{count}*count*，初始时 \textit{candidate}*candidate* 为任意值，\textit{count}=0*count*=0；
2. 遍历数组 \textit{nums}*nums* 中的所有元素，遍历到元素 x*x* 时，进行如下操作：
   1. 如果 \textit{count}=0*count*=0，则将 x*x* 的值赋给 \textit{candidate}*candidate*，否则不更新 \textit{candidate}*candidate* 的值；
   2. 如果 x=\textit{candidate}*x*=*candidate*，则将 \textit{count}*count* 加 11，否则将 \textit{count}*count* 减 11。
3. 遍历结束之后，如果数组 \textit{nums}*nums* 中存在主要元素，则 \textit{candidate}*candidate* 即为主要元素，否则 \textit{candidate}*candidate* 可能为数组中的任意一个元素。

由于不一定存在主要元素，因此需要第二次遍历数组，验证 \textit{candidate}*candidate* 是否为主要元素。第二次遍历时，统计 \textit{candidate}*candidate* 在数组中的出现次数，如果出现次数大于数组长度的一半，则 \textit{candidate}*candidate* 是主要元素，返回 \textit{candidate}*candidate*，否则数组中不存在主要元素，返回 -1−1。

为什么当数组中存在主要元素时，\text{Boyer-Moore}Boyer-Moore 投票算法可以确保得到主要元素？

在 \text{Boyer-Moore}Boyer-Moore 投票算法中，遇到相同的数则将 \textit{count}*count* 加 11，遇到不同的数则将 \textit{count}*count* 减 11。根据主要元素的定义，主要元素的出现次数大于其他元素的出现次数之和，因此在遍历过程中，主要元素和其他元素两两抵消，最后一定剩下至少一个主要元素，此时 \textit{candidate}*candidate* 为主要元素，且 \textit{count} \ge 1*count*≥1。

Python:

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = -1
        count = 0

        for num in nums:
            if count == 0:
                candidate = num
            if num == candidate:
                count += 1
            else:
                count -= 1

        count = 0 
        for num in nums:
            if num == candidate:
                count += 1
        
        return candidate if count > len(nums) // 2 else -1
```

C++:

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (auto num : nums)
        {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }
        count = 0;
        
        for (auto num : nums)
        {
            if (num == candidate)
                count++;
        }
        
        return (count > nums.size() / 2) ? candidate : -1;
    }
};
```

