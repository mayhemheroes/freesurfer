FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential libxml2-dev clang

COPY . /repo
WORKDIR /repo/utils
RUN g++ -o xmlToHtml xmlToHtml.cpp -lxml2 -I/usr/include/libxml2 -fpermissive
RUN clang++ /repo/mayhem/fuzz_add.cpp -fsanitize=fuzzer,address  -I /repo/include/ -o /fuzz

FROM ubuntu:22.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libxml2-dev
COPY --from=builder /repo/utils/xmlToHtml /
COPY --from=builder /fuzz /fuzz_add
