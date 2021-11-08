#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct Node {
	int PID;
	int tamanho;
	char nome [32];
	struct Node *next;
} Node;

typedef struct Fila {
	Node *ini;
	Node *end;
}Fila;

//prot�tipos de fun��es
void verificarPrioridade(bool prioridade, int t, int f);
void enfileirarProcesso(int PID, int tamanho, char nome[32], Fila *f1, Fila *f2);
void liberarPrrocessosF1 (Fila *f1);
//int menu(void);

int main() {

	bool prioridade;
	int t, f;
	setlocale(LC_ALL, "Portuguese");
		
	printf("Prioridade? \n1 - Sim \n0 - N�o\n");
	scanf("%d", &prioridade);

	verificarPrioridade(prioridade, t, f);
	
	return 0;

}


void verificarPrioridade(bool prioridade, int t, int f) {
	t = 1;
	f = 0;
	if (prioridade == t) {
		//printf("Good! ");
		return ;
	} if(prioridade == f) {
		//printf("Not good! ");
		return;
		}
}

void enfileirarProcesso(int PID, int tamanho, char nome[32], Fila *f1, Fila *f2) {
	Node *ptr = (Node*) malloc(sizeof(Node));
	
	bool prioridade;
	int t, f;
	
	verificarPrioridade(prioridade, t, f);
	if(ptr == NULL){
		printf("FALHA NA ALOCA��O!!! /n");
		} if (prioridade == f) {
			ptr->PID = PID;
			ptr->tamanho = tamanho;
			ptr->nome[32] = nome[32];
			ptr->next = NULL;
			if(f1->ini == NULL) {
				f1->ini = ptr;
			} else {
				f1->end->next = ptr;
			}
			f1->end = ptr;
		} else if (prioridade == t) {
			ptr->PID = PID;
			ptr->tamanho = tamanho;
			ptr->nome[32] = nome[32];
			ptr->next = NULL;
			if(f2->ini == NULL) {
				f2->ini = ptr;
			} else {
				f2->end->next = ptr;
			}
			f2->end = ptr;
		}
		
		f1->end = ptr;
}

void liberarPrrocessosF1(Fila *f1) {
	Node *ptr = f1->ini;
	int PID;
	int tamanho;
	char nome[32];
	if(ptr != NULL) { // Se o ponteiro n�o esta apontando para algo que seja NULL.
		f1->ini = ptr->next; // Fila f1 no inicio se torna ponteiro apontando proximo
		PID = ptr->PID; // Ponteiro apontando dados.
		nome[32] = ptr->nome[32]; // Ponteiro apontando dados.
		tamanho = ptr->tamanho; // Ponteiro apontando dados.		
		free(ptr); // Liberando ponteiro
		if(f1->ini == NULL) {
			f1->end = NULL;
		}
		return;
	} else { // se tiver algo no ponteiro.
		printf("Fila Vazia! \n");
		return;
	}
}
/*int menu(void) {
	
	int select;
	
	printf("Escolha a opcao\n");
 	printf("0. Sair\n");
 	printf("1. Exibir fila de processos\n");
 	printf("2. Adicionar processos a fila\n");
 	printf("3. Remover processo da fila\n");
	printf("4. Remover processo especifico da fila\n");
	printf("5. Limpar fila");
	printf("Opcao: "); 
	scanf("%d", &select);

 return select;
}*/
