#include <glib-object.h>
#include "abcpoint.h"

enum {
    PROP_0,
    PROP_X,
    PROP_Y,
    N_PROPERTIES
};

enum {
  EQUAL,
  N_SIGNALS
};

struct _AbcPointPrivate {
    guint x,y;
};

static guint point_signals[N_SIGNALS] = {0};
static GParamSpec *obj_properties[N_PROPERTIES] = {NULL,};

void abc_point_print (AbcPoint *self)
{
    ABC_POINT_GET_CLASS(self)->print(self);
}

static void abc_point_print_real (AbcPoint *self)
{
    g_print("x: %d, y: %d\n", self->priv->x, self->priv->y);
}

static void abc_point_clear (AbcPoint *self)
{
    g_object_set(self, "x", 0, "y", 0, NULL);
}

static void abc_point_get_property (GObject    *obj,
                                guint       prop_id,
                                GValue     *value,
                                GParamSpec *pspec)
{
    AbcPoint *point = ABC_POINT(obj);

    switch (prop_id) {
    case PROP_X:
        g_value_set_int(value, point->priv->x);
        break;
    case PROP_Y:
        g_value_set_int(value, point->priv->y);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, prop_id, pspec);
        break;
    }
}

static void abc_point_set_property (GObject      *obj,
                                guint         prop_id,
                                const GValue *value,
                                GParamSpec   *pspec)
{
    AbcPoint *point = ABC_POINT(obj);

    switch (prop_id) {
    case PROP_X: {
        gint new_x = g_value_get_int(value);
        point->priv->x = new_x;
        g_object_notify_by_pspec (obj, obj_properties[PROP_X]);
        break;
    }
    case PROP_Y: {
        gint new_y = g_value_get_int(value);
        point->priv->y = new_y;
        g_object_notify_by_pspec (obj, obj_properties[PROP_Y]);
        break;
    }
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, prop_id, pspec);
        break;
    }

    if (point->priv->x == point->priv->y)
         g_signal_emit (G_OBJECT (point), point_signals[EQUAL], 0);
}

static void
abc_point_init (AbcPoint *point)
{
    point->priv = G_TYPE_INSTANCE_GET_PRIVATE (point, ABC_TYPE_POINT, AbcPointPrivate);
}

static void abc_point_class_init (AbcPointClass *cls)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS(cls);

    g_type_class_add_private (cls, sizeof (AbcPointPrivate));
    
    gobject_class->get_property = abc_point_get_property;
    gobject_class->set_property = abc_point_set_property;
    
    cls->clear = abc_point_clear;
    cls->print = abc_point_print_real;

    obj_properties[PROP_X] = 
        g_param_spec_int(
        "x", "x", "x loc of point",
        INT_MIN, /* => */ INT_MAX,
        0,
        G_PARAM_READWRITE);

    obj_properties[PROP_Y] =
        g_param_spec_int(
        "y", "y", "y loc of point",
        INT_MIN, /* => */ INT_MAX,
        0,
        G_PARAM_READWRITE);

    g_object_class_install_properties (gobject_class,
                                       N_PROPERTIES,
                                       obj_properties);
    
    point_signals[EQUAL] = g_signal_new(
        "coordinates-equal",                   /* signal_name */
        ABC_TYPE_POINT,                        /* itype */
        G_SIGNAL_RUN_LAST | G_SIGNAL_DETAILED, /* signal_flags */
        0,                                     /* class_offset */
        NULL,                                  /* accumulator */
        NULL,                                  /* accu_data */
        NULL,                                  /* c_marshaller */
        G_TYPE_NONE,                           /* return_type */
        0);                                    /* n_params */
}

G_DEFINE_TYPE(AbcPoint, abc_point, G_TYPE_OBJECT);
