#include <glib-object.h>
#include "point.h"

G_DEFINE_TYPE(Point, point, G_TYPE_OBJECT);

enum {
    PROP_0,
    PROP_X,
    PROP_Y
};

enum {
  EQUAL,
  LAST_SIGNAL
};

static guint point_signals[LAST_SIGNAL] = {0};

/* virtual print method that calls whatever is in the classes vtable  */
void point_print (Point *self) {
    POINT_GET_CLASS(self)->print(self);
}

static void point_print_real (Point *self) {
    g_print("x: %d, y: %d\n", self->x, self->y);
}

static void point_clear (Point *self) {
    g_object_set(self, "x", 0, "y", 0, NULL);
}

static void point_get_property (GObject    *obj,
                                guint       prop_id,
                                GValue     *value,
                                GParamSpec *pspec) {
    Point *point = POINT(obj);

    switch (prop_id) {
    case PROP_X:
        g_value_set_int(value, point->x);
        break;
    case PROP_Y:
        g_value_set_int(value, point->y);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, prop_id, pspec);
        break;
    }
}

static void point_set_property (GObject      *obj,
                                guint         prop_id,
                                const GValue *value,
                                GParamSpec   *pspec) {
    Point *point = POINT(obj);

    switch (prop_id) {
    case PROP_X: {
        gint new_x = g_value_get_int(value);
        point->x = new_x;
        break;
    }
    case PROP_Y: {
        gint new_y = g_value_get_int(value);
        point->y = new_y;
        break;
    }
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, prop_id, pspec);
        break;
    }
}

static void
point_init (Point *point)
{

}

static void point_class_init (PointClass *cls) {
    GObjectClass *g_object_class = G_OBJECT_CLASS(cls);
    
    g_object_class->get_property = point_get_property;
    g_object_class->set_property = point_set_property;
    
    cls->clear = point_clear;
    cls->print = point_print_real;
    
    g_object_class_install_property(
        g_object_class,
        PROP_X,
        g_param_spec_int(
        "x", "x", "x loc of point",
        INT_MIN, /* => */ INT_MAX,
        0,
        G_PARAM_READWRITE));
    
    g_object_class_install_property(
        g_object_class,
        PROP_Y,
        g_param_spec_int(
        "y", "y", "y loc of point",
        INT_MIN, /* => */ INT_MAX,
        0,
        G_PARAM_READWRITE));
    
    point_signals[EQUAL] = g_signal_new(
        "coordinates-equal",                   /* signal_name */
        TYPE_POINT,                            /* itype */
        G_SIGNAL_RUN_LAST | G_SIGNAL_DETAILED, /* signal_flags */
        0,                                     /* class_offset */
        NULL,                                  /* accumulator */
        NULL,                                  /* accu_data */
        NULL,                                  /* c_marshaller */
        G_TYPE_NONE,                           /* return_type */
        0);                                    /* n_params */
}

