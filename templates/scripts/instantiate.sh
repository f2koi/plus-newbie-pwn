function enter_workdir() {
    PREVIOUS_DIRECTORY=$PWD
    CURRENT_DIRECTORY=${0%/*}
    cd $CURRENT_DIRECTORY
}

function leave_workdir() {
    cd $PREVIOUS_DIRECTORY
}

function exit_with_message() {
    echo -e $1
    exit
}

function get_my_name() {
    echo ${0##*/}
}

function exit_with_usage() {
    SCRIPT_NAME=$(get_my_name)
    USAGE="usage: $SCRIPT_NAME <type>"
    USAGE+="\n(type: xinetd | compose)"
    exit_with_message "$USAGE"
}

function main() {
    TYPE=$1
    FILE_TO_EMBED=$2

    if [ $TYPE == "xinetd" ]
    then
        bash ./instantiate-xinetd.sh $FILE_TO_EMBED
    elif [ $TYPE == "compose" ]
    then
        bash ./instantiate-compose.sh $FILE_TO_EMBED
    else
        exit_with_usage
    fi
}


enter_workdir

TYPE=$1
FILE_TO_EMBED="../challs_and_ports.txt"
main $TYPE "$FILE_TO_EMBED"

leave_workdir