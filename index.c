#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

void lowCase(char x[]) {
    int i = 0;
    while (x[i]) {
        x[i] = tolower(x[i]);
        i++;
    }
}

int main() {
    char op[40];
    int quantidade = 99;
    bool pd = true;

    struct cadastro {
        int codigo;
        char nome[51];
        char cpf[15];
        char vacina[30];
        char data[11];
        int lote;
    } vacinado[quantidade];

    int i = 0; // Índice para controlar o número de cadastros

    while (pd) {
        system("clear");
        printf("\nVocê deseja: cadastrar, listar, consultar ou sair?.");
        printf("\n-> Cadastrar vacina.");
        printf("\n-> Listar Aplicações");
        printf("\n-> Consultar por CPF");
        printf("\n-> Sair.");

        printf("\nDigite a operação desejada: ");
        scanf("%39s", op);
        fflush(stdin);
        lowCase(op);

        if (strcmp(op, "sair") == 0) {
            system("clear");
            break;
        }

        if (strcmp(op, "cadastrar") == 0) {
            system("clear");
            printf("\nCADASTRO DE VACINADO");

            do {
                printf("\nCadastrado nº: %d\n", i + 1);
                vacinado[i].codigo = i + 1;

                printf("Nome do vacinado: ");
                scanf(" %50[^\n]", vacinado[i].nome);
                fflush(stdin);

                printf("CPF: ");
                scanf(" %14[^\n]", vacinado[i].cpf);
                fflush(stdin);

                printf("Vacina: ");
                scanf(" %29[^\n]", vacinado[i].vacina);
                fflush(stdin);

                printf("Data: ");
                scanf(" %10[^\n]", vacinado[i].data);
                fflush(stdin);

                printf("Número Lote: ");
                scanf("%d", &vacinado[i].lote);
                fflush(stdin);

                printf("\nDeseja cadastrar mais um [Y/n]? ");
                scanf(" %1[^\n]", op); // Leitura de apenas um caractere
                fflush(stdin);

                i++;

            } while (tolower(op[0]) == 'y');

            printf("\nVoltando à tela inicial.\n");
            sleep(3);
        }

        if (strcmp(op, "listar") == 0) {
            system("clear");
            printf("\nLISTAR VACINADOS");

            int h = 0;
            while (h < i) { // Itera apenas sobre os cadastros existentes
                printf("\nCódigo: %d\n", vacinado[h].codigo);
                printf("Nome: %s\n", vacinado[h].nome);
                printf("CPF: %s\n", vacinado[h].cpf);
                printf("Vacina: %s\n", vacinado[h].vacina);
                printf("Data: %s\n", vacinado[h].data);
                printf("Lote: %d\n", vacinado[h].lote);
                printf("................................\n");
                h++;
            }

            printf("\nPressione ENTER para sair.\n");
            getchar(); // Aguarda o pressionamento da tecla Enter
        }

        if (strcmp(op, "consultar") == 0) {
            system("clear");
            printf("CONSULTAR VACINADO");

            printf("\nQual o CPF do vacinado? ");
            scanf(" %14[^\n]", op);
            fflush(stdin);

            bool encontrado = false;
            for (int h = 0; h < i; h++) { // Itera apenas sobre os cadastros existentes
                if (strcmp(op, vacinado[h].cpf) == 0) {
                    printf("\nCódigo: %d\n", vacinado[h].codigo);
                    printf("Nome: %s\n", vacinado[h].nome);
                    printf("CPF: %s\n", vacinado[h].cpf);
                    printf("Vacina: %s\n", vacinado[h].vacina);
                    printf("Data: %s\n", vacinado[h].data);
                    printf("Lote: %d\n", vacinado[h].lote);
                    printf("................................\n");
                    encontrado = true;
                }
            }

            if (!encontrado) {
                printf("\nCPF não encontrado.\n");
            }

            printf("\nPressione ENTER para sair.\n");
            getchar(); // Aguarda o pressionamento da tecla Enter
        }
    }

    return 0;
}