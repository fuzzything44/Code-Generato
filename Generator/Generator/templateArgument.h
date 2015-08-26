#pragma once
#include "classDef.h"

class templateArgument
{
public:
    templateArgument(classDef argType);
    bool fitsArg(classDef doesFit);
private:
    classDef arg;
};