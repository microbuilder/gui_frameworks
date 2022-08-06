appname  = app

CC      := gcc
CFLAGS  := -Wall -D_GNU_SOURCE=1 -D_THREAD_SAFE -std=c99
CFLAGS  += $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS += $(shell pkg-config --libs gtk+-3.0)

srcfiles := $(shell find . -name "*.c")
objects  := $(patsubst %.c, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CC) $(CFLAGS) -o $(appname) $(objects) $(LDFLAGS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
