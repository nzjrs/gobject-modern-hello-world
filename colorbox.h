#ifndef __ABC_COLOR_BOX_H__
#define __ABC_COLOR_BOX_H__

#include <gtk/gtk.h>
#include "point.h"

G_BEGIN_DECLS

#define ABC_TYPE_COLOR_BOX		(abc_color_box_get_type ())
#define ABC_COLOR_BOX(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), ABC_TYPE_COLOR_BOX, AbcColorBox))
#define ABC_COLOR_BOX_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), ABC_COLOR_BOX, AbcColorBoxClass))
#define ABC_IS_COLOR_BOX(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), ABC_TYPE_COLOR_BOX))
#define ABC_IS_COLOR_BOX_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), ABC_TYPE_COLOR_BOX))
#define ABC_COLOR_BOX_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), ABC_TYPE_COLOR_BOX, AbcColorBoxClass))

typedef struct _AbcColorBoxPrivate  AbcColorBoxPrivate;
typedef struct _AbcColorBox		    AbcColorBox;
typedef struct _AbcColorBoxClass	AbcColorBoxClass;

struct _AbcColorBox
{
	GtkWidget parent;

	AbcColorBoxPrivate *priv;
};

struct _AbcColorBoxClass
{
	GtkWidgetClass parent_class;
};

GType abc_color_box_get_type (void);

GtkWidget *abc_color_box_new (void);
void       abc_color_box_set_point (AbcColorBox *box, AbcPoint *point);

G_END_DECLS

#endif

