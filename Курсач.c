#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100


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

void instructions() {
	printf("Правила\n\n");
	printf("Під час гри в слова, кожен гравець називає слово на букву, на яку закінчилося слово минулого гравця.\nНаприклад: Кавун - Нектарін, Київ - Волинь і так далі. \nВ цій версії є 5 тематик гри на вибір:\n1. Тварини\n2. Рослини\n3. Міста \n4. Техніка\n5. Все одразу.\nВи можете обрати будь-яку з них на початку гри. Слова потрібно вводити в нижньому регістрі для корректної роботи програми\n\n\n\n");
	system("pause");
	main();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int i, a, topicChoice;

    char topicFiles[5][20] = {"animals.txt", "plants.txt", "cities.txt", "tech.txt", "all_words.txt"};
    char topicNames[5][20] = {" - Тварини - ", " - Рослини - ", " - Міста - ", " - Техніка - ", " - Всі теми - "};
    
    while (1) {
		system("cls");
		Sleep(250);
		printf("---------------МЕНЮ---------------\n\n\n");
		Sleep(250);
		printf("1. Почати гру.\n");
		Sleep(250);
		printf("2. Інструкція.\n");
		Sleep(250);
		printf("3. Вихід.\n");
		Sleep(250);
		printf("\n\n----------------------------------");
		Sleep(250);
		printf("\n> ");
		scanf("%d", &a);
		system("cls");
		
		while (a==1) {
				printf("Оберіть тему:\n");
    			for (i=0; i<5; i++) {
       				 printf("%d. %s\n", i+1, topicNames[i]);
    				}

    printf("--> ");
    scanf("%d", &topicChoice);
    topicChoice--;
    
    while (scanf("%d", &topicChoice) != 1 || topicChoice < 1 || topicChoice > 5) {
        printf("Неправильний вибір. Введіть номер теми знову (1-5): ");
        while (getchar() != '\n');
    }
    
    const char* currentTopic = topicFiles[topicChoice - 1];
    printf("Тема: %s\n\n", topicNames[topicChoice - 1]);
    printf("Будь ласка, вводьте слова у нижньому регістрі \nдля запобігання перенавантаження бази даних \n\n\n");

    char word[MAX_WORD_LENGTH];
    printf("Введіть перше слово\n > ");
    scanf("%s", word);
    
    if (strcmp(word, "вихід")==0) {
            	printf("\n - Ви здалися. Гра завершена. - \n\n");
            	system("pause");
            	main ();
			}
	if (strcmp(word, "здаюся")==0) {
            	printf("\n - Ви здалися. Гра завершена. - \n\n");
            	system("pause");
            	main ();
			}

    while (1) {
        if (!WordValid(currentTopic, word)) {		//При виборі "Так" слово заноситься до бази даних
            printf("Це слово неправильне, або його немає в базі даних.\nДодати його до бази? (Так/Ні)\n > ");

            char answer[4];
            scanf("%s", answer);

            if (strcmp(answer, "Так")==0||strcmp(answer, "так")==0) {
                updateDB(currentTopic, word);
            }
        }

        char lastChar = word[strlen(word)-1];
        if (lastChar=='ь'||lastChar=='и') {
        	lastChar=word[strlen(word)-2];
		}
        
        printf("Введіть слово, що починається з літери '%c'\n > ", lastChar);

        char nextword[MAX_WORD_LENGTH];
        scanf("%s", nextword);
        if (strcmp(nextword, "здаюся")==0) {
            	printf("\n - Ви здалися. Гра завершена. - \n\n");
            	system("pause");
            	main ();
			}
		if (strcmp(nextword, "вихід")==0) {
            	printf("\n - Ви здалися. Гра завершена. - \n\n");
            	system("pause");
            	main ();
			}

        while (nextword[0]!=lastChar) {
            printf("Ви повинні назвати слово, що починається з літери '%c'.\n", lastChar);
            printf("Спробуйте ще раз\n > ");
            scanf("%s", nextword);
        }

        strcpy(word, nextword);
        
    }
}

	while (a==2) {
		instructions();
		break;
	}
	while (a==3) {	
			printf("Дякую, що зіграли :)");
			return 0;
		}
	return 0;
}
}
