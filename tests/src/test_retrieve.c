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

#include "unity.h"
#include <retrieve.h>

void setUp(void) {}

void tearDown(void) {}

void test_load_file_returns_non_null(void) {
  char filename[9] = "test.txt";
  TEST_ASSERT_NOT_NULL(load_file(filename));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_load_file_returns_non_null);
  UNITY_END();
}
