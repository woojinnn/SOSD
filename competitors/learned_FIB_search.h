#ifndef LEARNED_FIB_SEARCH_H
#define LEARNED_FIB_SEARCH_H

#include "../Learned_FIB/include/Learned_FIB.h"
#include "base.h"

template <class KeyType>
class Learned_FIB_B : public Competitor {
 private:
  Learned_FIB<KeyType>* lf;

 public:
  uint64_t Build(const std::vector<KeyValue<KeyType>>& data) {
    const std::string lf_path =
        "/home/woojin/Learned_FIB/tests/test_model/branching/8/nn_trained";
    lf = new Learned_FIB<KeyType>();
    lf->load(lf_path);
    return 0;
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    size_t result = lf->find(lookup_key);
    return (SearchBound){.start = std::min(result - 254, result),
                         .stop = result + 254};
  }

  std::string name() const { return "Learned_FIB"; }

  std::size_t size() const { return 0; }

  ~Learned_FIB_B() { delete lf; }
};

#endif  // LEARNED_FIB_SEARCH_H