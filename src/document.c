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
#include <mupdf/fitz/context.h>
#include <mupdf/fitz/document.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
struct Document *open_document(const char *filepath) {
  struct Document *document = NULL;

  /* Allocate memory for the document structure. */
  document = malloc(sizeof(struct Document));

  /* Create a context to hold the exception stack and various caches. */
  document->context = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);

  /* Check if the context is empty. */
  if (!document->context) {
    goto could_not_create_context;
  }

  /* Check if the filepath is empty. */
  if (!filepath || filepath[0] == '\0') {
    goto filepath_is_empty;
  }

  /* Check if the filepath is not a PDF. */
  if (strstr(filepath, ".pdf") == NULL) {
    document->status = fprintf(stderr, "file is not a PDF\n");
    goto cleanup;
  }

  /* Register the default file types to handle. */
  fz_try(document->context) {
    fz_register_document_handlers(document->context);
  }

  fz_catch(document->context) {
    document->status = fprintf(stderr, "could not register handlers\n");
    goto cleanup;
  }

  /* Open the document from disk. */
  fz_try(document->context) {
    document->document = fz_open_document(document->context, filepath);
  }

  fz_catch(document->context) {
    document->status = fprintf(stderr, "could not open document\n");
    goto cleanup;
  }

  goto finally;

could_not_create_context:
  document->status = fprintf(stderr, "could not create context\n");
  goto finally;

filepath_is_empty:
  document->status = fprintf(stderr, "filepath is empty\n");
  goto finally;

cleanup:
  fz_drop_context(document->context);
  return document;

finally:
  return document;
}

/*
 * Close a document.
 *
 * This function closes a document by dropping the document and its context
 * from memory, and then freeing the Document structure.
 *
 * @param document A pointer to the Document structure to close.
 */
void close_document(struct Document *document) {
  fz_drop_document(document->context, document->document);
  fz_drop_context(document->context);
  free(document);
}
