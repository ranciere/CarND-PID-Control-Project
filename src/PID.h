#ifndef PID_H
#define PID_H

class PID
{
public:
  /**
   * Constructor
   */
  PID(double Kp_, double Ki_, double Kd_) : Kp(Kp_), Ki(Ki_), Kd(Kd_) {}

  /**
   * Destructor.
   */
  virtual ~PID() = default;

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  double update(double cte);

private:
  double prev_cte = 0.0;
  double sum = 0.0;

  bool initialized = true;

  /**
   * PID Coefficients
   */
  const double Kp;
  const double Ki;
  const double Kd;
};

#endif // PID_H