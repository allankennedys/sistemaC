#include <stdio.h>
#include <string.h>

#define MAX_DISCIPLINAS 10

// Estrutura para armazenar os dados do aluno
typedef struct {
    char nome[50];
    int idade;
    char serie[20];
    char disciplinas[MAX_DISCIPLINAS][30];
    float notas_iniciais[MAX_DISCIPLINAS];
    float notas_finais[MAX_DISCIPLINAS];
    int num_disciplinas;
    int periodo_estudo;
} Aluno;

// Fun��o para cadastrar o perfil do aluno
void cadastrarAluno(Aluno *aluno) {
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite a idade: ");
    scanf("%d", &aluno->idade);
    printf("Digite a s�rie: ");
    scanf(" %[^\n]", aluno->serie);

    printf("Quantas disciplinas deseja adicionar (at� %d): ", MAX_DISCIPLINAS);
    scanf("%d", &aluno->num_disciplinas);

    for (int i = 0; i < aluno->num_disciplinas; i++) {
        printf("\nDigite o nome da disciplina %d: ", i + 1);
        scanf(" %[^\n]", aluno->disciplinas[i]);
        printf("Digite a nota inicial para %s: ", aluno->disciplinas[i]);
        scanf("%f", &aluno->notas_iniciais[i]);
        aluno->notas_finais[i] = aluno->notas_iniciais[i];
    }
}

// Fun��o para definir o per�odo de estudo
void definirPeriodoEstudo(Aluno *aluno) {
    printf("Digite o per�odo de estudo em dias: ");
    scanf("%d", &aluno->periodo_estudo);
}

// Fun��o para atualizar as notas finais ap�s o per�odo de estudo
void atualizarNotas(Aluno *aluno) {
    for (int i = 0; i < aluno->num_disciplinas; i++) {
        printf("\nDigite a nova nota para %s: ", aluno->disciplinas[i]);
        scanf("%f", &aluno->notas_finais[i]);
    }
}

// Fun��o para avaliar o desempenho e gerar feedback
void avaliarDesempenho(Aluno *aluno) {
    printf("\nAn�lise de Desempenho de %s:\n", aluno->nome);

    for (int i = 0; i < aluno->num_disciplinas; i++) {
        float progresso = aluno->notas_finais[i] - aluno->notas_iniciais[i];
        printf("\nDisciplina: %s\n", aluno->disciplinas[i]);
        printf("Nota Inicial: %.2f, Nota Final: %.2f\n", aluno->notas_iniciais[i], aluno->notas_finais[i]);

        // Verificar progresso
        if (progresso > 0) {
            printf("Evolu��o: Houve progresso na disciplina. Continue assim!\n");
        } else if (progresso < 0) {
            printf("Queda: O desempenho caiu. Recomenda-se revisar o plano de estudos.\n");
        } else {
            printf("Estabilidade: A nota n�o mudou. Considere refor�ar o estudo.\n");
        }
    }
}

// Fun��o principal para executar o programa
int main() {
    Aluno aluno;
    int opcao;
    
    printf("Sistema de Rotina e Educa��o Personalizada Para Estudantes\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Definir Plano de Estudo\n");
        printf("3. Atualizar Notas\n");
        printf("4. Avaliar Desempenho\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(&aluno);
                break;
            case 2:
                definirPeriodoEstudo(&aluno);
                break;
            case 3:
                atualizarNotas(&aluno);
                break;
            case 4:
                avaliarDesempenho(&aluno);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

