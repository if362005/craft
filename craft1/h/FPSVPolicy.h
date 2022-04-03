#ifndef __FPFPSVPOLICY_H
#define __FPFPSVPOLICY_H

#include "FPSemantics.h"
#include "FPOperand.h"
#include "FPSV.h"
#include "FPReplaceEntry.h"

namespace FPInst {

/**
 * Handles decision-making for shadow-value or replacement analysis.
 *
 * Contains functions that policies can override to affect the behavior of
 * shadow-value analysis, including decisions about whether a particular
 * instruction should be instrumented, whether a value should be replaced, and
 * what shadow value types should be used. This class also decides which shadow
 * value type should be used in the case that two incompatible types are
 * involved in a common operation.
 *
 * The default policy returns defaultType for all base type decisions, applies a
 * basic bit-size lattice to common type evaluations, and decides to replace any
 * floating-point value that can be replaced on the current architecture.
 * This behavior can be changed by subclassing this object and overriding the
 * methods.
 */
class FPSVPolicy {

    public:

        FPSVPolicy(FPSVType defaultType);
        virtual ~FPSVPolicy();

        virtual bool shouldInstrument(FPSemantics *inst);

        // shadow value or replacement type for a particular instruction or
        // operand
        virtual FPSVType getSVType();
        virtual FPSVType getSVType(FPSemantics *inst);
        virtual FPSVType getSVType(FPOperand *op, FPSemantics *inst);

        // initial setting for candidate configuration file
        virtual FPReplaceEntryTag getDefaultRETag(FPSemantics *inst);

        virtual FPSVType getCommonType(FPSVType type1, FPSVType type2);
        virtual bool shouldReplaceWithPtr(FPOperand *op, FPSemantics *inst);

        virtual FPSVType RETag2SVType(FPReplaceEntryTag tag);

    protected:

        FPSVType defaultType;

};

}

#endif

