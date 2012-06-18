#include <gtk/gtk.h>

#include "point.h"
#include "colorbox.h"

int
main (int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *clock;
    AbcPoint *point;

    gtk_init (&argc, &argv);

    point = g_object_new (ABC_TYPE_POINT, "x", 5, "y", 17, NULL);
    clock = gtk_color_box_new ();
    gtk_color_box_set_point (clock, point);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_add (GTK_CONTAINER (window), clock);
    g_signal_connect (window, "destroy",
        G_CALLBACK (gtk_main_quit), NULL);

    gtk_widget_show_all (window);
    gtk_main ();

    return 0;
}
