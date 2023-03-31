#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_PESSOAS 1024

struct pessoa {
    unsigned int cpf;
    unsigned short int digito_verificador; 
    char *nome;
    short idade;
    char sexo[1];
    char *cor;
    float altura;
    float peso;
};

struct dict {
    struct pessoa *grupo[TAM_PESSOAS];
    int num_pessoas;
};

void inicializar(struct dict *dict)
{
    dict->num_pessoas = 0;
}

void inserir(struct pessoa *pessoa, struct dict *pessoas)
{
    if (pessoas->num_pessoas == TAM_PESSOAS)
        return;

    int indice = pessoas->num_pessoas;
    memcpy(pessoas->grupo[indice], pessoa, sizeof(struct pessoa));
    pessoas->num_pessoas++;
}

struct pessoa *buscar(unsigned int cpf, short int digito, struct dict *pessoas)
{
    for (int i = 0; i < pessoas->num_pessoas; i++) {
        if (pessoas->grupo[i]->cpf == cpf) {
            if (pessoas->grupo[i]->digito_verificador == digito)
                return pessoas->grupo[i];
        }
    }

    return NULL;
}

int main()
{
    struct dict pessoas;
    inicializar(&pessoas);
    struct pessoa *pessoa = malloc(sizeof(struct pessoa));
    pessoa->cpf = 139668759;
    pessoa->digito_verificador = 93;
    
    inserir(pessoa, &pessoas);
    struct pessoa *achou = buscar(139668759, 93, &pessoas);

    printf ("%d\n", achou->cpf);

    return 0;
}
