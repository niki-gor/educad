.PHONY: build del rebuild
build:
	mkdir build && cd build
	cd build && cmake .. && cmake --build .
del:
	rm -rf build
rebuild:
	make del
	make build
