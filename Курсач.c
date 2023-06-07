#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100


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

void instructions() {
	printf("�������\n\n");
	printf("ϳ� ��� ��� � �����, ����� ������� ������ ����� �� �����, �� ��� ���������� ����� �������� ������.\n���������: ����� - �������, ��� - ������ � ��� ���. \n� ��� ���� � 5 ������� ��� �� ����:\n1. �������\n2. �������\n3. ̳��� \n4. ������\n5. ��� ������.\n�� ������ ������ ����-��� � ��� �� ������� ���. ����� ������� ������� � �������� ������ ��� ��������� ������ ��������\n\n\n\n");
	system("pause");
	main();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int i, a, topicChoice;

    char topicFiles[5][20] = {"animals.txt", "plants.txt", "cities.txt", "tech.txt", "all_words.txt"};
    char topicNames[5][20] = {" - ������� - ", " - ������� - ", " - ̳��� - ", " - ������ - ", " - �� ���� - "};
    
    while (1) {
		system("cls");
		Sleep(250);
		printf("---------------����---------------\n\n\n");
		Sleep(250);
		printf("1. ������ ���.\n");
		Sleep(250);
		printf("2. ����������.\n");
		Sleep(250);
		printf("3. �����.\n");
		Sleep(250);
		printf("\n\n----------------------------------");
		Sleep(250);
		printf("\n> ");
		scanf("%d", &a);
		system("cls");
		
		while (a==1) {
				printf("������ ����:\n");
    			for (i=0; i<5; i++) {
       				 printf("%d. %s\n", i+1, topicNames[i]);
    				}

    printf("--> ");
    scanf("%d", &topicChoice);
    topicChoice--;
    
    while (scanf("%d", &topicChoice) != 1 || topicChoice < 1 || topicChoice > 5) {
        printf("������������ ����. ������ ����� ���� ����� (1-5): ");
        while (getchar() != '\n');
    }
    
    const char* currentTopic = topicFiles[topicChoice - 1];
    printf("����: %s\n\n", topicNames[topicChoice - 1]);
    printf("���� �����, ������� ����� � �������� ������ \n��� ���������� ���������������� ���� ����� \n\n\n");

    char word[MAX_WORD_LENGTH];
    printf("������ ����� �����\n > ");
    scanf("%s", word);
    
    if (strcmp(word, "�����")==0) {
            	printf("\n - �� �������. ��� ���������. - \n\n");
            	system("pause");
            	main ();
			}
	if (strcmp(word, "������")==0) {
            	printf("\n - �� �������. ��� ���������. - \n\n");
            	system("pause");
            	main ();
			}

    while (1) {
        if (!WordValid(currentTopic, word)) {		//��� ����� "���" ����� ���������� �� ���� �����
            printf("�� ����� �����������, ��� ���� ���� � ��� �����.\n������ ���� �� ����? (���/ͳ)\n > ");

            char answer[4];
            scanf("%s", answer);

            if (strcmp(answer, "���")==0||strcmp(answer, "���")==0) {
                updateDB(currentTopic, word);
            }
        }

        char lastChar = word[strlen(word)-1];
        if (lastChar=='�'||lastChar=='�') {
        	lastChar=word[strlen(word)-2];
		}
        
        printf("������ �����, �� ���������� � ����� '%c'\n > ", lastChar);

        char nextword[MAX_WORD_LENGTH];
        scanf("%s", nextword);
        if (strcmp(nextword, "������")==0) {
            	printf("\n - �� �������. ��� ���������. - \n\n");
            	system("pause");
            	main ();
			}
		if (strcmp(nextword, "�����")==0) {
            	printf("\n - �� �������. ��� ���������. - \n\n");
            	system("pause");
            	main ();
			}

        while (nextword[0]!=lastChar) {
            printf("�� ������ ������� �����, �� ���������� � ����� '%c'.\n", lastChar);
            printf("��������� �� ���\n > ");
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
			printf("�����, �� ������ :)");
			return 0;
		}
	return 0;
}
}
