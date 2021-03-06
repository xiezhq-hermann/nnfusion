// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

/**
 * \brief Unit tests for ir::Relu
 * \author generated by script
 */

#include "../test_util/common.hpp"

namespace nnfusion
{
    namespace test
    {
        template <typename T, size_t N>
        using NDArray = nnfusion::test::NDArray<T, N>;
    }

    namespace inventory
    {
        template <>
        shared_ptr<graph::GNode> create_object<op::Relu, float>(int option)
        {
            switch (option)
            {
            case 0:
            {
                auto graph = std::make_shared<graph::Graph>();
                auto shape_a = Shape{2, 5};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto relu = make_shared<op::Relu>();
                auto relu_gnode = graph->add_node_and_edge(relu, {A_gnode});
                return relu_gnode;
            }
            case 1:
            {
                auto graph = std::make_shared<graph::Graph>();
                auto shape_a = Shape{2, 2, 2, 2};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto relu = make_shared<op::Relu>();
                auto relu_gnode = graph->add_node_and_edge(relu, {A_gnode});
                return relu_gnode;
            }
            default: return nullptr;
            }
        }

        template <>
        vector<float> generate_input<op::Relu, float>(int option)
        {
            switch (option)
            {
            case 0:
            {
                vector<float> a = vector<float>{1, 8, -8, 17, -0.5, 1, 8, -8, 17, -0.5};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 1:
            {
                vector<float> a =
                    vector<float>{1, 8, -8, 17, -0.5, 1, 8, -8, 17, -0.5, 1, 8, -8, 17, -0.5, 1};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            default: return vector<float>();
            }
        }

        template <>
        vector<float> generate_output<op::Relu, float>(int option)
        {
            switch (option)
            {
            case 0:
            {
                vector<float> expected{1, 8, 0, 17, 0, 1, 8, 0, 17, 0};
                vector<float> result = expected;
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 1:
            {
                vector<float> expected{1, 8, 0, 17, 0, 1, 8, 0, 17, 0, 1, 8, 0, 17, 0, 1};
                vector<float> result = expected;
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            default: return vector<float>();
            }
        }
    }
}