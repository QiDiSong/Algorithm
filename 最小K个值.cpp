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
