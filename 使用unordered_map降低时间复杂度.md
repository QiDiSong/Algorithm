

<u>**算法中#include <bits/stdc++.h>头文件几乎包含了所有想用的头文件，只包含这一个就可以使用**</u>

#### [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)

**大餐** 是指 **恰好包含两道不同餐品** 的一餐，其美味程度之和等于 2 的幂。

你可以搭配 **任意** 两道餐品做一顿大餐。

给你一个整数数组 `deliciousness` ，其中 `deliciousness[i]` 是第 `i` 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 **大餐** 的数量。结果需要对 `109 + 7` 取余。

注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

```
输入：deliciousness = [1,3,5,7,9]
输出：4
解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
```

```c++
#include <bits/stdc++.h>
using namespace std;

static int MOD = 1000000007;
int countPairs(vector<int>& deliciousness)
{
    int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
    int maxSum = maxVal * 2;
    int ans = 0;
    unordered_map<int, int> mp;
    for (auto val : deliciousness)
    {
        for (int sum = 1; sum <= maxSum; sum <<= 1)
        {
            int count = mp.count(sum - val) ? mp[sum - val] : 0;
            ans = (ans + count) % MOD;
        }
        mp[val]++;
    }
    return ans;
}

int main_() {

    vector<int> delicious =  {1,3,5,7,9};
    cout << countPairs(delicious) << endl;
    return 0;
}
```





```
//
// Created by s50016161 on 2021/7/7.
//
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

bool is2mi(int x)
{
    return (x & (x-1)) == 0 ? true : false;
}

int countPairs_(vector<int>& deliciousness)
{
    int ans = 0;
    unordered_map<int, int> map;
    for (auto val : deliciousness)
    {
        unordered_map<int, int>::iterator iter = map.begin();
        while (iter != map.end())
        {
            int sum = iter->first + val;
            if (sum != 0 && is2mi(sum))
                ans = (ans + iter->second) % MOD;
            iter++;
        }
        map[val]++;
    }
    return ans;
}

int main() {
    vector<int> delicious =  {1,3,5,7,9};
    cout << countPairs_(delicious) << endl;
    return 0;
}
```

