#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct ReservationInfo {
    char* patient[10];
    char* purpose[100];
    char* telephone_number[12];
}ReservationInfo;


typedef struct Hospital {
	char Name[100];
	char Location[100];
    ReservationInfo RVI[24];


}Hospital;

void get_hos_info(Hospital* HS) {
    printf("Insert Hospital Name:");
    getchar();
    scanf("%[^\n]", HS->Name);  // 첫 번째 입력을 위한 올바른 사용
    getchar();  // scanf 후 남아있는 줄바꿈 문자 제거

    printf("Insert Hospital Location:");
    scanf("%[^\n]", HS->Location);  // 두 번째 입력을 위한 올바른 사용
    getchar();  // 마찬가지로 남아있는 줄바꿈 문자 제거

    for (int i = 0;i < 24;i++) {
        strcpy(HS->RVI[i].patient, ""); // 빈 문자열로 초기화
        strcpy(HS->RVI[i].purpose, ""); // 빈 문자열로 초기화
        strcpy(HS->RVI[i].telephone_number, ""); // 빈 문자열로 초기화
    }
    printf("\n");
}
