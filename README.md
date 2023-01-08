# sf_32_unit_testing
Home work for Skillfactory's cource of C++, module 32 "Unit testing".

## Task
Create and test two classes:
- DBConnection
- ClassThatUsesDB

## How to use
Tested with `Linux Fedora 37`. You need to install `gcc`, `cmake` version 3.25 or higher and `mysql` library.\
Before first start app pursue command mysql < init.sql to initiate database.\
Usage:\
```sh
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
$ ./src/sk_32_unit_testing #To start app
$ ./tests/test_app #To test app
```