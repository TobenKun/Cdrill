// 문자열 씹뜯맛
#include <stdio.h>
int copy_str(char *dest, char *src);
int stradd(char *dest, char *src);
int main(void) {
	char str1[100] = "hello my name is ";
	char str2[] = "youmi";
	
	printf("합치기 이전 : %s \n", str1);
	stradd(str1, str2);
	printf("합친 이후 : %s \n", str1);
	
	return 0;
}
int copy_str(char *dest, char *src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}
	
	*dest = '\0';
	
	return 1;
}
int stradd(char *dest, char *src) {
	while (*dest) {
		*dest++;
	}
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	
	return 1;
}
