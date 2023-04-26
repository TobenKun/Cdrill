// 도서 관리 프로그램
#include <stdio.h>
int addBook(char books[][3][30],int isHere[], int bookCount); //책 새로 추가 (제목, 저자, 출판사)
int searchBook(char books[][3][30],int isHere[]); // 책 검색을 시작하는 함수 (검색자체는 bookSearchTool이 진행함)
int borrowBook(char books[][3][30],int isHere[]); // 책 대출 함수
int returnBook(char books[][3][30],int isHere[]); // 책 반납 함수
int checkSame(char[], char[]); // 문자열이 같은지 체크하는 함수
int bookSearchTool(char books[][3][30], int j, int isHere[]); // 실제로 검색을 하는 함수

int main(void) {
	char books[100][3][30]; // books[권수][제목, 저자, 출판사][해당 내용]
	int isHere[100]; // 100권의 대출 여부 배열
	int bookCount = 0; // addbook함수에서 사용할 카운터, addBook 안에서 선언하면 초기화돼서 여기다 선언
	int userIndex; // 메뉴 호출 인덱스
	
	while (1) {
		printf("메뉴 번호를 입력하세요 \n");
		printf("1. 책 추가 \n");
		printf("2. 책 검색 \n");
		printf("3. 책 대여 \n");
		printf("4. 책 반납 \n");
		
		printf("0. 프로그램 종료 \n");
		printf("----------------------------- \n");
		
		scanf("%d", &userIndex);
		if (userIndex == 1) {
			addBook(books,isHere, bookCount);
			bookCount++; // 책 넣고 카운트 늘리는 부분
		}
		else if (userIndex == 2) {
			searchBook(books, isHere);
		}
		else if (userIndex == 3) {
			borrowBook(books, isHere);
		}
		else if (userIndex == 4) {
			returnBook(books, isHere);
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
	
	printf("무엇으로 검색하시겠습니까? \n");
	printf("1. 책 제목 \n");
	printf("2. 저자 \n");
	printf("3. 출판사 \n");
	scanf("%d", &i);
	j = i - 1; // book배열에 j를 바로 넣으려고 이렇게 1 빼줌
	
	bookSearchTool(books, j, isHere);

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
int bookSearchTool(char books[][3][30], int j, int isHere[]) {
	int i;
	int bookIndex = -1; // 몇번째 책인지 보관하는 변수, 0으로 선언하면 일치하는 책이 없는건지 확인이 안돼서 -1로 선언함
	char input[30];
	
	if (j == 0) printf("책 제목을 입력해주세요 : ");
	else if (j == 1) printf("저자를 입력해주세요 : ");
	else if (j == 2) printf("출판사를 입력해주세요 :");
	scanf("%s", input);
	
	for (i = 0; i < 100; i++) {
		if (checkSame(input, books[i][j]) == 1) {
			bookIndex = i;
			printf("\n책 제목 : %s \n", books[bookIndex][0]);
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
	
	return bookIndex; // borrowBook, returnBook 함수에서 쓸 수 있게 책 번호 전달
}
int borrowBook(char books[][3][30],int isHere[]) {
	int i; // 책 번호 전달받아서 저장
	char j[1]; // y,n 저장하는 한글자 배열
	
	printf("대여하려는 ");
	i = bookSearchTool(books, 0, isHere);
	if (isHere[i] == 1) {
		printf("대출하시겠습니까? : [y/n] \n");
		scanf("%s", j);
		if (j[0] == 'y') {
			isHere[i] = 0;
			printf("대출되었습니다. \n");
		}
		else if (j[0] == 'n') {
			printf("취소되었습니다. \n");
			printf("초기 메뉴로 돌아갑니다. \n\n");
		}
		else {
			printf("입력 오류입니다. 초기 메뉴로 돌아갑니다. \n\n");
		}
	}
	if (isHere[i] == 0) {
		printf("초기 메뉴로 돌아갑니다.\n\n");
	}
	
	return 0;
}
int returnBook(char books[][3][30],int isHere[]) {
	int i;
	char j[1];
	
	printf("반납하려는 ");
	i = bookSearchTool(books, 0, isHere);
	if (isHere[i] == 0) {
		printf("반납하시겠습니까? : [y/n] \n");
		scanf("%s", j);
		if (j[0] == 'y') {
			isHere[i] = 1;
			printf("반납되었습니다. \n");
			printf("초기 메뉴로 돌아갑니다. \n\n");
		}
		else if (j[0] == 'n') {
			printf("취소되었습니다. \n");
			printf("초기 메뉴로 돌아갑니다. \n\n");
		}
		else {
			printf("입력 오류입니다. 초기 메뉴로 돌아갑니다. \n\n");
		}
	}
	else if (isHere[i] == 1) {
		printf("대출 가능한 책은 반납할 수 없습니다. \n");
		printf("초기 메뉴로 돌아갑니다.\n\n");
	}
	
	return 0;
}
