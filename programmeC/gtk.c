


#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
  
  GtkWidget *mafenetre;  
  GtkWidget *maboite;// declaration d'1 box  
  GtkWidget *barredemenu;// la barre de menu  
  GtkWidget *lemenu; // le menu  
  GtkWidget *litem; // les items  
  
  gtk_init(&argc, &argv);  
  
  mafenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
  maboite=gtk_box_new(FALSE, 0);  
  gtk_window_set_title(GTK_WINDOW(mafenetre), "Vazo Misoma");  
  gtk_window_set_position(GTK_WINDOW(mafenetre), GTK_WIN_POS_CENTER);  
  gtk_window_set_default_size(GTK_WINDOW(mafenetre), 400, 200);  
  gtk_window_set_icon_from_file(GTK_WINDOW(mafenetre), "/home/faneva/mimi.jpg", NULL);  
  
  gtk_container_add(GTK_CONTAINER(mafenetre), maboite);  
  
  barredemenu = gtk_menu_bar_new(); //initialisation de la barre de menu  
  lemenu = gtk_menu_new();// initialisation du menu  
  
// création des items  
  litem = gtk_menu_item_new_with_label("Malagasy");  
  gtk_menu_shell_append(GTK_MENU_SHELL(lemenu), litem);  
  litem = gtk_menu_item_new_with_label("Francais");  
  gtk_menu_shell_append(GTK_MENU_SHELL(lemenu), litem);  
  litem = gtk_menu_item_new_with_label("Anglais");  
  gtk_menu_shell_append(GTK_MENU_SHELL(lemenu), litem);  
  litem = gtk_menu_item_new_with_label("Espagnol");  
  gtk_menu_shell_append(GTK_MENU_SHELL(lemenu), litem);  
  litem = gtk_menu_item_new_with_label("Chinois");  
  gtk_menu_shell_append(GTK_MENU_SHELL(lemenu), litem);  
  
 litem = gtk_menu_item_new_with_label("Quitter");  
  gtk_menu_shell_append(GTK_MENU_SHELL(lemenu), litem);  
  //signal permettant de fermer la fenêtre si on clique sur Quitter  
  g_signal_connect(litem, "activate" ,G_CALLBACK(gtk_main_quit), NULL);  
  // fin de la création des items  
  
  //Ajout du menu  
  litem = gtk_menu_item_new_with_label("Langue");  
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(litem), lemenu);  
 // Ajout des items dans la barre  
  gtk_menu_shell_append(GTK_MENU_SHELL(barredemenu), litem);  
  //Ajout de la barre dans la fenêtre  
  gtk_box_pack_start(GTK_BOX(maboite), barredemenu, FALSE, FALSE, 3);  
  gtk_widget_show_all(mafenetre);  
  
  gtk_main();  
  
	return 0;
}

