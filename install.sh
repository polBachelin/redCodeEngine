[ -d "./build" ] && sudo rm -rf build/
mkdir build && cd build/ && cmake .. && make -j
cd ..
while test $# -gt 0
do
    case "$1" in
        -d) valgrind ./build/redCode
        ;;
        -dl) valgrind --leak-check=full --show-leak-kinds=all ./build/redCode
        ;;
        *) ./build/redCode
        ;;
    esac
    shift
done
exit 0