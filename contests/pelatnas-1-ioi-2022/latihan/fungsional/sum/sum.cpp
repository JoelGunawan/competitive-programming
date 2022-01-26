long long getSum(int N, int A[]) {
  long long result = 0;
  for(int i = 0; i < N; ++i)
    result += A[i];
  return result;
}
