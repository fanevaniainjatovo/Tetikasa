

#include <faneva.h>

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	
	GtkWidget* window;
	GtkWidget* box;
	GtkWidget* button;
	GtkWidget* table;
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	box=gtk_box_new(TRUE,0);
    table=gtk_table_new(7,8,TRUE);
	button=gtk_button_new_with_label("quitter");
	
	gtk_container_add(GTK_CONTAINER(window),box);
	
    gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 9, 1, 9);
	
	gtk_box_pack_start(GTK_BOX(box),table,TRUE,TRUE,0);
	
	g_signal_connect(button, "button-press-event" ,G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

