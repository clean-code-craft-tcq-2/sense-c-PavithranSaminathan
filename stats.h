#ifndef stats_H
#define stats_H

struct Stats
{
 float average;
 float min;
 float max;
};

struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)(float maxThreshold, struct Stats computedStats);

void emailAlerter(float maxThreshold, struct Stats computedStats);
void ledAlerter(float maxThreshold, struct Stats computedStats);

alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

void check_and_alert(float maxThreshold, alerter_funcptr alerter[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

#endif
