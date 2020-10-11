#include <binaryen-c.h>
#include <stdio.h>

int main()
{
    BinaryenModuleRef module = BinaryenModuleCreate();

    BinaryenType ii[2] = {BinaryenTypeInt32(), BinaryenTypeInt32()};
    BinaryenType params = BinaryenTypeCreate(ii, 2);
    BinaryenType result = BinaryenTypeInt32();

    BinaryenExpressionRef i = BinaryenConst(module, BinaryenLiteralInt32(0));

    BinaryenExpressionRef ptr = BinaryenLoad(module, 4, 0, 0, 0, BinaryenTypeInt32(), i);

    BinaryenExpressionRef list[] = {
        ptr
    }; 
    BinaryenExpressionRef blk = BinaryenBlock(module, NULL, list, 1, result);

    BinaryenFunctionRef func = BinaryenAddFunction(module, "pmain", params, result, NULL, 0, blk);
    
    BinaryenModulePrint(module);
    // printf("%s", module);
    
}