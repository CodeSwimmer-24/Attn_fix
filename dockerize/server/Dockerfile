FROM drogon:latest

WORKDIR /app

COPY . .

RUN mkdir build
RUN cd build && cmake ..
RUN cd build && cmake --build . -j4 --config Release --target workers

CMD ["./build/workers"]
