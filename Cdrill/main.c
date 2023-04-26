// 도서 관리 프로그램
#include <stdio.h>
int addBook(char books[][3][30],int isHere[], int bookCount); //책 새로 추가 (제목, 저자, 출판사)
int searchBook(char books[][3][30],int isHere[]); // 책 제목 검색하면 책 정보 나오게
//int borrowBook();
//int returnBook();
int checkSame(char[], char[]);
int bookSearchTool(char books[][3][30], char[], int j, int isHere[]);

int main(void) {
	char books[100][3][30]; // books[권수][제목, 저자, 출판사][해당 내용]
	int isHere[100];
	int bookCount = 0;
	int userIndex;
	
	while (1) {
		printf("메뉴 번호를 입력하세요 \n");
		printf("1. 책 추가 \n");
		printf("2. 책 제목으로 검색 \n");
		
		printf("0. 프로그램 종료 \n");
		printf("----------------------------- \n");
		
		scanf("%d", &userIndex);
		if (userIndex == 1) {
			addBook(books,isHere, bookCount);
			bookCount++;
		}
		else if (userIndex == 2) {
			searchBook(books, isHere);
		}
		else if (userIndex == 0) {
			break;
		}
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
	printf("저장되었습니다. 초기 메뉴로 돌아갑니다 \n\n");
	
	
	return 1;
}
int searchBook(char books[][3][30],int isHere[]) {
	int i,j;
	int bookIndex = -1;
	char input[30];
	
	printf("무엇으로 검색하시겠습니까? \n");
	printf("0. 책 제목 \n");
	printf("1. 저자 \n");
	printf("2. 출판사 \n");
	scanf("%d", &j);
	
	if (j == 0) {
		printf("책 제목을 입력하세요 :");
		scanf("%s", input);
		bookSearchTool(books, input, j, isHere);
	}
	
	
//	for (i = 0; i < 100; i++) {
//		if (checkSame(input, books[i][j]) == 1) {
//			bookIndex = i;
//			printf("해당 책의 정보는 다음과 같습니다. \n");
//			printf("책 제목 : %s \n", books[bookIndex][0]);
//			printf("저자 : %s \n", books[bookIndex][1]);
//			printf("출판사 : %s \n", books[bookIndex][2]);
//										if (isHere[i] == 0) {
//										printf("이 책은 대출 중입니다. \n\n");
//										}
//										if (isHere[i] == 1) {
//										printf("이 책은 대출 가능합니다. \n\n");
//										}
//		}
//		else if (i == 99 && bookIndex == -1) {
//			printf("일치하는 책이 존재하지 않습니다. \n");
//			printf("초기 메뉴로 돌아갑니다. \n\n");
//		}
//	}

		
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
int bookSearchTool(char books[][3][30], char input[], int j, int isHere[]) {
	int i;
	int bookIndex = -1;
	for (i = 0; i < 100; i++) {
		if (checkSame(input, books[i][j]) == 1) {
			bookIndex = i;
			printf("해당 책의 정보는 다음과 같습니다. \n");
			printf("책 제목 : %s \n", books[bookIndex][0]);
			printf("저자 : %s \n", books[bookIndex][1]);
			printf("출판사 : %s \n", books[bookIndex][2]);
										if (isHere[i] == 0) {
										printf("이 책은 대출 중입니다. \n\n");
										}
										if (isHere[i] == 1) {
										printf("이 책은 대출 가능합니다. \n\n");
										}
		}
		else if (i == 99 && bookIndex == -1) {
			printf("일치하는 책이 존재하지 않습니다. \n");
			printf("초기 메뉴로 돌아갑니다. \n\n");
		}
	}
	
	return 0;
}
