bool isPerfectSquare(int num)
{
  long n = num;
  while (n * n > num)
  {
    n = (n + num / n) >> 1;
  }
  return n * n == num;
}
