#ifndef Alerter_h
#define Alerter_h

#include "stats.h"

void emailAlerter(float Threshold,struct Stats computedStats);

void ledAlerter(float Threshold,struct Stats computedStats);

#endif
