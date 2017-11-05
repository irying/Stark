这个博主的笔记真的强：http://www.jianshu.com/p/0190f4c987f7

### 一.map和set的底层实现为平衡二叉树

### `unordered_map`和`unordered_set`的底层实现为哈希表

```
两类查找问题

- 查找有无：元素’a’是否存在？set；集合
- 查找对应关系（键值对应）：元素’a’出现了几次？map；字典
```

哈希表不管查找、插入、删除都是O(1)的时间复杂度。

哈希表的缺点是失去了数据的顺序性

数据的顺序性

- 数据集中的最大值和最小值
- 某个元素的前驱和后继
- 某个元素的floor和ceil
- 某个元素的排位rank
- 选择某个排位的元素select

```
//349给定两个数组nums，求两个数组的公共元素。

//如nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//结果为[2]
//结果中每个元素只能出现一次
//出现的顺序可以是任意的
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>&num1, vector<int>&num2) {
       set<int> record(num1.begin(), num2.end());
       set<int> recordSet;
        for (int i = 0; i < num2.size(); i++) {
            if(record.find(num2[i]) != record.end())
                recordSet.insert(num1[i]);
        }
        
        return vector<int>(recordSet.begin(), recordSet.end());
    }
};

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersection(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}

```



###  二.Pattern Word

```
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {  
public:  
    bool wordPattern(string pattern, string str) {  
        str += " ";  
        int i = 0, j = 0, len1 = pattern.size(), len2=str.size();  
        unordered_map<char, string> hash1;  
        unordered_map<string, char> hash2;  
        while(i < len1 && j < len2)  
        {  
            int pos = str.find(' ', j);  
            string s = str.substr(j, pos-j);  
            if(hash1.count(pattern[i]) && hash1[pattern[i]]!=s) return false;  
            if(hash2.count(s) && hash2[s]!= pattern[i]) return false;  
            hash1[pattern[i]] = s, hash2[s] = pattern[i];  
            i++, j = pos+1;  
        }  
        return i==len1 && j ==len2;  
    }  
};  

int main() {
    string pattern = "aaaa";
    string str = "dog cat cat dog";
    bool res = Solution().wordPattern(pattern, str);
    cout<<res<<" ";
    cout<<endl;

    return 0;
}
```


php版本

```Php
<?php
$pattern = "abba";
$str = "dog cat cat dog";
$str .= " ";
$len1 = strlen($pattern);
$len2 = strlen($str);
$i=$j=0;
while ($i<$len1 && $j<$len2) {
    
    $pos = strpos($str, ' ', $j);
    $temp = substr($str, $j, $pos-$j);
    
    if (isset($hash1[$pattern[$i]]) && $hash1[$pattern[$i]] != $temp) {
        echo -1;
    } 
    
    if (isset($hash2[$temp]) && $hash2[$temp] != $pattern[$i]) {
        echo -2;
    } 
    $hash1[$pattern[$i]] = $temp;
    $hash2[$temp] = $pattern[$i];
  
    $j = $pos + 1;
    $i++;
}

if($i == $len1 && $j == $len2) {
    echo 1;
}else {
    echo 0;
}

?>
```