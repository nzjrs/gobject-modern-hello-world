from gi.repository import Gtk, Abc, GLib

class UI:
    def __init__(self):
        w = Gtk.Window()
        w.connect("delete-event", Gtk.main_quit)
        cb = Abc.ColorBox()
        self.p = Abc.Point(x=20,y=0)
        self.p.connect("coordinates-equal", self._coords_equal)
        cb.set_point(self.p)
        w.add(cb)
        w.show_all()
        GLib.timeout_add(500, self._tick)

    def _coords_equal(self, pt):
        print "the points coords are equal %d,%d" % (pt.props.x, pt.props.y)

    def _tick(self):
        self.p.props.y = self.p.props.y + 1
        print self.p.props.y
        return True


u = UI()
Gtk.main()
