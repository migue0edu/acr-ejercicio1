#include <stdio.h>
#include <pthread.h>

void* funcionHilo(void* params){
    int *int_params=(int *)params;
    printf("\n valor %d", *int_params);
    return NULL;
}

int main(){
    pthread_t hilo[10];
    int i;
    int j[10];
    for(i=0;i<10;i++){
        j[i]=i;
        pthread_create(&hilo[i], NULL, funcionHilo, (void *) &j[i]);
    }
    for(i=0;i<10;i++){
        pthread_join(hilo[i], NULL);
    }
    return 0;
}