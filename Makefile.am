ACLOCAL_AMFLAGS = -I build ${ACLOCAL_FLAGS}

SUBDIRS = .

DISTCHECK_CONFIGURE_FLAGS =
MAINTAINERCLEANFILES =
EXTRA_DIST =
CLEANFILES =
noinst_PROGRAMS =

lib_LTLIBRARIES = src/libabc.la

abcdir = $(pkgincludedir)/src
abc_HEADERS = 				\
	src/abc.h				\
	src/abcpoint.h			\
	src/abccolorbox.h

src_libabc_la_SOURCES = 	\
	src/abcpoint.c			\
	src/abccolorbox.c

src_libabc_la_CPPFLAGS = 	\
	-I$(top_srcdir)			\
	-I$(top_srcdir)/src		\
	$(AM_CPPFLAGS)

src_libabc_la_CFLAGS = 		\
	$(DEPS_CFLAGS)			\
	$(AM_CFLAGS)

src_libabc_la_LIBADD = 		\
	$(DEPS_LIBS)			\
	$(AM_LIBADD)

# Introspection
-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --warn-all
INTROSPECTION_COMPILER_ARGS =
DISTCHECK_CONFIGURE_FLAGS += --enable-introspection
EXTRA_DIST += introspection.m4

if HAVE_INTROSPECTION
src/Abc.gir: src/libabc.la
src_Abc_gir_INCLUDES = Gtk-3.0
src_Abc_gir_CFLAGS = $(DEPS_CFLAGS) $(src_libabc_la_CPPFLAGS)
src_Abc_gir_LIBS = src/libabc.la
src_Abc_gir_FILES = $(src_libabc_la_SOURCES) $(abc_HEADERS)
src_Abc_gir_NAMESPACE = Abc
src_Abc_gir_EXPORT_PACKAGES = libabc
src_Abc_gir_SCANNERFLAGS = 	\
	--nsversion=1.0 		\
	--symbol-prefix=abc 	\
	--c-include="abc/abc.h"

INTROSPECTION_GIRS += src/Abc.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)

DISTCHECK_CONFIGURE_FLAGS += --enable-introspection
EXTRA_DIST += introspection.m4
endif

noinst_PROGRAMS += demos/c/simple

demos_c_simple_SOURCES = 	\
	demos/c/simple.c

demos_c_simple_CPPFLAGS = 	\
	-I$(top_srcdir)/ 	\
	-I$(top_srcdir)/src \
	$(AM_CPPFLAGS)

demos_c_simple_CFLAGS = 	\
	$(DEPS_CFLAGS) 		\
	$(AM_CFLAGS)

demos_c_simple_LDADD = 	\
	$(top_builddir)/src/libabc.la \
	$(DEPS_LIBS) 		\
	$(AM_LDADD)


