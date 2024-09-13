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

#include "either.h"
#include <mupdf/fitz/context.h>
#include <mupdf/fitz/types.h>

#ifndef public
#define public
#endif // public

/*
 * Open a document.
 *
 * This function opens a document from a given file path. It first allocates
 * memory for a new Document structure. Then, it creates a new context to hold
 * the exception stack and various caches. If the context cannot be created, it
 * prints an error message and returns the document with the status set.
 *
 * After successfully creating the context, it tries to register the default
 * document handlers. If this fails, it prints an error message, drops the
 * context, and returns the document with the status set.
 *
 * Finally, it tries to open the document from the given file path. If this
 * fails, it prints an error message, drops the context, and returns the
 * document with the status set.
 *
 * @param filepath The path to the document to open.
 * @return A pointer to the opened Document structure, or a Document structure
 * with the status set if an error occurred.
 */
public
struct Either open_document(const char *filepath);

/* Close a document. */
public
struct Either close_document(fz_context *context, fz_document *document);
