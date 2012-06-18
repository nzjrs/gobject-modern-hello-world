#include <gtk/gtk.h>
#include <math.h>

#include "colorbox.h"
#include "point.h"

#define ABC_COLOR_BOX_DEFAULT_SIZE 100

struct _AbcColorBoxPrivate {
    AbcPoint *point;
};


static gboolean
abc_color_box_draw (GtkWidget *widget, cairo_t *cr)
{
    AbcColorBox *self = ABC_COLOR_BOX(widget);
    gint width = gtk_widget_get_allocated_width (widget);
    gint height = gtk_widget_get_allocated_height (widget);

	cairo_set_source_rgb (cr, 1, 0, 0);
    cairo_rectangle(cr, 0, 0, width, height);
	cairo_fill (cr);

    if (self->priv->point) {
        cairo_arc(cr, self->priv->point->x, self->priv->point->y, 5.0, 0.0, 2 * M_PI);
	    cairo_set_source_rgb (cr, 0, 1, 0);
        cairo_fill(cr);
    }

    return FALSE;
}

static void
abc_color_box_get_preferred_width (GtkWidget *widget, gint *minimum_size, gint *natural_size)
{
  if (minimum_size)
    *minimum_size = ABC_COLOR_BOX_DEFAULT_SIZE;
  if (natural_size)
    *natural_size = ABC_COLOR_BOX_DEFAULT_SIZE;
}

static void
abc_color_box_get_preferred_height (GtkWidget *widget, gint *minimum_size, gint *natural_size)
{
  if (minimum_size)
    *minimum_size = ABC_COLOR_BOX_DEFAULT_SIZE;
  if (natural_size)
    *natural_size = ABC_COLOR_BOX_DEFAULT_SIZE;
}

static void
abc_color_box_class_init (AbcColorBoxClass *class)
{
	GtkWidgetClass *widget_class;

	g_type_class_add_private (class, sizeof (AbcColorBoxPrivate));

	widget_class = GTK_WIDGET_CLASS (class);

	widget_class->draw = abc_color_box_draw;
    widget_class->get_preferred_width = abc_color_box_get_preferred_width;
    widget_class->get_preferred_height = abc_color_box_get_preferred_height;
}

static void
abc_color_box_init (AbcColorBox *clock)
{
	clock->priv = G_TYPE_INSTANCE_GET_PRIVATE (clock, ABC_TYPE_COLOR_BOX, AbcColorBoxPrivate);
    gtk_widget_set_has_window (GTK_WIDGET (clock), FALSE);
}

void
abc_color_box_set_point (AbcColorBox *box, AbcPoint *point)
{
    AbcColorBox *self = ABC_COLOR_BOX(box);
    self->priv->point = point;
    g_object_ref(point);
}

GtkWidget *
abc_color_box_new (void)
{
	return g_object_new (ABC_TYPE_COLOR_BOX, NULL);
}

G_DEFINE_TYPE (AbcColorBox, abc_color_box, GTK_TYPE_WIDGET);
