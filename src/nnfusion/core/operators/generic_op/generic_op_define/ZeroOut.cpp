#include "nnfusion/core/operators/generic_op/generic_op.hpp"

REGISTER_OP(ZeroOut)
    // .attr<nnfusion::op::OpConfig::any>("out_shape")
        .infershape(nnfusion::op::infershape::copy_shape_from_inputs);
        // .infershape([](std::shared_ptr<graph::GNode> gnode) -> void {
        // auto shape_0 = gnode->get_input_shape(0);
        // auto op = std::dynamic_pointer_cast<nnfusion::op::GenericOp>(gnode->get_op_ptr());
        // Shape out_shape = op->localOpConfig.getRoot()["out_shape"];
        // gnode->set_output_type_and_shape(0, element::f32, out_shape);
    //     gnode->set_output_type_and_shape(0, gnode->get_input_element_type(0), shape_0);
    // });