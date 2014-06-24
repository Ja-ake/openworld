#ifndef TESTEXT_H_
#define TESTEXT_H_

#include "std.h"
#include "engine/base/test.h"

class TestEXT : public Test {
public:
	TestEXT();
	virtual ~TestEXT();

	void update(double);
};

#endif /* TESTEXT_H_ */
