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

// Повна очистка консолі перед початком роботи программи, та установка Української локалізації
void clear() {
	
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
setlocale(LC_ALL, "Ukrainian");

	printf("\n");
	system("cls");
}

// Остановка программи після ії завершення (заборона на вихід з консолі без вводу команди користувачем) щоб переглянути пророблену роботу
void pause() {
	printf("\n");
	system("pause");
}

// Перший варіант меню
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
   
// Другий варіант меню
void option2() {
	printf("Rules\n\n");
	printf("Під час гри в слова, кожен гравець називає слово на букву, на яку закінчилося слово минулого гравця.\nНаприклад: Кавун - Нектарін, Київ - Волинь і так далі. \nВ цій версії є 5 тематик гри на вибір:\n1. Міста\n2. Рослини\n3. Техніка\n4. Тварини\5. Все");
    return;
}

// Третій варіант меню
void option3() {

    return;
}

void printCenterAligned(const char* text[], int numLines, int lineWidth) {
    int maxTextLength = 0;

    // Знаходження максимальної довжини рядка тексту
    for (int i = 0; i < numLines; i++) {
        int textLength = strlen(text[i]);
        if (textLength > maxTextLength) {
            maxTextLength = textLength;
        }
    }

    int padding = (lineWidth - maxTextLength) / 2;

    // Виведення вирівняних рядків тексту
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

// Саме меню до якого попередньо вже зроблені всі варіанти відповідей 
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
