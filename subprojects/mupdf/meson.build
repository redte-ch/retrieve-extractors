# Wrapper for the MuPDF library.
# https://github.com/ArtifexSoftware/mupdf

project(
    'mupdf',
    'c',
    version : '1.24.0',
)

cc = meson.get_compiler('c')

mupdf_lib = cc.find_library(
    'mupdf',
    dirs : meson.current_source_dir() + '/lib',
)

mupdf_dep = declare_dependency(
    dependencies : mupdf_lib,
    include_directories : include_directories('include'),
)

meson.override_dependency('mupdf', mupdf_dep)
