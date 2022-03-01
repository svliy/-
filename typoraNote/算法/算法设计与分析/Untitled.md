### 快速幂

```c++
typedef long long ll;
ll quick_pow(ll x,ll n,ll m){
	ll res = 1;
	while(n > 0){
		if(n & 1)	res = res * x % m;
		x = x * x % m;
		n >>= 1;//相当于n=n/2.详情请参考位移运算符。
	}
	return res;
} 
```

[ZZUOJ](http://acm.zzu.edu.cn/)



## 部分背包问题

```c++
#include <bits/stdc++.h>
using namespace std;
struct str{
    double m;
    double v;
    double u;
}s[101];
int n;
double ans,t;
bool cmp(str a,str b){
    return a.u>b.u;
}
int main(){
    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> s[i].m >> s[i].v;
        s[i].u = s[i].v / s[i].m;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        if(t>s[i].m){
            t -= s[i].m;
            ans += s[i].v;
        }else{
            ans += t*s[i].u;
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}
```





### 结构体

http://c.biancheng.net/view/1407.html

```

```

### poj

- 1521
- 2485
- 1751
- 1328
