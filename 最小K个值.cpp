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



快排
 Paritition1(int A[], int low, int high) {
   int pivot = A[low];
   while (low < high) {
     while (low < high && A[high] >= pivot) {
       --high;
     }
     A[low] = A[high];
     while (low < high && A[low] <= pivot) {
       ++low;
     }
     A[high] = A[low];
   }
   A[low] = pivot;
   return low;
 }

 void QuickSort(int A[], int low, int high) //快排母函数
 {
   if (low < high) {
     int pivot = Paritition1(A, low, high);
     QuickSort(A, low, pivot - 1);
     QuickSort(A, pivot + 1, high);
   }
 }

int partition(vector<int> a; int low, int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= pivot)
			high--;
		a[low] = a[high];
		while (low < high && a[low] <= pivot)
			low++;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void quickSort(vector<int> a, int low, int high)
{
	if (high >= low)
		return ;
	int pivot = partition(a, low, high);
	quickSort(a, low, pivot - 1);
	quickSort(a, pivot + 1, high);

}

topK(快排实现)
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        quickSort(arr, 0, arr.size() - 1, k);
        for (int i = 0; i < k; i++)
            ans[i] = arr[i];
        return ans;
    }
    int quickSortPartition(vector<int>& arr, int start, int end)
    {
        int pivot = arr[end];
        int bigger = start;
        for (int i = start; i <= end - 1; i++)
        {
            if (arr[i] < pivot)
            {
                swap(arr[i], arr[bigger]);
                bigger++;
            }
        }
        swap(arr[bigger], arr[end]);
        return bigger;
    }
    void quickSort(vector<int>& arr, int start, int end, int k)
    {
        if (start >= end)
            return;
        int kIndex = quickSortPartition(arr, start, end);
        if (kIndex == k)
            return;
        if (kIndex < k)
            quickSort(arr, kIndex + 1, end, k);
        else
            quickSort(arr, start, kIndex - 1, k);
    }
};


归并

堆排序
链表排序
lru
kmp
非静态成员的this指针
友元函数
