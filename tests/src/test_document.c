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

#include <document.h>
#include <either.h>
#include <stdlib.h>
#include <unity.h>
#include <unity_internals.h>

void setUp(void) {}

void tearDown(void) {}

void test_open_document(void) {
  const char *filename = "../tests/share/001-trivial/minimal-document.pdf";
  const struct Either document = open_document(filename);
  TEST_ASSERT_NOT_NULL(document.context);
  TEST_ASSERT_NOT_NULL(document.result);
  TEST_ASSERT_EQUAL_INT(EXIT_SUCCESS, document.status);
  TEST_ASSERT_NULL(document.error);
  const struct Either closed =
      close_document(document.context, document.result);
  TEST_ASSERT_EQUAL_INT(EXIT_SUCCESS, closed.status);
}

void test_open_document_when_filepath_is_null(void) {
  const char *filename = NULL;
  const struct Either document = open_document(filename);
  TEST_ASSERT_NOT_NULL(document.context);
  TEST_ASSERT_NULL(document.result);
  TEST_ASSERT_NOT_EQUAL_INT(EXIT_SUCCESS, document.status);
  TEST_ASSERT_EQUAL_STRING("filepath is empty", document.error);
  const struct Either closed =
      close_document(document.context, document.result);
  TEST_ASSERT_EQUAL_INT(EXIT_SUCCESS, closed.status);
}

void test_open_document_when_not_pdf(void) {
  const char *filename = "../tests/share/001-trivial/minimal-document.tex";
  const struct Either document = open_document(filename);
  TEST_ASSERT_NOT_NULL(document.context);
  TEST_ASSERT_NULL(document.result);
  TEST_ASSERT_NOT_EQUAL_INT(EXIT_SUCCESS, document.status);
  TEST_ASSERT_EQUAL_STRING("file is not a PDF", document.error);
  const struct Either closed =
      close_document(document.context, document.result);
  TEST_ASSERT_EQUAL_INT(EXIT_SUCCESS, closed.status);
}

void test_open_document_when_not_found(void) {
  const char *filename = "/does/not/exist.pdf";
  const struct Either document = open_document(filename);
  TEST_ASSERT_NOT_NULL(document.context);
  TEST_ASSERT_NULL(document.result);
  TEST_ASSERT_NOT_EQUAL_INT(EXIT_SUCCESS, document.status);
  TEST_ASSERT_EQUAL_STRING("could not open document", document.error);
  const struct Either closed =
      close_document(document.context, document.result);
  TEST_ASSERT_EQUAL_INT(EXIT_SUCCESS, closed.status);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_open_document);
  RUN_TEST(test_open_document_when_filepath_is_null);
  RUN_TEST(test_open_document_when_not_pdf);
  RUN_TEST(test_open_document_when_not_found);
  return UNITY_END();
}
