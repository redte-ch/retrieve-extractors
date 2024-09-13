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

#pragma once

#ifndef public
#define public
#endif // public

/*
 * Sum type that can hold either a result or an error.
 *
 * The Either monad is typically used in situations where a function can have
 * multiple possible outcomes, such as success or failure, and the caller needs
 * to handle each outcome differently.
 */
struct Either {
  /* Result of an operation. */
  int result;
  /* Error message. */
  const char *error;
};

/* Struct representing a successful result. */
public
struct Either success();

/* Failure struct with the given error message. */
public
struct Either failure(const char *error);
