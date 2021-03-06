#pragma once
#include "SpinSource.h"
#include "ReelSet.h"

class SpinSourceGenerator : public SpinSource
{
public:
	SpinSourceGenerator(const SymbolSet* symbolSet = nullptr);
	SpinSourceGenerator(const SymbolSet* symbolSet, JSONArray reelSets);
	SpinSourceGenerator(const SymbolSet * symbolSet, JSONArray reelSets, JSONArray payLines);
	virtual Spin* getNextSpin();
private:
	SpinSourceGenerator(const SpinSourceGenerator&);
	SpinSourceGenerator& operator=(const SpinSourceGenerator&);
protected:
	virtual Spin* getNextSpin(int reelSetChosen);
	int reelSetCount;
	std::vector<ReelSet*> reelSets;
	std::vector<int> reelSetPmls;
	PayLineSet payLineSet;
};