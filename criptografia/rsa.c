#include "rsa.h"
#include "prime.c"

void encrypt()
{
  int prime1, prime2, commonValue, commonValuePhi, i;
  prime1 = 2; //randPrime();
  msleep(1000);
  prime2 = 7; // randPrime();
  commonValue = prime1 * prime2;
  commonValuePhi = phi(prime1, prime2);

  for (i = 1; i < commonValuePhi; i++)
  {
    if (coprime(i, commonValue) && coprime(i, commonValuePhi))
    {
      printf("%d\n", i);
    }
  }
}

int phi(int num1, int num2)
{
  return (num1 - 1) * (num2 - 1);
}
