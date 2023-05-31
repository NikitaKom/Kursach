#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include <iostream>

#define EMPTY (-1)
#define MAX_LEN 1000

// SetConsoleCP(1251);
// SetConsoleOutputCP(1251);
// setlocale(LC_ALL, "Ukrainian");

// ����� ������� ������ ����� �������� ������ ���������, �� ��������� ��������� ����������
void clear() {
	
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
setlocale(LC_ALL, "Ukrainian");

	printf("\n");
	system("cls");
}

// ��������� ��������� ���� �� ���������� (�������� �� ����� � ������ ��� ����� ������� ������������) ��� ����������� ���������� ������
void pause() {
	printf("\n");
	system("pause");
}

// ������ ������ ����
void option1() {
	int start_menu;
	
	printf("Start game\n\n");
	printf("Choose topic:\n\n");
	switch (start_menu){
		case 1:
		break;	
	default:
				printf("Choose correct option");
	}
}
   
// ������ ������ ����
void option2() {
	printf("Rules\n\n");
	printf("ϳ� ��� ��� � �����, ����� ������� ������ ����� �� �����, �� ��� ���������� ����� �������� ������.\n���������: ����� - �������, ��� - ������ � ��� ���. \n� ��� ���� � 5 ������� ��� �� ����:\n1. ̳���\n2. �������\n3. ������\n4. �������\5. ���");
    return;
}

// ����� ������ ����
void option3() {

    return;
}

void printCenterAligned(const char* text[], int numLines, int lineWidth) {
    int maxTextLength = 0;

    // ����������� ����������� ������� ����� ������
    for (int i = 0; i < numLines; i++) {
        int textLength = strlen(text[i]);
        if (textLength > maxTextLength) {
            maxTextLength = textLength;
        }
    }

    int padding = (lineWidth - maxTextLength) / 2;

    // ��������� ��������� ����� ������
    for (int i = 0; i < numLines; i++) {
        int textLength = strlen(text[i]);
        int leftPadding = padding + (maxTextLength - textLength) / 2;

        for (int j = 0; j < leftPadding; j++) {
            printf(" ");
        }

        printf("%s\n", text[i]);
    }
}

int main() {
	srand(time(NULL));

// ���� ���� �� ����� ���������� ��� ������� �� ������� �������� 
	int menu;
	
        printf("--- GAME OF WORDS ---\n\n 1. - Start Game -\n 2. - Rules -\n 3. - Quit -\n\n> ");
		scanf("%d", &menu);

		switch (menu) {
			case 1:
				option1();
				break;	
			case 2:
				option2();
				break;
			case 3:
			    printf("Goodbye");
				break;
			default:
				printf("Choose correct option");
		}
	}
