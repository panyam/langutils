
#include "langutils.h"

struct LUTypeZone
{
};

DECLARE_PROTO_FUNC(lu_type_prototype, LUTypePrototype, NULL);

LUTypeZone *lu_type_default_zone()
{
    static LUTypeZone *default_zone = NULL;
    if (default_zone == NULL)
    {
        default_zone = lu_type_zone_create();
        lu_type_leaf(default_zone, cu_string("bool"));
        lu_type_leaf(default_zone, cu_string("char"));
        lu_type_leaf(default_zone, cu_string("short"));
        lu_type_leaf(default_zone, cu_string("int"));
        lu_type_leaf(default_zone, cu_string("float"));
        lu_type_leaf(default_zone, cu_string("long"));
        lu_type_leaf(default_zone, cu_string("double"));
    }
    return default_zone;
}

/**
 * Creates a new type zone.  This is the scope for all types used within a process.
 */
LUTypeZone *lu_type_zone_create()
{
    LUTypeZone *zone = ZNEW(LUTypeZone);
    return zone;
}

void lu_type_zone_destroy(LUTypeZone *zone)
{
    if (zone)
    {
        free(zone);
    }
};

LUType *lu_type_get(LUTypeZone *zone, const CUString *name)
{
    return NULL;
}

BOOL lu_type_set(LUTypeZone *zone, CUString *name, LUType *type, BOOL replace)
{
    return true;
}

/**
 * Creates an unresolved type with a given name.
 */
LUType *lu_type_unresolved(LUTypeZone *zone, CUString *name)
{
    LUType *t = (LUType *)cu_alloc(lu_type_prototype(), sizeof(LUType));
    t->zone = zone;
    cu_setattr(t, name, name);
    return t;
}

LUType *lu_type_leaf(LUTypeZone *zone, CUString *name)
{
    LUType *t = (LUType *)cu_alloc(lu_type_prototype(), sizeof(LUType));
    t->zone = zone;
    t->modifier = LUTM_LEAF_TYPE;
    t->resolved = true;
    cu_setattr(t, name, name);
    return t;
}

LUType *lu_type_reference(LUType *base_type)
{
    LUReferenceType *t = (LUReferenceType *)cu_alloc(lu_type_prototype(), sizeof(LUReferenceType));
    ((LUType *)t)->zone = base_type->zone;
    ((LUType *)t)->modifier = LUTM_REFERENCE_TYPE;
    ((LUType *)t)->resolved = base_type->resolved;
    cu_setattr(t, base_type, base_type);
    return (LUType *)t;
}

LUType *lu_type_array(LUType *base_type, int num_dimensions)
{
    LUArrayType *t = (LUArrayType *)cu_alloc(lu_type_prototype(), sizeof(LUArrayType));
    ((LUType *)t)->zone = base_type->zone;
    ((LUType *)t)->modifier = LUTM_ARRAY_TYPE;
    ((LUType *)t)->resolved = base_type->resolved;
    t->num_dimensions = num_dimensions;
    cu_setattr(t, base_type, base_type);
    return (LUType *)t;
}

LUType *lu_type_function(LUTypeZone *zone, LUType *return_type, CUList *param_types)
{
    LUFunctionType *t = (LUFunctionType *)cu_alloc(lu_type_prototype(), sizeof(LUFunctionType));
    ((LUType *)t)->zone = return_type->zone;
    ((LUType *)t)->modifier = LUTM_FUNCTION_TYPE;
    ((LUType *)t)->resolved = return_type->resolved;
    cu_setattr(t, return_type, return_type);
    cu_setattr(t, param_types, param_types);
    return (LUType *)t;
}

