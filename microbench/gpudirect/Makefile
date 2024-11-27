.PHONY: clean

CFLAGS  := -Wall -g
LD      := g++
LDLIBS  := ${LDLIBS} -lrdmacm -libverbs -lpthread -lcuda
INC		:= -I/usr/local/cuda/include

APPS    := server client

all: ${APPS}

client: client.o
	${LD} -o $@ $^ ${LDLIBS} ${INC}

server: server.o
	${LD} -o $@ $^ ${LDLIBS} ${INC}


clean:
	rm -f ${APPS}
