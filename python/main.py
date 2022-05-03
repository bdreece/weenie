from sys import argv

def bubble_sort(a):
	swapped = True
	while swapped:
		swapped = False
		for i in range(len(a) - 1):
			if a[i] > a[i + 1]:
				tmp = a[i]
				a[i] = a[i + 1]
				a[i + 1] = tmp
				swapped = True

if __name__ == '__main__':
	a = []
	for i in range(len(argv) - 1):
		a.append(argv[i + 1])
	bubble_sort(a)
	for i in range(len(a)):
		print(str(a[i]) + ', ')

