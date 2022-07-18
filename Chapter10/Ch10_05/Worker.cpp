#pragma once
#include "Timer.h"
#include "Worker.h"

void Worker::doSomething()
{
	Timer timer;	//start timer

					// do somer work here

	timer.elapsed(); // end timer and report elapsed time
}
