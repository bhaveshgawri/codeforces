#include <cstdio>

int main(){
	int a, b, c, d, ans;
	scanf("%d%d%d%d", &a ,&b ,&c ,&d);
	ans = ((a^b)&(c|d))^((b&c)|(a^d));
	printf("%d\n", ans);
}