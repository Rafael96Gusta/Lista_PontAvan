# Resolução de Lista de Ponteiros

Etapa 1 — Pseudocódigo

Parâmetros marcados com (&) são endereços: vetores, matrizes e ponteiros de saída.

ALGORITMO principal
  VARIÁVEIS: alunos[MAX_ALUNOS] (Aluno), notas[MAX_ALUNOS][MAX_DISC] (inteiro),
             medias[MAX_ALUNOS] (real), n, m, pos, novaIdade, indiceMaior (inteiro),
             maior (real)

  REPITA ler n ATÉ 1 ≤ n ≤ MAX_ALUNOS
  REPITA ler m ATÉ 1 ≤ m ≤ MAX_DISC

  lerDados(alunos, n, notas, m)
  calcularMedia(notas, n, m, medias)

  REPITA ler pos ATÉ 1 ≤ pos ≤ n
  REPITA ler novaIdade ATÉ novaIdade > 0
  alterarIdade(endereço de alunos[pos-1], novaIdade)

  buscarMaiorMedia(medias, n, endereço de indiceMaior, endereço de maior)

  mostrarResultados(alunos, medias, n)
  ESCREVER matrícula de alunos[indiceMaior] e maior
FIM

SUBPROGRAMA lerDados(alunos (&), n, notas (&), m)
  PARA i DE 0 ATÉ n-1
    ler alunos[i].matricula
    REPITA ler alunos[i].idade ATÉ idade > 0
    REPITA ler alunos[i].turno ATÉ turno ∈ {M, T, N}
    PARA j DE 0 ATÉ m-1
      REPITA ler notas[i][j] ATÉ 0 ≤ notas[i][j] ≤ 10
FIM

SUBPROGRAMA calcularMedia(notas (&), n, m, medias (&, saída))
  PARA i DE 0 ATÉ n-1
    soma ← 0
    PARA j DE 0 ATÉ m-1
      soma ← soma + notas[i][j]
    medias[i] ← soma / m
FIM

SUBPROGRAMA alterarIdade(aluno (&), novaIdade)
  idade do aluno apontado ← novaIdade     { alteração por referência }
FIM

SUBPROGRAMA buscarMaiorMedia(medias (&), n, indice (&, saída), maior (&, saída))
  conteúdo de indice ← 0
  conteúdo de maior ← medias[0]
  PARA i DE 1 ATÉ n-1
    SE medias[i] > conteúdo de maior ENTÃO     { > estrito: empate fica com o primeiro }
      conteúdo de maior ← medias[i]
      conteúdo de indice ← i
FIM

SUBPROGRAMA mostrarResultados(alunos (&), medias (&), n)
  PARA i DE 0 ATÉ n-1
    ESCREVER alunos[i].matricula, alunos[i].idade, alunos[i].turno, medias[i]
FIM
