
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

typedef struct Anime{
	GtkWidget* fix;
	GtkWidget* label[10];
	gint x[10];
	gint velx[10];
	gint y[10];
	gint vely[10];
	
}Anime;

void instaDesordre(int* x,int* y){
	
	srand(time(NULL));
	

	*x=1000*(float)(rand())/RAND_MAX;
	*y=500*(float)(rand())/RAND_MAX;
		
 if( (*x>0 && *x<1200) && (*y>0 && *y<600) ){   		
  	if(rand()%8==0){*x+=10;}
    else if(rand()%8==1){*y+=10;}
    else if(rand()%8==2){*x+=10;*y+=10;}
    else if(rand()%8==3){*x-=10;}
    else if(rand()%8==4){*y-=10;}
    else if(rand()%8==5){*x-=10;*y-=10;}
    else if(rand()%8==6){*x-=10;*y+=10;}
    else if(rand()%8==7){*x+=10;*y-=10;}
   }  
 
 else{
	if(*x<=0){*x=0;*x+=10;}
	else if(*x>=1200){*x=0;*x-=10;}
 
	if(*y<=0){*y=0;*y+=10;}  
	else if(*y>=600){*y=0;*y-=10;} 
    }
    
   }

void css(char* class,char* chemin,GtkWidget* widget){
   
   GtkCssProvider* css;
   GtkStyleContext* style;	
   
   style=gtk_widget_get_style_context(widget);
   gtk_style_context_add_class(style,class);
   
   css=gtk_css_provider_new();
   gtk_css_provider_load_from_file(css,g_file_new_for_path(chemin),NULL);
   gtk_style_context_add_provider(style,GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	}

static gboolean animate(gpointer data){
	
	Anime* insta=(Anime*)data;
	
	for(int i=0;i<10;i++){
	
	if( (insta->x[i]<0 || insta->x[i]>1000) ){   		
  	   insta->velx[i]=-insta->velx[i];
       }  
 
    if( (insta->y[i]<0 || insta->y[i]>500) ){
	   insta->vely[i]=-insta->vely[i]; 	
		}
	
	   insta->x[i]+=insta->velx[i];
	   insta->y[i]+=insta->vely[i];
	   
	   printf("%d %d\t%d %d\n",insta->x[i],insta->y[i],insta->velx[i],insta->vely[i]);
	   
	   gtk_fixed_move(GTK_FIXED(insta->fix),insta->label[i],insta->x[i],insta->y[i]); 	
		
	   gtk_widget_queue_draw(GTK_WIDGET(insta->fix));
		}
		
	    	
	return TRUE;
	
	}

int main(int argc, char **argv){
    
   gtk_init(&argc,&argv); 
   
   srand(time(NULL));
   
   GtkWidget* win;
   GtkWidget* input;
   Anime* insta=malloc(sizeof(Anime));
   
   win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_default_size(GTK_WINDOW(win),1000,500);
   
   insta->fix=gtk_fixed_new();
   input=gtk_entry_new();
   css("entry","/home/faneva/css/edit.css",input);  
   gtk_widget_set_size_request(input,26*10,50);
   gtk_widget_grab_focus(input);
   
   gtk_fixed_put(GTK_FIXED(insta->fix),input,500,375);
   css("win","/home/faneva/css/edit.css",win);
   
   const gchar artiste[11]="Ambondrona";
      
   for(int i=0;i<10;i++){
	   
	   char titi[2];
	   sprintf(titi,"%c",artiste[i]);
	   insta->label[i]=gtk_button_new_with_label(titi);
	   gtk_widget_set_size_request(insta->label[i],50,50);
	   
	   insta->x[i]=rand()%1000;
	   insta->velx[i]=(rand()%2==0)?-1:1;
	   insta->y[i]=rand()%500;
	   insta->vely[i]=(rand()%2==1)?-2:2;
	     
       gtk_fixed_put(GTK_FIXED(insta->fix),insta->label[i],insta->x[i],insta->y[i]);
       css("button","edit.css",insta->label[i]);  
       g_timeout_add(300,animate,insta);
      }
        
   gtk_container_add(GTK_CONTAINER(win),insta->fix);
   gtk_widget_show_all(win);	
   
   gtk_main();
   
   
   return 0;
    
   }

