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

# Source files for the tests.
tests_src = ['src/test_retrieve.c']

# Make the library usable as a dependency.
retrieve_dep = declare_dependency(
    include_directories: retrieve_include,
    link_with : retrieve_lib,
)

# Create the test executable.
retrieve_test = executable(
    'retrieve-test',
    tests_src,
    dependencies: [retrieve_dep, unity_dep],
    include_directories: retrieve_include,
    link_with: retrieve_lib,
)
