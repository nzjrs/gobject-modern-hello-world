#!/usr/bin/env gjs

const Gtk = imports.gi.Gtk;
const Abc = imports.gi.Abc;

Gtk.init(null, 0);

let w = new Gtk.Window()
let cb = new Abc.ColorBox()
cb.set_point(new Abc.Point({x : 5, y: 17}))
w.add(cb)
w.show_all()
w.connect ("destroy", function(){Gtk.main_quit()});
Gtk.main()

