package main

import (
	"fmt"
	"os"
	"strconv"
)

func bubbleSort(a []int, n int) {
	swapped := true
	for swapped {
		swapped = false
		for i := 0; i < n-1; i += 1 {
			if a[i] > a[i+1] {
				tmp := a[i]
				a[i] = a[i+1]
				a[i+1] = tmp
				swapped = true
			}
		}
	}
}

func main() {
	n := len(os.Args) - 1
	a := make([]int, n)
	for i := 0; i < n; i += 1 {
		a[i], _ = strconv.Atoi(os.Args[i+1])
	}
	bubbleSort(a, n)
	for i := 0; i < n; i += 1 {
		fmt.Printf("%d, ", a[i])
	}
	fmt.Println("")
}
