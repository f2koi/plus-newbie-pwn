function enter_workdir() {
    PREVIOUS_DIRECTORY=$PWD
    CURRENT_DIRECTORY=${0%/*}
    cd $CURRENT_DIRECTORY
}

function leave_workdir() {
    cd $PREVIOUS_DIRECTORY
}

function exit_with_message() {
    echo $1
    exit
}

function get_my_name() {
    echo ${0##*/}
}

function exit_with_usage() {
    SCRIPT_NAME=$(get_my_name)
    USAGE="usage: $SCRIPT_NAME <file_to_embed>"
    exit_with_message "$USAGE"
}

function instantiate() {
    _LINES=$1
    ROOT_DIR=../..
    TEMPLATE_DIR=$ROOT_DIR/templates

    cp $TEMPLATE_DIR/compose/base.yaml $TEMPLATE_DIR/compose/compose.yaml
    for LINE in $_LINES
    do
        PROB=${LINE%%:*}
        PORT=${LINE##*:}
        sed -e "s/{{prob}}/$PROB/g; s/{{port}}/$PORT/g; s/^/  /" $TEMPLATE_DIR/compose/service.yaml >> $TEMPLATE_DIR/compose/compose.yaml
    done
    mv $TEMPLATE_DIR/compose/compose.yaml $ROOT_DIR/compose.yaml
}

function main() {
    FILE_TO_EMBED=$1
    if [ -e $FILE_TO_EMBED ]
    then
        LINES=$(cat $FILE_TO_EMBED)
        instantiate "$LINES"
    else
        exit_with_usage
    fi
}

enter_workdir

FILE_TO_EMBED=$1
main $FILE_TO_EMBED

leave_workdir