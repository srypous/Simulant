#pragma once
#include "Window.h"
#include "Reel.h"
#include "JSON/JSON.h"
#include "Random.h"

class ReelSet
{
public:
	ReelSet(const JSONValue* source, const SymbolSet& symbolSet);
    ~ReelSet();
	void shuffle();
	virtual void spin();
	void spinToPosition(const std::vector<int>& position);
	void spinAndFind21(int symbolID);
	// Gets the spin window; if the parametr is nullptr, it allocates a new window,
	// which the caller is responsible to destroy
	Window* getWindow(Window* window = nullptr);
	int getReelsCount();
	int getReelLength(int reelID);
	const std::wstring& getName() const;
protected:
	virtual Reel& getReel(int position);
	void fullShuffle();	// generate a random permutation of reels, all permutations are allowed
    int reelsCount;
	int permCount;
	int visibleReelsCount;
	int windowMaxHeight;
	bool isShuffling;
	bool isSubstituting;
	std::vector<Reel*> reels;
	std::vector<Reel*> substituteReels;
	std::vector<Reel*> substituteBonusReels21; // this is not clean code
	std::vector<int> substitutePositions;
	std::vector<std::vector<int>> permutations;
	std::vector<int> reelID; // used for reel shuffle
	std::wstring name;
};