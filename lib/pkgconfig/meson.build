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

# Required headers for the library.
retrieve_headers = [
    meson.project_source_root() / 'include/either.h',
    meson.project_source_root() / 'include/document.h',
]

# Install the headers of the library.
install_headers(retrieve_headers, subdir : meson.project_name())

# Import the pkgconfig module.
pkg_mod = import('pkgconfig')

# Make this library usable from the system's package manager.
pkg_mod.generate(
    name : meson.project_name(),
    filebase : meson.project_name(),
    description : description,
    subdirs : meson.project_name(),
    libraries : retrieve_lib,
)
