#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100


void updateDB(const char* filename, const char* word) {
    FILE* file=fopen(filename, "a");
    if (file==NULL) {
        printf("Ïðè â³äêðèòò³ %s âèíèêëà ïîìèëêà\n", filename);
        return;
    }

    fprintf(file, "%s\n", word);
    fclose(file);
}

int WordValid(const char* filename, const char* word) {
    FILE* file=fopen(filename, "r");
    if (file==NULL) {
        printf("Ïðè â³äêðèòò³ %s âèíèêëà ïîìèëêà\n", filename);
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
	printf("Ïðàâèëà\n\n");
	printf("Ï³ä ÷àñ ãðè â ñëîâà, êîæåí ãðàâåöü íàçèâàº ñëîâî íà áóêâó, íà ÿêó çàê³í÷èëîñÿ ñëîâî ìèíóëîãî ãðàâöÿ.\nÍàïðèêëàä: Êàâóí - Íåêòàð³í, Êè¿â - Âîëèíü ³ òàê äàë³. \nÂ ö³é âåðñ³¿ º 5 òåìàòèê ãðè íà âèá³ð:\n1. Òâàðèíè\n2. Ðîñëèíè\n3. Ì³ñòà \n4. Òåõí³êà\n5. Âñå îäðàçó.\nÂè ìîæåòå îáðàòè áóäü-ÿêó ç íèõ íà ïî÷àòêó ãðè. Ñëîâà ïîòð³áíî ââîäèòè â íèæíüîìó ðåã³ñòð³ äëÿ êîððåêòíî¿ ðîáîòè ïðîãðàìè\n\n\n\n");
	system("pause");
	main();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int i, a, topicChoice;

    char topicFiles[5][20] = {"animals.txt", "plants.txt", "cities.txt", "tech.txt", "all_words.txt"};
    char topicNames[5][20] = {" - Òâàðèíè - ", " - Ðîñëèíè - ", " - Ì³ñòà - ", " - Òåõí³êà - ", " - Âñ³ òåìè - "};
    
    while (1) {
		system("cls");
		Sleep(250);
		printf("---------------ÌÅÍÞ---------------\n\n\n");
		Sleep(250);
		printf("1. Ïî÷àòè ãðó.\n");
		Sleep(250);
		printf("2. ²íñòðóêö³ÿ.\n");
		Sleep(250);
		printf("3. Âèõ³ä.\n");
		Sleep(250);
		printf("\n\n----------------------------------");
		Sleep(250);
		printf("\n> ");
		scanf("%d", &a);
		system("cls");
		
		while (a==1) {
				printf("Îáåð³òü òåìó:\n");
    			for (i=0; i<5; i++) {
       				 printf("%d. %s\n", i+1, topicNames[i]);
    				}

    printf("--> ");
    scanf("%d", &topicChoice);
    topicChoice--;
    
    while (scanf("%d", &topicChoice) != 1 || topicChoice < 1 || topicChoice > 5) {
        printf("Íåïðàâèëüíèé âèá³ð. Ââåä³òü íîìåð òåìè çíîâó (1-5): ");
        while (getchar() != '\n');
    }
    
    const char* currentTopic = topicFiles[topicChoice - 1];
    printf("Òåìà: %s\n\n", topicNames[topicChoice - 1]);
    printf("Áóäü ëàñêà, ââîäüòå ñëîâà ó íèæíüîìó ðåã³ñòð³ \näëÿ çàïîá³ãàííÿ ïåðåíàâàíòàæåííÿ áàçè äàíèõ \n\n\n");

    char word[MAX_WORD_LENGTH];
    printf("Ââåä³òü ïåðøå ñëîâî\n > ");
    scanf("%s", word);
    
    if (strcmp(word, "âèõ³ä")==0) {
            	printf("\n - Âè çäàëèñÿ. Ãðà çàâåðøåíà. - \n\n");
            	system("pause");
            	main ();
			}
	if (strcmp(word, "çäàþñÿ")==0) {
            	printf("\n - Âè çäàëèñÿ. Ãðà çàâåðøåíà. - \n\n");
            	system("pause");
            	main ();
			}

    while (1) {
        if (!WordValid(currentTopic, word)) {		//Ïðè âèáîð³ "Òàê" ñëîâî çàíîñèòüñÿ äî áàçè äàíèõ
            printf("Öå ñëîâî íåïðàâèëüíå, àáî éîãî íåìàº â áàç³ äàíèõ.\nÄîäàòè éîãî äî áàçè? (Òàê/Í³)\n > ");

            char answer[4];
            scanf("%s", answer);

            if (strcmp(answer, "Òàê")==0||strcmp(answer, "òàê")==0) {
                updateDB(currentTopic, word);
            }
        }

        char lastChar = word[strlen(word)-1];
        if (lastChar=='ü'||lastChar=='è') {
        	lastChar=word[strlen(word)-2];
		}
        
        printf("Ââåä³òü ñëîâî, ùî ïî÷èíàºòüñÿ ç ë³òåðè '%c'\n > ", lastChar);

        char nextword[MAX_WORD_LENGTH];
        scanf("%s", nextword);
        if (strcmp(nextword, "çäàþñÿ")==0) {
            	printf("\n - Âè çäàëèñÿ. Ãðà çàâåðøåíà. - \n\n");
            	system("pause");
            	main ();
			}
		if (strcmp(nextword, "âèõ³ä")==0) {
            	printf("\n - Âè çäàëèñÿ. Ãðà çàâåðøåíà. - \n\n");
            	system("pause");
            	main ();
			}

        while (nextword[0]!=lastChar) {
            printf("Âè ïîâèíí³ íàçâàòè ñëîâî, ùî ïî÷èíàºòüñÿ ç ë³òåðè '%c'.\n", lastChar);
            printf("Ñïðîáóéòå ùå ðàç\n > ");
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
			printf("Äÿêóþ, ùî ç³ãðàëè :)");
			break;
		}
	return 0;
	}
}
