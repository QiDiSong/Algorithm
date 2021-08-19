python输入输出

# 1.直接是整数对
while True:
    try:
        num = list(map(int, input().strip().split()))
        print(sum(num))
    except:
        break
import sys
for line in sys.stdin:
    num = list(map(int, line.strip().split()))
    a, b = num[0], num[1]
    print(a + b)


# 2.先输入整数n，再输入n个整数对
n = eval(input())
while n:
    n -= 1
    num = list(map(int, input().strip().split()))
    print(sum(num))


# 3.输入0 0 则结束输入
import sys
for line in sys.stdin:
    num = list(map(int, line.strip().split()))
    a, b = num[0], num[1]
    if a == 0 and b == 0:
        break
    print(a + b)

# 4. 输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。
while True:
    try:
        inputData = list(map(int, input().strip().split()))
        
        if inputData[0] == 0:
            break
        else:
            print(sum(inputData[1:]))
        
    except EOFError:
        break

#include<iostream>
using namespace std;
  
int main () {
    int sum;
    int temp;
    while (cin>>temp) {
        sum+=temp;
        if (cin.get()=='\n'){
            cout<<sum<<endl;
            sum=0;
        }
    }
    return 0;
}


# c++ 排序

sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
});
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};



struct Music{
	string name;
	string style;
	int sum = 0;
	Robot(string _name, string _style): name(_name), style(_style){};
}
sort(result.begin(), result.end(), [](Music a, Music b){
	if (a.sum != b.sum) {return a.sum > b.sum;}
	else {return a.name < b.name;}
	});
for (auto &m : result)
{
	cout << m.name << " " << m.style << endl;
}



while True:
    try:
        num = list(input().split(","))
        num.sort()
        print(",".join(num))
    except:
        break
