# MongoDB-C--Sample
This project is to get an abstract idea for coding in C++ for data insertion/deletion/read into MongoDB

## Build Command
g++ --std=c++11 <filename>.cpp -o build/<filename> $(pkg-config --cflags --libs libmongocxx) && ./build/<filename>

Note: 
> echo $(pkg-config --cflags --libs libmongocxx)
> -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/bsoncxx/v_noabi -I/usr/local/include/libbson-1.0 -L/usr/local/lib -lmongocxx -lbsoncxx

## Dockerfile
The provided dockerfile is adapted from https://stackoverflow.com/questions/46283218/installing-mongo-c-and-c-drivers-in-docker thanks to Pav K.

## Reference Websites
http://mongocxx.org/mongocxx-v3/tutorial/