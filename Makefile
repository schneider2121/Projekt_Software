.PHONY: build test clean check

build:
	$(MAKE) -C c build

test:
	$(MAKE) -C c test
	$(MAKE) -C python test

check:
	$(MAKE) -C c check
	$(MAKE) -C python check

clean:
	$(MAKE) -C c clean
	$(MAKE) -C python clean