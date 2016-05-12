all: installd

installd: JSCTest-debug.apk
	ant installd

build: JSCTest-debug.apk

JSCTest-debug.apk: libs/armeabi/libjsctest.so
	ant debug

libs/armeabi/libjsctest.so:
	ndk-build

clean:
	@rm -r bin gen libs obj ||:

clean-libjsctest:
	@rm libs/armeabi/libjsctest.so

.PHONY: all
.PHONY: installd
.PHONY: build
.PHONY: clean
