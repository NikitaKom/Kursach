#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include <iostream>
using namespace std;

#define EMPTY (-1)
#define MAX_LEN 1000
#define MAX_WORD_LENGTH 100

//��������� �������� ���������� ����� 2-�� �����, 24 ����� ������������ 121 "�������� ����������� ������������" ����������� ͳ����.

// ����� ������� ������ ����� �������� ������ ���������
void clear() {

	printf("\n");
	system("cls");
}
// ³������� ����� � ����� ���
void updateDB(const char* filename, const char* word) {
    FILE* file=fopen(filename, "a");
    if (file==NULL) {
        printf("��� ������� %s ������� �������\n", filename);
        return;
    }

    fprintf(file, "%s\n", word);
    fclose(file);
}

int WordValid(const char* filename, const char* word) {
    FILE* file=fopen(filename, "r");
    if (file==NULL) {
        printf("��� ������� %s ������� �������\n", filename);
        return 0;
    }
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")]='\0';
        if (strcmp(buffer, word)==0) {
            fclose(file);
            return 1;
        }
    }
    
    fclose(file);
    return 0;
}
// ������ ������ ����
void option1() {
	
	int i;
	char m1[100];
	
	// ������� � ������ � ��������� ����������
 	char topicFiles[5][20] = {"animals.txt", "plants.txt", "cities.txt", "tech.txt", "all_words.txt"};
    char topicNames[5][20] = {" - ������� - ", " - ������� - ", " - ̳��� - ", " - ������ - ", " - ��� ������ - "};

    printf("������ ����:\n");
    for (i=0; i<5; i++) {
        printf("%d. %s\n", i+1, topicNames[i]);
    }

    int topicChoice;
    printf("--> ");
    scanf("%d", &topicChoice);
    topicChoice--;

    const char* currentTopic = topicFiles[topicChoice];
    printf("����: %s\n\n", topicNames[topicChoice]);

    char word[MAX_WORD_LENGTH];
    printf("�����: ");
    scanf("%s", word);

    while (1) {
        if (!WordValid(currentTopic, word)) {	
            printf("�� ����� �����������, ��� ���� ���� � ��� �����. �� ������� ���� �� ����? (���/ͳ) \n > ");

            char answer[4];
            scanf("%s", answer);

            if (strcmp(answer, "???")==0||strcmp(answer, "???")==0) {
                updateDB(currentTopic, word);
            }
        }

        char lastChar = word[strlen(word)-1];
        printf("������ �����, �� ���������� �� ����� '%c': ", lastChar);

        char nextword[MAX_WORD_LENGTH];
        scanf("%s", nextword);

        while (nextword[0]!=lastChar) {
            printf("�� ������ ������� ����� �� ����� '%c'.\n", lastChar);
            printf("��������� �� ���. \n > ");
            scanf("%s", nextword);
        }

        strcpy(word, nextword);
        
    }
}
   
// ������ ������ ����
void option2() {
	printf("�������\n\n");
	printf("ϳ� ��� ��� � �����, ����� ������� ������ ����� �� �����, �� ��� ���������� ����� �������� ������.\n���������: ����� - �������, ��� - ������ � ��� ���. \n� ��� ���� � 5 ������� ��� �� ����:\n1. �������\n2. �������\n3. ̳��� \n4. ������\n5. ��� ������.\n�� ������ ������ ����-��� � ��� �� ������� ���.\n\n\n\n");
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
	
// ������������ ��������� �������곿
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");

// ���� ���� �� ����� ���������� ��� ������� �� ������� �������� 
	int menu;
	char m2[100];
	
  
   	 	do{
     	   printf("--- ��� � ����� ---\n\n 1. - ������ ��� -\n 2. - ������� -\n 3. - ����� -\n\n> ");
   		 scanf("%d", &menu);

   		 switch (menu) {
     		 case 1:
        		option1();
       			 break;  
      		 case 2:
       			 option2();
        		 break;
      		 case 3:
          		 printf("�����������\n");
        		 break;
      		default:
			 	printf("����-�����, ������ ���������� ������\n\n >");
			 	scanf("%d", &menu);
			
			}
    		} while (menu == 2);
   			  system("pause");
}
