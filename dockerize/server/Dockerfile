FROM crow:latest

WORKDIR /app

COPY . .

RUN make prepare
RUN cd build && cmake --build .

CMD ["./build/app/Server"]
