#include <stdio.h>
#include <stdlib.h>
#include <time.h> // pesquisei sobre a time.h para facilitar o programa

#define SIZE 4

// função para inicializar o tabuleiro com valores aleatórios
void initBoard(int board[SIZE][SIZE]) { // substitui algumas variaveis no codigo por ingles porque e mais intuitivo
    int i, j, k, l;
    srand(time(NULL)); // inicializa a semente do gerador de números aleatórios
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0; // inicializando o tabuleiro
        }
    }

    i = rand() % SIZE;
    j = rand() % SIZE;
    board[i][j] = rand() % 2 ? 2 : 4; // gera um número aleatório entre 2 e 4

    k = rand() % SIZE;
    l = rand() % SIZE;
    while ((i == k) && (j == l)) {
        k = rand() % SIZE;
        l = rand() % SIZE;
    }
    board[k][l] = rand() % 2 ? 2 : 4; // gera um número aleatório entre 2 e 4
}

// função para imprimir o tabuleiro na tela
void printBoard(int board[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
    printf("%d\t", board[i][j]);
        }
    printf("\n");
    }}

void addNewNumber(int board[SIZE][SIZE]) {
    int i, j;
    int emptySpaces = 0; // contador de espaços vazios no tabuleiro
    // percorre o tabuleiro para contar os espaços vazios
    for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
    if (board[i][j] == 0) {
                emptySpaces++;
    }}}
    
    if (emptySpaces > 0) {
        int newNumber = rand() % 10 < 9 ? 2 : 4; // gera um número aleatório entre 2 e 4 com 90% de chance para 2
        int randomIndex = rand() % emptySpaces; // escolhe um índice aleatório dentre os espaços vazios
        int emptyFound = 0; // contador de espaços vazios encontrados
        // percorre o tabuleiro novamente para encontrar a posição vazia escolhida aleatoriamente
        for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
        if (board[i][j] == 0) {
        if (emptyFound == randomIndex) {
                        // adiciona o novo número na posição vazia escolhida
        board[i][j] = newNumber;
        return;
                    }
                    emptyFound++;
}}}}}


// função para mover os números no tabuleiro para cima
void moveUp(int board[SIZE][SIZE]) {
    int i, j, k;

    // percorre as colunas
    for (j = 0; j < SIZE; j++) {
        // percorre as linhas da coluna atual
    for (i = 0; i < SIZE; i++) {
            // se o número na posição atual for diferente de 0
    if (board[i][j] != 0) {
     // percorre as linhas acima da posição atual
    for (k = i + 1; k < SIZE; k++) {
    // se o número na posição atual for igual ao número acima dele
     if (board[i][j] == board[k][j]) {
       // soma os dois números e armazena o resultado na posição atual
           board[i][j] += board[k][j];
           // zera o número acima
       board[k][j] = 0;
        break;
     } else if (board[k][j] != 0) {
       // se o número acima for diferente de zero e diferente do número atual, não é possível fazer a soma.
    break;
    }}}} }

    // percorre as colunas
    for (j = 0; j < SIZE; j++) {
     // percorre as linhas da coluna atual
     for (i = 0; i < SIZE; i++) {
      // se o número na posição atual for igual a zero
     if (board[i][j] == 0) {
   // percorre as linhas acima da posição atual
       for (k = i + 1; k < SIZE; k++) {
        // se o número acima for diferente de zero
        if (board[k][j] != 0) {
     // move o número acima para a posição atual
      board[i][j] = board[k][j];
      // zera a posição acima
      board[k][j] = 0;
      break;
    }}}}}}

void moveDown(int board[SIZE][SIZE]) {
    int i, j, k;

    // percorre as colunas
    for (j = 0; j < SIZE; j++) {
     // percorre as linhas da coluna atual de baixo para cima
    for (i = SIZE - 1; i >= 0; i--) {
     // se o número na posição atual for diferente de 0
     if (board[i][j] != 0) {
    // percorre as linhas abaixo da posição atual
     for (k = i - 1; k >= 0; k--) {
     // se o número na posição atual for igual ao número abaixo dele
     if (board[i][j] == board[k][j]) {
     // soma os dois números e armazena o resultado na posição atual
     board[i][j] += board[k][j];
     // zera o número abaixo
     board[k][j] = 0;
     break;
      } else if (board[k][j] != 0) {
     // se o número abaixo for diferente de zero e diferente do número atual, não é possível fazer a soma.
     break;
    }}}}}

    // percorre as colunas
    for (j = 0; j < SIZE; j++) {
    // percorre as linhas da coluna atual de baixo para cima
    for (i = SIZE - 1; i >= 0; i--) {
     // se o número na posição atual for igual a zero
     if (board[i][j] == 0) {
     // percorre as linhas abaixo da posição atual
     for (k = i - 1; k >= 0; k--) {
     // se o número abaixo for diferente de zero
     if (board[k][j] != 0) {
     // move o número abaixo para a posição atual
     board[i][j] = board[k][j];
     // zera a posição abaixo
    board[k][j] = 0;
     break;
    }}}}}}

void moveRight(int board[SIZE][SIZE]) {
    int i, j, k;

    // percorre as linhas
    for (i = 0; i < SIZE; i++) {
        // percorre as colunas da linha atual da direita para a esquerda
     for (j = SIZE - 1; j >= 0; j--) {
    // se o número na posição atual for diferente de 0
      if (board[i][j] != 0) {
         // percorre as colunas a direita da posição atual
    for (k = j + 1; k < SIZE; k++) {
        // se o número na posição atual for igual ao número a direita dele
     if (board[i][j] == board[i][k]) {
     // soma os dois números e armazena o resultado na posição atual
      board[i][j] += board[i][k];
     // zera o número a direita
      board[i][k] = 0;
      break;
     } else if (board[i][k] != 0) {
      // se o número a direita for diferente de zero e diferente do número atual, não é possível fazer a soma.
     break;
                    }}}}}

    // percorre as linhas
    for (i = 0; i < SIZE; i++) {
     // percorre as colunas da linha atual da direita para a esquerda
    for (j = SIZE - 1; j >= 0; j--) {
   // se o número na posição atual for igual a zero
    if (board[i][j] == 0) {
    // percorre as colunas a direita da posição atual
    for (k = j + 1; k < SIZE; k++) {
    // se o número a direita for diferente de zero
    if (board[i][k] != 0) {
     // move o número a direita para a posição atual
     board[i][j] = board[i][k];
    // zera a posição a direita
    board[i][k] = 0;
    break;
}}}}}}

void moveLeft(int board[SIZE][SIZE]) {
    int i, j, k;

    // percorre as linhas
    for (i = 0; i < SIZE; i++) {
     // percorre as colunas da linha atual da esquerda para a direita
     for (j = 0; j < SIZE; j++) {
    // se o número na posição atual for diferente de 0
     if (board[i][j] != 0) {
     // percorre as colunas a esquerda da posição atual
     for (k = j - 1; k >= 0; k--) {
      // se o número na posição atual for igual ao número a esquerda dele
    if (board[i][j] == board[i][k]) {
     // soma os dois números e armazena o resultado na posição atual
     board[i][j] += board[i][k];
     // zera o número a esquerda
     board[i][k] = 0;
     break;
   } else if (board[i][k] != 0) {
  // se o número a esquerda for diferente de zero e diferente do número atual, não é possível fazer a soma.
     break;
        }}}}}

    // percorre as linhas
    for (i = 0; i < SIZE; i++) {
     // percorre as colunas da linha atual da esquerda para a direita
    for (j = 0; j < SIZE; j++) {
      // se o número na posição atual for igual a zero
    if (board[i][j] == 0) {
    // percorre as colunas a esquerda da posição atual
    for (k = j - 1; k >= 0; k--) {
      // se o número a esquerda for diferente de zero
    if (board[i][k] != 0) {
     // move o número a esquerda para a posição atual
    board[i][j] = board[i][k];
    // zera a posição a esquerda
    board[i][k] = 0;
    break;
                    }}}}}}
  int checkGameOver(int board[SIZE][SIZE]) {
    int i, j;
    // percorre as linhas e colunas do tabuleiro
    for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
            // se há algum espaço vazio no tabuleiro, o jogo não acabou
            if (board[i][j] == 0) {
                return 0;
            }
            // se há alguma peça adjacente com o mesmo valor, o jogo não acabou
            if (i > 0 && board[i][j] == board[i-1][j]) {
                return 0;
            }
            if (i < SIZE - 1 && board[i][j] == board[i+1][j]) {
                return 0;
            }
            if (j > 0 && board[i][j] == board[i][j-1]) {
                return 0;
            }
            if (j < SIZE - 1 && board[i][j] == board[i][j+1]) {
                return 0;
            }}}
// se não há espaços vazios ou peças adjacentes com o mesmo valor, o jogo acabou
return 1;
}


int main() {
    int board[SIZE][SIZE];
    
    initBoard(board);
    printf("\e[H\e[2J");
    printBoard(board);
    printf("Insira a direcao do movimento (1 - cima, 2 - baixo, 3 - esquerda, 4 - direita): \n");

    int move;
    int gameOver = 0;
  
    while (!gameOver) {
        
        scanf("%d", &move);

        if (move == 1) {
            moveUp(board);
        } else if (move == 2) {
            moveDown(board);
        } else if (move == 3) {
            moveLeft(board);
        } else if (move == 4) {
            moveRight(board);
        }
          else if (move = 5){
            return 0;
        
        } else {
            printf("Movimento inválido\n");
        }
        printf("\e[H\e[2J");
        printBoard(board);
        printf("Insira a direcao do movimento (1 - cima, 2 - baixo, 3 - esquerda, 4 - direita): \n");
        // verifica se o jogo acabou
        gameOver = checkGameOver(board);
      
        addNewNumber(board);
    }
    printf("Fim de Jogo!");

    return 0;
}