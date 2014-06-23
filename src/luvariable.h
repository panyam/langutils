
#ifndef __LANGUTILS_VARIABLE_H__
#define __LANGUTILS_VARIABLE_H__

#include "lufwddefs.h"

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif

/**
 * The ast for a parser. 
 * Some basic nodes are described here.  Others can be defined by the custom parsers.
 */
struct LUVariable
{
    // name of the variable
    const char *name;
};

DEFINE_NODE(LUASTNumberNode,
    LUASTNumberType number_type;
    union {
        double double_value;
        long long_value;
        int int_value;
        float float_value;
    } value;
);

DEFINE_NODE(LUASTComplexNode,
    BOOL is_polar;
    double x;
    double y;
);

DEFINE_NODE(LUASTVariableNode, 
    CUString *var_name;
);

DEFINE_NODE(LUASTSubscriptNode,
    LUASTNode *target;
    LUASTNode *subscript;
);

DEFINE_NODE(LUASTVariableDeclNode,
    LUType *var_type;
    CUString *var_name;
    BOOL is_static;
);

DEFINE_NODE(LUASTBinaryNode,
    short opcode;
    LUASTNode *left;
    LUASTNode *right;
);

DEFINE_NODE(LUASTUnaryNode,
    short opcode;
    LUASTNode *child;
);

DEFINE_NODE(LUASTCastNode,
    LUASTNode *source;
    LUType *target_type;
);

DEFINE_NODE(LUASTDoWhileUntilNode,
    BOOL is_do;     // is this a do () { } while();  or a while () {}
    BOOL is_while;  // is this a while or an until?
    LUASTNode *condition;
    LUASTNode *body;
);

DEFINE_NODE(LUASTForLoopNode,
    LUASTNode *initialiser;
    LUASTNode *condition;
    LUASTNode *post_body;
    LUASTNode *body;
);

DEFINE_NODE(LUASTIfElseNode,
    LUASTNode *condition;
    LUASTNode *ifbody;
    LUASTNode *elsebody;
);

DEFINE_NODE(LUASTReturnNode,
    LUASTNode *return_value;
);
    
extern LUASTNode *lu_ast_create_node(size_t size, LUASTNodeType node_type);
extern LUASTNode *lu_ast_create_basic_node(LUASTNodeType node_type);
extern LUASTNode *lu_ast_create_return_node(LUASTNode *value);
extern LUASTNode *lu_ast_create_long_node(long value);
extern LUASTNode *lu_ast_create_double_node(double value);
extern LUASTNode *lu_ast_create_complex_node(double x, double y, BOOL is_polar);
extern LUASTNode *lu_ast_create_subscript_node(LUASTNode *target, LUASTNode *subscript);
extern LUASTNode *lu_ast_create_variable_node(CUString *name);
extern LUASTNode *lu_ast_create_variable_decl_node(LUType *var_type, CUString *name, BOOL is_static);
extern LUASTNode *lu_ast_create_binary_node(short opcode, LUASTNode *left, LUASTNode *right);
extern LUASTNode *lu_ast_create_unary_node(short opcode, LUASTNode *child);
extern LUASTNode *lu_ast_create_cast_node(LUASTNode *source, LUType *target_type);
extern LUASTNode *lu_ast_create_while_node(BOOL is_do, BOOL is_while, LUASTNode *condition, LUASTNode *body);
extern LUASTNode *lu_ast_create_for_node(LUASTNode *initialiser, LUASTNode *condition, LUASTNode *post_body, LUASTNode *body);
extern LUASTNode *lu_ast_create_ifelse_node(LUASTNode *condition, LUASTNode *ifbody, LUASTNode *elsebody);

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif

#endif

