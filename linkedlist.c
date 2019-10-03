#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//doubly linked list

typedef struct
{
   int codigo;
   char descricao[30];
   float valor;
   struct produto *proximo;  //ponteiro para o proximo produto
   struct produto *anterior; //ponteiro para o produto anterior
} produto;                   // aq declara a variavel da struct

typedef struct
{
   produto *primeiro;
   produto *ultimo;
} lista;

void inicializa(lista *ll)
{
   ll->primeiro = NULL;
   ll->ultimo = NULL;
}

void apresenta(lista ll)
{
   produto *p = ll.primeiro;
   while (p != NULL)
   {
      printf("\n%d %s\n", p->codigo, p->descricao);
      p = (produto*) p->proximo;
   }
}

void inserir(lista *ll, produto p)
{
   produto *aux = malloc(sizeof(produto));
   *aux = p;
   if (ll->ultimo == NULL)
   {
      ll->primeiro = aux;
      ll->ultimo = aux;
   }
   else
   {
      ll->ultimo->proximo = (struct produto *)aux;
      aux->anterior = (struct produto *)ll->ultimo;
      ll->ultimo = aux;
   }
}

produto *pesquisa(lista l, int cod)
{
   produto *p = l.primeiro;
   while (p != NULL && cod != p->codigo)
      p = (produto*) p->proximo;
   return p;
}

void deleta(lista *l, int cod) {
   produto *p, *anterior; 
   p = l->primeiro;
   anterior = NULL;
   //q = l->proximo;
   if (p != NULL && p->codigo == cod)
      {
         p = (produto*) p->proximo;
         printf("Procurando...\n");
         free(p);
      }
       while (p != NULL && cod != p->codigo)
      {
      anterior = (produto *) p->proximo;  
       p = (produto*) p->proximo;  
       free(p);
      }
      // else
      // {
      //    anterior = p;
      //    printf("Produto encontrado.");
      //    anterior->proximo = p->proximo;
      //    free(p);
      // }
}

int main()
{
   lista l;
   produto prod;
   produto *p;
   inicializa(&l);

   /* preenchimento */
   prod.codigo = 1;
   prod.valor = 2.50;
   strcpy(prod.descricao, "Parafuso Grande");
   prod.proximo = NULL;
   prod.anterior = NULL;
   inserir(&l, prod);

   prod.codigo = 2;
   prod.valor = 2.30;
   strcpy(prod.descricao, "Arruela");
   prod.proximo = NULL;
   prod.anterior = NULL;
   inserir(&l, prod);

   prod.codigo = 3;
   prod.valor = 1.70;
   strcpy(prod.descricao, "Porca");
   prod.proximo = NULL;
   prod.anterior = NULL;
   inserir(&l, prod);

   prod.codigo = 4;
   prod.valor = 1.70;
   strcpy(prod.descricao, "Mesa");
   prod.proximo = NULL;
   prod.anterior = NULL;
   inserir(&l, prod);

   //deleta
  deleta(&l, 4);

   /* pesquisa */
   printf("\n======================\n");
   p = pesquisa(l, 4);
   if (p != NULL)
      printf("\n%d %s\n", p->codigo, p->descricao);
   printf("\n======================\n");

   /* apresentação */
   apresenta(l);
}