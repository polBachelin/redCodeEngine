[ -d "build" ] && sudo rm -rf build
mkdir build/ && cd build && cmake .. && make && ./engine_tests
cd ..
