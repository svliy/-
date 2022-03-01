## 基本操作

## 数据结构

### Map映射

> map 是按照特定==顺序存储==由key和value的组合形成的元素的容器,默认按照key的值从小到大排序
>
> key键：唯一决定一组映射关系key->value, map中每个key都是唯一的

```c++
声明
    map<key,value> mp;
使用方法
    mp.size():获取元素个数O(1)
 	mp.empty():判断是否为空O(1)
 	mp.clear():清空mp O(1)
 	mp.find(key):在map中查找key并返回其iterator,找不到的话返回mp.end() O(logn)
 	mp.count(key):在map中找key的数量，由于每个key都是唯一的，只会返回0或1
	mp[key] 可以直接访问到键值队key---value中的value，如果不存在这样的键值对，那么mp[key]返回的是value类型默认构造器所构造的值，并将该键值对插入到map中
	mp[key]=tmp:可以把键值对key---value中的value赋值为tmp,如果没有对应的键值对,则将该键值对插入到map中
	复杂度： O(logn)
	mp.insert(make_pair(key,value)):在mp中插入键值对key----value。
	一般不这样用，想要插入键值对的话直接使用mp[key]=value即可，map已经对[]运算符重载过了.
```

example 1 

> it->first:表示迭代器指向的键值对的key值
>
> it->second:表示迭代器指向的键值对的value值
>
> 当key为string时，按照字典序排列

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    map<int,int> mp;
    for(int i=3;i>=0;i--){
        mp[i] = i+1;
    }
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout << it->first << ' ' << it->second << endl;
    }
   
    return 0;
}
```

[C++ string中的find()函数 - 王陸 - 博客园 (cnblogs.com)](https://www.cnblogs.com/wkfvawl/p/9429128.html)

