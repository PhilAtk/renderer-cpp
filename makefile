DEPS = src/main.cpp
CPP = clang++
CPPFLAGS = -lSDL2_image -lSDL2_ttf

a.out: $(DEPS)
	$(CPP) $(DEPS) $(CPPFLAGS)

main.cpp: