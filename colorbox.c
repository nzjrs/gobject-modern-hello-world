/**
 * clock.c
 *
 * A GTK+ widget that implements a clock face
 *
 * (c) 2005, Davyd Madeley
 *
 * Authors:
 *   Davyd Madeley  <davyd@madeley.id.au>
 */

#include <gtk/gtk.h>
#include <math.h>

#include "colorbox.h"
#include "point.h"

#define GTK_COLOR_BOX_DEFAULT_SIZE 100

struct _GtkColorBoxPrivate {
    AbcPoint *point;
};


static gboolean
gtk_color_box_draw (GtkWidget *widget, cairo_t *cr)
{
    gint width, height;
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);

	cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_rectangle(cr, 0, 0, width, height);
	cairo_stroke (cr);

    return FALSE;
}

static void
gtk_color_box_get_preferred_width (GtkWidget *widget, gint *minimum_size, gint *natural_size)
{
  if (minimum_size)
    *minimum_size = GTK_COLOR_BOX_DEFAULT_SIZE;
  if (natural_size)
    *natural_size = GTK_COLOR_BOX_DEFAULT_SIZE;
}

static void
gtk_color_box_get_preferred_height (GtkWidget *widget, gint *minimum_size, gint *natural_size)
{
  if (minimum_size)
    *minimum_size = GTK_COLOR_BOX_DEFAULT_SIZE;
  if (natural_size)
    *natural_size = GTK_COLOR_BOX_DEFAULT_SIZE;
}

static void
gtk_color_box_class_init (GtkColorBoxClass *class)
{
	GtkWidgetClass *widget_class;

	g_type_class_add_private (class, sizeof (GtkColorBoxPrivate));

	widget_class = GTK_WIDGET_CLASS (class);

	widget_class->draw = gtk_color_box_draw;
    widget_class->get_preferred_width = gtk_color_box_get_preferred_width;
    widget_class->get_preferred_height = gtk_color_box_get_preferred_height;
}

static void
gtk_color_box_init (GtkColorBox *clock)
{
	clock->priv = G_TYPE_INSTANCE_GET_PRIVATE (clock, GTK_TYPE_COLOR_BOX, GtkColorBoxPrivate);
    gtk_widget_set_has_window (GTK_WIDGET (clock), FALSE);
}

void
gtk_color_box_set_point (GtkWidget *box, AbcPoint *point)
{

}

GtkWidget *
gtk_color_box_new (void)
{
	return g_object_new (GTK_TYPE_COLOR_BOX, NULL);
}

G_DEFINE_TYPE (GtkColorBox, gtk_color_box, GTK_TYPE_WIDGET);
