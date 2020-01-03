#
# Copyright (c) 2020, 219 Design, LLC
# See LICENSE.txt
#
# https://www.219design.com
# Software | Electrical | Mechanical | Product Design
#
include($$top_srcdir/compiler_flags.pri) # each subproject must also include this

TEMPLATE = subdirs

SUBDIRS = \
    app \
    lib \
    lib_tests \
    libstyles \
    libtestmain

app.file = src/app/app.pro
lib.file = src/lib/lib.pro
lib_tests.file = src/lib/lib_tests.pro
libstyles.file = src/libstyles/libstyles.pro
libtestmain.file = src/libtests/libtestmain.pro

# The 'app' does not directly depend on this entire set of libraries.
# Instead, think of this massive dependency list as a way for us to tell qmake
# that "the install directory of app" indeed depends on (aka 'wishes to
# contain') all these libraries.
app.depends = \
    lib \
    libstyles \
    libtestmain \
    lib_tests

# The remaining 'depends' lines are used in the 'traditional' sense of actually
# specifying the miminum link-time dependencies of each item:

# NOTE: using 'CONFIG += ordered' is considered a bad practice—prefer using .depends instead.

lib.depends = libstyles
lib_tests.depends = lib libtestmain
