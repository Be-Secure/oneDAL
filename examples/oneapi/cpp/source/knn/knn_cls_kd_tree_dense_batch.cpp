/*******************************************************************************
* Copyright 2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <iomanip>
#include <iostream>

#include "oneapi/dal/algo/knn.hpp"
#include "oneapi/dal/io/csv.hpp"

#include "example_util/utils.hpp"

using namespace oneapi;

int main(int argc, char const *argv[]) {
  const std::string train_data_file_name  = get_data_path("k_nearest_neighbors_train_data.csv");
  const std::string train_label_file_name = get_data_path("k_nearest_neighbors_train_label.csv");
  const std::string test_data_file_name   = get_data_path("k_nearest_neighbors_test_data.csv");
  const std::string test_label_file_name  = get_data_path("k_nearest_neighbors_test_label.csv");

  const auto x_train = dal::read<dal::table>(dal::csv::data_source{train_data_file_name});
  const auto y_train = dal::read<dal::table>(dal::csv::data_source{train_label_file_name});

  const auto knn_desc =
      dal::knn::descriptor<float, oneapi::dal::knn::method::kd_tree>()
          .set_class_count(5)
          .set_neighbor_count(1)
          .set_data_use_in_model(false);

  const auto train_result = dal::train(knn_desc, x_train, y_train);

  const auto x_test = dal::read<dal::table>(dal::csv::data_source{test_data_file_name});
  const auto y_true = dal::read<dal::table>(dal::csv::data_source{test_label_file_name});

  const auto test_result =
      dal::infer(knn_desc, x_test, train_result.get_model());

  std::cout << "Test results:" << std::endl
            << test_result.get_labels() << std::endl;
  std::cout << "True labels:" << std::endl << y_true << std::endl;

  return 0;
}