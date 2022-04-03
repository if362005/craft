#ifndef __FPFILTERFUNC_H
#define __FPFILTERFUNC_H

#include "/home/lxj/test/craft/craft/extern/dyninst/instructionAPI/h/Instruction.h"
#include "Point.h"

#include "FPSemantics.h"
#include "FPDecoder.h"

using namespace Dyninst;

namespace FPInst {

class FPFilterFunc {

    public:

        bool operator()(PatchAPI::Point::Type, PatchAPI::Location, FPDecoder*);

        bool filter(InstructionAPI::Instruction::Ptr inst, FPDecoder*);

};

}

#endif

