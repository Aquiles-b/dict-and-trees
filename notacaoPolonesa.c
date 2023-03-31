#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MUL 1
#define DIV 2
#define DIF 3
#define ADD 4
#define TAM_ENT 64

struct nodo{
    int valor;
    struct nodo *filho_esq;
    struct nodo *filho_dir;
};

/*Le entrada do teclado e retorna um ponteiro.*/
char* lerEntrada()
{
    char* entrada = malloc(sizeof(size_t)*TAM_ENT);
    fgets(entrada, TAM_ENT, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    return entrada;
}

struct nodo* criaNodo()
{
    struct nodo* nodo = malloc(sizeof(struct nodo));
    if (!nodo)
        return NULL;

    return nodo;
}

int qualOperacao(char* op)
{
    switch (*op){
        case '*': 
            return MUL;
            break;
        case '/':
            return DIV;
            break;
        case '-':
            return DIF;
            break;
        case '+':
            return ADD;
            break;
        default:
            return 0;
            break;
    }
}

/*Converte de char para int.*/
int converteNumero(char* item)
{
    if (!(*item > 47 && *item < 58))
        return 0;

    return *item - 48; 
}

int montaSubArvore(struct nodo* nodo, char* entrada, int ind)
{
    int item;
    if (!(item = qualOperacao(&entrada[ind]))){
        nodo->valor = converteNumero(&entrada[ind]);
        nodo->filho_esq = NULL;
        nodo->filho_dir = NULL;
        return ind;
    }
    nodo->valor = item;
    nodo->filho_dir = criaNodo();
    nodo->filho_esq = criaNodo();

    ind++;
    ind = montaSubArvore(nodo->filho_esq, entrada, ind);
    ind = montaSubArvore(nodo->filho_dir, entrada, ind);

    return ind;
}

struct nodo* montaArvore(char* entrada)
{
    int item, i;
    i = 0;
    struct nodo *raiz, *nodo;
    raiz = criaNodo();
    nodo = raiz;
    if ((item = qualOperacao(&entrada[i]))){
        nodo->valor = item;
        nodo->filho_dir = criaNodo();
        nodo->filho_esq = criaNodo();
        i++;
        i = montaSubArvore(nodo->filho_esq, entrada, i);
        i = montaSubArvore(nodo->filho_dir, entrada, i);
    }
    else if ((item = converteNumero(&entrada[i])))
        nodo->valor= item;

    return raiz;
}

void imprimeArvore(struct nodo* raiz)
{

}
    

int main(){
    char* entrada = lerEntrada();
    struct nodo* raiz = montaArvore(entrada);

    free(entrada);

    return 0;
}
