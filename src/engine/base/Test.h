#ifndef TEST_H_
#define TEST_H_

#include "std.h"
#include "commandchain.h"

class Test : public CommandChain {
public:
	Test();
	virtual ~Test();

	void update(double);
};

#endif /* TEST_H_ */
