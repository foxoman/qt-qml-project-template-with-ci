#!/usr/bin/python3
# Note: ^^ the shebang line tells editors to highlight this as python code.

import scons_local_misc.helpers as helpers

# See SCons User Guide, Chapter 15. Separating Source and Build Directories
# https://scons.org/doc/0.98.0/HTML/scons-user/c2347.html
# TODO: figure out why folders ABOVE our root won't work.
BUILD_DESTINATION = "build"

EnsureSConsVersion(3, 0, 0)
EnsurePythonVersion(3, 5)

env = Environment()
helpers.configure_basic_compilation_settings(env)


# https://github.com/SCons/scons/wiki/GoFastButton
env.Decider("MD5-timestamp")
# https://github.com/SCons/scons/wiki/GoFastButton
env.SetOption('max_drift', 900)

# see comment above regarding BUILD_DESTINATION
common_sconscript_kwargs = {
    'must_exist': 1, 'variant_dir': BUILD_DESTINATION
}

Export("env")
minutil = SConscript("src/minutil/minutil.SConscript",
                     **common_sconscript_kwargs)


# Scons always builds the targets it is given on the command line, and any
# targets that are prerequisites to building the specific targets. Default sets up
# the list to build if no targets are supplied on the command line. If Default is
# not used, scons selects all the targets for building, which may be undesirable
# in a larger project.
#
# Default(minutil)  # <<-- choose some default and uncomment if the project gets large
