#include <linux/cprocessinf.h>
#include <sys/types.h>
#include <stdio.h>

struct prcdata{
	long prio; /* calculated with (20-process'es nice value) */
	long weight; /* calculated with process'es counter value + prio */
	pid_t pid; /* process id*/
	pid_t pidparent; /* process id of parent process*/
	int processcount; /* number of process of owner of current process. */
}

void printAll(struct *prcdata data_1);//check



main(){
	
  struct prcdata *data_1 = (struct prcdata*) malloc(sizeof(struct prcdata)); // check
  struct prcdata *data_2 = (struct prcdata*) malloc(sizeof(struct prcdata)); //check
  
  long nicev = 100; //

  
  //Test Case 1 
 	cprocessinf(data_1,200,100);//check
	printAll(data_1);//check
 
 
	//Test Case 2 
	//cprocessinf(data_2,100,nicev);//check
	//cprocessinf(data_1,200,100);//check
	

}

void printAll(struct *prcdata data_1){//check


  printf("prioData_1: %f \n",data_1->prio);//check
  printf("weightData_1: %f \n",data_1->weight);//check
  printf("processCountData_1: %d \n",data_1->processcount);//check

}

