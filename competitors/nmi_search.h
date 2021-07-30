#ifndef NMI_SEARCH_H
#define NMI_SEARCH_H

#include "base.h"
#include "../../../rmi_cpp/src/RMI.h"

// NMI with binary search
// nmi_size: number of second layer nodes
template<class KeyType, int nmi_variant,
         uint64_t build_time, int nmi_size>
class NMI_B{
    private:       
        uint64_t data_size_;
        RMI<KeyType, uint64_t, nmi_size> *rmi;

    public:
        uint64_t Build(const std::vector<KeyValue<KeyType>>& data) {
            data_size_ = data.size();
            const std::string nmi_path = "/home/woojin/rmi_cpp/tests/RMI_uint32_uint64_256_Neuron256/";
            rmi = new RMI<KeyType, uint64_t, nmi_size>();
            rmi->load(nmi_path);
            return build_time;
        }

        SearchBound EqualityLookup(const KeyType lookup_key) const {
            uint64_t minErr = 0;
            uint64_t maxErr = 0;

            uint64_t result = rmi->find(lookup_key, &minErr, &maxErr);
            return (SearchBound){ result - minErr, result + maxErr };
        }

        std::string name() const {
            return "NMI";
        }

        std::size_t size() const {
            return nmi_size;
        }

        bool applicable(bool _unique, const std::string& data_filename) const {
            return true;
        }

        int variant() const {
            return nmi_variant;
        };

        ~NMI_B() {
            delete rmi;
        }
};

#endif // NMI_SEARCH_H