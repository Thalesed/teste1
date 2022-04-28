#pragma once

#include <stdio.h>
#include <stdlib.h>

/*Funcoes de lista encadeada*/

/*definindo lista encadeada*/
struct lista{
	int data;
	struct lista *prox;
};

typedef struct lista Lista;

/*definindo lista duplamente encadeada*/
struct lista2{
	int data;
	struct lista2 *ant;
	struct lista2 *prox;
};

typedef struct lista2 Lista2;


Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo=(Lista *)malloc(sizeof(Lista));
	novo->data=i;
	novo->prox=l;
	return novo;
}

void lst_imprime(Lista *l){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		printf("Valor: %d\n", p->data);
	}
}

int lst_vazia(Lista *l){
	if(l==NULL)
		return 1;

	else
		return 0;
}

Lista* lst_busca(Lista *l, int v){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		if(p->data==v){
			return p;
		}
	}
	if(p==NULL){
		printf("Elemento não encontrado\n");
		return NULL;
	}
}

Lista *lst_retira(Lista *l, int v){
	Lista *p=l;
	Lista *ant=NULL;
	while(p!=NULL && p->data!=v){
		ant=p;
		p=p->prox;
	}
	if(p==NULL){
		printf("Elemento não encontrado\n");
		return l;
	}
	if(ant==NULL){
		l=p->prox;
	}
	else{
		ant->prox=p->prox;
	}
	free(p);
	return l;
}

void lst_libera(Lista *l){
	Lista *p=l;
	while(p!=NULL){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}

Lista *lst_insere_ordenado(Lista *l, int v){
	Lista *novo;
	novo=(Lista *)malloc(sizeof(Lista));
	novo->data=v;
	Lista *ant=NULL;
	Lista *p=l;
	while(p!=NULL && p->data<v){
		ant=p;
		p=p->prox;
	}
	if(ant==NULL){
		novo->prox=l;
		return novo;
	}
	else{
		ant->prox=novo;
		novo->prox=p;
		return l;
	}
}

int lst_igual(Lista *l1, Lista *l2){
	Lista *p1;
	Lista *p2;
	int tam1=0, tam2=0;
	for(p1=l1;p1!=NULL;p1=p1->prox){
		tam1++;
	}
	for(p2=l2;p2!=NULL;p2=p2->prox){
		tam2++;
	}
	p1=l1;
	p2=l2;
	if(tam1!=tam2){
		return 0; //diferente
	}
	else{
		while(p1!=NULL){
			if(p1->data==p2->data){
				p1=p1->prox;
				p2=p2->prox;
			}
			else return 0;
		}
	}
	return 1; //igual
}

/*listas circulares*/
void lcirc_imprime(Lista *l){
	Lista *p=l;
	if(p){
		do{
			printf("%d ", p->data);
			p=p->prox;
		} while(p!=l);
	}
	printf("\n");
}

Lista *lcirc_transforma(Lista *l){
	Lista *p=l;
	while(p->prox!=NULL){
		p=p->prox;
	}
	if(l==NULL){
		return l;
	}
	else{
		p->prox=l;
		return l;
	}
}

void lcirc_libera(Lista *l){
	Lista *p = l;
	do{
		Lista *t = p->prox;
		free(p);
		p=t;
	} while(p != l);
}

Lista* lcirc_busca(Lista *l, int v){
	Lista *p=l;
	do{
		if(p->data==v){
			return p;
		}
		else{
			p=p->prox;
		}
	} while(p!=l);
	if(p==l){
		printf("Elemento não encontrado\n");
		return NULL;
	}
}

/*listas duplamente encadeadas*/
Lista2 *lst2_insere(Lista2 *l, int v){
	Lista2 *novo=(Lista2 *)malloc(sizeof(Lista2));
	novo->prox=l;
	novo->ant=NULL;
	novo->data=v;
	if(l!=NULL){
		l->ant=novo;
	}
	return novo;
}

Lista2 *lst2_busca(Lista2 *l, int v){
	Lista2 *p;
	for(p=l;p!=NULL;p=p->prox){
		if(p->data==v){
			return p;
		}
	}
	return NULL;
}

Lista2 *lst2_retira(Lista2 *l, int v){
	Lista2 *p;
	p=lst2_busca(l, v);
	if(p->ant==NULL){
		l=p->prox;
	}
	else if(p->prox==NULL){
		p->ant->prox=NULL;
	}
	else if(p==NULL){
		printf("Célula não encontrada\n");
	}
	else{
		p->ant->prox=p->prox;
	}
	return l;
}

// FUNCAO COMPARA LISTAS ENCADEADAS
int listaCompara(Lista * lista, Lista * lista_){
    while(lista != NULL && lista_ != NULL){
        if(lista->data != lista_->data){
            return 0;
        }
	lista = lista->prox;
	lista_ = lista_->prox;
    }
    if((lista == NULL && lista_ != NULL) || (lista != NULL && lista_ == NULL)){
        return 0;
    }
	else return 1;
}

Lista *josephus(Lista * l){
	int data;
	l = l->prox;
	while(l->data != (l->prox)->data){
		printf("%d\t%d\n", l->data, (l->prox)->data);
		for(int i=1;i<3;i++) l = l->prox;
		data = l->data;
		l = l->prox;
		l = lst_retira(l, data);
		getchar();
	}

        return l;

}
