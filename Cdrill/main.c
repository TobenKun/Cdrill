// 도서 관리 프로그램
#include <stdio.h>
int addBook(char books[][3][30],int isHere[], int bookCount); //책 새로 추가 (제목, 저자, 출판사)
int searchBookName(char books[][3][30],int isHere[]); // 책 제목 검색하면 책 정보 나오게
//int searchBookAuthor();
//int searchBookPublish();
//int borrowBook();
//int returnBook();
int checkSame(char[], char[]);

int main(void) {
	char books[100][3][30]; // books[권수][제목, 저자, 출판사][해당 내용]
	int isHere[100];
	int bookCount = 0;
	int userIndex;
	
	
	printf("메뉴 번호를 입력하세요 \n");
	printf("1. 책 추가 \n");
	
	scanf("%d", &userIndex);
	if (userIndex == 1) {
		addBook(books,isHere, bookCount);
		bookCount++;
	}
	
	
	
	return 0;
}
int addBook(char books[][3][30],int isHere[], int bookCount) {
	
	printf("책 제목을 입력하세요 : ");
	scanf("%s", books[bookCount][0]);
	printf("책의 저자를 입력하세요 : ");
	scanf("%s", books[bookCount][1]);
	printf("출판사를 입력하세요 : ");
	scanf("%s", books[bookCount][2]);
	isHere[bookCount] = 1;
	
	
	return 1;
}
int searchBookName(char books[][3][30],int isHere[]) {
	int i;
	int bookIndex;
	char bookname[30];
	
	scanf("%s", bookname);
	for (i = 0; i < 100; i++) {
		if (checkSame(bookname, books[i][0]) == 1) {
			bookIndex = i;
			break;
		}
	}
		
	return 1;
}
int checkSame(char src1[], char src2[]) {
	int i = 0;
	while (!(src1[i] == 0 && src2[i] == 0)) {
		if (src1[i] == src2[i]) {
			i++;
		}
		else return 0;
	}
	return 1;
}
