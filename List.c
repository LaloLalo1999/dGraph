#include "List.h"
#include <stdlib.h>
#include <string.h>

struct strNode{
	Type data;
	struct strNode *prior;
	struct strNode *next;
};

typedef struct strNode *Node;

struct strList{
	Node first;
	Node last;
	unsigned int size;
	size_t data_size;
};

List listCreate(size_t bytes){
	List new=malloc(sizeof(struct strList));
	new->first=NULL;
	new->last=NULL;
	new->size=0;
	new->data_size=bytes;
	return new;
}

unsigned int listSize(List lt){
	if(lt!=NULL)
		return lt->size;
	return 0;
}

Node newNode(Type data, size_t bytes){
	Node new=malloc(sizeof(struct strNode));
	new->data=malloc(bytes);
	memcpy(new->data, data, bytes);
	new->prior=NULL;
	new->next=NULL;
	return new;
}

void listAdd(List lt, Type data){
	if(lt!=NULL){
		Node new=newNode(data, lt->data_size);
		if(listSize(lt)==0){
			//La lista esta vac�a
			lt->first=new;
			lt->last=new;
			lt->size=1;
		}
		else{
			//La lista NO esta vac�a
			lt->last->next=new;
			new->prior=lt->last;
			lt->last=new;
			lt->size+=1;
		}
	}
}

Type listGet(List lt, int p){
	if(lt!=NULL){
		//Validar que p se encuentre en el rango v�lido
		if((p>=0)&&(p<lt->size)){
			Node current=lt->first;
			int i=0;
			//Desplazar current hasta llegar a p
			while(i<p){
				current=current->next;
				i++;
			}
			//Ya estamos en el lugar correcto
			Type data=malloc(lt->data_size);
			memcpy(data, current->data, lt->data_size);
			return data;
		}
	}
	return NULL;
}

int listSearch(List lt, Type data){
	if(lt!=NULL){
		Node current=lt->first;
		int i=0;
		while(current!=NULL){
			if(memcmp(current->data, data, lt->data_size)==0)
				return i;
			current=current->next;
			i++;
		}
	}
	return -1;
}

Type listRemove(List lt, int p){
	if(lt!=NULL){
		//Validar que p se encuentre en el rango v�lido
		if((p>=0)&&(p<lt->size)){
			Node current=lt->first;
			if(lt->size==1){
				//La lista tiene un �nico elemento

				//Para no perder en donde esta: data
				Type temp=lt->first->data;

				//eliminar el nodo
				free(lt->first);

				//actualizar enlaces de first y last
				lt->first=NULL;
				lt->last=NULL;
				lt->size=0;
				return temp;
			}
			else{
				//Cuando tenemos dos o m�s elementos

				//�Vamos a eliminar el primer elemento?
				if(p==0){
					//Para no perder a data
					Type temp_data=lt->first->data;
					//Para no perder el nodo que vamos a remover
					Node temp_node=lt->first;

					//Actualizo a first
					lt->first=lt->first->next;

					//Actualizo el prior del nuevo primer nodo
					lt->first->prior=NULL;

					free(temp_node);
					lt->size-=1;

					return temp_data;

				}
				//�Vamos a eliminar el �ltimo elemento?
				if(p==lt->size-1){


				}

				int i=0;
				//Desplazar current hasta llegar a p
				while(i<p){
					current=current->next;
					i++;
				}
				//Ya estamos en el lugar correcto

				Type data=malloc(lt->data_size);
				memcpy(data, current->data, lt->data_size);
				return data;
			}
		}
	}
	return NULL;
}

void listDestroy(List lt){
	if(lt!=NULL){
		Node current=lt->first;
		while(current!=NULL){
			Node temp=current;
			current=current->next;
			free(temp->data);
			free(temp);
		}
		free(lt);
	}
}