题目描述：

一个只包含0和1的字符串S，让找到一个非空连续字串T使得0的个数减去1的个数的差值最大，并给出最大值是多少？

思路：

使用前缀和，求出前k个的value是多少。字符0的weight为+1，字符1的weight为-1

然后遍历前缀和数组，O(N*N)，两层for循环遍历，求出preSum[i] - preSum[j]最大的值是多少，即为所求

使用前缀和思路将原来的O(N*N*N)的复杂度降低到O(N*N)

```
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> preSum(s.size(), 0);
    presum[0] == (s[0] == '0' ? 1 : -1);
    int ans = INT_MIN;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '1')
            preSum[i] = preSum[i-1] - 1;
        else
            preSum[i] = preSum[i-1] + 1;
    }
    for (int i = 0; i <= s.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (preSum[i] - preSum[j] > ans)
                ans = preSum[i] - preSum[j];
        }
    }
    cout << ans << endl;
    return 0;
}

```

