#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


struct Stats compute_statistics(const float* numberset, int setlength)
{
    struct Stats s;
    int i;
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
        return s;
    }
    else
    {
        return s;
    }
    
}
