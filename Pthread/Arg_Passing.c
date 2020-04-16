//Darshan Mistry//
//Argument passing using a function...

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct argum //use a function by a struct

{
    char* user_name;
    int user_age;
};

void *func(void *input) //creat a void function for argumnet 

{
    printf("name: %s\n", ((struct argum*)input)->user_name);
    printf("age: %d\n", ((struct argum*)input)->user_age);
}

int main() {
    struct argum *Darshan = (struct argum *)malloc(sizeof(struct argum));
    char darshan[] = "Darshan";
    Darshan->user_name = darshan;
    Darshan->user_age = 24;

    pthread_t tid;
    pthread_create(&tid, NULL, func, (void *)Darshan); //pass a argument by pthread
    pthread_join(tid, NULL);
    return 0;
}