from gi.repository import Gtk, Abc, GLib

w = Gtk.Window()
w.connect("delete-event", Gtk.main_quit)
cb = Abc.ColorBox()
cb.set_point(Abc.Point(x=5,y=17))
w.add(cb)
w.show_all()
Gtk.main()
