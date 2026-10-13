#include <stdio.h>
#define MAX_ALUNOS 50
#define MAX_DISC 5

typedef struct {
    int matricula; /* numero inteiro de identificacao */
    int idade;
    char turno;    /* M, T ou N */
} Aluno;

void lerDados(Aluno alunos[], int n, int notas[][MAX_DISC], int m);
void calcularMedia(int notas[][MAX_DISC], int n, int m, float medias[]);
void alterarIdade(Aluno *aluno, int novaIdade);
void buscarMaiorMedia(float medias[], int n, int *indice, float *maior);
void mostrarResultados(Aluno alunos[], float medias[], int n);

/* Questoes adicionais (laboratorio) */
int contarAprovados(float medias[], int n);
void mediaDisciplina(int notas[][MAX_DISC], int n, int m, int disciplina, float *media);
void alterarNota(int notas[][MAX_DISC], int aluno, int disciplina, int novaNota);

int main(void) {
    Aluno alunos[MAX_ALUNOS];
    int notas[MAX_ALUNOS][MAX_DISC];
    float medias[MAX_ALUNOS];
    int n, m, pos, novaIdade;
    int indiceMaior;
    float maior;

    do {
        printf("Numero de alunos (1 a %d): ", MAX_ALUNOS);
        if (scanf("%d", &n) != 1) return 1;
    } while (n < 1 || n > MAX_ALUNOS);

    do {
        printf("Numero de disciplinas (1 a %d): ", MAX_DISC);
        if (scanf("%d", &m) != 1) return 1;
    } while (m < 1 || m > MAX_DISC);

    lerDados(alunos, n, notas, m);
    calcularMedia(notas, n, m, medias);

    do {
        printf("Aluno para alterar a idade (1 a %d): ", n);
        if (scanf("%d", &pos) != 1) return 1;
    } while (pos < 1 || pos > n);

    do {
        printf("Nova idade: ");
        if (scanf("%d", &novaIdade) != 1) return 1;
    } while (novaIdade <= 0);

    alterarIdade(&alunos[pos - 1], novaIdade);

    buscarMaiorMedia(medias, n, &indiceMaior, &maior);

    mostrarResultados(alunos, medias, n);
    printf("\nMaior media: %d \n\nMatricula: %.1f\n",
           alunos[indiceMaior].matricula, maior);
    printf("\nQuantidade de alunos aprovados: %d\n", contarAprovados(medias, n));

    return 0;
}

void lerDados(Aluno alunos[], int n, int notas[][MAX_DISC], int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        do {
            printf("Idade: ");
            scanf("%d", &alunos[i].idade);
        } while (alunos[i].idade <= 0);

        do {
            printf("Turno (M, T ou N): ");
            scanf(" %c", &alunos[i].turno);
        } while (alunos[i].turno != 'M' && alunos[i].turno != 'T' &&
                 alunos[i].turno != 'N');

        for (j = 0; j < m; j++) {
            do {
                printf("Nota %d (0 a 10): ", j + 1);
                scanf("%d", &notas[i][j]);
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
}

void calcularMedia(int notas[][MAX_DISC], int n, int m, float medias[]) {
    int i, j, soma;
    for (i = 0; i < n; i++) {
        soma = 0;
        for (j = 0; j < m; j++) {
            soma += notas[i][j];
        }
        medias[i] = (float)soma / m;
    }
}

void alterarIdade(Aluno *aluno, int novaIdade) {
    aluno->idade = novaIdade;
}

void buscarMaiorMedia(float medias[], int n, int *indice, float *maior) {
    int i;
    *indice = 0;
    *maior = medias[0];
    for (i = 1; i < n; i++) {
        if (medias[i] > *maior) { /* '>' estrito: empate fica com o primeiro */
            *maior = medias[i];
            *indice = i;
        }
    }
}

void mostrarResultados(Aluno alunos[], float medias[], int n) {
    int i;
    printf("\n%-10s %-6s %-6s %-6s\n", "Matricula", "Idade", "Turno", "Media");
    for (i = 0; i < n; i++) {
        printf("%-10d %-6d %-6c %-6.1f\n",
               alunos[i].matricula, alunos[i].idade,
               alunos[i].turno, medias[i]);
    }
}

//Adicionais

int contarAprovados(float medias[], int n) {
    int i, cont = 0;
    for (i = 0; i < n; i++) {
        if (medias[i] >= 6.0f) cont++;
    }
    return cont;
}

void mediaDisciplina(int notas[][MAX_DISC], int n, int m, int disciplina, float *media) {
    int i, soma = 0;
    (void)m; /* m nao e necessario para percorrer uma coluna */
    for (i = 0; i < n; i++) {
        soma += notas[i][disciplina];
    }
    *media = (float)soma / n;
}

void alterarNota(int notas[][MAX_DISC], int aluno, int disciplina, int novaNota) {
    notas[aluno][disciplina] = novaNota;
}

/*
#include <stdio.h>

#define MAX_ALUNOS 50
#define MAX_DISC 5

typedef struct {
    int matricula;
    int idade;
    char turno;
} Aluno;

void lerDados(Aluno alunos[], int n, int notas[][MAX_DISC], int m);
void calcularMedia(int notas[][MAX_DISC], int n, int m, float medias[]);
void alterarIdade(Aluno *aluno, int novaIdade);
void buscarMaiorMedia(float medias[], int n, int *indice, float *maior);
void mostrarResultados(Aluno alunos[], float medias[], int n);

int contarAprovados(float medias[], int n);
void mediaDisciplina(int notas[][MAX_DISC], int n, int m, int disciplina, float *media);
void alterarNota(int notas[][MAX_DISC], int aluno, int disciplina, int novaNota);

int main(void) {
    Aluno alunos[MAX_ALUNOS];
    int notas[MAX_ALUNOS][MAX_DISC];
    float medias[MAX_ALUNOS];
    int n, m, pos, novaIdade;
    int indiceMaior;
    float maior;

    int aluno, disciplina, novaNota;

    do {
        printf("Numero de alunos (1 a %d): ", MAX_ALUNOS);
        scanf("%d", &n);
    } while (n < 1 || n > MAX_ALUNOS);

    do {
        printf("Numero de disciplinas (1 a %d): ", MAX_DISC);
        scanf("%d", &m);
    } while (m < 1 || m > MAX_DISC);

    lerDados(alunos, n, notas, m);
    calcularMedia(notas, n, m, medias);

    /* Alterar idade */
    do {
        printf("\nAluno para alterar a idade (1 a %d): ", n);
        scanf("%d", &pos);
    } while (pos < 1 || pos > n);

    do {
        printf("Nova idade: ");
        scanf("%d", &novaIdade);
    } while (novaIdade <= 0);

    alterarIdade(&alunos[pos - 1], novaIdade);

    /* Alterar nota */
    do {
        printf("\nAluno para alterar a nota (1 a %d): ", n);
        scanf("%d", &aluno);
    } while (aluno < 1 || aluno > n);

    do {
        printf("Disciplina (1 a %d): ", m);
        scanf("%d", &disciplina);
    } while (disciplina < 1 || disciplina > m);

    do {
        printf("Nova nota (0 a 10): ");
        scanf("%d", &novaNota);
    } while (novaNota < 0 || novaNota > 10);

    alterarNota(notas, aluno - 1, disciplina - 1, novaNota);

    /* Recalcular as medias */
    calcularMedia(notas, n, m, medias);

    /* Buscar maior media */
    buscarMaiorMedia(medias, n, &indiceMaior, &maior);

    /* Mostrar resultados */
    mostrarResultados(alunos, medias, n);

    printf("\nMaior media: matricula %d, %.1f\n",
           alunos[indiceMaior].matricula, maior);

    printf("Quantidade de alunos aprovados: %d\n",
           contarAprovados(medias, n));

    return 0;
}

void lerDados(Aluno alunos[], int n, int notas[][MAX_DISC], int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        do {
            printf("Idade: ");
            scanf("%d", &alunos[i].idade);
        } while (alunos[i].idade <= 0);

        do {
            printf("Turno (M, T ou N): ");
            scanf(" %c", &alunos[i].turno);
        } while (alunos[i].turno != 'M' &&
                 alunos[i].turno != 'T' &&
                 alunos[i].turno != 'N');

        for (j = 0; j < m; j++) {
            do {
                printf("Nota %d (0 a 10): ", j + 1);
                scanf("%d", &notas[i][j]);
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
}

void calcularMedia(int notas[][MAX_DISC], int n, int m, float medias[]) {
    int i, j, soma;

    for (i = 0; i < n; i++) {
        soma = 0;

        for (j = 0; j < m; j++) {
            soma += notas[i][j];
        }

        medias[i] = (float)soma / m;
    }
}

void alterarIdade(Aluno *aluno, int novaIdade) {
    aluno->idade = novaIdade;
}

void buscarMaiorMedia(float medias[], int n, int *indice, float *maior) {
    int i;

    *indice = 0;
    *maior = medias[0];

    for (i = 1; i < n; i++) {
        if (medias[i] > *maior) {
            *maior = medias[i];
            *indice = i;
        }
    }
}

void mostrarResultados(Aluno alunos[], float medias[], int n) {
    int i;

    printf("\n%-10s %-6s %-6s %-6s\n",
           "Matricula", "Idade", "Turno", "Media");

    for (i = 0; i < n; i++) {
        printf("%-10d %-6d %-6c %-6.1f\n",
               alunos[i].matricula,
               alunos[i].idade,
               alunos[i].turno,
               medias[i]);
    }
}

int contarAprovados(float medias[], int n) {
    int i, cont = 0;

    for (i = 0; i < n; i++) {
        if (medias[i] >= 6.0f) {
            cont++;
        }
    }

    return cont;
}

void mediaDisciplina(int notas[][MAX_DISC], int n, int m,
                     int disciplina, float *media) {
    int i, soma = 0;

    for (i = 0; i < n; i++) {
        soma += notas[i][disciplina];
    }

    *media = (float)soma / n;
}

void alterarNota(int notas[][MAX_DISC], int aluno,
                 int disciplina, int novaNota) {
    notas[aluno][disciplina] = novaNota;
}