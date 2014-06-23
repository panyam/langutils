
#ifndef __LANGUTILS_PARSER_LUAST_H__
#define __LANGUTILS_PARSER_LUAST_H__

#include "lufwddefs.h"

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif

typedef enum LUASTNumberType 
{
    LUAST_NUMBER_BOOL,
    LUAST_NUMBER_INT,
    LUAST_NUMBER_LONG,
    LUAST_NUMBER_FLOAT,
    LUAST_NUMBER_DOUBLE,
} LUASTNumberType ;

typedef enum LUASTNodeType
{
    LUAST_EMPTY_NODE,
    LUAST_BREAK_NODE,
    LUAST_CONTINUE_NODE,
    LUAST_UNARY_NODE,
    LUAST_ASSIGNMENT_NODE,
    LUAST_BINARY_NODE,
    LUAST_NUMBER_NODE,
    LUAST_VARIABLE_NODE,
    LUAST_VARIABLE_DECL_NODE,
    LUAST_DEFINITIONS_NODE,
    LUAST_LOOP_NODE,
    LUAST_IFELSE_NODE,
    LUAST_CASE_NODE,
    LUAST_SUBSCRIPT_NODE,
    LUAST_CLUAST_NODE,
    LUAST_RETURN_NODE,
    LUAST_ERROR_NODE,
    LUAST_LIST_NODE,
    LUAST_FUNC_CALL_NODE,
    LUAST_MEMBER_ACCESS_NODE,
    LUAST_NODE_COUNT,
} LUASTNodeType;

typedef void (*LUASTNodeGenerateCodeFunc)(LUASTNode *node);

CU_INHERIT_STRUCT(LUASTNodePrototype, CUPrototype,
    LUASTNodeGenerateCodeFunc generateCodeFunc;
);

/**
 * The ast for a parser. 
 * Some basic nodes are described here.  Others can be defined by the custom parsers.
 */
DECLARE_CLASS(LUASTNode, LUASTNodePrototype, 
    LUASTNodeType node_type;
    int line;
    int column;
);

#define LU_DEFINE_AST_NODE(NODE_TYPE, ...)  CU_INHERIT_STRUCT(NODE_TYPE, LUASTNode, __VA_ARGS__)

LU_DEFINE_AST_NODE(LUASTStringNode, 
    CUString *value;
);

LU_DEFINE_AST_NODE(LUASTNumberNode, 
    LUASTNumberType number_type;
    union {
        double double_value;
        long long_value;
        int int_value;
        float float_value;
    } value;
);

LU_DEFINE_AST_NODE(LUASTVariableNode, 
    CUString *var_name;
);

LU_DEFINE_AST_NODE(LUASTVariableDeclNode, 
    LUType *var_type;
    CUString *var_name;
    CUSet *modifiers;   // eg static, public, etc - langauge specific
);

LU_DEFINE_AST_NODE(LUASTSubscriptNode, 
    LUASTNode *target;
    LUASTNode *subscript;
);

LU_DEFINE_AST_NODE(LUASTAssignmentNode, 
    BOOL assign;
    LUASTNode *left;
    LUASTNode *right;
);

LU_DEFINE_AST_NODE(LUASTBinaryNode, 
    short opcode;
    LUASTNode *left;
    LUASTNode *right;
);

LU_DEFINE_AST_NODE(LUASTUnaryNode, 
    BOOL prefix;
    short opcode;
    LUASTNode *child;
);

LU_DEFINE_AST_NODE(LUASTCastNode, 
    LUASTNode *source;
    LUType *target_type;
);

LU_DEFINE_AST_NODE(LUASTLoopNode, 
    LUASTNode *initialiser;
    LUASTNode *condition;
    LUASTNode *post_body;
    LUASTNode *body;
    int loopType;   // applications specific
    BOOL negate_condition;
    BOOL condition_is_after_body;
);

LU_DEFINE_AST_NODE(LUASTIfElseNode, 
    LUASTNode *condition;
    LUASTNode *ifbody;
    LUASTNode *elsebody;
);

CU_INHERIT_STRUCT(LUASTErrorNode, LUASTNode, 
    CUString *message;
);

CU_INHERIT_STRUCT(LUASTReturnNode, LUASTNode, 
    LUASTNode *return_value;
);

CU_INHERIT_STRUCT(LUASTStatementsNode, LUASTNode, 
    CUList *statements;
);

CU_INHERIT_STRUCT(LUASTFuncCallNode, LUASTNode, 
    LUASTNode *source;
    CUList *params;
);

CU_INHERIT_STRUCT(LUASTMemberAccessNode, LUASTNode, 
    LUASTNode *source;
    CUString *member;
);

CU_INHERIT_STRUCT(LUASTListNode, LUASTNode, 
    CUList *values;
);

extern LUASTNodePrototype *lu_ast_string_node_prototype();
extern LUASTNodePrototype *lu_ast_number_node_prototype();
extern LUASTNodePrototype *lu_ast_basic_node_prototype();
extern LUASTNodePrototype *lu_ast_variable_node_prototype();
extern LUASTNodePrototype *lu_ast_return_node_prototype();
extern LUASTNodePrototype *lu_ast_error_node_prototype();
extern LUASTNodePrototype *lu_ast_subscript_node_prototype();
extern LUASTNodePrototype *lu_ast_variable_decl_node_prototype();
extern LUASTNodePrototype *lu_ast_ifelse_node_prototype();
extern LUASTNodePrototype *lu_ast_loop_node_prototype();
extern LUASTNodePrototype *lu_ast_cast_node_prototype();
extern LUASTNodePrototype *lu_ast_assignment_node_prototype();
extern LUASTNodePrototype *lu_ast_binary_node_prototype();
extern LUASTNodePrototype *lu_ast_unary_node_prototype();
extern LUASTNodePrototype *lu_ast_statements_node_prototype();
extern LUASTNodePrototype *lu_ast_list_node_prototype();
extern LUASTNodePrototype *lu_ast_func_call_node_prototype();
extern LUASTNodePrototype *lu_ast_member_access_node_prototype();
    
extern LUASTNode *lu_ast_create_node(int line, int col, size_t size,
                                     LUASTNodeType node_type, LUASTNodePrototype *proto);
extern LUASTNode *lu_ast_create_basic_node(int line, int col, LUASTNodeType node_type);
extern LUASTNode *lu_ast_create_return_node(int line, int col, LUASTNode *value);
extern LUASTNode *lu_ast_create_error_node(int line, int col, CUString *message);
extern LUASTNode *lu_ast_create_long_node(int line, int col, long value);
extern LUASTNode *lu_ast_create_double_node(int line, int col, double value);
extern LUASTNode *lu_ast_create_string_node(int line, int col, CUString *value);
extern LUASTNode *lu_ast_create_subscript_node(int line, int col, LUASTNode *target, LUASTNode *subscript);
extern LUASTNode *lu_ast_create_variable_node(int line, int col, CUString *name);
extern LUASTNode *lu_ast_create_variable_decl_node(int line, int col, LUType *var_type, CUString *name, CUSet *modifiers);
extern LUASTNode *lu_ast_create_assignment_node(int line, int col, BOOL assign, LUASTNode *left, LUASTNode *right);
extern LUASTNode *lu_ast_create_binary_node(int line, int col, short opcode, LUASTNode *left, LUASTNode *right);
extern LUASTNode *lu_ast_create_unary_node(int line, int col, short opcode, LUASTNode *child, BOOL prefix);
extern LUASTNode *lu_ast_create_cast_node(int line, int col, LUASTNode *source, LUType *target_type);
extern LUASTNode *lu_ast_create_loop_node(int line, int col, int loopType,
                                          LUASTNode *initialiser,
                                          LUASTNode *condition,
                                          LUASTNode *post_body,
                                          LUASTNode *body,
                                          BOOL negate_condition,
                                          BOOL condition_is_after_body);
extern LUASTNode *lu_ast_create_ifelse_node(int line, int col, LUASTNode *condition, LUASTNode *ifbody, LUASTNode *elsebody);

extern LUASTNode *lu_ast_create_statements_node(int line, int col, LUASTNode *statement);
extern LUASTNode *lu_ast_add_statement(LUASTNode *statements, LUASTNode *statement);

/**
 * Function calls.
 */
extern LUASTNode *lu_ast_create_func_call_node(int line, int col, LUASTNode *source, CUList *params);
extern LUASTNode *lu_ast_add_func_call_param(LUASTNode *func_call_node, LUASTNode *param);

// Member accesses
extern LUASTNode *lu_ast_create_member_access_node(int line, int col, LUASTNode *source, CUString *attrib);

// Create a list of objects.
extern LUASTNode *lu_ast_create_list_node(int line, int col, CUList *values);

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif

#endif

