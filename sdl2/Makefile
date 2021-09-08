appname := app

CXX      := g++
CXXFLAGS := -std=c++11 $(shell pkg-config --cflags sdl2 SDL2_ttf SDL2_image)
LDFLAGS  = $(shell pkg-config --libs sdl2 SDL2_ttf SDL2_image)

srcfiles := $(shell find . -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) -o $(appname) $(objects) $(LDFLAGS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
