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

//Программа написана здобувачем освіти 2-го курсу, 24 групи спеціальності 121 "Розробка програмного забезпечення" Комельковом Нікітою.

// Повна очистка консолі перед початком роботи программи
void clear() {

	printf("\n");
	system("cls");
}
// Відкриття файлу з темою гри
void updateDB(const char* filename, const char* word) {
    FILE* file=fopen(filename, "a");
    if (file==NULL) {
        printf("При відкритті %s виникла помилка\n", filename);
        return;
    }

    fprintf(file, "%s\n", word);
    fclose(file);
}

int WordValid(const char* filename, const char* word) {
    FILE* file=fopen(filename, "r");
    if (file==NULL) {
        printf("При відкритті %s виникла помилка\n", filename);
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
// Перший варіант меню
void option1() {
	
	int i;
	char m1[100];
	
	// Массиви з темами в текстових документах
 	char topicFiles[5][20] = {"animals.txt", "plants.txt", "cities.txt", "tech.txt", "all_words.txt"};
    char topicNames[5][20] = {" - Тварини - ", " - Рослини - ", " - Міста - ", " - Техніка - ", " - Все одразу - "};

    printf("Оберіть тему:\n");
    for (i=0; i<5; i++) {
        printf("%d. %s\n", i+1, topicNames[i]);
    }

    int topicChoice;
    printf("--> ");
    scanf("%d", &topicChoice);
    topicChoice--;

    const char* currentTopic = topicFiles[topicChoice];
    printf("Тема: %s\n\n", topicNames[topicChoice]);

    char word[MAX_WORD_LENGTH];
    printf("Слово: ");
    scanf("%s", word);

    while (1) {
        if (!WordValid(currentTopic, word)) {	
            printf("Це слово неправильне, або його немає в базі даних. Чи занести його до бази? (Так/Ні) \n > ");

            char answer[4];
            scanf("%s", answer);

            if (strcmp(answer, "???")==0||strcmp(answer, "???")==0) {
                updateDB(currentTopic, word);
            }
        }

        char lastChar = word[strlen(word)-1];
        printf("Введіть слово, що починається на букву '%c': ", lastChar);

        char nextword[MAX_WORD_LENGTH];
        scanf("%s", nextword);

        while (nextword[0]!=lastChar) {
            printf("Ви повинні назвати слово на букву '%c'.\n", lastChar);
            printf("Спробуйте ще раз. \n > ");
            scanf("%s", nextword);
        }

        strcpy(word, nextword);
        
    }
}
   
// Другий варіант меню
void option2() {
	printf("Правила\n\n");
	printf("Під час гри в слова, кожен гравець називає слово на букву, на яку закінчилося слово минулого гравця.\nНаприклад: Кавун - Нектарін, Київ - Волинь і так далі. \nВ цій версії є 5 тематик гри на вибір:\n1. Тварини\n2. Рослини\n3. Міста \n4. Техніка\n5. Все одразу.\nВи можете обрати будь-яку з них на початку гри.\n\n\n\n");
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
	
// Встановлення Української локалізакії
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");

// Саме меню до якого попередньо вже зроблені всі варіанти відповідей 
	int menu;
	char m2[100];
	
  
   	 	do{
     	   printf("--- Гра в слова ---\n\n 1. - Почати гру -\n 2. - Правила -\n 3. - Вихід -\n\n> ");
   		 scanf("%d", &menu);

   		 switch (menu) {
     		 case 1:
        		option1();
       			 break;  
      		 case 2:
       			 option2();
        		 break;
      		 case 3:
          		 printf("Допобачення\n");
        		 break;
      		default:
			 	printf("Будь-ласка, оберіть правильний варіант\n\n >");
			 	scanf("%d", &menu);
			
			}
    		} while (menu == 2);
   			  system("pause");
}
