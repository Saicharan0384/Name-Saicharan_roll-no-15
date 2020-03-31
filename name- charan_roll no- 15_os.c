#include<pthread.h>
#include<stdio.h>
#include<conio.h>
int res_available=100; // to assign available resources value to a variable
pthread_mutex_t l;
void* increment_resources(int count) // void pointer with count argument for increment
{ 
	pthread_mutex_lock(&l);
	int z;
	z=res_available;
	z=z+count;
	sleep(1); // delay given 1 second
	res_available=z;
	printf("Resources released  \n\n");
	pthread_mutex_unlock(&l);
}
void* decrement_resources(int count) // void pointer with count argument for decrement
{
	if(res_available<count)
	 printf("No resources available \n\n");
	else{
		pthread_mutex_lock(&l);
		int z;
		z=res_available;
		z=z-count;
		sleep(1);
		res_available=z;
		printf("Resources allocated  \n\n");
		pthread_mutex_unlock(&l);
	}
}
int main(){
	pthread_mutex_init(&l, NULL);
    pthread_t inc_thread,dec_thread;
    while(1)
	{
    	 int inc_res,dec_res;
         printf("Enter increment resources and decrement resources values: \n");
         scanf("%d %d",&inc_res,&dec_res);
	     pthread_create(&inc_thread,NULL,increment_resources,inc_res);
         pthread_create(&dec_thread,NULL,decrement_resources,dec_res);
	     pthread_join(inc_thread, NULL);
         pthread_join(dec_thread,NULL);
	     printf("Resources Available -> %d \n\n",res_available);
	}
	getch();
}



