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

#include <either.h>
#include <stdlib.h>
#include <unity.h>
#include <unity_internals.h>

void setUp(void) {}

void tearDown(void) {}

void test_success(void) {
  const struct Either either = success();
  TEST_ASSERT_EQUAL_INT(either.result, EXIT_SUCCESS);
  TEST_ASSERT_NULL(either.error);
}

void test_failure(void) {
  const struct Either either = failure("did not work");
  TEST_ASSERT_NOT_EQUAL_INT(either.result, EXIT_SUCCESS);
  TEST_ASSERT_EQUAL_STRING("did not work", either.error);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_success);
  RUN_TEST(test_failure);
  return UNITY_END();
}
