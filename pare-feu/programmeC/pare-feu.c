#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char* entry=getenv("QUERY_STRING");
	
	char action[40];
	char chain[40];

	sscanf(entry,"%*[^=]=%[^&]&%*[^=]=%[^\n]",action,chain);

	printf("Content-type: text/html\n\n");
	printf("<h1>%s %s</h1>",action,chain);

	return 0;
}
