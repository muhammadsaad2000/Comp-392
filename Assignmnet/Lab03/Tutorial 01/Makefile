include. env

CFLAGS= -std=c++17 -I. -I$(VULKAN_SDK_PATH) / include
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib 'pkg-config -static -libs glfw3' -lvulkan

a. out: *. cpp *.hpp
	g++ $(CFLAGS) -0 a.out *.cpp $(LDFLAGS)

.PHONY: test clean

test: a.out
./a.out

clean:
rm -f a.out