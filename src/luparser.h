
#ifndef __LANGUTILS_PARSER_LLPARSER_H__
#define __LANGUTILS_PARSER_LLPARSER_H__

#include "lufwddefs.h"

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif

CU_INHERIT_STRUCT(LUCFGParserPrototype, CUPrototype);

typedef void (*LUCFGRuleHandlerFunc)(LUCFGParser *parser, LUCFGReduction *reduction);

struct LUCFGRule
{
    int nonterm;
    int numSymbols;
    int *symbols;   // symbols corresponding to the rule
    LUCFGRuleHandlerFunc handler;
};

struct LUCFGReduction
{
    LUCFGRule *rule;
    void *symbolResults[];
};

DECLARE_CLASS(LUCFGParser, LUCFGParserPrototype,
    int numNonTerms;
    CULinkedList **rules;   // numNonTerms number of lists of rules, each list containing all rules for a particular nonterm
    int numTerminals;
    int numRules;
    int *assocs;        // associativity for each terminal if any - default = "nonassoc"
    int *precedences;   // precedence for each terminal - if any - default = 100
    void *extraData;
);

extern LUCFGParserPrototype *lu_llparser_prototype();
extern LUCFGParser *lu_llparser_create(int numTerminals, int numNonTerminals);
extern int lu_llparser_add_production(LUCFGParser *parser, int nonterm, int *symbols, LUCFGRuleHandlerFunc handler);

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif

#endif

