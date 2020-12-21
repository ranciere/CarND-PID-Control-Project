#include "PID.h"

double PID::update(double cte)
{
  if (!initialized)
  {
    prev_cte = cte;
    initialized = true;
  }
  sum += cte;
  double res = - (Kp * cte + Ki * sum + Kd * (cte-prev_cte) );
  prev_cte = cte;
  return res;
}
