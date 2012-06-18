#ifndef __ABC_POINT_H__
#define __ABC_POINT_H__

#include <glib-object.h>

typedef struct _AbcPointPrivate AbcPointPrivate;
typedef struct _AbcPointClass   AbcPointClass;
typedef struct _AbcPoint        AbcPoint;

struct _AbcPointClass {
    GObjectClass parent;
    void (*clear) (AbcPoint *self);
    void (*print) (AbcPoint *self);
};

struct _AbcPoint {
    GObject  parent;

	AbcPointPrivate *priv;
};

#define ABC_TYPE_POINT           (abc_point_get_type         ())
#define ABC_POINT(obj)           (G_TYPE_CHECK_INSTANCE_CAST ((obj), ABC_TYPE_POINT, AbcPoint))
#define ABC_POINT_CLASS(cls)     (G_TYPE_CHECK_CLASS_CAST    ((cls), ABC_TYPE_POINT, AbcPointClass))
#define IS_ABC_POINT(obj)        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ABC_TYPE_POINT))
#define IS_ABC_POINT_CLASS(cls)  (G_TYPE_CHECK_CLASS_TYPE    ((cls), ABC_TYPE_POINT))
#define ABC_POINT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS  ((obj), ABC_TYPE_POINT, AbcPointClass))

GType  abc_point_get_type  (void);
void   abc_point_print     (AbcPoint *self);

#endif
