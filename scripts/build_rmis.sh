#! /usr/bin/env bash
# git submodule update --init --recursive

mkdir -p rmi_data

function build_rmi_set() {
    DATA_NAME=$1
    HEADER_PATH=~/SOSD/competitors/rmi/${DATA_NAME}_0.h
    JSON_PATH=~/SOSD/scripts/rmi_specs/${DATA_NAME}.json

    shift 1
    if [ ! -f $HEADER_PATH ]; then
        echo "Building RMI set for $DATA_NAME"
        # execute ~/Learend_index_ngs/RMI/target/release/rmi file
        # data stored at data/$DATA_NAME
        # with config at --param-grid ${JSON_PATH}
        # output at rmi_data (maybe...)
        # 8 thraeds, zero build time
        ~/SOSD/RMI/target/release/rmi ~/SOSD/data/$DATA_NAME --param-grid ${JSON_PATH} -d ~/SOSD/rmi_data/ --threads 8 --zero-build-time
        echo "Done"
        mv ${DATA_NAME}_* ~/SOSD/competitors/rmi/
    fi
}


cd ~/SOSD/RMI && cargo build --release && cd ..
build_rmi_set dna_uint32
~/SOSD/scripts/rmi_specs/gen.sh