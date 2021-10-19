#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    uint8_t i;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    static float average=0;
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
    
}
