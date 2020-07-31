#include "rsa.h"
#include "prime.c"

struct keyPair
{
  int key;
  int common;
};

void encrypt()
{
  struct keyPair *keys;
  keys = keyGeneration();
  printf("Common Number: %d\n", keys[0].common);
  printf("Public Number: %d\n", keys[0].key);
  printf("Private Number: %d\n", keys[1].key);
}

struct keyPair *keyGeneration()
{
  int prime1, prime2, commonValue, commonValuePhi, i;
  struct keyPair public, private;
  prime1 = 2; //randPrime();
  msleep(1000);
  prime2 = 7; // randPrime();
  commonValue = prime1 * prime2;
  commonValuePhi = phi(prime1, prime2);

public
  .common = commonValue;
private
  .common = commonValue;

  for (i = 1; i < commonValuePhi; i++)
  {
    if (coprime(i, commonValue) && coprime(i, commonValuePhi))
    {
      printf("%d\n", i);
    public
      .key = i;
    }
  }

  int random = 2; //randomNumber(5, 15);
  i = 0;
  while (i <= random * public.key + 1)
  {
    if (public.key * i % commonValuePhi == 1)
    {
    private
      .key = i;
    }
    i++;
  }
  struct keyPair *keys = (struct keyPair *)malloc(sizeof(struct keyPair) * 2);
  keys[0] = public;
  keys[1] = private;
  return keys;
}

int phi(int num1, int num2)
{
  return (num1 - 1) * (num2 - 1);
}
