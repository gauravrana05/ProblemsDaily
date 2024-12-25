#include<cstdio>
#include<iostream>
using namespace std;
const int N = 2e5 + 5;
int h[N], a[N];
int main(){
	int n, i, j, m, k;
	scanf("%d%d", &n, &m);
	for(i = 1;i <= n;i++)scanf("%d", &a[i]), h[a[i]] = i;
	for(i = 1, h[h[k = 0] = n + 1] = n + 1;i <= n;i++)k += h[i] < h[i - 1];
	while(m--){
		scanf("%d%d", &i, &j);
		if(a[i] > a[j])swap(i, j);
		k -= i < h[a[i] - 1];
		k -= h[a[i] + 1] < i;
		if(a[j] > a[i] + 1)k -= j < h[a[j] - 1];
		k -= h[a[j] + 1] < j;
		swap(a[i], a[j]);
		h[a[i]] = i;h[a[j]] = j;
		swap(i, j);
		k += i < h[a[i] - 1];
		k += h[a[i] + 1] < i;
		if(a[j] > a[i] + 1)k += j < h[a[j] - 1];
		k += h[a[j] + 1] < j;
		printf("%d\n", k);
	}return 0;
}