#!/usr/bin/python3
# Note: ^^ the shebang line helps some editors know to highlight this as python code.

Import("env")

# if we operate on 'env', it affects the whole build. 'localenv' will affect this lib only.
localenv = env.Clone()

local_sources = [
    "logger.cc",
]

lib = localenv.SharedLibrary("minutil", local_sources)
