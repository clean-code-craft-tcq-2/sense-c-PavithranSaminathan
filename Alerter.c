#include "Alerter.h"


void emailAlerter(float Threshold,struct Stats computedStats)
{
  if(computedStats.max > Threshold)
  {
    emailAlertCallCount=1;
  }
 }

void ledAlerter(float Threshold,struct Stats computedStats)
{
 if(computedStats.max > Threshold)
  {
   ledAlertCallCount=1;
  }
}
