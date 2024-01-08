

#include <gtk/gtk.h>

typedef struct Anime{
	GtkWidget* draw;
	gint x;
	gint y;
	gdouble color[8];
	
}Anime;

void css(char* class,char* chemin,GtkWidget* widget){
   
   GtkCssProvider* css;
   GtkStyleContext* style;	
   
   style=gtk_widget_get_style_context(widget);
   gtk_style_context_add_class(style,class);
   
   css=gtk_css_provider_new();
   gtk_css_provider_load_from_file(css,g_file_new_for_path(chemin),NULL);
   
   gtk_style_context_add_provider(style,GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	}

static gboolean on_draw(GtkWidget* widget,cairo_t* cr,gpointer data){
    
    Anime* papier=g_malloc(sizeof(Anime)*3);
    papier=(Anime*)data;
	
	for(int i=0;i<8;i++){
		
	   cairo_rectangle(cr,papier[i].x,papier[i].y,50,50);
	      
	       if(i==0){papier[i].color[0]=0;
			        papier[i].color[1]=0;
			        papier[i].color[2]=1;
			       }
			       
	       else if(i==1){papier[i].color[0]=0;
			             papier[i].color[1]=1;
			             papier[i].color[2]=0;
			            }
			       
	       else if(i==2){papier[i].color[0]=1;
			             papier[i].color[1]=0;
		                 papier[i].color[2]=0;
		                }
		                
	       else if(i==3){papier[i].color[0]=1;
			             papier[i].color[1]=1;
		                 papier[i].color[2]=0;
		                } 
	       
	       else if(i==4){papier[i].color[0]=1;
			             papier[i].color[1]=0;
		                 papier[i].color[2]=1;
		                }
		                 
	       else if(i==5){papier[i].color[0]=0;
			             papier[i].color[1]=1;
		                 papier[i].color[2]=1;
		                }
		                    
	       else if(i==6){papier[i].color[0]=1;
			             papier[i].color[1]=1;
		                 papier[i].color[2]=1;
		                }
		                
	       else if(i==7){papier[i].color[0]=0;
			             papier[i].color[1]=0;
		                 papier[i].color[2]=0;
		                } 
	      
	      
	   cairo_set_source_rgb(cr,papier[i].color[0],papier[i].color[1],papier[i].color[2]);  
	   cairo_fill(cr);
	   
	   }
      
	   
    return FALSE;	
	}

static gboolean animate(gpointer data){
    
    Anime* papier=g_malloc(sizeof(Anime)*8);
    papier=(Anime*)data;
    
     for(int i=0;i<8;i++){
		
 if( (papier[i].x>0 && papier[i].x<1200) && (papier[i].y>0 && papier[i].y<600) ){   		
  	if(rand()%8==0){papier[i].x+=10;}
    else if(rand()%8==1){papier[i].y+=10;}
    else if(rand()%8==2){papier[i].x+=10;papier[i].y+=10;}
    else if(rand()%8==3){papier[i].x-=10;}
    else if(rand()%8==4){papier[i].y-=10;}
    else if(rand()%8==5){papier[i].x-=10;papier[i].y-=10;}
    else if(rand()%8==6){papier[i].x-=10;papier[i].y+=10;}
    else if(rand()%8==7){papier[i].x+=10;papier[i].y-=10;}
   }  
 
 else{
	if(papier[i].x<=0){papier[i].x=0;papier[i].x+=10;}
	else if(papier[i].x>=1200){papier[i].x=0;papier[i].x-=10;}
 
	if(papier[i].y<=0){papier[i].y=0;papier[i].y+=10;}  
	else if(papier[i].y>=600){papier[i].y=0;papier[i].y-=10;} 
    }
        
        g_print("%d\t%d\n",papier[i].x,papier[i].y);
	    gtk_widget_queue_draw(papier[i].draw);
	    
	    }
	  
	   
	return TRUE;
	}

int main(int argc, char **argv)
{
    gtk_init(&argc,&argv);
    GtkWidget* window;
    Anime* papier=(Anime*)malloc(sizeof(Anime)*8);
    
    srand(time(NULL));
    
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),1500,750);
    
    css("win","/home/faneva/html/css/edit.css",window);
    
      for(int i=0;i<8;i++){
        
		papier[i].draw=gtk_drawing_area_new();
		gtk_container_add(GTK_CONTAINER(window),papier[i].draw);
         
        papier[i].x=rand()%1200;
		papier[i].y=rand()%600;
	    
	     for(int j=0;j<8;j++){ 
	        papier[i].color[j]=0;
		    }
	   	
	   	g_signal_connect(G_OBJECT(papier[i].draw),"draw",G_CALLBACK(on_draw),papier);
		g_timeout_add(300,animate,papier);
	     
	     }
    
    gtk_widget_show_all(window);
    gtk_main();
    
    	
	return 0;
}
