/*
표준 전지 전위 계산 프로그램 v0.1
By.김승훈
작동 방식 및 설계 과정은 https://blog.naver.com/soo0sleepy/223197093838 참고
 */

#include <stdio.h>
#include <string.h>

int no_data;

// 원소의 기호와 표준 환원 전위 값을 저장하고 있는 구조체 정의.
typedef struct {
    char symbol[3]; //symbol은 원소기호를 저장하는 문자열
    double ep; //ep는 electrode potential의 약자로 전지전위를 뜻하는 변수.
} Element;

// 원소와 그에 대한 표준 환원 전위 값을 저장하는 데이터를 사전에 입력하는 부분. (데이터 출처: 줌달의 일반 화학)
Element data[] = {
        {"Ag", 1.99}, //2가 이온을 기준으로 작성.
        {"Co", 1.82},
        {"Ce", 1.51},
        {"Au", 1.50},
        {"Br", 1.09},
        {"Hg", 0.80}, //단원자 이온을 기준으로 작성.
        {"I", 0.54},
        {"Cu", 0.34},//2가 이온을 기준으로 작성.
        {"H", 0.00},
        {"Pb", -0.13},
        {"Sn", -0.14},
        {"Ni", -0.23},
        {"Cd", -0.40},
        {"Fe", -0.44}, //2가 이온을 기준으로 작성.
        {"Cr", -0.73},
        {"Zn", -0.76},
        {"Mn", -1.18},
        {"Al", -1.66},
        {"Mg", -2.37},
        {"La", -2.37},
        {"Na", -2.71},
        {"Ca", -2.76},
        {"Ba", -2.90},
        {"K", -2.92},
        {"Li", -3.05},

};

// 주어진 원소 기호에 해당하는 표준 환원 전위 값을 데이터에서 찾는 함수 정의.
double findEP(const char* element_find) {
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        if (strcmp(data[i].symbol, element_find) == 0) {
            return data[i].ep;
        }
    }
    no_data=1;
    return 0.0; // 찾고자하는 원소가 데이터에 없을 경우 no_data=1.
}

int main() {
    char element_A[3], element_B[3];
    double ep_A, ep_B, ep_BATT;

    // 사용자로부터 원소 기호를 입력받습니다.
    printf("첫번째 전극의 원소 기호를 입력해주세요: ");
    scanf("%s", element_A);

    printf("두번째 전극의 원소 기호를 입력해주세요: ");
    scanf("%s", element_B);

    // 원소의 표준 환원 전위 값을 찾습니다.
    if (no_data==1){
        printf("입력한 원소가 데이터에 존재하지 않습니다! (대소문자, 오탈자 확인)\n");
        return 0;
    } else {
        ep_A = findEP(element_A);
        ep_B = findEP(element_B);
    }

    // 표준 전지 전위를 계산합니다.
    if (ep_A > ep_B) {
        ep_BATT = ep_A - ep_B;
        printf("산화 극: %s\n", element_B);
        printf("환원 극: %s\n", element_A);
    } else {
        ep_BATT = ep_B - ep_A;
        printf("산화 극: %s\n", element_A);
        printf("환원 극: %s\n", element_B);
    }

    // 결과를 출력합니다.
    printf("표준 전지 전위: %.2lf\n", ep_BATT);
    if (ep_BATT > 0.0) {
        printf("반응은 자발적으로 이뤄집니다.\n");
    } else {
        printf("반응은 비자발적으로 이뤄집니다.\n");
    }

    return 0;
}
