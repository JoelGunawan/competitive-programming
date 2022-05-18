#ifndef __EXPERIMENT_H__
#define __EXPERIMENT_H__

#include <vector>

std::vector<long long> get_experiment_results(int N, int M,
                                              std::vector<int> P, std::vector<int> Q,
                                              std::vector<int> L, std::vector<int> R,
                                              std::vector<int> D, std::vector<int> U);

#endif /* __EXPERIMENT_H__ */