.PHONY: clean

CPPFLAGS := $(CPPFLAGS) -O3

build: linux windows

linux: CPP = g++
linux:
	$(CPP) $(CPPFLAGS) a.cpp -o a.elf
	strip a.elf

windows: CPP = x86_64-w64-mingw32-g++
windows:
	$(CPP) $(CPPFLAGS) a.cpp -o a.exe

clean:
	$(RM) a.exe a.elf
