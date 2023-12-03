import cpp

from FunctionCall fc, Function f
where
    f = fc.getTarget() and
    f.hasGlobalName("strcpy") and
    not fc.getArgument(1).getType().(ArrayType).getSize() <= fc.getArgument(O).getType().(ArrayType).getSize()
select fc, "this call to strcpy could lead to a buffer overflow"