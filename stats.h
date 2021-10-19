#ifndef stats_H
#define stats_H

struct Stats
{
 uint8 average;
 uint8 min;
 uint8 max;
};

struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

#endif
