
#include "langutils.h"

#define MAKE_NODE(line, col, struct_type, node_type, proto)   ((struct_type *)lu_ast_create_node(line, col, sizeof(struct_type), node_type, proto))

LUASTNode *lu_ast_create_node(int line, int col, size_t size,
                              LUASTNodeType node_type, LUASTNodePrototype *prototype)
{
    LUASTNode *node = (LUASTNode *)cu_alloc(prototype, size);
    node->node_type = node_type;
    node->line = line;
    node->column = col;
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_basic_node(int line, int col, LUASTNodeType node_type)
{
    return MAKE_NODE(line, col, LUASTNode, node_type, lu_ast_basic_node_prototype());
}

LUASTNode *lu_ast_create_error_node(int line, int col, CUString *message)
{
    LUASTErrorNode *node = MAKE_NODE(line, col, LUASTErrorNode, LUAST_ERROR_NODE, lu_ast_error_node_prototype());
    cu_setattr(node, message, message);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_return_node(int line, int col, LUASTNode *value)
{
    LUASTReturnNode *node = MAKE_NODE(line, col, LUASTReturnNode, LUAST_RETURN_NODE, lu_ast_return_node_prototype());
    cu_setattr(node, return_value, value);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_long_node(int line, int col, long value)
{
    LUASTNumberNode *node = MAKE_NODE(line, col, LUASTNumberNode, LUAST_NUMBER_NODE, lu_ast_number_node_prototype());
    node->number_type = LUAST_NUMBER_LONG;
    node->value.long_value = value;
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_double_node(int line, int col, double value)
{
    LUASTNumberNode *node = MAKE_NODE(line, col, LUASTNumberNode, LUAST_NUMBER_NODE, lu_ast_number_node_prototype());
    node->number_type = LUAST_NUMBER_DOUBLE;
    node->value.double_value = value;
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_string_node(int line, int col, CUString *value)
{
    LUASTStringNode *node = MAKE_NODE(line, col, LUASTStringNode, LUAST_NUMBER_NODE, lu_ast_string_node_prototype());
    cu_setattr(node, value, value);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_subscript_node(int line, int col, LUASTNode *target, LUASTNode *subscript)
{
    LUASTSubscriptNode *node = MAKE_NODE(line, col, LUASTSubscriptNode, LUAST_SUBSCRIPT_NODE, lu_ast_subscript_node_prototype());
    cu_setattr(node, target, target);
    cu_setattr(node, subscript, subscript);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_variable_node(int line, int col, CUString *name)
{
    LUASTVariableNode *node = MAKE_NODE(line, col, LUASTVariableNode, LUAST_VARIABLE_NODE, lu_ast_variable_node_prototype());
    cu_setattr(node, var_name, name);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_variable_decl_node(int line, int col, LUType *var_type, CUString *var_name, CUSet *modifiers)
{
    LUASTVariableDeclNode *node = MAKE_NODE(line, col, LUASTVariableDeclNode, LUAST_VARIABLE_DECL_NODE, lu_ast_variable_decl_node_prototype());
    cu_setattr(node, var_type, var_type);
    cu_setattr(node, var_name, var_name);
    cu_setattr(node, modifiers, modifiers);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_assignment_node(int line, int col, BOOL assign, LUASTNode *left, LUASTNode *right)
{
    LUASTAssignmentNode *node = MAKE_NODE(line, col, LUASTAssignmentNode,
                                          LUAST_ASSIGNMENT_NODE,
                                          lu_ast_assignment_node_prototype());
    node->assign = assign;
    cu_setattr(node, left, left);
    cu_setattr(node, right, right);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_binary_node(int line, int col, short opcode, LUASTNode *left, LUASTNode *right)
{
    LUASTBinaryNode *node = MAKE_NODE(line, col, LUASTBinaryNode, LUAST_BINARY_NODE, lu_ast_binary_node_prototype());
    node->opcode = opcode;
    cu_setattr(node, left, left);
    cu_setattr(node, right, right);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_unary_node(int line, int col, short opcode, LUASTNode *child, BOOL prefix)
{
    LUASTUnaryNode *node = MAKE_NODE(line, col, LUASTUnaryNode, LUAST_UNARY_NODE, lu_ast_unary_node_prototype());
    node->prefix = prefix;
    node->opcode = opcode;
    cu_setattr(node, child, child);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_cast_node(int line, int col, LUASTNode *source, LUType *target_type)
{
    LUASTCastNode *node = MAKE_NODE(line, col, LUASTCastNode, LUAST_CLUAST_NODE, lu_ast_cast_node_prototype());
    cu_setattr(node, source, source);
    cu_setattr(node, target_type, target_type);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_loop_node(int line, int col, int loopType,
                                   LUASTNode *initialiser,
                                   LUASTNode *condition,
                                   LUASTNode *post_body,
                                   LUASTNode *body,
                                   BOOL negate_condition,
                                   BOOL condition_is_after_body)
{
    LUASTLoopNode *node = MAKE_NODE(line, col, LUASTLoopNode, LUAST_LOOP_NODE, lu_ast_loop_node_prototype());
    cu_setattr(node, condition, condition);
    cu_setattr(node, initialiser, initialiser);
    cu_setattr(node, post_body, post_body);
    cu_setattr(node, body, body);
    node->negate_condition = negate_condition;
    node->condition_is_after_body = condition_is_after_body;
    node->loopType = loopType;
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_list_node(int line, int col, CUList *values)
{
    LUASTListNode *node = MAKE_NODE(line, col, LUASTListNode, LUAST_LIST_NODE, lu_ast_list_node_prototype());
    cu_setattr(node, values, values);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_func_call_node(int line, int col, LUASTNode *source, CUList *params)
{
    LUASTFuncCallNode *node = MAKE_NODE(line, col, LUASTFuncCallNode, LUAST_FUNC_CALL_NODE, lu_ast_func_call_node_prototype());
    cu_setattr(node, source, source);
    cu_setattr(node, params, params);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_member_access_node(int line, int col, LUASTNode *source, CUString *member)
{
    LUASTMemberAccessNode *node = MAKE_NODE(line, col, 
                                            LUASTMemberAccessNode, LUAST_MEMBER_ACCESS_NODE,
                                            lu_ast_member_access_node_prototype());
    cu_setattr(node, source, source);
    cu_setattr(node, member, member);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_ifelse_node(int line, int col,
                                     LUASTNode *condition, LUASTNode *ifbody, LUASTNode *elsebody)
{
    LUASTIfElseNode *node = MAKE_NODE(line, col, LUASTIfElseNode, LUAST_IFELSE_NODE, lu_ast_ifelse_node_prototype());
    cu_setattr(node, condition, condition);
    cu_setattr(node, ifbody, ifbody);
    cu_setattr(node, elsebody, elsebody);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_create_statements_node(int line, int col, LUASTNode *statement)
{
    LUASTStatementsNode *node = MAKE_NODE(line, col, LUASTStatementsNode, LUAST_DEFINITIONS_NODE, lu_ast_statements_node_prototype());
    node->statements = NULL;
    lu_ast_add_statement((LUASTNode *)node, statement);
    return (LUASTNode *)node;
}

LUASTNode *lu_ast_add_statement(LUASTNode *statements, LUASTNode *statement)
{
    if (statement)
    {
        LUASTStatementsNode *defns_node = (LUASTStatementsNode *)statements;
        if (defns_node->statements == NULL)
        {
            defns_node->statements = (CUList *)cu_linkedlist();
        }
        cu_list_push_back(defns_node->statements, statement);
    }
    return statements;
}

DECLARE_PROTO_FUNC(lu_ast_string_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_number_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_basic_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_variable_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_return_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_error_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_subscript_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_variable_decl_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_ifelse_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_loop_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_cast_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_binary_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_assignment_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_unary_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_statements_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_func_call_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_member_access_node_prototype, LUASTNodePrototype, NULL);
DECLARE_PROTO_FUNC(lu_ast_list_node_prototype, LUASTNodePrototype, NULL);

