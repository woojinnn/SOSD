#!/bin/bash
set -e

# # build RMI
# echo "Start scripts/build_rmis_dna.sh"
# rm -f competitors/rmi/dna_uint32_*
# rm -f output_logs/build_rmi_dna.txt
# bash scripts/build_rmis.sh > output_logs/build_rmi.txt

# prepare (make lookup file, build)
echo "Start scripts/prepare.sh"
rm -f data/dna_uint32_equal*
rm -f output_logs/prepare.txt
bash scripts/prepare.sh > output_logs/prepare.txt

# Execute
echo "Start scripts/execute.sh"
rm -f output_logs/execute.txt
rm -f results/dna_uint32_results.txt
rm -f results/dna_uint32_skipped_results.txt
# bash scripts/execute.sh > output_logs/execute.txt
bash scripts/execute.sh