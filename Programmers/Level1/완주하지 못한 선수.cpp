#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

#define MAX_KEY 25
#define MAX_TABLE 262144

typedef struct {
	char key[MAX_KEY + 1];
	int cnt;
}Hash;
Hash tb[MAX_TABLE];

unsigned long makeHash(const char* str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++) hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	return hash % MAX_TABLE;
}

char* find() {
	int cnt = MAX_TABLE;
	while (cnt--) {
		if (tb[cnt].key[0] != 0 && tb[cnt].cnt != 0) return tb[cnt].key;
	}
	return 0;
}

int add(const char* key) {
	unsigned long h = makeHash(key);
	while (tb[h].key[0] != 0) {
		if (strcmp(tb[h].key, key) == 0) {
			tb[h].cnt++;
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	tb[h].cnt = 1;
	return 1;
}

int del(const char* key) {
	unsigned long h = makeHash(key);
	int cnt = MAX_TABLE;
	while (tb[h].key[0] != 0 && cnt--) {
		if (strcmp(tb[h].key, key) == 0) {
			tb[h].cnt--;
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int main() {

	vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa", "josipa", "abc" };
	vector<string> completion = { "josipa", "filipa", "marina", "nikola", "vinko", "abc" };

	int N1 = participant.size();
	for (int i = 0; i < N1; i++) add(participant[i].c_str());
	for (int i = 0; i < N1 - 1; i++) del(completion[i].c_str());

	string name(find());
	cout << name << "\n";

	return 0;
}