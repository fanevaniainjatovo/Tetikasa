

#include <faneva.h>

int main(int argc, char **argv)
{  
	gtk_init(&argc,&argv);
	
	GtkWidget* window;
	GtkWidget* box;
	GtkWidget* test;
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	box=gtk_box_new(TRUE,6);
	test=gtk_button_new_with_label("Veloma ianao");
	
	gtk_container_add(GTK_CONTAINER(window),box);
    gtk_box_pack_start(GTK_BOX(box),test,FALSE,TRUE,9);	
	
	gtk_widget_show_all(window);
	gtk_main();
	return EXIT_SUCCESS;
}

