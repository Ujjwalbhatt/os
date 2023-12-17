// // Program to create Threads

// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<pthread.h>
// void *thread_function(void *arg);
//  int i,j;
//  int main() {
//  pthread_t a_thread;  //thread declaration

//  pthread_create(&a_thread, NULL, thread_function, NULL); 
//thread is created
 pthread_join(a_thread, NULL); //process waits for thread to finish . //Comment this line to see the difference
 printf("Inside Main Program\n");
 for(j=20;j<25;j++)
 {
 printf("%d\n",j);
 sleep(1);
 }
//  }


// void *thread_function(void *arg) {    
// // the work to be done by the thread is defined in this function
//  printf("Inside Thread\n");
//  for(i=0;i<5;i++)
//  {
//  printf("%d\n",i);
//  sleep(1);
//  }
//  }
// // ======================


// #include<pthread.h>
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                       void *(*start_routine) (void *), void arg);

// // The first parameter is the buffer which will contain the ID of the new thread, if pthread_create is successful. The second parameter specifies the attributes of the thread. This parameter is generally NULL until you want to change the default settings. The third parameter is the name the function which the thread will execute. Hence, everything that you want the thread to do should be defined in this function. Lastly, the fourth parameter is the input to the function in the third parameter. If the function in the third parameter does not take any input then the fourth parameter is NULL.
// // To compile any program which involves creation of thread(s) use pthread library (lpthread)
// // Suppose the above program is named “Thread.c”, then to compile write
// // $gcc Thread.c -lpthread
// // To run the command remains same
// // $./a.out


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg); // Thread function declaration

int main() {
    pthread_t a_thread; // Thread declaration

    // Creating the thread
    if(pthread_create(&a_thread, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Uncomment the next line to wait for the thread to finish
    // pthread_join(a_thread, NULL);

    printf("Inside Main Program\n");
    for(int j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1);
    }

    return 0;
}

void *thread_function(void *arg) {
    printf("Inside Thread\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}
