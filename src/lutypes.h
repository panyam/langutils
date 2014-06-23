
#ifndef __LANGUTILS_TYPES_H__
#define __LANGUTILS_TYPES_H__

#include "lufwddefs.h"

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif

typedef enum LUTypeModifier
{
    LUTM_UNRESOLVED_TYPE,
    LUTM_NULL_TYPE,
    LUTM_LEAF_TYPE,
    LUTM_ARRAY_TYPE,
    LUTM_REFERENCE_TYPE,
    LUTM_TUPLE_TYPE,
    LUTM_RECORD_TYPE,
    LUTM_FUNCTION_TYPE,
    LUTM_PARAMETRIC_TYPE,
} LUTypeModifier;

CU_INHERIT_STRUCT(LUTypePrototype, CUPrototype);

DECLARE_CLASS(LUType, LUTypePrototype,
    BOOL resolved;              // has the type been resolved - allow for lazy loading
    LUTypeModifier modifier;    // identifies the type of type!
    CUString *name;             // Name of the type
    LUTypeZone *zone;           // Type zone
);

CU_INHERIT_STRUCT(LUArrayType, LUType,
    LUType *base_type;
    int num_dimensions;
);

CU_INHERIT_STRUCT(LUReferenceType, LUType,
    LUType *base_type;
);

CU_INHERIT_STRUCT(LUTupleType, LUType,
    CUList *fields;         // for tuples
);

CU_INHERIT_STRUCT(LURecordType, LUType,
    CUMap *fields;          // for classes, records, structs
);

/**
 * Function types - return and param types.
 */
CU_INHERIT_STRUCT(LUFunctionType, LUType,
    LUType *return_type;
    CUList *param_types;
);

/**
 * Parametric types.
 */
CU_INHERIT_STRUCT(LUParametricType, LUType,
    // name of the parameter
    CUString *param_name;

    // Constraints on the parameter - ie of interfaces whose functions must be implemented by the base type
    CUList *constraints;
);

/**
 * Generalised algebraic data types
 */
CU_INHERIT_STRUCT(LUGADType, LUType,
    CUString *name;         // name of the GAD type, eg Tree, List etc
    CUList *param_names;    // Name of the parameter if any
    CUMap *constructors;    // each constructor is a key value pair, where 
                            // the key is the name of the constructor and 
                            // the value is a list of types that is held 
                            // by the constructor, 
                            // 
                            // eg: data Tree = Empty
                            //              | Leaf Int
                            //              | Node Tree Tree
                            // 
                            // or
                            //
                            // data List a = Nil | Cons a (List a)
);

/**
 * Creates a new type zone.  This is the scope for all types used within a process.
 */
extern LUTypeZone *lu_type_default_zone();
extern LUTypeZone *lu_type_zone_create();
extern void lu_type_zone_destroy(LUTypeZone *zone);

extern LUTypePrototype *lu_type_prototype();

// get a type given the name
extern LUType *lu_type_get(LUTypeZone *zone, const CUString *name);

// set the type for a given name
extern BOOL lu_type_set(LUTypeZone *zone, CUString *name, LUType *type, BOOL replace);

extern LUType *lu_type_unresolved(LUTypeZone *zone, CUString *name);
extern LUType *lu_type_leaf(LUTypeZone *zone, CUString *name);
extern LUType *lu_type_reference(LUType *base_type);
extern LUType *lu_type_array(LUType *base_type, int num_dimensions);
extern LUType *lu_type_function(LUTypeZone *zone, LUType *return_type, CUList *param_types);

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif

#endif

