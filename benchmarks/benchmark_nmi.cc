#include "benchmarks/benchmark_nmi.h"

#include "benchmarks/common.h"
#include "benchmark.h"
#include "competitors/nmi_search.h"

template <template<typename> typename Searcher>
void benchmark_32_nmi(sosd::Benchmark<uint32_t, Searcher>& benchmark, bool pareto){
    benchmark.template Run<NMI_B<uint32_t, 0, 0, 256>>();
}

INSTANTIATE_TEMPLATES(benchmark_32_nmi, uint32_t);