#pragma once
#include "benchmark.h"

template<template<typename> typename Searcher>
void benchmark_32_lf(sosd::Benchmark<uint32_t, Searcher>& benchmark, bool pareto);