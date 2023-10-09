#include <stdio.h>
#include <pthread.h>
// Compile with -pthread

int sum = 0; //shared
pthread_mutex_t lock;

void *countgold(void *param) {
	int i; // local to each thread
	for (i = 0; i < 10000000; i++) {
		pthread_mutex_lock(&lock);
		sum += 1;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main() {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, countgold, NULL);
  pthread_create(&tid2, NULL, countgold, NULL);

  //Wait for both threads to finish:
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  printf("ARRRRG sum is %d\n", sum);
  return 0;
}
