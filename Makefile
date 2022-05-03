all: bubblesort_c bubblesort_cxx bubblesort_go bubblesort.py bubblesort_rust

bench: all
	python fill.py 5000
	hyperfine "cat list.txt | xargs ./bubblesort_c" \
		"cat list.txt | xargs ./bubblesort_cxx" \
		"cat list.txt | xargs ./bubblesort_go" \
		"cat list.txt | xargs ./bubblesort_rust" \
		"cat list.txt | xargs python bubblesort.py"

hard-bench: all
	python fill.py 100000
	hyperfine "cat list.txt | xargs ./bubblesort_c" \
		"cat list.txt | xargs ./bubblesort_cxx" \
		"cat list.txt | xargs ./bubblesort_go" \
		"cat list.txt | xargs ./bubblesort_rust"

.PHONY: clean
clean:
	rm -f ./bubblesort*

bubblesort_c: c/main.c
	gcc -g -O3 -o $@ $<

bubblesort_cxx: cxx/main.cpp
	g++ -g -O3 -o $@ $<

bubblesort_go: go/main.go
	cd go; go build -o ../$@ .

bubblesort.py: python/main.py
	cp $^ $@

bubblesort_rust: rust/src/main.rs
	cd rust; cargo b -rj16; cp target/release/rust ../$@
