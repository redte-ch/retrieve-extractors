// Red Innovation © 2024.
//
// This file (hereafter, the "work") is licensed under the European Union
// Public Licence, Version 1.2 or later (the "EUPL"). This EUPL applies to this
// work, which is provided under the terms of this EUPL. You may obtain a copy
// of this EUPL at:
//
//     https://joinup.ec.europa.eu/collection/eupl/eupl-text-eupl-12
//
// Any use of this work, other than as authorised under this EUPL, is
// prohibited (to the extent such use is covered by a right of the copyright
// holder of this work).
//
// Author: Mauko Quiroga-Alvarado <mauko@redte.ch>.

#include "either.h"
#include <stdlib.h>

/* Struct representing a successful result. */
struct Either success(void *context, void *result) {
  return (struct Either){.context = context,
                         .result = result,
                         .status = EXIT_SUCCESS,
                         .error = NULL};
}

/* Failure struct with the given error message. */
struct Either failure(void *context, void *result, const int status,
                      const char *error) {
  return (struct Either){
      .context = context, .result = result, .status = status, .error = error};
}
