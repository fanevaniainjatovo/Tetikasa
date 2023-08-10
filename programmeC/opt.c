
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int opt=getopt(argc,argv,"sgdytcuy");
	
  
	  
	     if(opt=='s'){printf("sarindra");}
	     else if(opt=='g'){printf("guianna");}
	     else if(opt=='g'){printf("debora");}
	     else if(opt==-1){printf("izy rehetra");}
	  
	 
	     
	return 0;
}

