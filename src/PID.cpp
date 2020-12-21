#include <cstdio>
#include "PID.h"

double PID::update(double cte)
{
  if (!initialized)
  {
    prev_cte = cte;
    initialized = true;
  }
  sum += cte;
  // Limiting integral term summa
  if (sum > 15) { sum = 15; }
  if (sum < -15) { sum = -15; }

  double res = - (Kp * cte + Ki * sum + Kd * (cte-prev_cte) );
  prev_cte = cte;
  return res;
}
