typedef unsigned long long uint64;

int get(uint64 mask, int index) {
	return (mask >> (index << 2)) & 15);
}

uint64 set(uint64 mask, int index, uint64 value) {
	return mask & ~(15LL << (index << 2) | (value << (index << 2));
}