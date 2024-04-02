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

cc = meson.get_compiler('c')
mupdf_dir = '/opt/homebrew/opt/mupdf'
mupdf_inc = include_directories(mupdf_dir / 'include')
mupdf_lib = cc.find_library(
    'mupdf',
    dirs : [mupdf_dir / 'lib'],
    has_headers : ['mupdf/fitz.h', 'mupdf/pdf.h'],
    header_include_directories : [mupdf_inc],
    required : true,
)
mupdf_dep = declare_dependency(
    dependencies : [mupdf_lib],
    include_directories : [mupdf_inc],
)
