#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(float maxThreshold,struct Stats computedStats)
{
  if(computedStats.max > maxThreshold)
  {
    emailAlertCallCount=1;
  }
 }

void ledAlerter(float maxThreshold,struct Stats computedStats)
{
 if(computedStats.max > maxThreshold)
  {
   ledAlertCallCount=1;
  }
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    alerters[0](maxThreshold,computedStats);
    alerters[1](maxThreshold,computedStats);
}
struct Stats compute_statistics(const float* numberset, int setlength)
{
    struct Stats s;
    int i;
    float maxThreshold;
    s.average = NAN;
    s.min = NAN;
    s.max = NAN;
    static float average=0;
    if(0 != setlength)
    {
        for(i =0 ; i<setlength ; i++)
        {
            if(s.min > numberset[i])
            {
                s.min= numberset[i];
            }
            if(s.max < numberset[i])
            {
                s.max= numberset[i];
            }
            average+=numberset[i];
        }
        average/=setlength;
        check_and_alert(maxThreshold,alerters,s);
        return s;
    }
    else
    {
        return s;
    }
    
}
