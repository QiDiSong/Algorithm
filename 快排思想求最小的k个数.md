快排思想求解数组中的前K小的数，前K小的数不需要排序

核心函数：quickSortPartition(a, start, end)

此函数会将a[start, end]的全部数据，以a[end]为中轴线，划分为左右两边

其中bigger表示大于中轴线pivot的第一个idx

less表示从start到end-1的当前idx

经过一次quick Sort Partition过后，就会以a[end]为中轴划分成左右两边

C++代码：

```
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size()-1, k);
        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++) 
        {
            ans[i] = arr[i];
        }
        return ans;
    }
    int quickSortPartition(vector<int> &arr, int start, int end)
    {
        int pivor = arr[end];
        int bigger = start;
        for (int less = start; less <= end - 1; less++)
        {
            if (arr[less] < pivor)
            {
                swap(arr[bigger], arr[less]);
                bigger++;
            }
        }
        swap(arr[bigger], arr[end]);
        return bigger;
    }
    void quickSort(vector<int> &arr, int start, int end, int k)
    {
        if (start >= end)
            return;
        int ret = quickSortPartition(arr, start, end);
        if (ret == k)
            return;
        if (ret < k) {
            quickSort(arr, ret+1, end, k);
        } else {
            quickSort(arr, start, ret-1, k);
        }
    }
};
```

Python代码：

```
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:

        def quickSortPartition(a, start, end):
            pivot = a[end]
            bigger = start
            for less in range(start, end):
                if a[less] < pivot:
                    a[less], a[bigger] = a[bigger], a[less]
                    bigger += 1
            a[bigger], a[end] = a[end], a[bigger]
            return bigger
        def quickSort(a, start, end, k):
            if start >= end:
                return
            idx = quickSortPartition(a, start, end)
            if idx == k:
                return 
            if (idx < k):
                quickSort(a, idx+1, end, k)
            else:
                quickSort(a, start, idx-1, k)
        quickSort(arr, 0, len(arr)-1, k)
        return arr[0:k]
```

