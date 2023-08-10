
#include <string.h>
#include "/home/faneva/programmeC/Machine.h"

void tri(Machine *pc,int strn){
	
 for(int j=0;j<strn;j++){	
	for(int i=0;i<strn;i++){
		if(strcmp(pc[i].label,pc[j].label)>0 && i<strn-1 ){
			Machine tmp;
			tmp=pc[j];
			pc[j]=pc[i];
			pc[i]=tmp;
			}
		}	
	 }
   }

