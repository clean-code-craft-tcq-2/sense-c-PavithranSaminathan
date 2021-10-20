#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

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


void check_and_alert(float max_Threshold, alerter_funcptr alerter[], struct Stats computedStats)
{
    alerter[0](max_Threshold,computedStats);
    alerter[1](max_Threshold,computedStats);
}
struct Stats compute_statistics(const float* numberset, int setlength)
{
    struct Stats s;
    int i;
    float maxThreshold=10.5;
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
        //alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
        //check_and_alert(maxThreshold,alerters,s);
        return s;
    }
    else
    {
        return s;
    }
    
}
