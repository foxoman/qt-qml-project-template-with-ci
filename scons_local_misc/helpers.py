#!/usr/bin/python3

# Use as it becomes expedient to do so (depending on new helper needs):
# from SCons.Script import Action
# from SCons.Script import BoolVariable, PathVariable, Variables, Help
# from SCons.Script import Dir, Environment
# from SCons.Script import Progress, Command, AlwaysBuild
# from SCons.Tool.MSCommon.vc import get_default_version, get_host_target, find_batch_file
# from SCons.Variables import BoolVariable, EnumVariable


def configure_basic_compilation_settings(env):
    # allows our code to include util-assert.h

    # we must NOT use string literals with embedded whitespace, or else SCons
    # adds quotes (which we don't want).
    env.Prepend(CXXFLAGS=["-isystem", "src/assert"])
