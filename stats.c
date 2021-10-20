#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
float maxThreshold=10.5;
struct Stats computedStats;
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
    //struct Stats s;
    int i;
    //float maxThreshold=10.5;
    computedStats.average = NAN;
    computedStats.min = NAN;
    computedStats.max = NAN;
    static float average=0;
    if(0 != setlength)
    {
        for(i =0 ; i<setlength ; i++)
        {
            if(computedStats.min > numberset[i])
            {
                computedStats.min= numberset[i];
            }
            if(computedStats.max < numberset[i])
            {
                computedStats.max= numberset[i];
            }
            average+=numberset[i];
        }
        average/=setlength;
        //alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
        //check_and_alert(maxThreshold,alerters,s);
        return computedStats;
    }
    else
    {
        return computedStats;
    }
    
}
