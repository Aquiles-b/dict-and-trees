#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int chave;
    struct nodo *filhoEsq;
    struct nodo *idir;
};

 /* Cria um nodo e retorna um ponteiro para o mesmo. */
struct nodo *criaNodo(int valor)
{
    struct nodo *nodo = malloc(sizeof(struct nodo));
    if (!nodo)
        return NULL;

    nodo->filhoEsq = NULL;
    nodo->idir = NULL;
    nodo->chave = valor;

    return nodo;
}

 /* Adiciona um filho para o nodo @nodo com o valor @valor. */
int adicionaFilho(struct nodo *nodo, int valor)
{
    struct nodo *novoNodo, *nodoAux;
    novoNodo = criaNodo(valor);
    if (novoNodo == NULL)
        return 1;

    if (nodo->filhoEsq == NULL){
        nodo->filhoEsq = novoNodo;
        return 0;
    }

    nodoAux = nodo->filhoEsq;
    while (nodoAux->idir != NULL)
        nodoAux = nodoAux->idir;

    nodoAux->idir = novoNodo;

    return 0;
}

 /* Insere a raiz de uma sub arvore como filho do @nodo. */
int insereSubArvore(struct nodo *raizSub, struct nodo *nodo)
{
    struct nodo *nodoAux;
    if (nodo->filhoEsq == NULL){
        nodo->filhoEsq = raizSub;
        return 0;
    }

    nodoAux = nodo->filhoEsq;
    while (nodoAux->idir != NULL)
        nodoAux = nodoAux->idir;

    nodoAux->idir = raizSub;

    return 0;
}

/* Imprime a arvore em pre-ordem.*/
void imprimePreOrd(struct nodo *nodo)
{
    if (nodo == NULL)
        return;
    printf ("%d ", nodo->chave);
    imprimePreOrd(nodo->filhoEsq);
    imprimePreOrd(nodo->idir);
}
 
void buscaDf(struct nodo *nodo)
{
    if (nodo == NULL)
        return;
    printf ("%d ", nodo->chave);
    imprimePreOrd(nodo->filhoEsq);
    imprimePreOrd(nodo->idir);
}

void imprimeFilhos(struct nodo *nodo)
{
    struct nodo *nodoAux = nodo->filhoEsq;
    while (nodoAux != NULL) {
        printf ("%d ", nodoAux->chave);
        nodoAux = nodoAux->idir;
    }
}

/* imprime em largura.*/
void auxImprimeLargura(struct nodo *nodo)
{
    if (nodo == NULL)
        return;

    imprimeFilhos(nodo);
    auxImprimeLargura(nodo->idir);
    auxImprimeLargura(nodo->filhoEsq);
}

/* Imprime em largura.*/
void imprimeLargura(struct nodo *raiz)
{
    printf ("%d ", raiz->chave);
    auxImprimeLargura(raiz);
    printf ("\n");
}

int main()
{
    struct nodo *raiz, *subArv, *nodo;
    raiz = criaNodo(1);
    subArv = criaNodo(1);

    /*Adiciona filhos da raiz e na subArv.*/
    adicionaFilho(raiz, 2);
    adicionaFilho(raiz, 3);
    adicionaFilho(subArv, 2);
    adicionaFilho(subArv, 3);

    /* Adiciona filhos do nodo 2.*/
    nodo = raiz->filhoEsq;
    adicionaFilho(nodo, 4);
    adicionaFilho(nodo, 5);
    /* Adciona filho no nodo 5.*/
    nodo = nodo->filhoEsq->idir;
    adicionaFilho(nodo, 7);
    /* Adiciona filho ao nodo 3.*/
    nodo = raiz->filhoEsq->idir;
    adicionaFilho(nodo, 7);
    /* Adiciona filho ao nodo 7.*/
    nodo = nodo->filhoEsq;
    adicionaFilho(nodo, 6);

    /* Adiciona filho ao nodo 2 da subArv.*/
    nodo = subArv->filhoEsq;
    adicionaFilho(nodo, 5);
    /* Adiciona filho ao nodo 3 da subArv.*/
    nodo = subArv->filhoEsq->idir;
    adicionaFilho(nodo, 7);

    imprimeLargura(raiz);

    /* Insere a subArv no nodo 3 da raiz.*/
    insereSubArvore(subArv, raiz->filhoEsq->idir);

    return 0;
}
