// 문자열 씹뜯맛
#include <stdio.h>
int copy_str(char *dest, char *src);
int stradd(char *dest, char *src);
int compare(char *str1, char *str2);
int main(void) {
	char str1[100] = "hello evryone";
	char str2[] = "hello ";
	
	if (compare(str1, str2)) {
		printf("str1 : %s \n", str1);
		printf("str2 : %s \n", str2);
		printf("우리는 같음 \n");
	}
	else {
		printf("str1 : %s \n", str1);
		printf("str2 : %s \n", str2);
		printf("우리는 다름 \n");
	}
	
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
int compare(char *str1, char *str2) {
	while (!(*str1 == 0 && *str2 == 0)) {
		if (*str1 == *str2) {
			str1++;
			str2++;
		}
		else return 0;
	}
	return 1;
}
