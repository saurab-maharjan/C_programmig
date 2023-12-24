#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

/*
Author : Gihan De Silva
gihansblog.com
Purpose: This program displays the string in the label,which user enter in the text entry.
*/
GladeXML *xml;
GtkWidget *widget;

int main(int argc, char *argv[])
{

gtk_init(&argc, &argv);

/*import glade file*/
xml = glade_xml_new(“TextEntry.glade”, NULL, NULL);

/* get a widget (useful if you want to change something) */
widget = glade_xml_get_widget(xml, “mainWindow”);

/* connect signal handlers */
glade_xml_signal_autoconnect(xml);

/*show widget*/
gtk_widget_show (widget);

gtk_main();

return 0;
}