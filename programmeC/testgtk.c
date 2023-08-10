
#include <faneva.h>

typedef struct fenetre{
	
	GtkWidget* window;
	GtkWidget* box;
	GtkWidget* button1;
	GtkWidget* button2;
	GtkWidget* button3;
	GtkWidget* button4;
	
	
	}fenetre;
	
void menu();
gboolean retour(GtkWidget* button,GdkEventButton* event,gpointer data);
gboolean on_click_button(GtkWidget* button,GdkEventButton* event,gpointer data);
  
int main(int argc,char** argv){
	
	gtk_init(&argc, &argv);
	menu();
	gtk_main();
	
	return 0;	
	
  }


gboolean retour(GtkWidget* button,GdkEventButton* event,gpointer data){
	
	
	fenetre* myw=(fenetre*)data;
	
	gtk_widget_destroy(myw->window);
	myw->window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	menu();
	
    return FALSE;
	}


gboolean on_click_button(GtkWidget* button,GdkEventButton* event,gpointer data){
	
	fenetre* myw=(fenetre*)data;
	
	
	gtk_widget_destroy(myw->box);
	
	myw->box=gtk_box_new(TRUE,10);
	GtkWidget* label1;
	label1=gtk_label_new("TONGASOA");
    
    GtkWidget* quit;
     
    quit=gtk_button_new_from_stock(GTK_STOCK_QUIT); 
    myw->button1=gtk_button_new_with_label("RETOUR"); 
    g_signal_connect(myw->button1,"button-press-event" ,G_CALLBACK(retour),myw); 
      
    gtk_container_add(GTK_CONTAINER(myw->window),myw->box); 
    gtk_box_pack_start(GTK_BOX(myw->box),label1,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(myw->box),myw->button1,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(myw->box),quit,FALSE,FALSE,0);
    gtk_widget_show_all(myw->window);
	
	return TRUE;
	
	}  

	
void menu(){
	
	fenetre* myw=(fenetre*)malloc(sizeof(fenetre));
	
	myw->window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	myw->box=gtk_box_new(TRUE,0);
	myw->button1=gtk_button_new_with_label("Lyrics Translating");
	myw->button2=gtk_button_new_with_label("Singer's name reordering");
	myw->button3=gtk_button_new_with_label("Guess the song");
	myw->button4=gtk_button_new_with_label("QUITTER");
	
	gtk_window_set_title(GTK_WINDOW(myw->window),"VAZO MISOMA");
	gtk_window_set_position(GTK_WINDOW(myw->window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(myw->window),1000,1000);
    gtk_window_set_icon_from_file(GTK_WINDOW(myw->window),"/home/faneva/mimi.jpg",NULL);
	
	gtk_container_add(GTK_CONTAINER(myw->window),myw->box);
	
	gtk_box_pack_start(GTK_BOX(myw->box),myw->button1,TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(myw->box),myw->button2,TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(myw->box),myw->button3,TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(myw->box),myw->button4,TRUE,TRUE,0);
	
	
	g_signal_connect(myw->button1,"button-press-event",(GCallback)on_click_button,myw);
	g_signal_connect(myw->button2,"button-press-event",(GCallback)on_click_button,myw);
	g_signal_connect(myw->button3,"button-press-event",(GCallback)on_click_button,myw);
	g_signal_connect(myw->button4,"button-press-event",G_CALLBACK(gtk_main_quit), NULL); 
	
	gtk_widget_show_all(myw->window);
	
	}	

  
