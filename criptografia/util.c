#include <math.h>
#include <time.h>
#include <errno.h>
#include "util.h"

#define new_max(x, y) ((x) >= (y)) ? (x) : (y)

/**
 * Generates a random number inside range
 * @param min_num 
 * @param max_num 
 */
int randomNumber(int min_num, int max_num)
{
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num)
  {
    low_num = min_num;
    hi_num = max_num + 1; // include max_num in output
  }
  else
  {
    low_num = max_num + 1; // include max_num in output
    hi_num = min_num;
  }

  srand(time(NULL));
  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}

/**
 *  Returns the greatest common denominator of the inputted pair pair
 * @param num1 
 * @param num1 
 */
int getGCDByModulus(int num1, int num2)
{
  while (num1 != 0 && num2 != 0)
  {
    if (num1 > num2)
      num1 %= num2;
    else
      num2 %= num1;
  }
  return new_max(num1, num2);
}

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
  struct timespec ts;
  int res;

  if (msec < 0)
  {
    errno = EINVAL;
    return -1;
  }

  ts.tv_sec = msec / 1000;
  ts.tv_nsec = (msec % 1000) * 1000000;

  do
  {
    res = nanosleep(&ts, &ts);
  } while (res && errno == EINTR);

  return res;
}