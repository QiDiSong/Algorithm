C++中对于vector中的元素顺序排序为：

```cpp
std::sort(v.begin(),v.end());
```

对于vector中的元素逆序排序为：

```cpp
std::sort(v.rbegin(),v.rend());
```

如对以下vector逆序排序

```cpp
#include <vector>
#include <algorithm>
int main() {
 std::vector<int> v1;
 v1.push_back(10);
 v1.push_back(2);
 v1.push_back(0);
 v1.push_back(5);
 v1.push_back(-1);
 v1.push_back(20);
 v1.push_back(3);
 v1.push_back(1);
 v1.push_back(-5);
 v1.push_back(2);
 std::sort(v1.rbegin(), v1.rend());
 for (unsigned int i = 0; i < v1.size(); i++)
 {
  printf("[%d]",v1[i]);
 }
}12345678910111213141516171819
```

运行结果为:

```cpp
[20][10][5][3][2][2][1][0][-1][-5]
```

**<u>vector如何reverse</u>**

```
reverse(vec.begin(), vec.end())
```

