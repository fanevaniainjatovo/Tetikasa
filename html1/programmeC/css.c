void css(char* chemin){
	
	FILE* css=fopen(chemin,"r");
    char style;
    
    printf("<style type=text/css>\n");
    printf("<!--\n");
  
    while(style!=EOF){style=fgetc(css);printf("%c",style);}
    
    printf("\n-->");
    printf("</style>\n");
	
	fclose(css);
	}

