FROM debian:12.4

WORKDIR /drogon

RUN apt-get update
RUN apt-get -y install wget
RUN apt-get -y install gcc g++ make cmake
RUN apt-get -y install libjsoncpp-dev uuid-dev zlib1g-dev
RUN apt-get -y install libmariadb-dev
RUN apt-get -y install libc-ares-dev libbrotli-dev

RUN wget https://github.com/drogonframework/drogon/archive/refs/tags/v1.9.2.tar.gz
RUN tar xvzf v1.9.2.tar.gz -C .
RUN mv drogon-1.9.2/* .
RUN rm -rf drogon-1.9.2
RUN rm v1.9.2.tar.gz
RUN wget https://github.com/an-tao/trantor/archive/refs/tags/v1.5.16.tar.gz
RUN tar xvzf v1.5.16.tar.gz -C ./trantor
RUN mv trantor/trantor-1.5.16/* ./trantor
RUN cd trantor && rm -rf trantor-1.5.16
RUN rm v1.5.16.tar.gz

RUN mkdir build
RUN cd build && cmake ..
RUN cd build && cmake --build . -j4
RUN cd build && make install
