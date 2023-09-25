#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// verifica se é um número inteiro
bool isInteger(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    // Define a equipe e zera os pontos 
    char equipes[4][20];
    int pontos[4] = {0, 0, 0, 0};

    // Pede pro usuário alterar o nome da equipe se quiser
    for (int i = 0; i < 4; i++) {
        printf("Informe o nome da equipe %c: ", 'A' + i);
        scanf("%s", equipes[i]);
    }

    // Loop dos jogos
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            printf("Jogo: %s vs %s\n", equipes[i], equipes[j]);
            
            int gols_time1, gols_time2;
            char input[10];

            do {
                printf("Informe os gols de %s (Usando um numero inteiro): ", equipes[i]);
                scanf("%s", input);

                if (!isInteger(input)) {
                    printf("Por favor, insira um numero inteiro!\n");
                } else {
                    gols_time1 = atoi(input);
                    break;
                }
            } while (true);

            do {
                printf("Informe os gols de %s (Usando um numero inteiro): ", equipes[j]);
                scanf("%s", input);

                if (!isInteger(input)) {
                    printf("Por favor, insira um numero inteiro!\n");
                } else {
                    gols_time2 = atoi(input);
                    break;
                }
            } while (true);

            if (gols_time1 > gols_time2) {
                pontos[i] += 3;
            } else if (gols_time1 < gols_time2) {
                pontos[j] += 3;
            } else {
                pontos[i]++;
                pontos[j]++;
            }
        }
    }

    // Classifica as equipes
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (pontos[i] < pontos[j]) {
                // Troca as posições
                int temp_pontos = pontos[i];
                pontos[i] = pontos[j];
                pontos[j] = temp_pontos;

                char temp_equipe[20];
                strcpy(temp_equipe, equipes[i]);
                strcpy(equipes[i], equipes[j]);
                strcpy(equipes[j], temp_equipe);
            }
        }
    }

    // Resultado final
    printf("O Resultado Final do campeonato foi:\n");
    for (int i = 0; i < 4; i++) {
        printf("Equipe: %s - Pontos: %d\n", equipes[i], pontos[i]);
    }

	system("pause");
	
    return 0;
       
}

