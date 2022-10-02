#include "container.h"

void Container::fill(int n) {
	size = n;
}

bool Container::consume(int n) {
	size -= n;
	return true;
}

int Container::getSize() {
	return size;
}