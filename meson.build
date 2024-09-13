# Red Innovation © 2024.
#
# This file (hereafter, the "work") is licensed under the European Union
# Public Licence, Version 1.2 or later (the "EUPL"). This EUPL applies to this
# work, which is provided under the terms of this EUPL. You may obtain a copy
# of this EUPL at:
#
#     https://joinup.ec.europa.eu/collection/eupl/eupl-text-eupl-12
#
# Any use of this work, other than as authorised under this EUPL, is
# prohibited (to the extent such use is covered by a right of the copyright
# holder of this work).
#
# Author: Mauko Quiroga-Alvarado <mauko@redte.ch>.

project(
    'retrieve-extractors',
    'c', 'cpp',
    version : '0.0.0',
    license : 'EUPL-1.2-or-later',
    meson_version : '>=1.2.1',
    default_options : [
        'backend=ninja',
        'optimization=3',
        'warning_level=3',
        'c_std=gnu23',
        '''c_args=
            -O3
            -Wall
            -Werror
            -Wextra
            -Wmissing-include-dirs
            -Wnested-externs
            -Wold-style-definition
            -Wpedantic
            -Wredundant-decls
            -Wshadow
            -Wstrict-prototypes
            -Wwrite-strings
            -fopenmp
            -fvisibility=hidden
            -march=native
            -mtune=native
            -std=gnu23
        ''',
        '''c_link_args=
            -O3
            -Wall
            -Werror
            -Wextra
            -fopenmp
            -fvisibility=hidden
            -march=native
            -mtune=native
        ''',
    ]
)

# Description of the library.
description = 'Library to deal with text extraction in Retrieve.'

# Source files for the library.
retrieve_src = files(['src/document.c', 'src/either.c'])

# Required headers for the library.
retrieve_include = [include_directories('include')]

# Dependencies for the library.
subdir('ext/mupdf')
logc_dep = dependency('log.c')
unity_dep = dependency('unity')

# Add name and version to the build args.
build_args = [
    '-DPROJECT_NAME=' + meson.project_name(),
    '-DPROJECT_VERSION=' + meson.project_version(),
]

# Only make public interfaces visible.
if target_machine.system() == 'windows' or target_machine.system() == 'cygwin'
    build_args += '-Dpublic="__declspec(dllexport)"'
else
    build_args += '-Dpublic=__attribute__((visibility("default")))'
endif

# Create the library.
subdir('src')

# Create the tests for the library.
subdir('tests')

# Make this library usable from the system's package manager.
subdir('lib/pkgconfig')

# Run the tests.
if not meson.is_subproject()
    test('tests', retrieve_test_either)
    test('tests', retrieve_test_document)
endif
