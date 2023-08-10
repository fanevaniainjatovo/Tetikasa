#include <stdlib.h>
#include <gtk/gtk.h>
int main (int argc, char **argv)
{

GtkWidget *p_window = NULL;
/* Initialisation de GTK+ */
gtk_init (&argc, &argv);
/* Creation de la fenetre principale de notre application */
p_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
g_signal_connect (G_OBJECT (p_window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
/* Affichage de la fenetre principale */
gtk_widget_show (p_window);
/* Lancement de la boucle principale */
gtk_main ();
return EXIT_SUCCESS;

}
