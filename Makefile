.PHONY: build del rebuild angemTest makeAngemReport startReportServer
build:
	mkdir build && cd build
	cd build && cmake .. && cmake --build .
del:
	rm -rf build
rebuild:
	make del
	make build
angemTest:
	./build/test/testAngem
makeAngemReport:
	cd build && 														\
	lcov -t "test/testAngem" -o Cov.info -c -d . &&		\
	genhtml -o report Cov.info
startReportServer:
	cd build/report &&													\
	python3 -m http.server 8080											\