FROM drogon:latest

WORKDIR /app

COPY . .

RUN mkdir build
RUN cd build && cmake ..
RUN cd build && cmake --build . -j4

CMD ["./build/workers"]
