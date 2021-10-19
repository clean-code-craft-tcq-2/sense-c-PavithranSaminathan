#include "Alert.h"

void emailAlerter()
{
  if(computedStats.max > maxThreshold)
  {
    emailAlertCallCount=1;
  }
 }

void ledAlerter()
{
 if(computedStats.max > maxThreshold)
  {
   ledAlertCallCount=1;
  }
}
