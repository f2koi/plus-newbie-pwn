function enter_workdir() {
    PREVIOUS_DIRECTORY=$PWD
    CURRENT_DIRECTORY=${0%/*}
    cd $CURRENT_DIRECTORY
}

function leave_workdir() {
    cd $PREVIOUS_DIRECTORY
}

enter_workdir
bash ./instantiate.sh xinetd
bash ./instantiate.sh compose
leave_workdir