
#ifndef __LANGUTILS_FWDDEFS_H__
#define __LANGUTILS_FWDDEFS_H__

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif

#include <cutils.h>

// typedef enum LUTypeModifier LUTypeModifier;
// typedef enum LUASTNumberType LUASTNumberType;
// typedef enum LUASTNodeType LUASTNodeType;
typedef struct LUTokenizer LUTokenizer;
typedef struct LUCFGRule LUCFGRule;
typedef struct LUCFGReduction LUCFGReduction;
typedef struct LUCFGParser LUCFGParser;
typedef struct LUCFGParserPrototype LUCFGParserPrototype;

typedef struct LUToken LUToken;
typedef struct LUTypePrototype LUTypePrototype;
typedef struct LUTypeZone LUTypeZone;
typedef struct LUType LUType;
typedef struct LUArrayType LUArrayType;
typedef struct LUFunctionType LUFunctionType;
typedef struct LUReferenceType LUReferenceType;
typedef struct LUTupleType LUTupleType;

typedef struct LUASTNodePrototype LUASTNodePrototype;
typedef struct LUASTNode LUASTNode;
typedef struct LUASTStatementsNode LUASTStatementsNode;
typedef struct LUASTStringNode LUASTStringNode;
typedef struct LUASTNumberNode LUASTNumberNode;
typedef struct LUASTVariableNode LUASTVariableNode;
typedef struct LUASTSubscriptNode LUASTSubscriptNode;
typedef struct LUASTVariableDeclNode LUASTVariableDeclNode;
typedef struct LUASTAssignmentNode LUASTAssignmentNode;
typedef struct LUASTBinaryNode LUASTBinaryNode;
typedef struct LUASTUnaryNode LUASTUnaryNode;
typedef struct LUASTCastNode LUASTCastNode;
typedef struct LUASTLoopNode LUASTLoopNode;
typedef struct LUASTSwitchNode LUASTSwitchNode;
typedef struct LUASTIfElseNode LUASTIfElseNode;
typedef struct LUASTReturnNode LUASTReturnNode;
typedef struct LUASTErrorNode LUASTErrorNode;
typedef struct LUASTFuncCallNode LUASTFuncCallNode;
typedef struct LUASTMemberAccessNode LUASTMemberAccessNode;
typedef struct LUASTListNode LUASTListNode;

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif

#endif

