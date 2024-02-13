FROM gcc:latest
WORKDIR /src
COPY source ./src
RUN make linux
CMD [ "main" ]