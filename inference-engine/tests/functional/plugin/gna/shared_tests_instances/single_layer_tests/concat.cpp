// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "single_layer_tests/concat.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;

namespace {

std::vector<size_t > axes = {0, 1, 2, 3};
std::vector<std::vector<std::vector<size_t>>> inShapes = {
        {{10, 10, 10, 10}},
        {{10, 10, 10, 10}, {10, 10, 10, 10}},
        {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}},
        {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}},
        {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}
};

std::vector<InferenceEngine::Precision> inputPrecisions = {InferenceEngine::Precision::FP32,
//         InferenceEngine::Precision::U8, // TODO: Preferable primitive descriptor is not set.
//         InferenceEngine::Precision::I8  // TODO: Issue: 26570
};


std::vector<InferenceEngine::Precision> netPrecisions = {InferenceEngine::Precision::FP32,
                                                         InferenceEngine::Precision::FP16};

// TODO: Issue:  26421
INSTANTIATE_TEST_CASE_P(DISABLED_NoReshape, ConcatLayerTest,
                        ::testing::Combine(
                                ::testing::ValuesIn(axes),
                                ::testing::ValuesIn(inShapes),
                                ::testing::ValuesIn(inputPrecisions),
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(CommonTestUtils::DEVICE_GNA)),
                        ConcatLayerTest::getTestCaseName);
}  // namespace