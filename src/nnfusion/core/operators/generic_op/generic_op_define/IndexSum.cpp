#include "nnfusion/core/operators/generic_op/generic_op.hpp"

REGISTER_OP(IndexSum)
    // .attr<nnfusion::op::OpConfig::any>("out_shape")
        // .infershape(nnfusion::op::infershape::copy_shape_from_inputs);
        .infershape(
        [](std::shared_ptr<graph::GNode> gnode) -> void {
        // enforce is like assert, but when thing goes wrong, it will print error message.
        // NNFUSION_CHECK(gnode->get_input_size() >= 2)
        //     << "Inputs of AddN operator should not be less than 2.";

        auto& shape_0 = gnode->get_input_shape(0);
        // for (int i = 1; i < gnode->get_input_size(); i++)
        // {
        //     auto& shape_n = gnode->get_input_shape(i);
        //     NNFUSION_CHECK(shape_0.size() == shape_n.size()) << "Shape dimension size not match.";
        //     for (int j = 0; j < shape_0.size(); j++)
        //     {
        //         NNFUSION_CHECK(shape_0[j] == shape_n[j]) << "Dimension " << j
        //                                                  << " in shapes must be equal.";
        //     }
        // }

        nnfusion::Shape output_shape_0(shape_0);
        gnode->set_output_type_and_shape(0, gnode->get_input_element_type(0), output_shape_0);
    });
        
        // .infershape([](std::shared_ptr<graph::GNode> gnode) -> void {
        // auto shape_0 = gnode->get_input_shape(0);
        // auto op = std::dynamic_pointer_cast<nnfusion::op::GenericOp>(gnode->get_op_ptr());
        // Shape out_shape = op->localOpConfig.getRoot()["out_shape"];
        // gnode->set_output_type_and_shape(0, element::f32, out_shape);
    //     gnode->set_output_type_and_shape(0, gnode->get_input_element_type(0), shape_0);
    // });