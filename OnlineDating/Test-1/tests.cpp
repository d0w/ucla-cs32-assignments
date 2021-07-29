#include "OnlineDating.h"
#include <type_traits>

#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }
static_assert(std::is_default_constructible<OnlineDating>::value
	,
	"Map must be default-constructible.");

static_assert(std::is_copy_constructible<OnlineDating>::value,
	"Map must be copy-constructible.");
void ThisFunctionWillNeverBeCalled()
{
	CHECKTYPE(&OnlineDating::operator=, OnlineDating &
		(OnlineDating::*)(const OnlineDating&));
	CHECKTYPE(&OnlineDating::noMatches, bool
	(OnlineDating::*)() const);
	CHECKTYPE(&OnlineDating::howManyMatches, int
	(OnlineDating::*)() const);
	CHECKTYPE(&OnlineDating::makeMatch, bool (OnlineDating::*)
		(const std::string&, const std::string&, const
			OnlineType&));
	CHECKTYPE(&OnlineDating::transformMatch, bool
	(OnlineDating::*)(const std::string&, const std::string&,
		const OnlineType&));
	CHECKTYPE(&OnlineDating::makeOrTransform, bool
	(OnlineDating::*)(const std::string&, const std::string&,
		const OnlineType&));
	CHECKTYPE(&OnlineDating::blockPreviousMatch, bool
	(OnlineDating::*)
		(const std::string&, const std::string&));
	CHECKTYPE(&OnlineDating::someoneAmongMatches, bool
	(OnlineDating::*)(const std::string&, const std::string&)
		const);
	CHECKTYPE(&OnlineDating::lookAtMatches, bool
	(OnlineDating::*)
		(const std::string&, const std::string&, OnlineType&)
		const);
	CHECKTYPE(&OnlineDating::confirmMatch, bool (OnlineDating::*)
		(int, std::string&, std::string&, OnlineType&)
		const);
	CHECKTYPE(&OnlineDating::tradeMatches, void
	(OnlineDating::*)(OnlineDating&));
		CHECKTYPE(mergeMatches, bool (*)(const OnlineDating&, const
			OnlineDating&, OnlineDating&));
	CHECKTYPE(authenticateMatches, void (*)(const std::string&,
		const std::string&, const OnlineDating&, OnlineDating&));
}
int main()
{}