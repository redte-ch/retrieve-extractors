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

#include "document.h"
#include "either.h"
#include <mupdf/fitz/context.h>
#include <mupdf/fitz/document.h>
#include <mupdf/fitz/types.h>
#include <stdio.h>
#include <string.h>

// Error messages
const char *const ERR_CONTEXT_CREATE = "could not create context";
const char *const ERR_FILEPATH_EMPTY = "filepath is empty";
const char *const ERR_NOT_A_PDF = "file is not a PDF";
const char *const ERR_HANDLERS_REGISTER = "could not register handlers";
const char *const ERR_DOC_OPEN = "could not open document";

/** Handle errors. **/
struct Either fail(fz_context *context, const char *error) {
  const int status = fprintf(stderr, "%s\n", error);
  return failure(context, NULL, status, error);
}

/* Open a document. */
struct Either open_document(const char *filepath) {
  fz_document *document = NULL;

  /* Create a context to hold the exception stack and various caches. */
  fz_context *context = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);

  /* Check if the context is empty. */
  if (!context) {
    return fail(context, ERR_CONTEXT_CREATE);
  }

  /* Check if the filepath is empty. */
  if (!filepath || filepath[0] == '\0') {
    return fail(context, ERR_FILEPATH_EMPTY);
  }

  /* Check if the file is not a PDF. */
  if (strstr(filepath, ".pdf") == NULL) {
    return fail(context, ERR_NOT_A_PDF);
  }

  /* Register the default file types to handle. */
  fz_try(context) { fz_register_document_handlers(context); }

  /* Check if the handlers could not be registered. */
  fz_catch(context) { return fail(context, ERR_HANDLERS_REGISTER); }

  /* Open the document from disk. */
  fz_try(context) { document = fz_open_document(context, filepath); }

  /* Check if the document could not be opened. */
  fz_catch(context) { return fail(context, ERR_DOC_OPEN); }

  return success(context, document);
}

/*
 * Close a document.
 *
 * This function closes a document by dropping the document and its context
 * from memory, and then freeing the Document structure.
 *
 * @param context A pointer to the document to close.
 * @param document A pointer to the Document structure to close.
 */
struct Either close_document(fz_context *context, fz_document *document) {
  fz_drop_document(context, document);
  fz_drop_context(context);
  return success(NULL, NULL);
}
