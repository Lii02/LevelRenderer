#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <chrono>

class Stopwatch {
	using TimePoint = std::chrono::high_resolution_clock::time_point;
private:
	TimePoint begin, end;
	double delta;
public:
	Stopwatch();

	void Begin();
	void End();
	double GetDeltaMillis() const;
	double GetDeltaSeconds() const;
};

#endif