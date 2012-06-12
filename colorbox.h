/**
 * clock.h
 *
 * A GTK+ widget that implements a clock face
 *
 * (c) 2005, Davyd Madeley
 *
 * Authors:
 *   Davyd Madeley  <davyd@madeley.id.au>
 */

#ifndef __GTK_COLOR_BOX_H__
#define __GTK_COLOR_BOX_H__

#include <gtk/gtk.h>
#include "point.h"

G_BEGIN_DECLS

#define GTK_TYPE_COLOR_BOX		(gtk_color_box_get_type ())
#define GTK_COLOR_BOX(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_COLOR_BOX, GtkColorBox))
#define GTK_COLOR_BOX_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_COLOR_BOX, GtkColorBoxClass))
#define GTK_IS_COLOR_BOX(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_COLOR_BOX))
#define GTK_IS_COLOR_BOX_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), EFF_TYPE_COLOR_BOX))
#define GTK_COLOR_BOX_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_COLOR_BOX, GtkColorBoxClass))

typedef struct _GtkColorBoxPrivate  GtkColorBoxPrivate;
typedef struct _GtkColorBox		    GtkColorBox;
typedef struct _GtkColorBoxClass	GtkColorBoxClass;

struct _GtkColorBox
{
	GtkWidget parent;

	GtkColorBoxPrivate *priv;
};

struct _GtkColorBoxClass
{
	GtkWidgetClass parent_class;
};

GType gtk_color_box_get_type (void);

GtkWidget *gtk_color_box_new (void);
void       gtk_color_box_set_point (GtkWidget *box, Point *point);

G_END_DECLS

#endif

