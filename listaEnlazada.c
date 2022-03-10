#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};

typedef struct nodo tnodo;
typedef tnodo* tnodoptr;

tnodo *creaNodo(int);
int insertaInicio(tnodoptr*,int);
int insertaFinal(tnodoptr*,int);
int eliminaInicio(tnodoptr*);
int eliminaFinal(tnodoptr*);
int eliminaTodo(tnodoptr*);
void imprimeLista(tnodoptr*);

int main(void) {
    tnodoptr cab = NULL;
    int op,entero, success;

    do {
        printf("          Bienvenido al programa listaEnlazada\n");
        printf("En este programa se manipulan listas enlazadas con enteros\n");
        printf("          Seleccione la accion que necesite:\n");
        printf("                1: Inserta al inicio\n");
        printf("                2: Inserta al final\n");
        printf("                3: Elimina el inicio\n");
        printf("                4: Elimina el final\n");
        printf("                5: Elimina todo\n");
        printf("                6: Imprime lista\n");
        printf("                7: Salir del programa\n");
        
        scanf("%d",&op);

        switch(op) {
            case 1:
                printf("Numero a insertar: ");
                scanf("%d",&entero);
                success = insertaInicio(&cab,entero);
                if(success == 0) {printf("                Insertado\n");}
                else {printf("                Error al insertar\n");}
            break;
            case 2:
                printf("Numero a insertar: ");
                scanf("%d",&entero);
                success = insertaFinal(&cab,entero);
                if(success == 0) {printf("                Insertado\n");}
                else {printf("                Error al insertar\n");}
            break;
            case 3:
                success = eliminaInicio(&cab);
                if(success == 0) {printf("                Eliminado de la lista\n");}
                else {printf("                Error al eliminar\n");}
            break;
            case 4:
                success = eliminaFinal(&cab);
                if(success == 0) {printf("                Eliminado de la lista\n");}
                else {printf("                Error al eliminar\n");}
            break;
            case 5:
                success = eliminaTodo(&cab);
                if(success == 0) {printf("                Lista eliminada\n");}
                else {printf("                Error al eliminar\n");}
            break;
            case 6:
                imprimeLista(&cab);
            break;
            case 7:
                success = eliminaTodo(&cab);
                if(success == 0) {printf("                Lista elimanada\n");}
                else {printf("                Error al eliminar\n");}
                return 0;
            break;
            default:
                success = eliminaTodo(&cab);
                if(success == 0) {printf("                Lista eliminada\n");}
                else {printf("                Error al eliminar\n");}
                return 0;
        }
    }while(op != 7);
}

tnodo* creaNodo(int info) {
    tnodo *nuevo = (tnodo*)malloc(sizeof(tnodo));
    nuevo->sig = NULL;
    if (nuevo == NULL) {
        printf("Error al crear un nodo/n");
        exit(EXIT_FAILURE);
    }
    nuevo->info=info;
    return nuevo;
}

void imprimeLista(tnodoptr *cab) {
    if(*cab == NULL) {
        printf("La lista no tiene elementos\n");
        return;
    }
    tnodo *aux = *cab;
    printf("La lista es: ");
    while(aux != NULL) {
        printf("%d ",aux->info);
        aux = aux->sig;
    }
    printf("\n");
}

//La cabecera va referenciada
int insertaInicio(tnodoptr *cab, int info) {
    tnodo *nuevo = creaNodo(info);
    tnodo *aux;
    if(*cab == NULL) {
        *cab = nuevo;
        return 0;
    }
    aux = *cab;
    nuevo->sig = aux;
    *cab = nuevo;
    return 0;
}

int insertaFinal(tnodoptr *cab, int info) {
    tnodo *nuevo = creaNodo(info);
    tnodoptr aux;

    if(*cab == NULL) {
        *cab = nuevo;
        return 0;
    }
    aux = *cab;
    while(aux->sig != NULL) {
        aux = aux->sig;
    }
    aux->sig = nuevo;
    return 0;
}

int eliminaInicio(tnodoptr *cab) {
    if(*cab == NULL) {
        printf("La lista no tiene elementos\n");
        return -1;
    }
    
    tnodoptr aux = *cab;
    *cab = aux->sig;
    free(aux);
    return 0;
}

int eliminaFinal(tnodoptr *cab) {
    if(*cab == NULL) {
        printf("La lista no tiene elementos\n");
        return -1;
    }

    tnodoptr aux = *cab;
    tnodoptr aux1 = NULL;

    if(aux->sig == NULL) {
        free(aux);
        *cab = NULL;
        return 0;
    }

    while(aux->sig != NULL) {
        aux1 = aux;
        aux = aux->sig;
    }
    free(aux);
    aux1->sig = NULL;
    return 0;
}

int eliminaTodo(tnodoptr *cab) {
    if(*cab == NULL) {
        printf("La lista no tiene elementos\n");
        return -1;
    }
    
    while(*cab != NULL) {
        tnodoptr aux = *cab;
        *cab = aux->sig;
        free(aux);
    }
    return 0;
}