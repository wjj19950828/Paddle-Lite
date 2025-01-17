// Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

namespace nnadapter {
namespace operation {

#define STACK_OPERATION_EXTRACT_INPUTS_OUTPUTS                              \
  auto& input_operands = operation->input_operands;                         \
  auto& output_operands = operation->output_operands;                       \
  auto input_count = input_operands.size();                                 \
  auto output_count = output_operands.size();                               \
  NNADAPTER_CHECK_GE(input_count, 2);                                       \
  NNADAPTER_CHECK_EQ(output_count, 1);                                      \
  /* Inputs */                                                              \
  for (int i = 0; i < input_count - 1; i++) {                               \
    NNADAPTER_VLOG(5) << "input" << i << ": "                               \
                      << OperandToString(input_operands[i]);                \
  }                                                                         \
  /* Axis */                                                                \
  auto axis =                                                               \
      *reinterpret_cast<int32_t*>(input_operands[input_count - 1]->buffer); \
  NNADAPTER_VLOG(5) << "axis=" << axis;                                     \
  /* Output */                                                              \
  auto output_operand = output_operands[0];                                 \
  NNADAPTER_VLOG(5) << "output: " << OperandToString(output_operand);

}  // namespace operation
}  // namespace nnadapter
