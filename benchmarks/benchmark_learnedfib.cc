#include "benchmarks/benchmark_learnedfib.h"

#include "benchmarks/common.h"
#include "benchmark.h"
#include "competitors/learned_FIB_search.h"

template <template<typename> typename Searcher>
void benchmark_32_lf(sosd::Benchmark<uint32_t, Searcher>& benchmark, bool pareto){
    benchmark.template Run<Learned_FIB_B<uint32_t>>();
}

INSTANTIATE_TEMPLATES(benchmark_32_lf, uint32_t);