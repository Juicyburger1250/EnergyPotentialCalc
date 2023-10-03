/*
ǥ�� ���� ���� ��� ���α׷� v0.1
By.�����
�۵� ��� �� ���� ������ https://blog.naver.com/soo0sleepy/223197093838 ����
 */

#include <stdio.h>
#include <string.h>

int no_data;

// ������ ��ȣ�� ǥ�� ȯ�� ���� ���� �����ϰ� �ִ� ����ü ����.
typedef struct {
    char symbol[3]; //symbol�� ���ұ�ȣ�� �����ϴ� ���ڿ�
    double ep; //ep�� electrode potential�� ���ڷ� ���������� ���ϴ� ����.
} Element;

// ���ҿ� �׿� ���� ǥ�� ȯ�� ���� ���� �����ϴ� �����͸� ������ �Է��ϴ� �κ�. (������ ��ó: �ܴ��� �Ϲ� ȭ��)
Element data[] = {
        {"Ag", 1.99}, //2�� �̿��� �������� �ۼ�.
        {"Co", 1.82},
        {"Ce", 1.51},
        {"Au", 1.50},
        {"Br", 1.09},
        {"Hg", 0.80}, //�ܿ��� �̿��� �������� �ۼ�.
        {"I", 0.54},
        {"Cu", 0.34},//2�� �̿��� �������� �ۼ�.
        {"H", 0.00},
        {"Pb", -0.13},
        {"Sn", -0.14},
        {"Ni", -0.23},
        {"Cd", -0.40},
        {"Fe", -0.44}, //2�� �̿��� �������� �ۼ�.
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

// �־��� ���� ��ȣ�� �ش��ϴ� ǥ�� ȯ�� ���� ���� �����Ϳ��� ã�� �Լ� ����.
double findEP(const char* element_find) {
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        if (strcmp(data[i].symbol, element_find) == 0) {
            return data[i].ep;
        }
    }
    no_data=1;
    return 0.0; // ã�����ϴ� ���Ұ� �����Ϳ� ���� ��� no_data=1.
}

int main() {
    char element_A[3], element_B[3];
    double ep_A, ep_B, ep_BATT;

    // ����ڷκ��� ���� ��ȣ�� �Է¹޽��ϴ�.
    printf("ù��° ������ ���� ��ȣ�� �Է����ּ���: ");
    scanf("%s", element_A);

    printf("�ι�° ������ ���� ��ȣ�� �Է����ּ���: ");
    scanf("%s", element_B);

    // ������ ǥ�� ȯ�� ���� ���� ã���ϴ�.
    if (no_data==1){
        printf("�Է��� ���Ұ� �����Ϳ� �������� �ʽ��ϴ�! (��ҹ���, ��Ż�� Ȯ��)\n");
        return 0;
    } else {
        ep_A = findEP(element_A);
        ep_B = findEP(element_B);
    }

    // ǥ�� ���� ������ ����մϴ�.
    if (ep_A > ep_B) {
        ep_BATT = ep_A - ep_B;
        printf("��ȭ ��: %s\n", element_B);
        printf("ȯ�� ��: %s\n", element_A);
    } else {
        ep_BATT = ep_B - ep_A;
        printf("��ȭ ��: %s\n", element_A);
        printf("ȯ�� ��: %s\n", element_B);
    }

    // ����� ����մϴ�.
    printf("ǥ�� ���� ����: %.2lf\n", ep_BATT);
    if (ep_BATT > 0.0) {
        printf("������ �ڹ������� �̷����ϴ�.\n");
    } else {
        printf("������ ���ڹ������� �̷����ϴ�.\n");
    }

    return 0;
}
