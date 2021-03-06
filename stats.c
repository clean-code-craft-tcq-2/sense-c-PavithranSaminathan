#include "stats.h"
#include <math.h>
#include "stdio.h"
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(float max_Threshold, alerter_funcptr alerter[], struct Stats computedStats)
{
    alerter[0](max_Threshold,computedStats);
    alerter[1](max_Threshold,computedStats);
}
struct Stats compute_statistics(const float* numberset, int setlength)
{
    struct Stats s;
    int i;
    //float maxThreshold=10.5;
    
    if(numberset != NULL)
     {
       s.average = 0;
       s.min = numberset[0];
       s.max = numberset[0];
      }
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
            s.average+=numberset[i];
        }
        s.average/=setlength;
        //alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
        //check_and_alert(maxThreshold,alerters,s);
        return s;
    }
    else
    {
    s.min =nanf("");
    s.max =nanf("");
    s.average=nanf("");
    printf("d=%f",s.average);
    return s;
    }
    
}
